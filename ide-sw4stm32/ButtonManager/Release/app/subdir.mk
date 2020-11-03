################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/factory.cpp 

OBJS += \
./app/factory.o 

CPP_DEPS += \
./app/factory.d 


# Each subdirectory must supply rules for building sources it contributes
app/factory.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/factory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16  -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include"  -O2 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


