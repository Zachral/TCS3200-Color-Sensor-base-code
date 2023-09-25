#include <stdio.h>
#include <avr/io.h> 
#include <util/delay.h>
#include "color_sensor.h"
#include "uart.h"

int main(){
    color_sensor_init();
    init_serial(); 
     int redColor = 0,  greenColor = 0, blueColor = 0; 

    //Start with connecting the sensor and get input from red, green and blue colors
    //Note the highest and lowest value of each color
    //when thats done, comment this while-loop out and uncomment the next
    while (1){
        int redFrequency = 0, greenFrequency = 0, blueFrequency = 0;
        set_color_to_detect(RED);
        redFrequency = read_color_sensor(OUT_PIN,255); 
        _delay_ms(100);

        set_color_to_detect(GREEN);
        greenFrequency = read_color_sensor(OUT_PIN,255);
        _delay_ms(100);

        set_color_to_detect(BLUE);
        blueFrequency = read_color_sensor(OUT_PIN,255);
        _delay_ms(100); 

        printf("R = %d, G = %d, B = %d\n", redFrequency, greenFrequency, blueFrequency);
    }

        //Uncomment to differentiate between colors
        //In convert_input_frequency, add your own high and low values for the different colors.
        //The lowest value corresponds to 255 and the highest to 0. 
        // while(1){
        // set_color_to_detect(RED);
        // redFrequency = read_color_sensor(OUT_PIN,255); 
        // redColor = Convert_input_frequency(redFrequency,179, 577 , 255, 0); 
        // _delay_ms(100);

        // set_color_to_detect(GREEN);
        // greenFrequency = read_color_sensor(OUT_PIN,255);
        // greenColor = Convert_input_frequency(greenFrequency, 178, 422, 255, 0);
        // _delay_ms(100);

        // set_color_to_detect(BLUE);
        // blueFrequency = read_color_sensor(OUT_PIN,255);
        // blueColor = Convert_input_frequency(blueFrequency, 229, 956, 255, 0); 
        // _delay_ms(100); 

        // if(redColor > greenColor && redColor > blueColor) printf("RED DETECTED\n");
        // if(greenColor > redColor && greenColor > blueColor) printf("GREEN DETECTED\n");
        // if(blueColor > redColor && blueColor > greenColor) printf("BLUE DETECTED\n");
        // }
    return 0; 
}