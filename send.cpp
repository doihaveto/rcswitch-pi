/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <decimal code> <bit length> <pulse length>\n", argv[0]);
        return 1;
    }
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 5;
    unsigned int decimalCode = atoi(argv[1]); // light: 10434200
    int bitLength = atoi(argv[2]); // light: 24
    int pulseLength = atoi(argv[3]); // light: 130
    if (wiringPiSetup () == -1)
        return 1;

    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(PIN);
    mySwitch.setPulseLength(pulseLength);
    
    mySwitch.send(decimalCode, bitLength);
    return 0;
}
