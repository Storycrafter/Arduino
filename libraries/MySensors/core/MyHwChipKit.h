/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */
#ifndef MyHwChipKit_h
#define MyHwChipKit_h

#include "MyHw.h"
#include <Wire.h>

#ifdef __cplusplus
#include <Arduino.h>
//#include <SPI.h>
#endif

#define MY_SERIALDEVICE Serial
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define snprintf_P(s, f, ...) snprintf((s), (f), __VA_ARGS__)

// Define these as macros to save valuable space
uint8_t configBlock[1024];
#define hwDigitalWrite(__pin, __value) (digitalWrite(__pin, __value))
void hwInit();
void hwWatchdogReset();
void hwReboot();
void serialEventRun();
#define hwMillis() millis()
#define delay(secs) delayMicroseconds(secs * 1000)

void hwReadConfigBlock(void* buf, void* adr, size_t length);
void hwWriteConfigBlock(void* buf, void* adr, size_t length);
void hwWriteConfig(int adr, uint8_t value);
uint8_t hwReadConfig(int adr);


#endif // #ifdef ARDUINO_ARCH_SAMD
