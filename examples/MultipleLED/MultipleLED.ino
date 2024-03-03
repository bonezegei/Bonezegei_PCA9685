/*
  Multiple LED Example 
  Author: Bonezegei (Jofel Batutay)
  Date: March 2024 

  Connect LED At Channels, 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
*/

#include "Bonezegei_PCA9685.h"

// Default Address of PCA9685 = 0x40
Bonezegei_PCA9685 expander(0x40);

void setup() {
  Serial.begin(9600);

  //Initialize the Expander
  if (expander.begin()) {
    Serial.println("PCA9685 Found");
  } else {
    Serial.println("Error PCA9685 not Connected");
  }

  // Frequency in Hertz
  expander.setFrequency(50);
}

void loop() {

  for (int a = 0; a < 4095; a++) {

    // setValue(Param1, Param2);
    // Param1 = Channel (0 - 15)
    // Param2 = Value (0 - 4095)
    for (int b = 0; b < 16; b++) {
      expander.setValue(b, a);
    }
    delayMicroseconds(100);
  }

  for (int a = 4095; a > 0; a--) {
    for (int b = 0; b < 16; b++) {
      expander.setValue(b, a);
    }
    delayMicroseconds(100);
  }
}
