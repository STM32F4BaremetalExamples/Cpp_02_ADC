#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f4.h"
#include "cadc_stm32f4.h"

void osInitAll(void);

int main(){
	//User application
	osInitAll();
	cadc_init();
	SerialStream* serial  = new SerialUSART2(9600);
	serial->printf("\nHello World\n");
	while(1){
		serial->printf("AN0 = %d\n",cadc_getDataInjected1());
		osDelay(1000);
	}
}

void osInitAll(void){
	osKernelInitialize();
	osKernelStart();
}
