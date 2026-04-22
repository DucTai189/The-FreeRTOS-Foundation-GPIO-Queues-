################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c 

OBJS += \
./Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o 

C_DEPS += \
./Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/%.o Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/%.su Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/%.cyclo: ../Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/%.c Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DNO_ATOMIC_64_SUPPORT -DMETAL_INTERNAL -DMETAL_MAX_DEVICE_REGIONS=2 -DVIRTIO_SLAVE_ONLY -DUSE_HAL_DRIVER -DSTM32MP157Dxx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../OPENAMP -I../../Middlewares/Third_Party/OpenAMP/open-amp/lib/include -I../../Middlewares/Third_Party/OpenAMP/libmetal/lib/include -I../../Drivers/STM32MP1xx_HAL_Driver/Inc -I../../Drivers/STM32MP1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32MP1xx/Include -I../../Middlewares/Third_Party/OpenAMP/virtual_driver -I../../Drivers/CMSIS/Include -I../Core/ThreadSafe -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/RTOS2/Include -I../../Middlewares/Third_Party/SEGGER/Config -I../../Middlewares/Third_Party/SEGGER/OS -I../../Middlewares/Third_Party/SEGGER/SEGGER -I../../Middlewares/Third_Party/SEGGER/SEGGER/Syscalls -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-SEGGER-2f-SEGGER-2f-Syscalls

clean-Middlewares-2f-Third_Party-2f-SEGGER-2f-SEGGER-2f-Syscalls:
	-$(RM) ./Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.cyclo ./Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d ./Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o ./Middlewares/Third_Party/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-SEGGER-2f-SEGGER-2f-Syscalls

