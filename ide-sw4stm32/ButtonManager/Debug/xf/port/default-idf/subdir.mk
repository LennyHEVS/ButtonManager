################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/xf/port/default-idf/eventqueue-default.cpp \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/xf/port/default-idf/mutex-default.cpp 

OBJS += \
./xf/port/default-idf/eventqueue-default.o \
./xf/port/default-idf/mutex-default.o 

CPP_DEPS += \
./xf/port/default-idf/eventqueue-default.d \
./xf/port/default-idf/mutex-default.d 


# Each subdirectory must supply rules for building sources it contributes
xf/port/default-idf/eventqueue-default.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/xf/port/default-idf/eventqueue-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Middlewares/Third_Party/FatFs/src"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/port/default-idf/mutex-default.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/xf/port/default-idf/mutex-default.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Middlewares/Third_Party/FatFs/src"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


