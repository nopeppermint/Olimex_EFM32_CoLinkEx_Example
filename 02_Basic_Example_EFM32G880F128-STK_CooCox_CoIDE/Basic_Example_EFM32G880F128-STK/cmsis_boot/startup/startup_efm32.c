/**
 ******************************************************************************
 * @file      startup_efm32.c
 * @author    Coocox
 * @version   V1.0
 * @date      1/19/2011
 * @brief     EFM32 Devices Startup code.
 *            This module performs:
 *                - Set the initial SP
 *                - Set the vector table entries with the exceptions ISR address
 *                - Initialize data and bss
 *                - Setup the microcontroller system.
 *                - Call the application's entry point.
 *            After Reset the Cortex-M3 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 *******************************************************************************
 */
 
 
/*----------Stack Configuration-----------------------------------------------*/  
#define STACK_SIZE       0x00000100      /*!< The Stack size suggest using even number    */
__attribute__ ((section(".co_stack")))
unsigned long pulStack[STACK_SIZE];      


/*----------Macro definition--------------------------------------------------*/  
#define WEAK __attribute__ ((weak))           


/*----------Declaration of the default fault handlers-------------------------*/  
/* System exception vector handler */
__attribute__ ((used))
void WEAK  Reset_Handler(void);
void WEAK  NMI_Handler(void);          
void WEAK  HardFault_Handler(void);    
void WEAK  MemManage_Handler(void);    
void WEAK  BusFault_Handler(void);     
void WEAK  UsageFault_Handler(void);   
void WEAK  SVC_Handler(void);
void WEAK  DebugMon_Handler(void);
void WEAK  PendSV_Handler(void);
void WEAK  SysTick_Handler(void);
void WEAK  UDMA_IRQHandler(void);
void WEAK  GPIO_EVEN_IRQHandler(void);
void WEAK  TIMER0_IRQHandler(void);
void WEAK  USART0_RX_IRQHandler(void);
void WEAK  USART0_TX_IRQHandler(void);
void WEAK  ACMP0_IRQHandler(void);
void WEAK  ADC0_IRQHandler(void);
void WEAK  DAC0_IRQHandler(void);
void WEAK  I2C0_IRQHandler(void);
void WEAK  GPIO_ODD_IRQHandler(void);
void WEAK  TIMER1_IRQHandler(void);
void WEAK  TIMER2_IRQHandler(void);
void WEAK  USART1_RX_IRQHandler(void);
void WEAK  USART1_TX_IRQHandler(void);
void WEAK  USART2_RX_IRQHandler(void);
void WEAK  USART2_TX_IRQHandler(void);
void WEAK  UART0_RX_IRQHandler(void);
void WEAK  UART0_TX_IRQHandler(void);
void WEAK  LEUART0_IRQHandler(void);
void WEAK  LEUART1_IRQHandler(void);
void WEAK  LETIMER0_IRQHandler(void);
void WEAK  PCNT0_IRQHandler(void);
void WEAK  PCNT1_IRQHandler(void);
void WEAK  PCNT2_IRQHandler(void);
void WEAK  RTC_IRQHandler(void);
void WEAK  CMU_IRQHandler(void);
void WEAK  VCMP_IRQHandler(void);
void WEAK  LCD_IRQHandler(void);
void WEAK  IMEM_IRQHandler(void);
void WEAK  AES_IRQHandler(void);     


/*----------Symbols defined in linker script----------------------------------*/  
extern unsigned long _sidata;    /*!< Start address for the initialization 
                                      values of the .data section.            */
extern unsigned long _sdata;     /*!< Start address for the .data section     */    
extern unsigned long _edata;     /*!< End address for the .data section       */    
extern unsigned long _sbss;      /*!< Start address for the .bss section      */
extern unsigned long _ebss;      /*!< End address for the .bss section        */      
extern void _eram;               /*!< End address for ram                     */


/*----------Function prototypes-----------------------------------------------*/  
extern int main(void);           /*!< The entry point for the application.    */
extern void SystemInit(void);    /*!< Setup the microcontroller system(CMSIS) */
void Default_Reset_Handler(void);   /*!< Default reset handler                */
static void Default_Handler(void);  /*!< Default exception handler            */


