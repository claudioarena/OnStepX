/* ---------------------------------------------------------------------------------------------------------------------------------
 * Configuration for OnStepX controller options
 *
 *          For more information on setting OnStep up see http://www.stellarjourney.com/index.php?r=site/equipment_onstep 
 *                      and join the OnStep Groups.io at https://groups.io/g/onstep
 * 
 *           *** Read the compiler warnings and errors, they are there to help guard against invalid configurations ***
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * ADJUST THE FOLLOWING TO CONFIGURE YOUR CONTROLLER FEATURES ----------------------------------------------------------------------
 * <-Req'd = always must set, <-Often = usually must set, Option = optional, Adjust = adjust as req'd, Infreq = infrequently changed
*/
//      Parameter Name              Value   Default  Notes                                                                      Hint

// =================================================================================================================================
// CONTROLLER ======================================================================================================================

// PINMAP ---------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#PINMAP
#define PINMAP                        MaxESP_RCX400 //    OFF, Choose from: MksGenL2, MiniPCB2, MaxPCB2, MaxESP3, CNC3, STM32Blue,     <-Req'd
                                          //         MaxSTM3, FYSETC_S6_2, etc.  Other boards and more info. in ~/src/Constants.h

// SERIAL PORT COMMAND CHANNELS ------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#SERIAL
#define SERIAL_A_BAUD_DEFAULT        9600 //   9600, n. Where n=9600,19200,57600,115200,230400,460800 (common baud rates.)    Infreq
#define SERIAL_B_BAUD_DEFAULT        9600 //   9600, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Option
#define SERIAL_B_ESP_FLASHING         ON //    OFF, ON Upload ESP8266 WiFi firmware through SERIAL_B with :ESPFLASH# cmd.    Option
#define SERIAL_C_BAUD_DEFAULT         OFF //    OFF, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Option
#define SERIAL_D_BAUD_DEFAULT         OFF //    OFF, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Option

// USER FEEDBACK -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#USER_FEEDBACK
#define STATUS_LED                    ON //    OFF, Steady illumination if no error, blinks w/error code otherwise.          Option

// RETICLE CONTROL ------------------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#RETICLE
#define RETICLE_LED_DEFAULT           OFF //    OFF, n. Where n=0..255 (0..100%) activates feature sets default brightness.   Option
#define RETICLE_LED_MEMORY            OFF //    OFF, ON Remember reticle brightness across power cycles.                      Option

// WEATHER SENSOR ------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SENSORS
#define WEATHER                       BME280_0x76 //    OFF, BME280 (I2C 0x77,) BME280_0x76, BME280_SPI (see pinmap for CS.)          Option
                                          //         BMP280 (I2C 0x77,) BMP280_0x76, BMP280_SPI (see pinmap for CS.)
                                          //         BME280 or BMP280 for temperature, pressure.  BME280 for humidity also.

// MOTION ---------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#MOTION
#define STEP_WAVE_FORM                SQUARE // SQUARE, PULSE Step signal wave form faster rates. SQUARE best signal integrity.  Adjust
                                          //         Applies to all axes.

// =================================================================================================================================
// MOUNT ===========================================================================================================================

// Driver models (Step/Dir and Servo) many have specific requirements so be sure to follow the link below to help learn about these.
// Typically: A4988, DRV8825, LV8729, S109, TMC2130, TMC5160, TMC2209S, TMC2209U, TMC2226S, TMC2226U
// Others: SERVO_II and SERVO_PD have settings in Extended.config.h

