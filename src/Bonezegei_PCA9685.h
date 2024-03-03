/*
  This Library is written for PCA9685 I2C PWM Expander
  Author: Bonezegei (Jofel Batutay)
  Date: March 2024 
*/
#ifndef _BONEZEGEI_PCA9685_H_
#define _BONEZEGEI_PCA9685_H_

#include <Arduino.h>
#include <Wire.h>

#define ADDR_MODE1 0x01
#define ADDR_MODE2 0x02
#define ADDR_PRESCALE 0xFE
#define ADDR_CHANNEL_BASE 0x06

class Bonezegei_PCA9685 {
public:
  Bonezegei_PCA9685(uint8_t addr);

  char begin();
  void setValue(uint8_t channel, int value);

  //Set Frequency in Hertz
  void setFrequency(int value);

  // I2C Read and Write
  void write(uint8_t reg_addr, uint8_t data);
  uint8_t read(uint8_t reg_addr);

  uint8_t _addr;
};

#endif
