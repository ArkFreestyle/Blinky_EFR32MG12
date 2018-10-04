#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "ustimer.h"
#include "ecode.h"
#include "ustimer_config.h"

#include "hal-config.h"

volatile uint32_t msTicks; // counts 1ms timeTicks
void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}

void delay(uint32_t number)
{
	bool delayON = true;
	int counter = 0;
	while(delayON == true)
	{
		counter = counter + 1;
		if(counter>number)
		{
			delayON = false;
		}
	}
}

int main(void)
{
  /* Chip errata */
  CHIP_Init();
  //Always enable the clock relevant to what you're working with! This is the clock for
  //on-board LEDs
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Infinite loop */
  while (1) {
	  
	  //Delay Program to blink both on-board LEDs
	  GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 1);
	  //Delay(1000);
	  //USTIMER_Delay(1000);
	  delay(1000000);
	  GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 1);
	  delay(1000000);
	  GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0);
	  delay(1000000);
	  GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 0);
	  delay(1000000);
	  
	  

  }
}
