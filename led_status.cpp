#include <Arduino.h>

#include "led_status.h"

int led_counter = 0;
// int led_state = LED_ERROR;
int led_state = LED_NORMAL;


void led_on(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void led_off(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

void init_led_status(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
}

int set_led_status(int status)
{
  return -1;
}

int get_led_status(void)
{
  return -1;
}

void service_led_status(void)
{
  switch(led_state)
  {
    case LED_ERROR:
      if(led_counter == 1)
      {
        led_off();
        // led_counter = 1; //let the counter do the thing
      }
      else
      {
        led_on();
        led_counter = 0; //theres ++ at the bottom
      }
      break;
    case LED_IDLE:
      if(led_counter == 1)
        led_on();
      else
        led_off();
      if(led_counter == 10)
        led_counter = 0;
      break;
    case LED_CALIB:
      if(led_counter <= 10)
        led_on();
      else
        led_off();
      if(led_counter == 20)
        led_counter = 0;
      break;
    case LED_NORMAL:
      if(led_counter == 1)
        led_on();
      else if(led_counter == 3)
        led_on();
      else
        led_off();
      if(led_counter == 20)
        led_counter = 0;
      break;
    default:
      ;
  }
  led_counter++;
}