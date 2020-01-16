#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
}

double echotime = 0.0;
uint16_t distance = 0;

void setup() {

    Serial.begin(9600);
    DDRD |= (1<<LED_PIN);
    PORTD |= (1<<LED_PIN);
    setupHCSR04();

}

void loop() {   

    sendTrigger();
    waitEcho(&echotime);
    pulseWidth(&distance, echotime);

    Serial.println("************");
    Serial.print("Echo time: "); Serial.println(echotime);
    Serial.print("Disntace in cm: "); Serial.println(distance);
    delay(1000);
}