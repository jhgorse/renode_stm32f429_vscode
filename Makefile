SOURCE = ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_ll_sdmmc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_tim.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_spi.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_rtc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_sd.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_flash.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_iwdg.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_pcd.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_uart.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_adc_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_nor.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_wwdg.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_i2c.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_ll_fmc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_flash_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_ll_fsmc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_nand.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_i2s_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_ll_usb.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_pccard.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_rcc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_rtc_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_rcc_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_pwr.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_irda.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_cryp_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_cortex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_smartcard.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_dma_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_pwr_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_ltdc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_cryp.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_sai.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_dac_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_dac.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_usart.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_dma.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_dcmi.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_adc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_hash.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_i2c_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_dma2d.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_sram.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_eth.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_hcd.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_rng.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_hash_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_can.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_tim_ex.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_i2s.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_sdram.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_crc.c ./Libraries/STM32F4xx_StdPeriph_Driver/Src/stm32f4xx_hal_gpio.c ./src/printf_retarget_semihost.c ./src/syscalls.c ./src/main.c ./src/system_stm32f4xx.c ./src/stm32f4xx_hal_msp.c ./src/stm32f4xx_it.c ./src/startup_stm32f429x.s
OBJS = $(SOURCE:%.c=%.o)
INCLUDE = -I./src -I./Libraries/STM32F4xx_StdPeriph_Driver/Inc -I./Libraries/CMSIS/Include -I./Libraries/Device/ST/STM32F4xx/Include
OUT	= test1.elf
CC = arm-none-eabi-gcc
CFLAGS  = -O0 -g3 -c -Wall 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += --specs=nosys.specs
CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -DSTM32F429_439xx
CFLAGS += $(INCLUDE)
LDFLAGS = $(filter-out -c, $(CFLAGS)) -T./stm32f4_flash.ld -Xlinker -Map=test1.map 

$(OUT): $(OBJS) ./stm32f4_flash.ld
	$(CC) -g $(OBJS) -o $(OUT) $(LDFLAGS)
	arm-none-eabi-objdump -x test1.elf > test1.list

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

%.o : %.s
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(filter %.o, $(OBJS)) $(OUT)
