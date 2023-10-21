################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/6step_conf.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/6step_core.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/6step_init.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/adc.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/dac.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/dma.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/gpio.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/main.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/mc_config.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/motor_control_protocol.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/motorcontrol.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/stm32g4xx_hal_msp.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/stm32g4xx_it.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/stm32g4xx_mc_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/tim.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/ui_task.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/usart.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/user_interface.c 

OBJS += \
./Application/User/6step_conf.o \
./Application/User/6step_core.o \
./Application/User/6step_init.o \
./Application/User/adc.o \
./Application/User/dac.o \
./Application/User/dma.o \
./Application/User/gpio.o \
./Application/User/main.o \
./Application/User/mc_config.o \
./Application/User/motor_control_protocol.o \
./Application/User/motorcontrol.o \
./Application/User/stm32g4xx_hal_msp.o \
./Application/User/stm32g4xx_it.o \
./Application/User/stm32g4xx_mc_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/tim.o \
./Application/User/ui_task.o \
./Application/User/usart.o \
./Application/User/user_interface.o 

C_DEPS += \
./Application/User/6step_conf.d \
./Application/User/6step_core.d \
./Application/User/6step_init.d \
./Application/User/adc.d \
./Application/User/dac.d \
./Application/User/dma.d \
./Application/User/gpio.d \
./Application/User/main.d \
./Application/User/mc_config.d \
./Application/User/motor_control_protocol.d \
./Application/User/motorcontrol.d \
./Application/User/stm32g4xx_hal_msp.d \
./Application/User/stm32g4xx_it.d \
./Application/User/stm32g4xx_mc_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/tim.d \
./Application/User/ui_task.d \
./Application/User/usart.d \
./Application/User/user_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/6step_conf.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/6step_conf.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/6step_conf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/6step_core.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/6step_core.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/6step_core.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/6step_init.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/6step_init.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/6step_init.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/adc.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/adc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/adc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/dac.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/dac.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/dac.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/dma.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/dma.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/gpio.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/gpio.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_config.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/mc_config.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_config.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/motor_control_protocol.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/motor_control_protocol.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/motor_control_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/motorcontrol.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/motorcontrol.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/motorcontrol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32g4xx_hal_msp.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/stm32g4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32g4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32g4xx_it.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/stm32g4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32g4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32g4xx_mc_it.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/stm32g4xx_mc_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32g4xx_mc_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/tim.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/tim.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/ui_task.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/ui_task.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/ui_task.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/usart.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/usart.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/user_interface.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/Src/user_interface.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/user_interface.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/6step_conf.d ./Application/User/6step_conf.o ./Application/User/6step_conf.su ./Application/User/6step_core.d ./Application/User/6step_core.o ./Application/User/6step_core.su ./Application/User/6step_init.d ./Application/User/6step_init.o ./Application/User/6step_init.su ./Application/User/adc.d ./Application/User/adc.o ./Application/User/adc.su ./Application/User/dac.d ./Application/User/dac.o ./Application/User/dac.su ./Application/User/dma.d ./Application/User/dma.o ./Application/User/dma.su ./Application/User/gpio.d ./Application/User/gpio.o ./Application/User/gpio.su ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/mc_config.d ./Application/User/mc_config.o ./Application/User/mc_config.su ./Application/User/motor_control_protocol.d ./Application/User/motor_control_protocol.o ./Application/User/motor_control_protocol.su ./Application/User/motorcontrol.d ./Application/User/motorcontrol.o ./Application/User/motorcontrol.su ./Application/User/stm32g4xx_hal_msp.d ./Application/User/stm32g4xx_hal_msp.o ./Application/User/stm32g4xx_hal_msp.su ./Application/User/stm32g4xx_it.d ./Application/User/stm32g4xx_it.o ./Application/User/stm32g4xx_it.su ./Application/User/stm32g4xx_mc_it.d ./Application/User/stm32g4xx_mc_it.o ./Application/User/stm32g4xx_mc_it.su ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su ./Application/User/tim.d ./Application/User/tim.o ./Application/User/tim.su ./Application/User/ui_task.d ./Application/User/ui_task.o ./Application/User/ui_task.su ./Application/User/usart.d ./Application/User/usart.o ./Application/User/usart.su ./Application/User/user_interface.d ./Application/User/user_interface.o ./Application/User/user_interface.su

.PHONY: clean-Application-2f-User

