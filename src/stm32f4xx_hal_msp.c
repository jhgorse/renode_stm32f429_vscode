/**
  ******************************************************************************
  * File Name          : stm32f4xx_hal_msp.c
  * Date               : 25/09/2014 18:15:13
  * Description        : This file provides code for the MSP Initialization 
  *                      and de-Initialization codes.
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

// Don't need to call UARTs because their drivers use MspInit
// TIM1 init is in _qlab_backlight.c BSP file
void HAL_MspInit() {
//  dprint("HAL_MspInit\n\r");
  // GPIOs
  GPIO_InitTypeDef   GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __GPIOE_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();
  __GPIOF_CLK_ENABLE();
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();
  __GPIOG_CLK_ENABLE();
  __GPIOD_CLK_ENABLE();

  /*Configure GPIO pins : PA0 PA1 PA2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC1 PC5 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_1|GPIO_PIN_5|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12*/
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 PB14 */
//  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PD2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* Hold Flash in reset for now */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin : PG9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  //// FMC
    /* Enable GPIOs clock */
  __GPIOB_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();
  __GPIOD_CLK_ENABLE();
  __GPIOE_CLK_ENABLE();
  __GPIOF_CLK_ENABLE();
  __GPIOG_CLK_ENABLE();

/*-- GPIOs Configuration -----------------------------------------------------*/
/*
 +-------------------+--------------------+--------------------+--------------------+
 +                       SDRAM/NOR pins assignment                                  +
 +-------------------+--------------------+--------------------+--------------------+
 | PD0  <-> FMC_D2   |                    | PF0  <-> FMC_A0    | PG0  <-> FMC_A10   |
 | PD1  <-> FMC_D3   |                    | PF1  <-> FMC_A1    | PG1  <-> FMC_A11   |
 | PD8  <-> FMC_D13  | PE7  <-> FMC_D4    | PF2  <-> FMC_A2    |                    |
 | PD9  <-> FMC_D14  | PE8  <-> FMC_D5    | PF3  <-> FMC_A3    |                    |
 | PD10 <-> FMC_D15  | PE9  <-> FMC_D6    | PF4  <-> FMC_A4    | PG2  <-> FMC_A12   |
 | PD14 <-> FMC_D0   | PE10 <-> FMC_D7    | PF5  <-> FMC_A5    | PG3  <-> FMC_A13
 | PD15 <-> FMC_D1   | PE11 <-> FMC_D8    |                    | PG4  <-> FMC_A14
 +-------------------| PE12 <-> FMC_D9    | PF12 <-> FMC_A6    |
 |                   | PE13 <-> FMC_D10   | PF13 <-> FMC_A7    |
 |                   | PE14 <-> FMC_D11   | PF14 <-> FMC_A8    |
                     | PE15 <-> FMC_D12   | PF15 <-> FMC_A9    |
 +-------------------+--------------------+--------------------+--------------------+
*/

  /* Common GPIO configuration */
  GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;


  /* GPIOD configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_0  | GPIO_PIN_1  | GPIO_PIN_3  | GPIO_PIN_4 |
                           GPIO_PIN_5  | GPIO_PIN_6  | GPIO_PIN_7  |
                           GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 | GPIO_PIN_11 |
                           GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* GPIOE configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3 |
                           GPIO_PIN_4  | GPIO_PIN_5  | GPIO_PIN_6 | GPIO_PIN_7 |
                           GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 | GPIO_PIN_11 |
                           GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;

  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* GPIOF configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_0  | GPIO_PIN_1 | GPIO_PIN_2 |
                           GPIO_PIN_3  | GPIO_PIN_4 | GPIO_PIN_5 |
                           GPIO_PIN_12 | GPIO_PIN_13 |
                           GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /* GPIOG configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 |
                           GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_13 |
                           GPIO_PIN_14;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  //// SDRAM
  /* Enable GPIOs clock */
  __GPIOC_CLK_ENABLE();
  __GPIOE_CLK_ENABLE();
  __GPIOF_CLK_ENABLE();
  __GPIOG_CLK_ENABLE();

  /*-- GPIOs Configuration -----------------------------------------------------*/
  /*
  +-------------------+--------------------+--------------------+
  +                       SDRAM pins assignment                 +
  +-------------------+--------------------+--------------------+
  | PE0  <-> FMC_NBL0  |
  | PE1  <-> FMC_NBL1  |
  +-------------------------------------------------------------+
  | PG8  <-> FMC_SDCLK |
  | PG15 <-> FMC_NCAS  |
  +-------------------------------------------------------------+
  | PF11 <-> FMC_NRAS  |
  +-------------------+--------------------+--------------------+
  | PC0 <-> FMC_SDNWE |
  | PC3 <-> SDCKE0    |
  | PC2 <-> FMC_SDNE0 |
  +-------------------+
  */

  /* Common GPIO configuration */
  GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

  /* GPIOC configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* GPIOE configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_0  | GPIO_PIN_1;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* GPIOF configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /* GPIOG configuration */
  GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

}

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - NVIC configuration for UART interrupt request enable
  * @param husart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_LOW; // GPIO_SPEED_FAST

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /*##-2- Configure peripheral GPIO ##########################################*/
  /* USART TX/RX GPIO pin configuration  */
  switch ((uint32_t)(huart->Instance)) {
  case (uint32_t)USART1:
    __GPIOA_CLK_ENABLE();
    __USART1_CLK_ENABLE();
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;   // 9 TX, 10 RX
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    break;
  case (uint32_t)USART3:
    __GPIOC_CLK_ENABLE();
    __USART3_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_11;  // 10 TX, 11 RX
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    break;
  default:
    break;
  }

  /*##-3- Configure the NVIC for USART ########################################*/
  /* NVIC for USART3 */
  // Interrupt-based
  //HAL_NVIC_SetPriority(USARTx_IRQn, 0, 1);
  //HAL_NVIC_EnableIRQ(USARTx_IRQn);
}

