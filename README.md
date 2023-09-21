# TCS3200-Color-Sensor-base-code

Base code for the TCS3200 Color Sensor written in C. 

I was unable to find any easy to use code for the TCS3200 written in C so I wrote one myself. Its fairly basic and straight forward and as it is meant to be used by me in a bigger project where the sensor only will be activated in special cirumstances and not continuously. I have opted to not use interrupts but it would be possible to implement if that is favrouble.

It contains two separate while-loops. The first one is meant to be used to calibrate your sensor and the second for differantiating between the base colors red, green and blue. See comments in source files for more extensive info.  