// AXIS1 RA/AZM -------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration---Rotator-and-Focusers#AXIS1
#define AXIS1_DRIVER_MODEL            GENERIC2_STEPDIR_SERVO //    OFF, Enter motor driver model (above) in both axes to activate the mount.    <-Often

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ 
#define AXIS1_STEPS_PER_DEGREE      194.44444444  //  12800, n. Number of steps per degree:                                          <-Req'd
#define AXIS1_REVERSE                 OFF //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.   <-Often
#define AXIS1_LIMIT_MIN              -180 //   -180, n. Where n= -90..-360 (degrees.) Minimum "Hour Angle" or Azimuth.        Adjust
#define AXIS1_LIMIT_MAX               180 //    180, n. Where n=  90.. 360 (degrees.) Maximum "Hour Angle" or Azimuth.        Adjust

#define AXIS1_DRIVER_MICROSTEPS        256 //    OFF, n. Microstep mode when tracking.                                        <-Req'd
#define AXIS1_DRIVER_MICROSTEPS_GOTO    1 //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, TMC2209U, TMC2226U STEP/DIR driver models:
#define AXIS1_DRIVER_IHOLD            OFF //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS1_DRIVER_IRUN             OFF //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS1_DRIVER_IGOTO            OFF //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS1_DRIVER_STATUS           OFF //    OFF, ON, HIGH, or LOW.  For driver status info/fault detection.               Option

#define AXIS1_DRIVER_DECAY            OFF //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS1_DRIVER_DECAY_GOTO       OFF //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS1_POWER_DOWN              OFF //    OFF, ON Powers off 30sec after movement stops or 10min after last<=1x guide.  Infreq

#define AXIS1_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from front. Option
#define AXIS1_SENSE_LIMIT_MIN LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS1_SENSE_LIMIT_MAX LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
                                          //         Digital, optionally add: |HYST(n) Where n=0..1023 stability time in ms.
                                          //         Analog capable sense inputs also allow adding:
                                          //         |THLD(n) Where n=1..1023 (ADU) for Analog threshold.
                                          //         |HYST(n) Where n=0..1023 (ADU) for +/- Hystersis range.

#define AXIS1_WRAP                    OFF //    OFF, ON Allows unlimited RA/Azm range and ignores min/max/meridian limits.    Option

#define AXIS1_ENABLE_STATE            HIGH                         // default state of ENable pin for motor power on
#define AXIS1_SENSE_HOME_INIT         INPUT_PULLUP                // pin mode for home sensing

// AXIS2 DEC/ALT ------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration---Rotator-and-Focusers#AXIS2
#define AXIS2_DRIVER_MODEL            GENERIC2_STEPDIR_SERVO //    OFF, Enter motor driver model (above) in both axes to activate the mount.    <-Often

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS2_STEPS_PER_DEGREE      194.44444444 //  12800, n. Number of steps per degree:                                          <-Req'd
                                          //         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
#define AXIS2_REVERSE                 ON //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.   <-Often
#define AXIS2_LIMIT_MIN               -90 //    -90, n. Where n=-90..0 (degrees.) Minimum allowed declination.                Infreq
#define AXIS2_LIMIT_MAX                90 //     90, n. Where n=0..90 (degrees.) Maximum allowed declination.                 Infreq

#define AXIS2_DRIVER_MICROSTEPS        256 //    OFF, n. Microstep mode when tracking.                                        <-Often
#define AXIS2_DRIVER_MICROSTEPS_GOTO    1 //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, and TMC2209U STEP/DIR driver models:
#define AXIS2_DRIVER_IHOLD            OFF //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS2_DRIVER_IRUN             OFF //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS2_DRIVER_IGOTO            OFF //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS2_HOME_DEFAULT            30
#define AXIS2_DRIVER_STATUS           OFF //    OFF, ON, HIGH, or LOW.  Polling for driver status info/fault detection.       Option

#define AXIS2_DRIVER_DECAY            OFF //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS2_DRIVER_DECAY_GOTO       OFF //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS2_POWER_DOWN              OFF //    OFF, ON Powers off 30sec after movement stops or 10min after last<=1x guide.  Option

#define AXIS2_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from above. Option
#define AXIS2_SENSE_LIMIT_MIN LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS2_SENSE_LIMIT_MAX LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option

