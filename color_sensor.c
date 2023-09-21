#include <avr/io.h>
#include "color_sensor.h"

static unsigned int duration;

void color_sensor_init(){
    //set as output
    COLOR_SENSOR_PORT_DIRECTION_S0_S1_OUT   |= (1<<S0_PIN);
    COLOR_SENSOR_PORT_DIRECTION_S0_S1_OUT   |= (1<<S1_PIN);
    COLOR_SENSOR_PORT_DIRECTION_S2_S3       |= (1<<S2_PIN);
    COLOR_SENSOR_PORT_DIRECTION_S2_S3       |= (1<<S3_PIN);

    //set as input
    COLOR_SENSOR_PORT_DIRECTION_S0_S1_OUT   &= ~(1<<OUT_PIN);

    //Set scaling to 20% - recomended for arduino
    COLOR_SENSOR_PORT_S0_S1_OUT             |= (1<<S0_PIN);
    COLOR_SENSOR_PORT_S0_S1_OUT             &= ~(1<<S1_PIN);
   
}

void set_color_to_detect(uint8_t color){

  switch (color){
  case RED:
      //Sets the sensor to detect red
      COLOR_SENSOR_PORT_S2_S3                   &= ~(1<<S2_PIN);
      COLOR_SENSOR_PORT_S2_S3                   &= ~(1<<S3_PIN);
      break;
  case GREEN:
      //Sets the sensor to detect green
      COLOR_SENSOR_PORT_S2_S3                   |= (1<<S2_PIN);
      COLOR_SENSOR_PORT_S2_S3                   |= (1<<S3_PIN);
      break;
  case BLUE:
      //Sets the sensor to detect blue
      COLOR_SENSOR_PORT_S2_S3                   &= ~(1<<S2_PIN);
      COLOR_SENSOR_PORT_S2_S3                   |= (1<<S3_PIN);
      break;
  default:
    break;
  }
}

unsigned int read_color_sensor(unsigned int out_pin){
    duration = 0;
    while((COLOR_SENSOR_OUTPUT&out_pin) == out_pin);
    while(((COLOR_SENSOR_OUTPUT&out_pin) != out_pin) && (duration<20000))
    {
      _delay_us(1);
      duration++;
    }
    return duration;
}

long Convert_input_frequency(long frequency, long in_min, long in_max, long out_min, long out_max) {
  return (frequency - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

