#include "M5DinMeter.h"
#include <Avatar.h>
#define PI 3.14159265

using namespace m5avatar;

Avatar avatar;

void setup() {
    auto cfg = M5.config();
    DinMeter.begin(cfg, true);
    DinMeter.Display.setRotation(1);
    avatar.setPosition(-10, 5);
    avatar.setScale(0.7);
    avatar.init(); // start drawing
}

long oldPosition = -999;

void loop() {
    DinMeter.update();
    long newPosition = DinMeter.Encoder.read();
    if (newPosition != oldPosition) {
        DinMeter.Speaker.tone(8000, 20);
        oldPosition = newPosition;
        if(newPosition > 60){
          newPosition = 0;
        }
        Serial.println(newPosition);
        avatar.setRotation(PI/30*newPosition);

    }

    if (DinMeter.BtnA.wasHold()) {
      DinMeter.Power.powerOff();
    }
}