#define AXIS2_TANGENT_ARM             OFF //    OFF, ON +limit range above. Set cntr w/[Reset Home] Return cntr w/[Find Home] Infreq
#define AXIS2_TANGENT_ARM_CORRECTION  OFF //    OFF, ON enables tangent arm geometry correction for Axis2.                    Infreq

#define AXIS2_ENABLE_STATE            HIGH                         // default state of ENable pin for motor power on
#define AXIS2_SENSE_HOME_INIT         INPUT_PULLUP                // pin mode for home sensing

// MOUNT ------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#MOUNT_TYPE
#define MOUNT_TYPE                    ALTAZM //    GEM, GEM for German Equatorial, FORK for Equatorial Fork, or ALTAZM          <-Req'd
                                          //         Dobsonian etc. mounts. GEM Eq mounts perform meridian flips.
#define MOUNT_COORDS          TOPOCENTRIC // ...RIC, Applies refraction to coordinates to/from OnStep, except exactly         Infreq
                                          //              at the poles. Use TOPO_STRICT to apply refraction even in that case.
                                          //              Use OBSERVED_PLACE for no refraction.

// TIME AND LOCATION -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#TLS
#define TIME_LOCATION_SOURCE          DS3231 //    OFF, DS3231 (I2c,) DS3234 (Spi,) TEENSY (T3.2 internal,) or GPS source.       Option
                                          //         Provides Date/Time, and if available, PPS & Lat/Long also.
#define TIME_LOCATION_PPS_SENSE       HIGH //    OFF, HIGH senses PPS (pulse per second,) signal rising edge, or use LOW for   Option
                                          //         falling edge, or use BOTH for rising and falling edges.
                                          //         Better tracking accuracy especially for Mega2560's w/ceramic resonator.

// USER FEEDBACK -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#USER_FEEDBACK
#define STATUS_MOUNT_LED              ON //    OFF, ON Flashes proportional to rate of movement or solid on for slews.       Option
#define STATUS_BUZZER                 ON //    OFF, ON, n. Where n=100..6000 (Hz freq.) for speaker. ON for piezo buzzer.    Option
#define STATUS_BUZZER_DEFAULT         OFF //    OFF, ON default starts w/buzzer enabled.                                      Option
#define STATUS_BUZZER_MEMORY          OFF //    OFF, ON to remember buzzer setting across power cycles.                       Option

// ST4 INTERFACE ------------------------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#ST4
// *** It is up to you to verify the interface meets the electrical specifications of any connected device, use at your own risk ***
#define ST4_INTERFACE                 OFF //    OFF, ON enables interface. <= 1X guides unless hand control mode.             Option
                                          //         During goto btn press: aborts slew or continue meridian flip pause home
#define ST4_HAND_CONTROL               ON //     ON, ON for hand controller special features and SHC support.                 Option
                                          //         Hold [E]+[W] btns >2s: Guide rate   [E]-  [W]+  [N] trk on/off [S] sync
                                          //         Hold [N]+[S] btns >2s: Usr cat item [E]-  [W]+  [N] goto [S] snd on/off
#define ST4_HAND_CONTROL_FOCUSER       ON //     ON, ON alternate to above: Focuser move [E]f1 [W]f2 [N]-     [S]+            Option

// GUIDING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#GUIDING
#define GUIDE_TIME_LIMIT               10 //     10, Ten seconds. Or n. Where n=1..120 second time limit guard.               Adjust
#define GUIDE_DISABLE_BACKLASH        OFF //    OFF, Disable backlash takeup during guiding at <= 1X.                         Option
#define GUIDE_SEPARATE_PULSE_RATE      ON //     ON, Uses a separate rate (stored in NV) for pulse guiding.                   Infreq

// SENSORS -------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SENSORS
#define LIMIT_SENSE                   LOW //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option

