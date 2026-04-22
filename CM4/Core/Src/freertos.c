/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "FreeRTOS.h"
#include "cmsis_os2.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "queue.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticQueue_t osStaticMessageQDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
typedef struct
{
    uint8_t led_state_u8;
    uint8_t Led_selected_u8;

}Led_Control_st;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
Led_Control_st Led_Control_t ={
  .led_state_u8 = 0,
  .Led_selected_u8 = 0,
};
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Tsk_ControlLed */
osThreadId_t Tsk_ControlLedHandle;
uint32_t Tsk_ControlLedBuffer[ 128 ];
osStaticThreadDef_t Tsk_ControlLedControlBlock;
const osThreadAttr_t Tsk_ControlLed_attributes = {
  .name = "Tsk_ControlLed",
  .cb_mem = &Tsk_ControlLedControlBlock,
  .cb_size = sizeof(Tsk_ControlLedControlBlock),
  .stack_mem = &Tsk_ControlLedBuffer[0],
  .stack_size = sizeof(Tsk_ControlLedBuffer),
  .priority = (osPriority_t) osPriorityNormal2,
};
/* Definitions for Tsk_BlikingLed */
osThreadId_t Tsk_BlikingLedHandle;
uint32_t Tsk_BlikingLedBuffer[ 128 ];
osStaticThreadDef_t Tsk_BlikingLedControlBlock;
const osThreadAttr_t Tsk_BlikingLed_attributes = {
  .name = "Tsk_BlikingLed",
  .cb_mem = &Tsk_BlikingLedControlBlock,
  .cb_size = sizeof(Tsk_BlikingLedControlBlock),
  .stack_mem = &Tsk_BlikingLedBuffer[0],
  .stack_size = sizeof(Tsk_BlikingLedBuffer),
  .priority = (osPriority_t) osPriorityNormal1,
};
/* Definitions for Trigger_LED */
osMessageQueueId_t Trigger_LEDHandle;
uint8_t Trigger_LEDBuffer[ 16 * sizeof( uint16_t ) ];
osStaticMessageQDef_t Trigger_LEDControlBlock;
const osMessageQueueAttr_t Trigger_LED_attributes = {
  .name = "Trigger_LED",
  .cb_mem = &Trigger_LEDControlBlock,
  .cb_size = sizeof(Trigger_LEDControlBlock),
  .mq_mem = &Trigger_LEDBuffer,
  .mq_size = sizeof(Trigger_LEDBuffer)
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartTask03(void *argument);
void StartTask02(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of Trigger_LED */
  Trigger_LEDHandle = osMessageQueueNew (16, sizeof(uint16_t), &Trigger_LED_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of Tsk_ControlLed */
  Tsk_ControlLedHandle = osThreadNew(StartTask03, NULL, &Tsk_ControlLed_attributes);

  /* creation of Tsk_BlikingLed */
  Tsk_BlikingLedHandle = osThreadNew(StartTask02, NULL, &Tsk_BlikingLed_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
	static uint32_t idle_counter = 0;
  for(;;)
  {
	  idle_counter ++;
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the Tsk_ControlLed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void *argument)
{
  /* USER CODE BEGIN StartTask03 */
	TickType_t last_wakeup_time = xTaskGetTickCount();
	const TickType_t frequency = pdMS_TO_TICKS(10);
  static Led_Control_st Temp_Led_Control_st ;
  static GPIO_TypeDef* const Port_Led[3] = { LED_1_GPIO_Port, LED_2_GPIO_Port, LED_3_GPIO_Port};
  static const uint16_t Pin_Led[3] = {LED_1_Pin, LED_2_Pin, LED_3_Pin};
  
  for(;;)
  {
    // Receive data select led
    // Receive data toggle led
    if( (xQueueReceive(Trigger_LEDHandle, &Temp_Led_Control_st, 10) == pdPASS) )
    {
  
        HAL_GPIO_WritePin(Port_Led[Temp_Led_Control_st.Led_selected_u8], Pin_Led[Temp_Led_Control_st.Led_selected_u8], (GPIO_PinState)Temp_Led_Control_st.led_state_u8 );
    }
  //  vTaskDelayUntil(&last_wakeup_time,frequency);
    // osDelay(1);
      //osDelay(500);
    }
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the Tsk_BlikingLed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  TickType_t last_wakeup_time = xTaskGetTickCount();
	const TickType_t frequency = pdMS_TO_TICKS(10);
  static uint8_t counter_u8 = 0;
  for(;;)
  {
    if(counter_u8 < 50)
    {
    	counter_u8 ++;
      
    }
    else
    {
    	counter_u8 = 0;
      HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin);
    }
    vTaskDelayUntil(&last_wakeup_time,frequency);
  }
  /* USER CODE END StartTask02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
 

    switch (GPIO_Pin)
    {
      case BUTTON_SEL_LED_Pin:
        Led_Control_t.Led_selected_u8 ++;
        if(Led_Control_t.Led_selected_u8 > 2)
        {
          Led_Control_t.Led_selected_u8 = 0;
        }
        break;
        case BUTTON_TOGGLE_LED_Pin:
          Led_Control_t.led_state_u8 ^= (uint8_t)0x01;
          
        break;
      default:
        break;
    }
xQueueSendFromISR(Trigger_LEDHandle, &Led_Control_t, pdFALSE);

}
/* USER CODE END Application */

