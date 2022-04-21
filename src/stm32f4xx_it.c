/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @date    25/09/2014 18:15:12
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2014 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* External variables --------------------------------------------------------*/


extern TIM_HandleTypeDef TimHandle;
extern LTDC_HandleTypeDef hltdc;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */
/******************************************************************************/

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

/**
  * @brief  This function handles TIM interrupt request.
  * @param  None
  * @retval None
  */
void TIM3_IRQHandler(void)
{
}

/**
  * @brief  This function handles LTDC global interrupt request.
  * @param  None
  * @retval None
  */
void LTDC_IRQHandler(void)
{
}

void EXTI9_5_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7); // PA7
}

/**
  * @brief EXTI line detection callbacks
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == GPIO_PIN_7)
  {
    // printf("00 PA7 %u status %x Touch EXTI\r\n", HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7), BSP_TS_ITGetStatus());
    // BSP_Pointer_Update();
    // BSP_TS_ITClear();
  }
}

void I2C3_EV_IRQHandler(void)
{
  printf("I2C3_EV_IRQHandler received\r\n");
}

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}
void DMA2_Stream0_IRQHandler() {while(1);}
void DMA2_Stream3_IRQHandler () { while (1); }
void DMA2D_IRQHandler() { while (1); }
//void Default_Handler() { while (1); }

void DMA1_Stream0_IRQHandler() { while (1); }
void DMA1_Stream1_IRQHandler() { while (1); }
void DMA1_Stream2_IRQHandler() { while (1); }
void DMA1_Stream3_IRQHandler() { while (1); }
void DMA1_Stream4_IRQHandler() { while (1); }
void DMA1_Stream5_IRQHandler() { while (1); }
void DMA1_Stream6_IRQHandler() { while (1); }
void DMA1_Stream7_IRQHandler() { while (1); }
//void DMA2_Stream0_IRQHandler() { while (1); }
void DMA2_Stream1_IRQHandler() { while (1); }
//void DMA2_Stream2_IRQHandler() { while (1); }
//void DMA2_Stream3_IRQHandler() { while (1); }
void DMA2_Stream4_IRQHandler() { while (1); }
void DMA2_Stream5_IRQHandler() { while (1); }
void DMA2_Stream6_IRQHandler() { while (1); }
void DMA2_Stream7_IRQHandler() { while (1); }

void LTDC_ER_IRQHandler() { while (1); }

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  volatile int continue_ = 0;

  /* Go to infinite loop when Hard Fault exception occurs */
  /* set continue = 1 to leave handler and restore stack */
  while (continue_ == 0)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
