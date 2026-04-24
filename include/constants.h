#ifndef CONSTANTS_H
#define CONSTANTS_H

// --- PWM Configuration ---
const int PWM_FREQ = 5000;
const int PWM_RESOLUTION = 8; // 0-255

// --- Pin Definitions ---
const int LED_PIN = 2;
const int MOTOR_PIN = 18;

// --- Motor Parameters ---
// TODO: Find the minimum PWM value to overcome static friction
const int MOTOR_START_OFFSET = 40; 

// --- Gamma Correction Parameters ---
const float GAMMA = 2.2;

#endif
