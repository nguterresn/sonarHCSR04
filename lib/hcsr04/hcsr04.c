#include "hcsr04.h"

// change micros() to timer1 counter

void setupHCSR04() {

    // Set trig as output 
    DDRD |= (1<<TRIG);
    DDRD &= ~(1<<ECHO);
    // ECHO is set INPUT as default

}

void sendTrigger() {

    PORTD &= ~(1<<TRIG);
    PORTD |= (1<<TRIG);
    _delay_us(10);
    PORTD &= ~(1<<TRIG);

}

void waitEcho(double *echotime) {

    uint64_t start, end;
    /* WHILE ECHO IS LOW */
    while(!(PIND & (1 << ECHO)));

    /* START MEASURE TIME */
    PORTD |= (1<<LED_PIN);
    start = micros();

    /* WAIT WHILE ECHO IS HIGH */
    while(PIND & (1 << ECHO));

    /* END MEASURE TIME */
    end = micros();
    PORTD &= ~(1<<LED_PIN);
    *echotime = end - start;
}

void pulseWidth(uint16_t *distance, double echotime) {

    *distance = echotime / 58;

}