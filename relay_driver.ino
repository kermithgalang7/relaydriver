#include "led_status.h"
#include "adc.h"
#include "eeprom.h"

unsigned long led_service_ctr = 0;
unsigned long adc_service_ctr = 0;
unsigned long main_service_ctr = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println();
  Serial.println("Relay Driver");

  init_led_status();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(millis() < main_service_ctr)
    main_service_ctr = 0;
  if((millis() - main_service_ctr) > 2500)
  {
    main_service_ctr = millis();
  
    get_adc(0);

 
 
  }  

  if(millis() < adc_service_ctr)
      adc_service_ctr = 0;
  if((millis() - adc_service_ctr) > 100)
  {
    adc_service_ctr = millis();
    service_adc();
  }

  if(millis() < led_service_ctr)
      led_service_ctr = 0;
  if((millis() - led_service_ctr) > 100)
  {
    led_service_ctr = millis();
    service_led_status();
  }
  
} //end loop