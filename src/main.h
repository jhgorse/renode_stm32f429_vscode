/*
 *  main.h
 *
 *  Created on: May 1, 2015
 *      Author: Joe Gorse jhgorse@gmail.com
 *      Modified BSD License
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>

#include "stm32f4xx_hal.h"
#include "printf_retarget_semihost.h"

extern char dMsg[50];

extern void MainTask(void);

#endif /* MAIN_H_ */
