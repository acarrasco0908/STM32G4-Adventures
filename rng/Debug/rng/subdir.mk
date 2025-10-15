################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rng/rng.c 

OBJS += \
./rng/rng.o 

C_DEPS += \
./rng/rng.d 


# Each subdirectory must supply rules for building sources it contributes
rng/%.o rng/%.su rng/%.cyclo: ../rng/%.c rng/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Data/code/STM32G4-Adventures/rng/rng" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-rng

clean-rng:
	-$(RM) ./rng/rng.cyclo ./rng/rng.d ./rng/rng.o ./rng/rng.su

.PHONY: clean-rng

