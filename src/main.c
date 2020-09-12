/**
  ******************************************************************************
  * @file    main.c
  * @author  Supreeth
  * @version V1.0
  * @date    16-Aug-2020
  *
  * @brief   Blinky application uing ARM Bit Band Feature.
  *
  * Overview
  * --------
  * This application toggle the User LED(LD2, Green), if there is a key press
  * event from the user otherwise the LED remains in OFF state and this action
  * is implemented using ARM Bit Band Feature.
  *
  * User LED(LD2, Green) is connected to PA5.
  * User Button(B1, Blue in Color) is connected to PC13
  *
  * Runs on stm32f446re
  *
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include "stm32f446xx_bitband.h"

void LED_Init(void);
void Button_Init(void);

int main(void)
{
	HAL_Init();
	LED_Init();
	Button_Init();

	for(;;) {
		/* Button has a negative logic */
		if (!BB_RD_PC(13)) {
			BB_WR_PA(5) ^= (1U << 0U);
			HAL_Delay(100);
		} else {
			BB_WR_PA(5) = 0;
		}
	}
}

/**********************************************************************
 *
 * @brief PortA Initialization for User LED(LD2, Green)
 *
 * User LED(LD2, Green) is connected to PA5.
 *
 * @param None
 *
 * @return None
 *
 *********************************************************************/

void LED_Init(void)
{
	GPIO_InitTypeDef LEDGpio;

	/* Enable Clock to GPIOA Port */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	LEDGpio.Mode = GPIO_MODE_OUTPUT_PP;
	LEDGpio.Pin = GPIO_PIN_5;
	LEDGpio.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(GPIOA, &LEDGpio);
}


/**********************************************************************
 *
 * @brief PortC Initialization for User Button(B1, Blue)
 *
 * User Button(B1, Blue in Color) is connected to PC13.
 *
 * @param  None
 *
 * @return None
 *
 * @note Button has a built-in Pull Up Resistor. On pressing the button,
 * 		 the pin goes from a HIGH to LOW state.
 *
 *********************************************************************/
void Button_Init(void)
{
	GPIO_InitTypeDef btnGPIO;

	/* Enable Clock for GPIOC Port */
	__HAL_RCC_GPIOC_CLK_ENABLE();

	btnGPIO.Mode  = GPIO_MODE_INPUT;
	btnGPIO.Pin   = GPIO_PIN_13;
	btnGPIO.Pull  = GPIO_NOPULL;
	btnGPIO.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(USER_BUTTON_GPIO_PORT, &btnGPIO);
}
