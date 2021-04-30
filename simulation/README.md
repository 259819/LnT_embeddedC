# Seat Heating Application in Action
[Seat Heating Application](https://github.com/259819/LnT_embeddedC#seat-heating-application-in-action)


# Activity-I In Action

|OFF-OFF|OFF-ON|ON-OFF|ON-ON|
|:--:|:--:|:-:|:-:|
|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity1-Images/off-off.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity1-Images/off-on.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity1-Images/on-off.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity1-Images/on-on.PNG)|


# Activity-II In Action	

|OFF-OFF|OFF-ON|ON-OFF|ON-ON|
|:--:|:--:|:-:|:-:|
|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity2-Images/Activity2-OFF-OFF-ADC-1.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity2-Images/Activity2-ON-OFF-ADC-1.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity2-Images/Activity2-ON-ON-ADC-1.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity2-Images/Activity2-ON-ON-ADC-2.PNG)|


# Activity-III In Action	

|20% Duty Cycle|40% Duty Cycle|70% Duty Cycle|95% Duty Cycle|
|:--:|:--:|:-:|:-:|
|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity3-Images/Activity3-PWM-20%25-new.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity3-Images/Activity3-PWM-40%25-new.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity3-Images/Activity3-PWM-70%25-new.PNG)|![](https://github.com/259819/LnT_embeddedC/blob/main/simulation/Activity3-Images/Activity3-PWM-95%25-new.PNG)|


# code

        
         while(1)
        {
        switch_status= Activity1();
        if(switch_status==1)                               //if both switches are on, then only ADC will work
        {                                     
          temp=Activity2();                                // ADC value measured,returned and stored in temp  
           OUTPUT_COMPARE_REGISTER=Activity3(temp);       //PWM pulses will be generated only if adc is working else the pulses will be of default duty cycle
                                                          //passing the ADC reading for the display of temperature using UART 
        } else
        {  
   
        OUTPUT_COMPARE_REGISTER=0x00;    
        }
        if(OUTPUT_COMPARE_REGISTER>=0 && OUTPUT_COMPARE_REGISTER<=52)
        {
               Activity4("20 degree Celcius\n");
        }
        else if(OUTPUT_COMPARE_REGISTER>52 && OUTPUT_COMPARE_REGISTER<=103)
        {
              Activity4("25 degree Celcius\n");                 //passing the temperature for displaying using UART
        }
        else if(OUTPUT_COMPARE_REGISTER>103 && OUTPUT_COMPARE_REGISTER<=180)
        {
               Activity4("29 degree Celcius\n");
        }
        else if(OUTPUT_COMPARE_REGISTER>180 && OUTPUT_COMPARE_REGISTER<=244)
        {
               Activity4("33 degree Celcius\n");
        }
 
    }
