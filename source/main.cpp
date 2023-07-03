#include "MicroBit.h"

MicroBit uBit;

int main()
{
    uBit.init();

    uBit.io.speaker.setAnalogValue(128);
    
    while (1) {
        int volatile brightness = uBit.display.readLightLevel();

        uBit.io.speaker.setAnalogPeriodUs((brightness * -30) + 8000);

        uBit.serial.printf("%d ", brightness);
        uBit.sleep(100);
    }
}