// PARK -------------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#PARK
#define PARK_SENSE                    OFF //    OFF, HIGH or LOW state indicates mount is in the park orientation.            Option
#define PARK_SIGNAL                   OFF //    OFF, HIGH or LOW state park input signal triggers parking.                    Option
#define PARK_STATUS                   OFF //    OFF, signals with a HIGH or LOW state when successfully parked.               Option 
#define PARK_STRICT                   OFF //    OFF, ON Un-parking is only allowed if successfully parked.                    Option

// PEC ---------------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#PEC
                                          //         n = (AXIS1_STEPS_PER_DEGREE*360)/reduction_final_stage
#define PEC_STEPS_PER_WORM_ROTATION   200 //      0, n. Steps per worm rotation (0 disables else 720 sec buffer allocated.)  <-Req'd

#define PEC_SENSE                     OFF //    OFF, HIGH. Senses the PEC signal rising edge or use LOW for falling edge.     Option
                                          //         Ignored in ALTAZM mode.
#define PEC_BUFFER_SIZE_LIMIT         720 //    720, Seconds of PEC buffer allowed.                                           Infreq

// TRACKING BEHAVIOUR -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#TRACKING
#define TRACK_BACKLASH_RATE            25 //     25, n. Where n=2..50 (x sidereal rate) during backlash takeup.               Option
                                          //         Too fast motors stall/gears slam or too slow and sluggish in backlash.
#define TRACK_AUTOSTART               OFF //    OFF, ON Start with tracking enabled.                                          Option
#define TRACK_COMPENSATION_DEFAULT    OFF //    OFF, No compensation or REFRACTION, REFRACTION_DUAL, MODEL, MODEL_DUAL.       Option
#define TRACK_COMPENSATION_MEMORY     OFF //    OFF, ON Remembers refraction/pointing model compensated tracking settings.    Option

// SLEWING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SLEWING
#define SLEW_RATE_BASE_DESIRED        1.0 //    1.0, n. Desired slew rate in deg/sec. Adjustable at run-time from            <-Req'd
                                          //         1/2 to 2x this rate, and as performace considerations require.
#define SLEW_RATE_MEMORY              ON //    OFF, ON Remembers rates set across power cycles.                              Option
#define SLEW_ACCELERATION_DIST        5.0 //    5.0, n, (degrees.) Approx. distance for acceleration (and deceleration.)      Adjust
#define SLEW_RAPID_STOP_DIST          2.0 //    2.0, n, (degrees.) Approx. distance required to stop when a slew              Adjust
                                          //         is aborted or a limit is exceeded.
#define SLEW_GOTO                      ON //     ON, Use OFF to disable mount Goto features.                                  Infreq
#define SLEW_GOTO_OFFSET             0.25 //   0.25, Offset in deg's for goto target unidirectional approach, 0.0 disables    Option
#define SLEW_GOTO_OFFSET_ALIGN        OFF //    OFF, ON skips final phase of goto for align stars so user tends to approach   Option
                                          //         from the correct direction when centering.

// PIER SIDE BEHAVIOUR -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SYNCING
#define MFLIP_SKIP_HOME               OFF //    OFF, ON Goto directly to the destination without visiting home position.      Option
#define MFLIP_AUTOMATIC_DEFAULT       OFF //    OFF, ON Start with automatic meridian flips enabled.                          Option
#define MFLIP_AUTOMATIC_MEMORY        OFF //    OFF, ON Remember automatic meridian flip setting across power cycles.         Option
#define MFLIP_PAUSE_HOME_DEFAULT      OFF //    OFF, ON Start with meridian flip pause at home enabed.                        Infreq
#define MFLIP_PAUSE_HOME_MEMORY       OFF //    OFF, ON Remember meridian flip pause at home setting across power cycles.     Infreq

#define PIER_SIDE_SYNC_CHANGE_SIDES   OFF //    OFF, ON Allows sync to change pier side, for GEM mounts.                      Option
#define PIER_SIDE_PREFERRED_DEFAULT  BEST //   BEST, BEST Stays on current side if possible. EAST or WEST switch if possible. Option
#define PIER_SIDE_PREFERRED_MEMORY    OFF //    OFF, ON Remember preferred pier side setting across power cycles.             Option

