#include <Arduino.h>
#include "constants.h"

/**
 * @brief Drive the motor with dead-zone compensation.
 * Formula: finalPWM = Offset + speed * (255 - Offset) / 255
 * 
 * @param speed Target speed (0-255)
 */
void smartDrive(int speed) {
    if (speed <= 0) {
        analogWrite(MOTOR_PIN, 0);
        return;
    }
    
    // Dead-zone compensation
    int finalPWM = MOTOR_START_OFFSET + (speed * (255 - MOTOR_START_OFFSET) / 255);
    
    // Ensure it doesn't exceed 255
    if (finalPWM > 255) finalPWM = 255;
    
    analogWrite(MOTOR_PIN, finalPWM);
}

/**
 * @brief Linear respiratory LED
 */
void breathingLinear() {
    for (int i = 0; i <= 255; i++) {
        analogWrite(LED_PIN, i);
        delay(10);
    }
    for (int i = 255; i >= 0; i--) {
        analogWrite(LED_PIN, i);
        delay(10);
    }
}

/**
 * @brief Gamma corrected respiratory LED
 */
void breathingGamma() {
    for (int i = 0; i <= 255; i++) {
        // Simple square correction for B group: (i*i/255)
        int brightness = (i * i) / 255;
        analogWrite(LED_PIN, brightness);
        delay(10);
    }
    for (int i = 255; i >= 0; i--) {
        int brightness = (i * i) / 255;
        analogWrite(LED_PIN, brightness);
        delay(10);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    pinMode(MOTOR_PIN, OUTPUT);
    
    Serial.println("PWM Basics Lab Started");
}

void loop() {
    // Demo: Gamma breathing
    breathingGamma();
    
    // Demo: Linear breathing
    // breathingLinear();
    
    // Demo: Motor control (example speed 128)
    // smartDrive(128);
}
