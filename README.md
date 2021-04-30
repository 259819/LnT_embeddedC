# Embedded C Programming Example with Continuous Integration and Code Quality

# Activity - Seat Heating Application 

# Introduction:
This Application is designed to control the temperature of the Seat in a Vehicle. The application checks the presence of a person inside the vehicle i.e., is the person seated on the seat or not. Simultaneously it also check if the heater switch is on or off. If both the switches are on, the LED glows. The ADC measures the temperature reading. This temperature reading is further utilized to set the PWM duty cycle which will control the temperature of the seat according to the table shown below.

|ADC value|Output PWM(Duty Cycle)|Temperature|
|:--:|:--:|:--:|
|0-200|20%|20°C|
|210-500|40%|25°C|
|510-700|70%|29°C|
|710-1024|90%|33°C|

The whole Activity is divided into 4 sub-activities as mentioned:


### Activity 1
 Turn on led when the passenger is seated on the seat and the heater is turned on.
### Activity 2
 Measure the temperature using the temperature sensor annd the ADC of the microcontroller.
### Activity 3
 Generate PWM pulses according to the ADC values and displaying it on a CRO.

### Activity 4
 Send temperature data serially from the micro-controller to external Display using UART protocol.
 
 ## CI and Code Quality

|Build|Cppcheck|Codacy|
|:--:|:--:|:--:|
|[![Compile-Linux](https://github.com/259819/LnT_embeddedC/actions/workflows/compile.yml/badge.svg)](https://github.com/259819/LnT_embeddedC/actions/workflows/compile.yml)|[![Cppcheck](https://github.com/259819/LnT_embeddedC/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/259819/LnT_embeddedC/actions/workflows/cppcheck.yml)|[![Codacy Badge](https://app.codacy.com/project/badge/Grade/0cabd0782afe431ea3b3888dcccd6fb2)](https://www.codacy.com/gh/259819/LnT_embeddedC/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=259819/LnT_embeddedC&amp;utm_campaign=Badge_Grade)|


## Seat Heating Application in Action

|20% Duty Cycle,20 degree Celcius|40% Duty Cycle,25 degree Celcius|70% Duty Cycle,29 degree Celcius|95% Duty Cycle,33 degree Celcius|
|:--:|:--:|:--:|:--:|
|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Seat_Heating_App/Seat%20heating%20App-20%20C.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Seat_Heating_App/Seat%20heating%20App-25%20C.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Seat_Heating_App/Seat%20heating%20App-29%20C.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Seat_Heating_App/Seat%20heating%20App-33%20C.PNG)|


## Wiki Documentation
* System   [SETUP](https://github.com/259819/LnT_embeddedC.git)
