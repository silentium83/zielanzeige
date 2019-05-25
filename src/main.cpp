#include "font.h"

#include <Arduino.h>
#include <avr/cpufunc.h>
#include <avr/pgmspace.h>

#include <limits.h>
#include <stdint.h>

int pixel_width(String const & text);
void shiftout(uint8_t const bit);
void clear_buffer();
int write_letter_at(int col, uint8_t const letter);
void letters(int pos);
void receive_serial();

int const WIDTH = 120;
int const LINES = 7;
int const CHAR_GAP = 1;
int const LINE_PINS[7] = { 2, 3, 4, 5, 6, 7, 8 };
int const LED_PIN = 13;

uint8_t buffer[120];
String message = "Infodesk   #GPN19";
String newMessage;
int messageLength = pixel_width(message);
int ticks = 0;
int turn = 120;

int pixel_width(String const & text) {
	int width = 0;
	for (unsigned int i = 0; i < text.length(); ++i) {
		uint8_t const charWidth = pgm_read_byte(&font_var_width[(uint8_t)(text[i])].width);
		if (charWidth) {
			if (width < INT_MAX - CHAR_GAP - charWidth) {
				width += charWidth + CHAR_GAP;
			} else {
				return INT_MAX;
			}
		}
	}
	width -= CHAR_GAP;
	if (width < 0) {
		width = 0;
	}
	return width;
}

// Shift register needs to use raw AVR
// B1 is clock
// B2 is data
void shiftout(uint8_t const bit) {
	PORTB = bit << 2;
	PORTB |= 0x02;
	PORTB = 0;
}

void clear_buffer() {
	for (int i = 0; i < WIDTH; ++i) {
		buffer[i] = 0;
	}
}

int write_letter_at(int col, uint8_t const letter) {
	uint8_t charWidth = pgm_read_byte(&font_var_width[letter].width);
	for (int_fast8_t x = 0; x < charWidth; ++x) {
		if (col >= 0 && col < WIDTH) {
			buffer[col] = pgm_read_byte(&font_var_width[letter].columns[x]);
		} else if (col >= WIDTH) {
			return col;
		}
		++col;
	}
	col += CHAR_GAP;
	return col;
}

void letters(int pos) {
	clear_buffer();

	for (unsigned int c = 0; c < message.length() && pos < WIDTH; ++c) {
		pos = write_letter_at(pos, message[c]);
	}
}

void receive_serial() {
	while (Serial.available() > 0) {
		char const receivedChar = Serial.read();
		switch (receivedChar) {
			case '\b': // backspace
				if (newMessage.length() > 0) {
					newMessage.remove(newMessage.length() - 1);
					Serial.write("\b ");
				}
				break;
			case '\n': // newline
				if (newMessage.length() > 0) {
					if (message != newMessage) {
						message = newMessage;
						messageLength = pixel_width(message);
						ticks = 0;
						turn = 120;
					}
					newMessage = "";
				}
				Serial.print(message);
				break;
			case '\r': // carriage return
				break;
			default:
				newMessage += receivedChar;
				break;
		}
		Serial.write(receivedChar);
	}
}

void setup() {
	for (uint_fast8_t i = 2; i <= 10; ++i) {
		pinMode(i, OUTPUT);
	}
	pinMode(LED_PIN, OUTPUT);

	Serial.begin(9600);
}

void loop() {
	for (uint_fast8_t y = 0; y < LINES; ++y) {
		for (uint_fast8_t x = 0; x < WIDTH; ++x) {
			uint8_t const bit = (buffer[x] & (1 << y)) ? 1 : 0;
			shiftout(bit);
		}

		digitalWrite(LINE_PINS[y], 1);
		delayMicroseconds(200);
		digitalWrite(LINE_PINS[y], 0);
	}

	++ticks;
	if (ticks == 6) {
		if (messageLength > 120) {
			clear_buffer();
		}
	} else if (ticks == 8) {
		ticks = 0;
		if (messageLength > 120) {
			--turn;

			letters(turn);

			if (turn == -messageLength) {
				turn = 120;
			}
		} else {
			int const padding = (120 - messageLength) / 2;

			letters(padding);
		}
	}
	receive_serial();
}
