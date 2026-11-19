/**
 * VÍ DỤ 1-03: ĐIỀU CHẾ ĐỘ RỘNG XUNG LEDC PWM (BREATHING LED)
 */
#include <Arduino.h>

const int LED_PIN = 2;
const int PWM_CHANNEL = 0;
const int PWM_FREQ = 5000;
const int PWM_RESOLUTION = 8;

void setup() {
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loop() {
    // Tăng dần độ sáng (Fade In)
    for (int duty = 0; duty <= 255; duty++) {
        ledcWrite(PWM_CHANNEL, duty);
        delay(8);
    }
    delay(200);

    // Giảm dần độ sáng (Fade Out)
    for (int duty = 255; duty >= 0; duty--) {
        ledcWrite(PWM_CHANNEL, duty);
        delay(8);
    }
    delay(500);
}
