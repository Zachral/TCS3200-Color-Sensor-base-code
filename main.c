#include <stdio.h>
#include <avr/io.h> 
#include <util/delay.h>
#include "color_sensor.h"
#include "uart.h"

int main(){
    color_sensor_init();
    init_serial(); 
    int redFrequency = 0, greenFrequency = 0, blueFrequency = 0; 

    while (1){
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
    return 0; 
}