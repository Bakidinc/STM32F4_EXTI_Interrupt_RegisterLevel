#include "stm32f4xx.h"

volatile uint8_t x = 0;

void Read_Exti_PC7() {
    // GPIOC Clock Enable
    RCC->AHB1ENR |= (1 << 2);//C Clock
    volatile uint32_t delay = RCC->AHB1ENR; // Bekleme

    // PC7'yi Input olarak ayarla
    GPIOC->MODER &= ~(3UL << 14);//Input
    GPIOC->PUPDR &= ~(3 << 14);
    GPIOC->PUPDR |= (1 << 14); // Pull-up

    // SYSCFG Clock Enable
    RCC->APB2ENR |= (1 << 14);
    delay = RCC->APB2ENR; // Bekleme

    // EXTI7 için PC7 seç
    SYSCFG->EXTICR[1] &= ~(0xF << 12);
    SYSCFG->EXTICR[1] |= (0x2 << 12); // Port C7

    // EXTI7 Falling Edge Trigger
    EXTI->IMR |= (1 << 7);
    EXTI->FTSR |= (1 << 7);
    EXTI->RTSR &= ~(1 << 7);

    // NVIC Ayarları (IRQ23 için - EXTI9_5)
    NVIC->IP[23] = (0x01 << 4);  // Priority 1
    NVIC->ISER[0] |= (1 << 23);  // IRQ23 Enable
}

void EXTI9_5_IRQHandler(void) {
    if (EXTI->PR & (1 << 7)) {
        EXTI->PR = (1 << 7);  // EXTI7 flag'ini temizle
        x++;
    }
}

