#pragma once
// -------------------------------------------------------------------------------------------------
// Pin map for OnStep MaxESP Version 3.x (ESP32S)
#pragma once

//TODO:
//shared pins for directions for focuser and collimator
//shared EN for focuser and coll
//aux or in conf for aux functions?
//check grey out #ifdef
//check spreadsheet matches schematic
#if defined(ESP32)

// Serial ports (see Pins.defaults.h for SERIAL_A)
// Serial0: RX Pin GPIO3, TX Pin GPIO1 (to USB serial adapter)
// Serial1: RX1 Pin GPIO10, TX1 Pin GPIO9 (on SPI Flash pins, must be moved to be used)
// Serial2: RX2 Pin GPIO39, TX2 Pin GPIO18

#if SERIAL_A_BAUD_DEFAULT != OFF
#define SERIAL_A              Serial
#endif
#if SERIAL_B_BAUD_DEFAULT != OFF
#define SERIAL_B              Serial2
#endif

#define AUX1_PIN		      GPIO_PIN(7)		 // Dew heater
#define AUX2_PIN              GPIO_PIN(6)		 // Fan
#define AUX3_PIN              GPIO_PIN(5)		 // Intervalometer
#define AUX4_PIN              27		         // PPS or Step for Collimator 3, depending on board jumper setting
#define AUX5_PIN              18		         // RX Serial B or Step for Collimator 1, depending on board jumper setting

//Alternative SDA/SCL, if needed
#define I2C_SDA_PIN           25
#define I2C_SCL_PIN           22

//Serial B
#define SERIAL_B_RX           39
#define SERIAL_B_TX           AUX5_PIN

//One Wire temperature
#define ONE_WIRE_PIN          32                          // for Auxiliary feature #1 (dew heater)

// Misc. pins
#define ADDON_GPIO0_PIN       19                 // ESP8266 GPIO0 (Dir2) - Axis 2 DIR
#ifndef ADDON_RESET_PIN
#define ADDON_RESET_PIN       GPIO_PIN(15)       // ESP8266 RST
#endif

// The status LED is a two wire jumper with a 10k resistor in series to limit the current to the LED
#ifndef STATUS_LED_PIN
#define STATUS_LED_PIN        GPIO_PIN(13)       // Default LED Cathode (-)
#endif
#define MOUNT_LED_PIN         STATUS_LED_PIN     // Default LED Cathode (-)

// For a piezo buzzer
#ifndef STATUS_BUZZER_PIN
#define STATUS_BUZZER_PIN     GPIO_PIN(14)       // Tone
#endif

// The PPS pin is a 3.3V logic input, OnStep measures time between rising edges and adjusts the internal sidereal clock frequency
#ifndef PPS_SENSE_PIN
#define PPS_SENSE_PIN         AUX4_PIN           // PPS time source, RTC
#endif

// The limit switch sense is a logic level input normally pull high (2k resistor,) shorted to ground it stops gotos/tracking
#ifndef LIMIT_SENSE_PIN
#define LIMIT_SENSE_PIN       35
#endif

#define SHARED_DIRECTION_PINS                    // Hint that the direction pins are shared (for axis >2)
#define SHARED_ENABLE_PIN     GPIO_PIN(8)        // Hint that the enable pins are shared
#define SHARED_ENABLE_PIN2    GPIO_PIN(11)       // Hint that the enable pins are shared

// Axis1 RA/Azm step/dir driver
#define AXIS1_ENABLE_PIN      SHARED
#define AXIS1_M0_PIN          OFF
#define AXIS1_M1_PIN          OFF
#define AXIS1_M2_PIN          5                   // Multi-step pin
#define AXIS1_M3_PIN          OFF
#define AXIS1_STEP_PIN        12
#define AXIS1_DIR_PIN         21
#ifndef AXIS1_SENSE_HOME_PIN
#define AXIS1_SENSE_HOME_PIN  34
#endif

// Axis2 Dec/Alt step/dir driver
#define AXIS2_ENABLE_PIN      SHARED
#define AXIS2_M0_PIN          OFF
#define AXIS2_M1_PIN          OFF
#define AXIS2_M2_PIN          14                  // Multi-step pin
#define AXIS2_M3_PIN          OFF
#define AXIS2_STEP_PIN        26
#define AXIS2_DIR_PIN         19
#ifndef AXIS2_SENSE_HOME_PIN
#define AXIS2_SENSE_HOME_PIN  36
#endif

// For rotator stepper driver
#define AXIS3_ENABLE_PIN      OFF                // No enable pin control (always enabled)
#define AXIS3_M0_PIN          OFF
#define AXIS3_M1_PIN          OFF
#define AXIS3_M2_PIN          OFF
#define AXIS3_M3_PIN          OFF
#define AXIS3_STEP_PIN        OFF              
#define AXIS3_DIR_PIN         OFF

// For focuser1 stepper driver
#define AXIS4_ENABLE_PIN      GPIO_PIN(12)       // Enable pin on external GPIO
#define AXIS4_M0_PIN          OFF
#define AXIS4_M1_PIN          OFF
#define AXIS4_M2_PIN          OFF
#define AXIS4_M3_PIN          OFF
#define AXIS4_STEP_PIN        4
#define AXIS4_DIR_PIN         2

// For collimator1 stepper driver
#define AXIS5_ENABLE_PIN      SHARED       // shared with all other collimator motors
#define AXIS5_M0_PIN          OFF
#define AXIS5_M1_PIN          OFF
#define AXIS5_M2_PIN          OFF
#define AXIS5_M3_PIN          OFF
#define AXIS5_STEP_PIN        AUX5_PIN           // If ESP8266 is not used
#define AXIS5_DIR_PIN         2                  // shared with all other collimator motors

// For collimator2 stepper driver
#define AXIS6_ENABLE_PIN      SHARED             // shared with all other collimator motors
#define AXIS6_M0_PIN          OFF
#define AXIS6_M1_PIN          OFF
#define AXIS6_M2_PIN          OFF
#define AXIS6_M3_PIN          OFF
#define AXIS6_STEP_PIN        23                // Use RX2 pin if ESP8266 is not used
#define AXIS6_DIR_PIN         2                  // shared with all other collimator motors

// For collimator3 stepper driver
#define AXIS7_ENABLE_PIN      SHARED             // shared with all other collimator motors
#define AXIS7_M0_PIN          OFF
#define AXIS7_M1_PIN          OFF
#define AXIS7_M2_PIN          OFF
#define AXIS7_M3_PIN          OFF
#define AXIS7_STEP_PIN        AUX4_PIN           // if PPS is not used
#define AXIS7_DIR_PIN         2                  // shared with all other collimator motors

// ST4 interface
#define ST4_RA_W_PIN          17                 // ST4 RA- West
#define ST4_DEC_S_PIN         13                 // ST4 DE- South
#define ST4_DEC_N_PIN         33                 // ST4 DE+ North
#define ST4_RA_E_PIN          16                 // ST4 RA+ East

#else
#error "Wrong processor for this configuration!"

#endif