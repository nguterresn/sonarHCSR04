#include "stdint.h"
#include <avr/io.h>
#include <util/delay.h>
#include <time.h>
#include "Arduino.h"

/* Uno - HCSR04 connected Pins */
#define TRIG 2
#define ECHO 3
#define LED_PIN 4

void setupHCSR04();
void sendTrigger();
void waitEcho(double *echotime);
void pulseWidth(uint16_t *distance, double echotime);