#include "hal.h"

int umain()//btn 30 ms need to reduce delay
{
	int delay = 500;

	int leds[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_11, GPIO_PIN_12};
	int sw_num[] ={GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};
	int i=0;
	int n=7;
	int led1=0;
	int led2=0;
	int flag=1;
	while(1){
		
		GPIO_PinState state0 = HAL_GPIO_ReadPin(GPIOE,sw_num[0]);
		GPIO_PinState state1 = HAL_GPIO_ReadPin(GPIOE,sw_num[1]);
		GPIO_PinState state2 = HAL_GPIO_ReadPin(GPIOE,sw_num[2]);
		GPIO_PinState state3 = HAL_GPIO_ReadPin(GPIOE,sw_num[3]);
		
		if (state0==GPIO_PIN_SET && state1==GPIO_PIN_RESET && state2==GPIO_PIN_RESET && state3==GPIO_PIN_RESET){//1000
			GPIO_PinState state=GPIO_PIN_RESET;
						
				//vd6 green
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14, GPIO_PIN_RESET);
				
				for (int k=0; k<8; k++){
					HAL_GPIO_WritePin(GPIOD,leds[k],GPIO_PIN_RESET);
				}
				led1=n-i;
				if(i!=n) {
					led2=n-i-1;
				} else {
					led2=n;
					i=-1;
				}
				HAL_GPIO_WritePin(GPIOD,leds[led1], GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD,leds[led2], GPIO_PIN_SET);
				HAL_Delay(delay);
				
				i=1+i;
			
		} else {
			//vd7 yellow
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13, GPIO_PIN_RESET);
			flag=1;
			for (int k=0; k<4; k++){
				HAL_GPIO_WritePin(GPIOD,leds[k],HAL_GPIO_ReadPin(GPIOE,sw_num[k]));
			}
			for (int k=4; k<8;k++){
				HAL_GPIO_WritePin(GPIOD,leds[k],GPIO_PIN_RESET);
			}
		}
	}
	return 0;

}