/**
  *@brief The minimal vector table for a Cortex M3.  Note that the proper constructs
  *       must be placed on this to ensure that it ends up at physical address
  *       0x00000000.  
  */
__attribute__ ((used,section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
  /*----------Core Exceptions------------------------------------------------ */
  (void *)&pulStack[STACK_SIZE],     /*!< The initial stack pointer         */
  Reset_Handler,                       /*!< The reset handler                 */
  NMI_Handler,                         /*!< The NMI handler                   */ 
  HardFault_Handler,                   /*!< The hard fault handler            */
  MemManage_Handler,                   /*!< The MPU fault handler             */
  BusFault_Handler,                    /*!< The bus fault handler             */
  UsageFault_Handler,                  /*!< The usage fault handler           */ 
  0,0,0,0,                             /*!< Reserved                          */
  SVC_Handler,                         /*!< SVCall handler                    */
  DebugMon_Handler,                    /*!< Debug monitor handler             */
  0,                                   /*!< Reserved                          */
  PendSV_Handler,                      /*!< The PendSV handler                */
  SysTick_Handler,                     /*!< The SysTick handler               */ 
  
  /*----------External Exceptions---------------------------------------------*/
  UDMA_IRQHandler,                     /*!<  0: UDMA Interrupt                */
  GPIO_EVEN_IRQHandler,                /*!<  1: GPIO_EVEN Interrupt           */
  TIMER0_IRQHandler,                   /*!<  2: TIMER0 Interrupt              */
  USART0_RX_IRQHandler,                /*!<  3: USART0_RX Interrupt           */
  USART0_TX_IRQHandler,                /*!<  4: USART0_TX Interrupt           */
  ACMP0_IRQHandler,                    /*!<  5: ACMP0 Interrupt               */
  ADC0_IRQHandler,                     /*!<  6: ADC0 Interrupt                */
  DAC0_IRQHandler,                     /*!<  7: DAC0 Interrupt                */
  I2C0_IRQHandler,                     /*!<  8: I2C0 Interrupt                */
  GPIO_ODD_IRQHandler,                 /*!<  9: GPIO_ODD Interrupt            */
  TIMER1_IRQHandler,                   /*!< 10: TIMER1 Interrupt              */
  TIMER2_IRQHandler,                   /*!< 11: TIMER2 Interrupt              */
  USART1_RX_IRQHandler,                /*!< 12: USART1_RX Interrupt           */
  USART1_TX_IRQHandler,                /*!< 13: USART1_TX Interrupt           */  
  USART2_RX_IRQHandler,                /*!< 14: USART2_RX Interrupt           */ 
  USART2_TX_IRQHandler,                /*!< 15: USART2_TX Interrupt           */ 
  UART0_RX_IRQHandler,                 /*!< 16: UART0_RX Interrupt            */
  UART0_TX_IRQHandler,                 /*!< 17: UART0_TX Interrupt            */
  LEUART0_IRQHandler,                  /*!< 18: LEUART0 Interrupt             */
  LEUART1_IRQHandler,                  /*!< 19: LEUART1 Interrupt             */
  LETIMER0_IRQHandler,                 /*!< 20: LETIMER0 Interrupt            */
  PCNT0_IRQHandler,                    /*!< 21: PCNT0 Interrupt               */
  PCNT1_IRQHandler,                    /*!< 22: PCNT1 Interrupt               */
  PCNT2_IRQHandler,                    /*!< 23: PCNT2 Interrupt               */ 
  RTC_IRQHandler,                      /*!< 24: RTC Interrupt                 */
  CMU_IRQHandler,                      /*!< 25: CMU Interrupt                 */
  VCMP_IRQHandler,                     /*!< 26: VCMP Interrupt                */
  LCD_IRQHandler,                      /*!< 27: LCD Interrupt                 */ 
  IMEM_IRQHandler,                     /*!< 28: IMEM Interrupt                */  
  AES_IRQHandler,                      /*!< 29: AES Interrupt                 */
};  


/**
  * @brief  This is the code that gets called when the processor first
  *         starts execution following a reset event. Only the absolutely
  *         necessary set is performed, after which the application
  *         supplied main() routine is called. 
  * @param  None
  * @retval None
  */
void Default_Reset_Handler(void)
{
  /* Initialize data and bss */
  unsigned long *pulSrc, *pulDest;

  /* Copy the data segment initializers from flash to SRAM */
  pulSrc = &_sidata;

  for(pulDest = &_sdata; pulDest < &_edata; )
  {
    *(pulDest++) = *(pulSrc++);
  }
  
  /* Zero fill the bss segment.  This is done with inline assembly since this
     will clear the value of pulDest if it is not kept in a register. */
  __asm("  ldr     r0, =_sbss\n"
        "  ldr     r1, =_ebss\n"
        "  mov     r2, #0\n"
        "  .thumb_func\n"
        "zero_loop:\n"
        "    cmp     r0, r1\n"
        "    it      lt\n"
        "    strlt   r2, [r0], #4\n"
        "    blt     zero_loop");
  
  /* Setup the microcontroller system. */
  SystemInit();
  
  /* Call the application's entry point.*/
  main();
}


/**
  *@brief Provide weak aliases for each Exception handler to the Default_Handler. 
  *       As they are weak aliases, any function with the same name will override 
  *       this definition.
  */
  
#pragma weak Reset_Handler = Default_Reset_Handler
#pragma weak NMI_Handler = Default_Handler          
#pragma weak HardFault_Handler = Default_Handler    
#pragma weak MemManage_Handler = Default_Handler    
#pragma weak BusFault_Handler = Default_Handler     
#pragma weak UsageFault_Handler = Default_Handler   
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler
#pragma weak UDMA_IRQHandler = Default_Handler
#pragma weak GPIO_EVEN_IRQHandler = Default_Handler
#pragma weak TIMER0_IRQHandler = Default_Handler
#pragma weak USART0_RX_IRQHandler = Default_Handler
#pragma weak USART0_TX_IRQHandler = Default_Handler
#pragma weak ACMP0_IRQHandler = Default_Handler
#pragma weak ADC0_IRQHandler = Default_Handler
#pragma weak DAC0_IRQHandler = Default_Handler
#pragma weak I2C0_IRQHandler = Default_Handler
#pragma weak GPIO_ODD_IRQHandler = Default_Handler
#pragma weak TIMER1_IRQHandler = Default_Handler
#pragma weak TIMER2_IRQHandler = Default_Handler
#pragma weak USART1_RX_IRQHandler = Default_Handler
#pragma weak USART1_TX_IRQHandler = Default_Handler
#pragma weak USART2_RX_IRQHandler = Default_Handler
#pragma weak USART2_TX_IRQHandler = Default_Handler
#pragma weak UART0_RX_IRQHandler = Default_Handler
#pragma weak UART0_TX_IRQHandler = Default_Handler
#pragma weak LEUART0_IRQHandler = Default_Handler
#pragma weak LEUART1_IRQHandler = Default_Handler
#pragma weak LETIMER0_IRQHandler = Default_Handler
#pragma weak PCNT0_IRQHandler = Default_Handler
#pragma weak PCNT1_IRQHandler = Default_Handler
#pragma weak PCNT2_IRQHandler = Default_Handler
#pragma weak RTC_IRQHandler = Default_Handler
#pragma weak CMU_IRQHandler = Default_Handler
#pragma weak VCMP_IRQHandler = Default_Handler
#pragma weak LCD_IRQHandler = Default_Handler
#pragma weak IMEM_IRQHandler = Default_Handler
#pragma weak AES_IRQHandler = Default_Handler

/**
  * @brief  This is the code that gets called when the processor receives an 
  *         unexpected interrupt.  This simply enters an infinite loop, 
  *         preserving the system state for examination by a debugger.
  * @param  None
  * @retval None  
  */
static void Default_Handler(void) 
{
  /* Go into an infinite loop. */
  while (1) 
  {
  }
}

/*********************** (C) COPYRIGHT 2009 Coocox ************END OF FILE*****/
