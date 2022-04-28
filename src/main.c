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

void MainTask(void);

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
	MainTask();
	while (1);
}

#include "DIALOG.h"

/* 
File        : GRAPH_Usage.c
Purpose     : Sample that demonstrates the usage of GRAPH widgets
              in emWin.
Requirements: WindowManager - (x)
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
---------------------------END-OF-HEADER------------------------------ */
void MainTask(void) {
  GRAPH_DATA_Handle  hData;
  GRAPH_SCALE_Handle hScale;
  WM_HWIN            hGraph;
  int                Angle;
  int                Value;

  //
  // Init GUI
  //
  GUI_Init();
  //
  // Enable multi-buffering to avoid flickering during the continuous update of the graph.
  //
  WM_MULTIBUF_Enable(1);
  //
  // Create graph widget
  //
  hGraph = GRAPH_CreateEx(0, 0, LCD_GetXSize(), LCD_GetYSize(), WM_HBKWIN, WM_CF_SHOW, GRAPH_CF_GRID_FIXED_X, GUI_ID_GRAPH0);
  //
  // Configure grid
  //
  GRAPH_SetGridVis(hGraph, 1);     // Enable grid
  GRAPH_SetGridDistX(hGraph, 10);  // Set X size of grid to 10 pixels
  GRAPH_SetGridDistY(hGraph, 10);  // Set Y size of grid to 10 pixels
  GRAPH_SetGridOffY(hGraph, -5);   // Set offset of grid to match with the graph
  //
  // Set a border to the left of the graph
  //
  GRAPH_SetBorder(hGraph, 30, 0, 0, 0);
  //
  // Create data object
  // A graph widget has one or more data objects attached.
  // These objects are the line displaying the graph data.
  // emWin supports two types of curves:
  //   - GRAPH_DATA_XY for showing a function graph with X/Y coordinates
  //   - GRAPH_DATA_YT for showing curves with 1 Y-value for each X-position
  //     e.g. for displaying continuously updated measurement values
  //
  hData = GRAPH_DATA_YT_Create(GUI_RED, LCD_GetXSize(), NULL, 0);
  //
  // Position the curve
  //
  GRAPH_DATA_YT_SetAlign(hData, GRAPH_ALIGN_LEFT);
  GRAPH_DATA_YT_SetOffY(hData, 75);
  //
  // Attach the data object to the graph
  //
  GRAPH_AttachData(hGraph, hData);
  //
  // Create scale object
  //
  hScale = GRAPH_SCALE_Create(15, GUI_TA_HCENTER | GUI_TA_VCENTER, GRAPH_SCALE_CF_VERTICAL, 1);
  //
  // Configure the scale
  //
  GRAPH_SCALE_SetNumDecs(hScale, 0);    // No decimals are shown on the scale
  GRAPH_SCALE_SetFactor(hScale, 1);     // Factor of the numbers on the scale
  GRAPH_SCALE_SetTickDist(hScale, 20);  // Distance in pixels between each number on the scale
  GRAPH_SCALE_SetOff(hScale, 130);      // Set y-offset of the scale to show negative numbers
  //
  // Attach the scale object to the graph
  //
  GRAPH_AttachScale(hGraph, hScale);
  //
  // Continuously feed the graph with data to create a sine curve
  //
  Angle = 0;
  while (1) {
    GUI_Delay(10);
    Value = GUI__SinHQ(((Angle++) % 360) * 1000);
    Value = (50 * Value) >> 16;
    GRAPH_DATA_YT_AddValue(hData, (I16)Value + 60);
  }
}
