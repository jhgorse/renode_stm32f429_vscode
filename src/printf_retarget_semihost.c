/*
 * printf_retarget_semihost.c
 *
 *  Created on: May 1, 2015
 *      Author: Joe Gorse jhgorse@gmail.com
 *      Modified BSD License
 */
#include "stm32f4xx_hal.h"
#include "string.h"

UART_HandleTypeDef UART_HandleStructure;

/**
  * @brief  Select and configure UART
  * @param  None
  * @retval None
  */
USART_TypeDef *USART;

void printf_Retarget_Init() {
  USART = USART3;
  UART_HandleStructure.Instance        = USART;
  UART_HandleStructure.Init.BaudRate   = 115200;
  UART_HandleStructure.Init.WordLength = UART_WORDLENGTH_8B;
  UART_HandleStructure.Init.StopBits   = UART_STOPBITS_1;
  UART_HandleStructure.Init.Parity     = UART_PARITY_NONE;
  UART_HandleStructure.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  UART_HandleStructure.Init.Mode       = UART_MODE_TX_RX;

  /* USART configuration */
  HAL_UART_Init(&UART_HandleStructure);
  __HAL_UART_ENABLE(&UART_HandleStructure);
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
int _putchar(int ch)
{
  while (!(USART->SR & USART_SR_TXE)) {}
  USART3->DR = (uint32_t)ch;
  return ch;
}
void _ttywrch(int ch) {
  /* Write one char "ch" to the default console */
  while (!(USART->SR & USART_SR_TXE)) {}
  USART3->DR = (uint32_t)ch;
}

/*
 * @brief  Retargets the C library _write function to our __io_putchar().
 * Write "len" of char from "ptr" to file id "fd"
 * Return number of char written.
 */
int _write(int file,char *ptr,int len)
{
    for(int i=0;i<len;i++)
    {
      _putchar(ptr[i]);
    }
    return len;
}
/*
 * @brief Read "len" of char to "ptr" from file id "fd"
 * @retval number of char read.
 * NOTE: Not working yet.
 */
int _read (int fd, char *ptr, int len)
{
  if (len) {
    for (int i = 0; i < len; i++) {
      while (!(USART->SR & USART_SR_RXNE)) {}
      ptr[i] = (char)(USART->DR);
    }
  }
  return len;
}


/*
 * @brief Print character string to ARM semihosting
 * @retval number of chars
 */
uint32_t shprint(const char *str) {
  (void)str;

  static uint32_t args[3];
  args[0] = 1;
  args[1] = (uint32_t)str;
  args[2] = strlen(str); //sizeof(str1)-1;
/*  asm("mov r0, #5\n"
      "mov r1, %0\n"
      "bkpt 0x00ab"  : : "r"(args) : "r0", "r1"); */
  return args[2];
}
