#include <Arduino.h>
#include <avr/cpufunc.h>
#include <avr/pgmspace.h>

#include "font.h"

const int WIDTH = 120;
const int LINES = 7;
const int LINE_PINS[7] = { 2, 3, 4, 5, 6, 7, 8 };

uint8_t buffer[120];
String message = "9600N1   ISO8859-15   https://github.com/silentium83/zielanzeige/tree/develop";
String newMessage;
int ticks = 0;
int runde = 120;

// Shift register needs to use raw AVR
// B1 is clock
// B2 is data
void shiftout(uint8_t bit) {
	PORTB = bit << 2;
	PORTB |= 0x02;
	PORTB = 0;
}

void write_letter_at(int startcol, uint8_t letter) {
	for (int_fast8_t x = 0; x < 5; x++) {
		int col = startcol + x;
		if (col >= 0 && col < WIDTH) {
			buffer[col] = pgm_read_byte(&font_5x7_col[letter][x]);
		}
	}
}

void letters(int round) {
	for (int i = 0; i < WIDTH; i++) {
		buffer[i] = 0;
	}

	int pos = 0;
	for (unsigned int c = 0; c < message.length(); c++) {
		write_letter_at(round + pos, message[c]);
		pos += 6;
	}
}

void receive_serial() {
	while (Serial.available() > 0) {
		char receivedChar = Serial.read();
		switch (receivedChar) {
			case '\b': // backspace
				if (newMessage.length() > 0) {
					newMessage.remove(newMessage.length() - 1);
				}
				break;
			case '\n': // newline
			case '\r': // carriage return
				if (newMessage.length() > 0) {
					if (message != newMessage) {
						message = newMessage;
						ticks = 0;
						runde = 120;
					}
					newMessage = "";
				}
				break;
			default:
				newMessage += receivedChar;
				break;
		}
	}
}

void setup() {
	for (uint_fast8_t i = 2; i <= 10; i++) {
		pinMode(i, OUTPUT);
	}
	pinMode(13, OUTPUT);

	Serial.begin(9600);
}

void loop() {
	for (uint_fast8_t y = 0; y < LINES; y++) {
		for (uint_fast8_t x = 0; x < WIDTH; x++) {
			uint8_t bit = (buffer[x] & (1 << y)) ? 1 : 0;
			shiftout(bit);
		}

		digitalWrite(13, 1);
		digitalWrite(LINE_PINS[y], 1);
		delayMicroseconds(200);
		digitalWrite(13, 0);
		digitalWrite(LINE_PINS[y], 0);
	}

	ticks++;
	if (ticks == 8) {
		ticks = 0;
		if ((6 * (int)message.length()) > 120) {
			runde--;

			letters(runde);

			if (runde == -(6 * (int)message.length())) {
				runde = 120;
			}
		} else {
			int padding = (120 - (6 * (int)message.length())) / 2;

			letters(padding);
		}
	}
	receive_serial();
}
