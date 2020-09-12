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
  * The following contents are copied from STM32F446xx Reference Manual.
  *
  * A mapping formula shows how to reference each word in the alias region
  * to a corresponding bit in the bit-band region. The mapping formula is:
  *
  * bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)
  *
  * where:
  *
  * --> bit_word_addr is the address of the word in the alias memory region
  *     that maps to the targeted bit.
  *
  * --> bit_band_base is the starting address of the alias region.
  *
  * --> byte_offset is the number of the byte in the bit-band region that
  *     contains the targeted bit.
  *
  * --> bit_number is the bit position (0-7) of the targeted bit.
  *
  * Example
  * --------
  *
  * --> The following example shows how to map bit 2 of the byte located at SRAM address
  *     0x20000300 to the alias region:
  *
  * 0x22006008 = 0x22000000 + (0x300*32) + (2*4)
  *
  * Writing to address 0x22006008 has the same effect as a read-modify-write operation
  * on bit 2 of the byte at SRAM address 0x20000300.
  *
  * Reading address 0x22006008 returns the value (0x01 or 0x00) of bit 2 of the byte
  * at SRAM address 0x20000300 (0x01: bit set; 0x00: bit reset).
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
