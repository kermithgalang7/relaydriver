#define LED_ERROR       -1
#define LED_IDLE        0
#define LED_CALIB       1
#define LED_NORMAL      2


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println();
  Serial.println("Relay Driver");

  pinMode(LED_BUILTIN, OUTPUT);
}

int led_counter = 0;
int led_state = LED_ERROR;
void led_service(void)
{
  switch(led_state)
  {
    case LED_ERROR:
      if(led_counter == 1)
      {
        digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

        // led_counter = 1; //let the counter do the thing
      }
      else
      {
        digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
        led_counter = 0; //theres ++ at the bottom
      }
      break;
  }
  led_counter++;
}

int sensorValue; 
void adc_service(void)
{
  int aveSensorValue = 0;
  int samples = 20;

  for(int i = 0; i < samples; i++)
  {
    aveSensorValue += analogRead(A0);
    delay(5);
  }
  aveSensorValue /= samples;
  
  sensorValue = aveSensorValue;
  Serial.print("Sensor Value : ");
  Serial.println(sensorValue);
}

unsigned long led_service_ctr = 0;
unsigned long adc_service_ctr = 0;
void loop() {
  // put your main code here, to run repeatedly:


  if((millis() - adc_service_ctr) > 1000)
  {
    adc_service_ctr = millis();
    adc_service();
  }
  if(millis() < adc_service_ctr)
      adc_service_ctr = 0;

  if((millis() - led_service_ctr) > 100)
  {
    led_service_ctr = millis();
    led_service();
  }
  if(millis() < led_service_ctr)
      led_service_ctr = 0;
}
