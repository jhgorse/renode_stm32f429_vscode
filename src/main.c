/*
 *  main.c
 *
 *  Created on: May 1, 2015
 *      Author: Joe Gorse jhgorse@gmail.com
 *      Modified BSD License
 */

#define DEBUG 1

#include "main.h"
//#include <gpio.h>
//#include <tim2.h>
//#include "system.h"
//#include "rtc.h"
//#include "Dma2.h"
//#include "flash.h"
//#include "Usart1.h"

#ifdef DEBUG
void assert_failed(uint8_t* file, uint32_t line) {
	printf("Assert failed. %s:%u\n\r",file, (unsigned int)line);
}
#endif

/**
  System Clock Configuration
 */
static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	__PWR_CLK_ENABLE();

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;                     // 1MHz PLLM output
	RCC_OscInitStruct.PLL.PLLN = 336;                   // * 336MHz
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;         // 168MHz SYSCLK
	RCC_OscInitStruct.PLL.PLLQ = 7;                     // 48MHz PLLQ output
	if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		while(1);
	}

	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	// 168 input
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  // AHB & Core at 168MHz
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;   // APB1 at 42MHz
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;   // APB2 at 84MHz
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

}


int main(void)
{
	printf_Retarget_Init(); // Retarget UART for stdio so printf outputs to debug UART3
	printf("\n\r\n\r");
	printf("printf_Retarget_Init() complete \n\r");

	// STM STD Periph init
	HAL_Init();
	// enable the clock to port c
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	// reset io port c
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST;
	GPIOC->ODR |= GPIO_PIN_1; // LED On

	SystemClock_Config();


	printf("Test assert(0) failure: ");
	assert(0);

	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

	__CRC_CLK_ENABLE();

	printf("the end.\n");
	while (1);
}


