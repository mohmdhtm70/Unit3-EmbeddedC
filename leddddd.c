/*
 * leddddd.c
 *
 *  Created on: Feb 8, 2023
 *      Author: ELBOSTAN
 */

typedef volatile unsigned int vuint32_t;

#include<stdint.h>

#define RCC_BASE 0x40021000
#define GPIO_BASE 0x40010800
#define RCC_APB2ENR *( vuint32_t *)(RCC_BASE +0x18)
#define GPIO_CRH   *(vuint32_t *)(GPIO_BASE+0x04)
#define GPIO_ODR  *(vuint32_t *)(GPIO_BASE+0x0C)

int main ()
{
	RCC_APB2ENR |=1<<2;
	 GPIO_CRH &=0xff0fffff;
	 GPIO_CRH |=0x00200000;
	 while (1)
	 {
		 GPIO_ODR |=1<<13;
		 for(int i=0;i<5000;i++);
		 GPIO_ODR &=~(1<<13);
		for(int i=0;i<5000;i++);

	 }
return 0;

}