// ALIGN ---------------------------------------------------------------------------------------------------------------------------
#define ALIGN_AUTO_HOME               OFF //    OFF, ON uses home switches to find home first when starting an align.         Option
#define ALIGN_MAX_STARS              AUTO //   AUTO, Uses HAL specified default (either 6 or 9 stars.)                        Infreq
                                          //         Or use n. Where n=1 (for Sync only) or 3 to 9 (for Goto Assist.)

// =================================================================================================================================
// ROTATOR =========================================================================================================================

// Driver models (Step/Dir and Servo) many have specific requirements so be sure to follow the link below to help learn about these.
// Typically: A4988, DRV8825, LV8729, S109, TMC2130, TMC5160, TMC2209S, TMC2209U, TMC2226S, TMC2226U
// Others: SERVO_II and SERVO_PD have settings in Extended.config.h

// AXIS3 ROTATOR ------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration---Rotator-and-Focusers#AXIS3
#define AXIS3_DRIVER_MODEL            OFF //    OFF, Enter motor driver model (above) to activate the rotator.                Option
#define AXIS3_SLEW_RATE_DESIRED       1.0 //    1.0, n, (degrees/second) Maximum speed depends on processor.                  Adjust

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS3_STEPS_PER_DEGREE       64.0 //   64.0, n. Number of steps per degree for rotator/de-rotator.                    Adjust
                                          //         Alt/Az de-rotation: n = (num_circumference_pixels * 2)/360, minimum
#define AXIS3_REVERSE                 OFF //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.    Option
#define AXIS3_LIMIT_MIN              -180 //   -180, n. Where n=-360..0 (degrees.) Minimum allowed rotator angle.             Infreq
#define AXIS3_LIMIT_MAX               180 //    180, n. Where n=0..360 (degrees.) Maximum allowed rotator angle.              Infreq

#define AXIS3_DRIVER_MICROSTEPS       OFF //    OFF, n. Microstep mode when tracking.                                         Option
#define AXIS3_DRIVER_MICROSTEPS_GOTO  OFF //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, and TMC2209U STEP/DIR driver models:
#define AXIS3_DRIVER_IHOLD            OFF //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS3_DRIVER_IRUN             OFF //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS3_DRIVER_IGOTO            OFF //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS3_DRIVER_STATUS           OFF //    OFF, ON, HIGH, or LOW.  For driver status info/fault detection.               Option

#define AXIS3_DRIVER_DECAY            OFF //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS3_DRIVER_DECAY_GOTO       OFF //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS3_POWER_DOWN              OFF //    OFF, ON Powers off the motor at stand-still.                                  Option

#define AXIS3_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from above. Option
#define AXIS3_SENSE_LIMIT_MIN         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS3_SENSE_LIMIT_MAX         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option

// ROTATOR USER FEEDBACK ------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#USER_FEEDBACK
#define STATUS_ROTATOR_LED            OFF //    OFF, ON Flashes proportional to the rate of movement (2Hz = 1deg/s.)          Option

// =================================================================================================================================
// FOCUSERS ========================================================================================================================

// Driver models (Step/Dir and Servo) many have specific requirements so be sure to follow the link below to help learn about these.
// Typically: A4988, DRV8825, LV8729, S109, TMC2130, TMC5160, TMC2209S, TMC2209U, TMC2226S, TMC2226U
// Others: SERVO_II and SERVO_PD have settings in Extended.config.h

