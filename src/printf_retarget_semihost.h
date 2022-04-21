/*
 * printf_retarget_semihost.h
 *
 *  Created on: May 1, 2015
 *      Author: Joe Gorse jhgorse@gmail.com
 *      Modified BSD License
 */

#ifndef STM_PERIPH_PRINTF_RETARGET_SEMIHOST_H_
#define STM_PERIPH_PRINTF_RETARGET_SEMIHOST_H_

extern UART_HandleTypeDef UART_HandleStructure;

void printf_Retarget_Init(void);
int shprint(const char *str);

#endif /* STM_PERIPH_PRINTF_RETARGET_SEMIHOST_H_ */
