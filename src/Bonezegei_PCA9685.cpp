/*
  This Library is written for PCA9685 I2C PWM Expander
  Author: Bonezegei (Jofel Batutay)
  Date: March 2024 
*/

#include "Bonezegei_PCA9685.h"

Bonezegei_PCA9685::Bonezegei_PCA9685(uint8_t addr) {
  _addr = addr;
  Wire.begin();
}

char Bonezegei_PCA9685::begin() {

  uint8_t r = read(0);
  if (r) {

    if (r & 0x80) {  //If Restrat Bit 7
      write(0, r & 0xBF);
      delay(1);
      r = read(0);
      write(0, r | 0x80);
      delay(1);
      write(0, 0x01);
    }
    r = read(0);

    if (r & 0x10) {
      write(0, 0x01);
    }
    return 1;
  } else {
    return 0;
  }
  return 0;
}

void Bonezegei_PCA9685::setValue(uint8_t channel, int value) {
  // int value_ON = 4096 - value;
  // int value_OFF = 4095;
  int value_ON = 1;
  int value_OFF = value;

  write((ADDR_CHANNEL_BASE + (4 * channel)) + 1, (value_ON >> 8) & 0xff);   // ON_HIGH
  write((ADDR_CHANNEL_BASE + (4 * channel)), value_ON & 0xff);              // ON_LOW
  write((ADDR_CHANNEL_BASE + (4 * channel)) + 3, (value_OFF >> 8) & 0xff);  // OFF_HIGH
  write((ADDR_CHANNEL_BASE + (4 * channel)) + 2, value_OFF & 0xff);         // OFF_LOW
}

void Bonezegei_PCA9685::setFrequency(int value) {
  int pre = round(6103.515625 / value) - 1;
  write(ADDR_PRESCALE, pre);
}


void Bonezegei_PCA9685::write(uint8_t reg_addr, uint8_t data) {
  Wire.beginTransmission(_addr);
  Wire.write(reg_addr);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t Bonezegei_PCA9685::read(uint8_t reg_addr) {
  Wire.beginTransmission(_addr);
  Wire.write(reg_addr);
  Wire.endTransmission();
  Wire.requestFrom((int)_addr, 1);

  uint8_t ch = 0;
  while (Wire.available()) {
    ch = Wire.read();
  }

  return ch;
}