// AXIS4 FOCUSER 1 -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#AXIS4
#define AXIS4_DRIVER_MODEL            GENERIC2_STEPDIR_SERVO //    OFF, Enter motor driver model (above) to activate the focuser.                Option
#define AXIS4_SLEW_RATE_DESIRED       500 //    500, n, Where n=200..5000 (um/s.) Desired (maximum) microns/second.           Adjust

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS4_STEPS_PER_MICRON        0.2 //    0.5, n. Steps per micrometer. Figure this out by testing or other means.      Adjust
#define AXIS4_REVERSE                 OFF //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.    Option
#define AXIS4_LIMIT_MIN                 0 //      0, n. Where n=0..500 (millimeters.) Minimum allowed position.               Adjust
#define AXIS4_LIMIT_MAX                13 //     50, n. Where n=0..500 (millimeters.) Maximum allowed position.               Adjust

#define AXIS4_DRIVER_MICROSTEPS       OFF //    OFF, n. Microstep mode when tracking.                                         Option
#define AXIS4_DRIVER_MICROSTEPS_GOTO  OFF //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, and TMC2209U STEP/DIR driver models:
#define AXIS4_DRIVER_IHOLD            OFF //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS4_DRIVER_IRUN             OFF //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS4_DRIVER_IGOTO            OFF //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /


#define AXIS4_DRIVER_STATUS           OFF //    OFF, ON, HIGH, or LOW.  For driver status info/fault detection.               Option

#define AXIS4_DRIVER_DECAY            OFF //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS4_DRIVER_DECAY_GOTO       OFF //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS4_POWER_DOWN              OFF //    OFF, ON Powers off 30sec after movement stops.                                Option

#define AXIS4_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from above. Option
#define AXIS4_SENSE_LIMIT_MIN         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS4_SENSE_LIMIT_MAX         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option

#define AXIS4_SLEW_RATE_MINIMUM       500 //      2, n. Where n=1..10 (um/s.) Minimum microns/second.                         Adjust

// FOCUSER USER FEEDBACK ------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#USER_FEEDBACK
#define STATUS_FOCUSER_LED            OFF //    OFF, ON Flashes proportional to the rate of movement (2Hz = 500um/s.)         Option

// FOCUSER SENSORS ------------------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#SENSORS
#define FOCUSER_TEMPERATURE           OFF //    OFF, THERMISTOR, DS1820, n. Where n is the DS1820 s/n for focuser temp.       Adjust

// AXIS5 FOCUSER 2 -----------------------------------------------------------------------------------------------------------------
// Up to 6 focusers can be present (AXIS4 to AXIS9) simply copy the above text for focuser 1 and rename to AXIS5_ for focuser 2, etc

// =================================================================================================================================
// AUXILIARY FEATURES ==============================================================================================================

// FEATURES ----------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-ConfigurationMaster#AUXILIARY
// Note: Temporarily set DEBUG mode to VERBOSE and use "FEATURE1_TEMP DS1820" to list the DS18B20 device serial numbers.

#define FEATURE1_PURPOSE              SWITCH //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE1_NAME          "FEATURE1" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE1_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE1_PIN                  512 //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE1_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE1_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE1_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE2_PURPOSE              SWITCH //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE2_NAME          "FAN" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE2_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE2_PIN                  516 //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE2_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE2_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE3_PURPOSE              OFF //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE3_NAME          "FEATURE3" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE3_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE3_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE3_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE3_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE4_PURPOSE              OFF //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE4_NAME          "FEATURE4" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE4_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE4_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE4_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE4_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE5_PURPOSE              OFF //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE5_NAME          "FEATURE5" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE5_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE5_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE5_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE5_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE6_PURPOSE              OFF //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE6_NAME          "FEATURE6" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE6_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE6_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE6_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE6_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE7_PURPOSE              OFF //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE7_NAME          "FEATURE7" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE7_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE7_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE7_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE7_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE8_PURPOSE              OFF //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.                          Option
#define FEATURE8_NAME          "FEATURE8" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE8_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE8_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE8_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE8_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

// ---------------------------------------------------------------------------------------------------------------------------------
#define FileVersionConfig 5
#include "Extended.config.h"
