################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32mp157dacx.s 

OBJS += \
./Core/Startup/startup_stm32mp157dacx.o 

S_DEPS += \
./Core/Startup/startup_stm32mp157dacx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I../Core/Inc -I../../Middlewares/Third_Party/SEGGER/SEGGER/Syscalls -I"D:/ST_Stm32Mp157D-DK1/Practice/Exercise_1_1/CM4/Middlewares/Third_Party/SEGGER/Config" -I"D:/ST_Stm32Mp157D-DK1/Practice/Exercise_1_1/CM4/Middlewares/Third_Party/SEGGER/SEGGER" -I"D:/ST_Stm32Mp157D-DK1/Practice/Exercise_1_1/CM4/Middlewares/Third_Party/SEGGER/OS" -I../OPENAMP -I../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../Drivers/STM32MP1xx_HAL_Driver/Inc -I../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../Middlewares/Third_Party/OpenAMP/virtual_driver -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Drivers/CMSIS/RTOS2/Include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32mp157dacx.d ./Core/Startup/startup_stm32mp157dacx.o

.PHONY: clean-Core-2f-Startup

