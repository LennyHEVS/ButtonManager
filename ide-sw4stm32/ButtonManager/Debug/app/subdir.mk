################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/buttoneventsfilelogger.cpp \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/buttoneventsledflasher.cpp \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/buttoneventslogger.cpp \
C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/factory.cpp 

OBJS += \
./app/buttoneventsfilelogger.o \
./app/buttoneventsledflasher.o \
./app/buttoneventslogger.o \
./app/factory.o 

CPP_DEPS += \
./app/buttoneventsfilelogger.d \
./app/buttoneventsledflasher.d \
./app/buttoneventslogger.d \
./app/factory.d 


# Each subdirectory must supply rules for building sources it contributes
app/buttoneventsfilelogger.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/buttoneventsfilelogger.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Middlewares/Third_Party/FatFs/src"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/buttoneventsledflasher.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/buttoneventsledflasher.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Middlewares/Third_Party/FatFs/src"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/buttoneventslogger.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/buttoneventslogger.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Middlewares/Third_Party/FatFs/src"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/factory.o: C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/src/app/factory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw" -I"C:/Users/favre/3emeHES/PTR/ButtonManager/work/ButtonManager/ide-sw4stm32/ButtonManager/Middlewares/Third_Party/FatFs/src"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


