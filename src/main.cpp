/**
 *  @file   calc.ino
 *  @brief  This source code contains the main function of the calculator, and all the necessary input and output.
 * 
 *  This file contains all of the Arduino sensors and actuators. The keypad, LCD display, and other Arduino components
 *  will be monitored in this source code.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   15/04/2026
 *  @bug    No known bugs.
 */

#include <Arduino.h>
#include <stdint.h>
#include <Key.h>
#include <Keypad.h>

#define ROW 4
#define COL 4

// Create a mapping of each button to a specific character
char mappings[ROW][COL] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'*', '0', '=', '/'}
};

// Pin placement for the keypad
uint8_t rowPins[ROW] = {2, 3, 4, 5};
uint8_t colPins[COL] = {6, 7, 8, 9};

// Create a keypad object using Keypad.h
Keypad keypad = Keypad(makeKeymap(mappings), rowPins, colPins, ROW, COL);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  int numbers[MAX_SIZE];
  char operations[MAX_SIZE];

  if (key)
    Serial.println(key);
}
