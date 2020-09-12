/**
  ******************************************************************************
  * @file    stm32f446xx_bitband.h
  * @author  Supreeth
  * @version V1.0
  * @date    05-Sep-2020
  *
  * @brief   Macro definitions for ARM bitband feature.
  *
  * Overview
  * --------
  * This file contains macros for using bitband feature for stm32f446re
  * Nucleo Boards.
  *
  * Runs on stm32f446re
  *
  ******************************************************************************
*/

#ifndef __STM32F446XX_BITBAND_H
#define __STM32F446XX_BITBAND_H

#include "stm32f4xx.h"

#define GPIOX_IDR_OFFSET		0x10UL
#define GPIOX_ODR_OFFSET		0x14UL

#define GPIOA_IDR_ADDR			(GPIOA_BASE + GPIOX_IDR_OFFSET)
#define GPIOB_IDR_ADDR			(GPIOB_BASE + GPIOX_IDR_OFFSET)
#define GPIOC_IDR_ADDR			(GPIOC_BASE + GPIOX_IDR_OFFSET)
#define GPIOD_IDR_ADDR			(GPIOD_BASE + GPIOX_IDR_OFFSET)
#define GPIOH_IDR_ADDR			(GPIOH_BASE + GPIOX_IDR_OFFSET)

#define GPIOA_ODR_ADDR			(GPIOA_BASE + GPIOX_ODR_OFFSET)
#define GPIOB_ODR_ADDR			(GPIOB_BASE + GPIOX_ODR_OFFSET)
#define GPIOC_ODR_ADDR			(GPIOC_BASE + GPIOX_ODR_OFFSET)
#define GPIOD_ODR_ADDR			(GPIOD_BASE + GPIOX_ODR_OFFSET)
#define GPIOH_ODR_ADDR			(GPIOH_BASE + GPIOX_ODR_OFFSET)

#define BB_PERIPH(addr, bit)	((PERIPH_BB_BASE + ((addr - PERIPH_BASE) << 5U) + (bit << 2U)))

#define BB_WR_PA(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOA_ODR_ADDR, bit))))
#define BB_WR_PB(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOB_ODR_ADDR, bit))))
#define BB_WR_PC(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOC_ODR_ADDR, bit))))
#define BB_WR_PD(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOD_ODR_ADDR, bit))))
#define BB_WR_PH(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOH_ODR_ADDR, bit))))

#define BB_RD_PA(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOA_IDR_ADDR, bit))))
#define BB_RD_PB(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOB_IDR_ADDR, bit))))
#define BB_RD_PC(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOC_IDR_ADDR, bit))))
#define BB_RD_PD(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOD_IDR_ADDR, bit))))
#define BB_RD_PH(bit) 			(*((volatile uint32_t *) (BB_PERIPH(GPIOH_IDR_ADDR, bit))))

#endif	//__STM32F446XX_BITBAND_H
