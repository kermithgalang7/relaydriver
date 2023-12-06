#ifndef __LED_STATUS_H__
#define __LED_STATUS_H__

#define LED_ERROR       -1
#define LED_IDLE        0
#define LED_CALIB       1
#define LED_NORMAL      2


void init_led_status(void);
int set_led_status(int status);
int get_led_status(void);
void service_led_status(void);


#endif //__LED_STATUS_H__