#include <Arduino.h>
#include <mouse_control.h>

#define SLEEP 100

Mouse_control my_mouse_control; /* Creamos el objecto mouse */

void setup() {
  my_mouse_control.init();
}

void loop() {
  my_mouse_control.run();
  delay(SLEEP);
}