/**
  * @brief USART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO and NVIC configuration to their default state
  * @param hUSART: USART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  dprint("HAL_UART_MspDeInit\n\r");
  /*##-1- Reset peripherals ##################################################*/

  /*##-2- Disable peripherals and GPIO Clocks #################################*/
  /* Configure USART Tx as alternate function  */


  switch ((uint32_t)(huart->Instance)) {
  case (uint32_t)USART1:
    __USART1_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9 | GPIO_PIN_10);  // TX 9, RX 10
    break;
  case (uint32_t)USART3:
    __USART3_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10 | GPIO_PIN_11); // 10 TX, 11 RX
    break;
  default:
    break;
  }

  /*##-3- Disable the NVIC for USART ##########################################*/
  //HAL_NVIC_DisableIRQ(USARTx_IRQn);
}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef* hltdc)
{
  dprint("HAL_LTDC_MspInit\n\r");
  GPIO_InitTypeDef GPIO_InitStruct;
  if(hltdc->Instance==LTDC)
  {
    /* Peripheral clock enable */
    __LTDC_CLK_ENABLE();

    /**LTDC GPIO Configuration
    PF10     ------> LTDC_DE
    PA3     ------> LTDC_B5
    PA4     ------> LTDC_VSYNC
    PA6     ------> LTDC_G2
    PB0     ------> LTDC_R3 // AF9
    PB1     ------> LTDC_R6 // AF9
    PB10     ------> LTDC_G4
    PB11     ------> LTDC_G5
    PG6     ------> LTDC_R7
    PG7     ------> LTDC_CLK
    PC6     ------> LTDC_HSYNC
    PC7     ------> LTDC_G6
    PA11     ------> LTDC_R4
    PA12     ------> LTDC_R5
    PD3     ------> LTDC_G7
    PG10     ------> LTDC_G3
    PG11     ------> LTDC_B3
    PG12     ------> LTDC_B4
    PB8     ------> LTDC_B6
    PB9     ------> LTDC_B7
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_11
                          |GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);  // This causes NOR flash to die


    /* Set LTDC Interrupt to the lowest priority */
    HAL_NVIC_SetPriority(LTDC_IRQn, 0xF, 0);

    /* Enable LTDC Interrupt */
    HAL_NVIC_EnableIRQ(LTDC_IRQn);
  }
}

