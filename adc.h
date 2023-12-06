#ifndef __ADC_H__
#define __ADC_H__

#define ADC_SAMPLE_SIZE     10

void init_adc(void);
int get_adc(int gpio);
void service_adc(void);

#endif //__ADC_H__