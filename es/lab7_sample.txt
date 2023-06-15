//2 digit up counter on 7 segment display
#include <LPC17xx.h>
unsigned char tohex[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int arr[2]={0,0};
unsigned int i,j;

int main(){
	LPC_GPIO0->FIODIR |= 0xFF0;
	LPC_GPIO1->FIODIR |= 0xF<<23;
	while(1){
		for (arr[1]=0;arr[1]<10;arr[1]++)
			for (arr[0]=0;arr[0]<10;arr[0]++){
				for (i=0;i<2;i++){
					LPC_GPIO1->FIOPIN = i<<23;
					LPC_GPIO0->FIOPIN = tohex[arr[i]]<<4;
					for (j=0;j<10000;j++);
				}
				for(j=0;j<10000;j++);
				LPC_GPIO0->FIOCLR |= 0x00000FF0;
			}
	}
}
