/*
  This Library is written for PCA9685 I2C PWM Expander
  Author: Bonezegei (Jofel Batutay)
  Date: March 2024 
*/

#include "Bonezegei_PCA9685.h"

Bonezegei_PCA9685::Bonezegei_PCA9685(uint8_t addr) {
  _addr = addr;
}

char Bonezegei_PCA9685::begin() {
  if (Wire.begin()) {
    return 1;
  } else {
    return 0;
  }
}

void Bonezegei_PCA9685::setValue(uint8_t channel, int value){

}


void  Bonezegei_PCA9685::write(uint8_t reg_addr, uint8_t data){

}

uint8_t  Bonezegei_PCA9685::read(uint8_t reg_addr){
  return 1;
}
