// The old version of the Arduino IDE (at the moment 1.8.19) is required, the 2.x version does not upload to my Picos correctly (for me!).

// Basic idea was taken from the Arduino KeyboardAndMouseControl sketch, thanks for the very good example <3. Add this "additional Boards Manager
// URL": https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json and switch to Pi Pico and Compile. See
// https://randomnerdtutorials.com/programming-raspberry-pi-pico-w-arduino-ide/ as an example how to switch the board to the Pico.

#include <Keyboard.h>
#include <Mouse.h>
// The board libs include these includes.

void setup() {
  // Make the pin an input and turn on the pullup resistor, so it goes LOW unless connected to ground.
  pinMode(0, INPUT_PULLUP); // mouse left
  pinMode(1, INPUT_PULLUP); // mouse right
  pinMode(2, INPUT_PULLUP); // button 1
  pinMode(3, INPUT_PULLUP); // button 2
  pinMode(4, INPUT_PULLUP); // button 3
  pinMode(5, INPUT_PULLUP); // button 4
  pinMode(6, INPUT_PULLUP); // button 6
  pinMode(7, INPUT_PULLUP); // button 7
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // Sorting is upside down to have all other keys interrupt the mainly used (almost permanently pressed) left mouse-click.
  if (digitalRead(7) == LOW) { Keyboard.print("z");      delay(77); }
  if (digitalRead(6) == LOW) { Keyboard.print("q");      delay(77); }
  if (digitalRead(5) == LOW) { Keyboard.print("4");      delay(77); }
  if (digitalRead(4) == LOW) { Keyboard.print("3");      delay(77); }
  if (digitalRead(3) == LOW) { Keyboard.print("2");      delay(77); }
  if (digitalRead(2) == LOW) { Keyboard.print("1");      delay(77); }
  if (digitalRead(1) == LOW) { Keyboard.print("q");      delay(77); }
  // if (digitalRead(1) == LOW) { Mouse.click(MOUSE_RIGHT); delay(77); }
  if (digitalRead(0) == LOW) { Mouse.click(MOUSE_LEFT);  delay(77); }
}
