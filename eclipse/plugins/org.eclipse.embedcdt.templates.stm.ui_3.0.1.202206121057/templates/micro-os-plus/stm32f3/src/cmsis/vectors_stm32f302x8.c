/*
 * This file was automatically generated from the Arm assembly file.
 * Copyright (c) 2020 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// The list of external handlers is from the Arm assembly startup files.

// ----------------------------------------------------------------------------

#include <cortexm/exception-handlers.h>

// ----------------------------------------------------------------------------

void __attribute__((weak))
Default_Handler(void);

// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions

void __attribute__ ((weak, alias ("Default_Handler")))
WWDG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
PVD_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TAMP_STAMP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FLASH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RCC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI2_TSC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ADC1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_HP_CAN_TX_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_LP_CAN_RX0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN_RX1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN_SCE_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI9_5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_BRK_TIM15_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_UP_TIM16_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_TRG_COM_TIM17_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI15_10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_Alarm_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USBWakeUp_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM6_DAC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
COMP2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
COMP4_6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C3_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C3_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_HP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_LP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USBWakeUp_RMP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FPU_IRQHandler(void);

// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

// ----------------------------------------------------------------------------

// The table of interrupt handlers. It has an explicit section name
// and relies on the linker script to place it at the correct location
// in memory.

__attribute__ ((section(".isr_vector"),used))
pHandler __isr_vectors[] =
  {
    // Cortex-M Core Handlers
    (pHandler) &_estack,               // The initial stack pointer
    Reset_Handler,                     // The reset handler

    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    MemManage_Handler,                 // The MPU fault handler
    BusFault_Handler,                  // The bus fault handler
    UsageFault_Handler,                // The usage fault handler
#else
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
#endif
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    DebugMon_Handler,                  // Debug monitor handler
#else
    0,                                 // Reserved
#endif
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // ----------------------------------------------------------------------
    // External Interrupts
    WWDG_IRQHandler,                   // Window WatchDog
    PVD_IRQHandler,                    // PVD through EXTI Line detection
    TAMP_STAMP_IRQHandler,             // Tamper and TimeStamps through the EXTI line
    RTC_WKUP_IRQHandler,               // RTC Wakeup through the EXTI line
    FLASH_IRQHandler,                  // FLASH
    RCC_IRQHandler,                    // RCC
    EXTI0_IRQHandler,                  // EXTI Line0
    EXTI1_IRQHandler,                  // EXTI Line1
    EXTI2_TSC_IRQHandler,              // EXTI Line2 and Touch Sense controller
    EXTI3_IRQHandler,                  // EXTI Line3
    EXTI4_IRQHandler,                  // EXTI Line4
    DMA1_Channel1_IRQHandler,          // DMA1 Channel 1
    DMA1_Channel2_IRQHandler,          // DMA1 Channel 2
    DMA1_Channel3_IRQHandler,          // DMA1 Channel 3
    DMA1_Channel4_IRQHandler,          // DMA1 Channel 4
    DMA1_Channel5_IRQHandler,          // DMA1 Channel 5
    DMA1_Channel6_IRQHandler,          // DMA1 Channel 6
    DMA1_Channel7_IRQHandler,          // DMA1 Channel 7
    ADC1_IRQHandler,                   // ADC1
    USB_HP_CAN_TX_IRQHandler,          // USB Device High Priority or CAN TX
    USB_LP_CAN_RX0_IRQHandler,         // USB Device Low Priority or CAN RX0
    CAN_RX1_IRQHandler,                // CAN RX1
    CAN_SCE_IRQHandler,                // CAN SCE
    EXTI9_5_IRQHandler,                // External Line[9:5]s
    TIM1_BRK_TIM15_IRQHandler,         // TIM1 Break and TIM15
    TIM1_UP_TIM16_IRQHandler,          // TIM1 Update and TIM16
    TIM1_TRG_COM_TIM17_IRQHandler,     // TIM1 Trigger and Commutation and TIM17
    TIM1_CC_IRQHandler,                // TIM1 Capture Compare
    TIM2_IRQHandler,                   // TIM2
    0,                                 // Reserved
    0,                                 // Reserved
    I2C1_EV_IRQHandler,                // I2C1 Event
    I2C1_ER_IRQHandler,                // I2C1 Error
    I2C2_EV_IRQHandler,                // I2C2 Event
    I2C2_ER_IRQHandler,                // I2C2 Error
    0,                                 // Reserved
    SPI2_IRQHandler,                   // SPI2
    USART1_IRQHandler,                 // USART1
    USART2_IRQHandler,                 // USART2
    USART3_IRQHandler,                 // USART3
    EXTI15_10_IRQHandler,              // External Line[15:10]s
    RTC_Alarm_IRQHandler,              // RTC Alarm (A and B) through EXTI Line
    USBWakeUp_IRQHandler,              // USB Wakeup through EXTI line
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SPI3_IRQHandler,                   // SPI3
    0,                                 // Reserved
    0,                                 // Reserved
    TIM6_DAC_IRQHandler,               // TIM6 and DAC1&2 underrun errors
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    COMP2_IRQHandler,                  // COMP2
    COMP4_6_IRQHandler,                // COMP4 and COMP6
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    I2C3_EV_IRQHandler,                // I2C3 Event
    I2C3_ER_IRQHandler,                // I2C3 Error
    USB_HP_IRQHandler,                 // USB High Priority remap
    USB_LP_IRQHandler,                 // USB Low Priority remap
    USBWakeUp_RMP_IRQHandler,          // USB Wakeup remap through EXTI
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    FPU_IRQHandler,                    // FPU
};

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a
// specific handler is not present in the application code.
// When in DEBUG, trigger a debug exception to clearly notify
// the user of the exception and help identify the cause.

void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
#if defined(DEBUG)
__DEBUG_BKPT();
#endif
while (1)
  {
    ;
  }
}

// ----------------------------------------------------------------------------
