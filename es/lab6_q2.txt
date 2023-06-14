#include <LPC17xx.h>
int main(void){
	unsigned int j;
	unsigned long LED;
	
	//configure Port0 PINS P0.4-P0.11 as GPIO function
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	//configure P0.4-P0.11 as output port
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0xFFFFEFFF;	//P2.12 as input port
	
	while(1){
		if (LPC_GPIO2->FIOPIN & 1<<12){	//switch not pressed
			for(LED=255;LED>=0;LED--){	//down counter
				LPC_GPIO0->FIOPIN = LED<<4;
				for(j=0;j<10000;j++);    //a random delay
			} //loop for 255 times
		} else{
			for(LED=0;LED<256;LED++){	 //up counter
				LPC_GPIO0->FIOPIN = LED<<4;
				for(j=0;j<10000;j++);    //a random delay
			} //loop for 255 times	
		}
	}
}