void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* hltdc)
{
  dprint("HAL_LTDC_MspDeInit\n\r");
  if(hltdc->Instance==LTDC)
  {
    /* Peripheral clock disable */
    __LTDC_CLK_DISABLE();

    /**LTDC GPIO Configuration
    PF10     ------> LTDC_DE
    PA3     ------> LTDC_B5
    PA4     ------> LTDC_VSYNC
    PA6     ------> LTDC_G2
    PB0     ------> LTDC_R3
    PB1     ------> LTDC_R6
    PB10     ------> LTDC_G4
    PB11     ------> LTDC_G5
    PG6     ------> LTDC_R7
    PG7     ------> LTDC_CLK
    PC6     ------> LTDC_HSYNC
    PC7     ------> LTDC_G6
    PA11     ------> LTDC_R4
    PA12     ------> LTDC_R5
    PD3     ------> LTDC_G7
    PG10     ------> LTDC_G3
    PG11     ------> LTDC_B3
    PG12     ------> LTDC_B4
    PB8     ------> LTDC_B6
    PB9     ------> LTDC_B7
    */
    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_10);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_11
                          |GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_8|GPIO_PIN_9);

    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6|GPIO_PIN_7);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_3);

    /* Reset peripherals */
    /* Enable LTDC reset state */
    __LTDC_FORCE_RESET();

    /* Release LTDC from reset state */
    __LTDC_RELEASE_RESET();
  }
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* TIMx Peripheral clock enable */
  __TIM3_CLK_ENABLE();

  /*##-2- Configure the NVIC for TIMx #########################################*/
  /* Set the TIMx priority */
  HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

// static int FMC_Initialized = 0;
/*
static void HAL_FMC_MspInit(void)
{
  dprint("HAL_FMC_MspInit()\n\r");
  GPIO_InitTypeDef GPIO_InitStruct;
  if (FMC_Initialized) {
    return;
  }
  FMC_Initialized = 1;
// deprecated. moved up ^^
}
*/
void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram){
  // moved up ^^
}

static int FMC_DeInitialized = 0;

static void HAL_FMC_MspDeInit(void)
{
  dprint("HAL_FMC_MspDeInit()\n\r");
  if (FMC_DeInitialized) {
    return;
  }
  FMC_DeInitialized = 1;
  /* Peripheral clock enable */
  __FMC_CLK_DISABLE();

  /** FMC GPIO Configuration
  PE2   ------> FMC_A23
  PE3   ------> FMC_A19
  PE4   ------> FMC_A20
  PE5   ------> FMC_A21
  PE6   ------> FMC_A22
  PF0   ------> FMC_A0
  PF1   ------> FMC_A1
  PF2   ------> FMC_A2
  PF3   ------> FMC_A3
  PF4   ------> FMC_A4
  PF5   ------> FMC_A5
  PC0   ------> FMC_SDNWE
  PC2   ------> FMC_SDNE0
  PC3   ------> FMC_SDCKE0
  PF11   ------> FMC_SDNRAS
  PF12   ------> FMC_A6
  PF13   ------> FMC_A7
  PF14   ------> FMC_A8
  PF15   ------> FMC_A9
  PG0   ------> FMC_A10
  PG1   ------> FMC_A11
  PE7   ------> FMC_D4
  PE8   ------> FMC_D5
  PE9   ------> FMC_D6
  PE10   ------> FMC_D7
  PE11   ------> FMC_D8
  PE12   ------> FMC_D9
  PE13   ------> FMC_D10
  PE14   ------> FMC_D11
  PE15   ------> FMC_D12
  PD8   ------> FMC_D13
  PD9   ------> FMC_D14
  PD10   ------> FMC_D15
  PD11   ------> FMC_A16
  PD12   ------> FMC_A17
  PD13   ------> FMC_A18
  PD14   ------> FMC_D0
  PD15   ------> FMC_D1
  PG2   ------> FMC_A12
  PG3   ------> FMC_A13
  PG4   ------> FMC_A14
  PG4   ------> FMC_BA0
  PG5   ------> FMC_A15
  PG5   ------> FMC_BA1
  PG8   ------> FMC_SDCLK
  PD0   ------> FMC_D2
  PD1   ------> FMC_D3
  PD4   ------> FMC_NOE
  PD5   ------> FMC_NWE
  PD6   ------> FMC_NWAIT
  PD7   ------> FMC_NE1
  PG13   ------> FMC_A24
  PG14   ------> FMC_A25
  PG15   ------> FMC_SDNCAS
  PB7   ------> FMC_NL
  PE0   ------> FMC_NBL0
  PE1   ------> FMC_NBL1
  */
  HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1);

  HAL_GPIO_DeInit(GPIOF, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOC, GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3);

  HAL_GPIO_DeInit(GPIOG, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15);

  HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7);

  HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

}

void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef* hsdram){
  (void)hsdram;
  dprint("HAL_SDRAM_MspDeInit()\n\r");
  HAL_FMC_MspDeInit();
}


/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
