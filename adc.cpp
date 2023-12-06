#include <Arduino.h>

#include "adc.h"

int adc_sample[ADC_SAMPLE_SIZE];
int adc_sample_ctr = 0;

void init_adc(void)
{

}

int get_adc(int gpio)
{
  int sensorValue = 0; 

  for(int i = 0; i < ADC_SAMPLE_SIZE; i++)
    sensorValue += adc_sample[i];

  sensorValue /= ADC_SAMPLE_SIZE;

  Serial.print("Sensor Value : ");
  Serial.println(sensorValue);

  return sensorValue;
}

void service_adc(void)
{
    adc_sample[adc_sample_ctr] = analogRead(A0);
    adc_sample_ctr++;
    if(adc_sample_ctr >= ADC_SAMPLE_SIZE)
      adc_sample_ctr = 0;
}