################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Src/frame_communication_protocol.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830/g431rb_bus.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1/ihm16m1.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830/stspin830.c \
C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Src/usart_frame_communication_protocol.c 

OBJS += \
./Middlewares/MotorControl/frame_communication_protocol.o \
./Middlewares/MotorControl/g431rb_bus.o \
./Middlewares/MotorControl/ihm16m1.o \
./Middlewares/MotorControl/stspin830.o \
./Middlewares/MotorControl/usart_frame_communication_protocol.o 

C_DEPS += \
./Middlewares/MotorControl/frame_communication_protocol.d \
./Middlewares/MotorControl/g431rb_bus.d \
./Middlewares/MotorControl/ihm16m1.d \
./Middlewares/MotorControl/stspin830.d \
./Middlewares/MotorControl/usart_frame_communication_protocol.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/MotorControl/frame_communication_protocol.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Src/frame_communication_protocol.c Middlewares/MotorControl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/MotorControl/frame_communication_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/MotorControl/g431rb_bus.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830/g431rb_bus.c Middlewares/MotorControl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/MotorControl/g431rb_bus.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/MotorControl/ihm16m1.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1/ihm16m1.c Middlewares/MotorControl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/MotorControl/ihm16m1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/MotorControl/stspin830.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830/stspin830.c Middlewares/MotorControl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/MotorControl/stspin830.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/MotorControl/usart_frame_communication_protocol.o: C:/Users/Ferhat\ ATASOY/Desktop/MC\ Control/6Steps_P-NUCLEO-IHM003/MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Src/usart_frame_communication_protocol.c Middlewares/MotorControl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib6Step/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/Components/stspin830 -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/BSP/IHM16M1 -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/MotorControl/usart_frame_communication_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-MotorControl

clean-Middlewares-2f-MotorControl:
	-$(RM) ./Middlewares/MotorControl/frame_communication_protocol.d ./Middlewares/MotorControl/frame_communication_protocol.o ./Middlewares/MotorControl/frame_communication_protocol.su ./Middlewares/MotorControl/g431rb_bus.d ./Middlewares/MotorControl/g431rb_bus.o ./Middlewares/MotorControl/g431rb_bus.su ./Middlewares/MotorControl/ihm16m1.d ./Middlewares/MotorControl/ihm16m1.o ./Middlewares/MotorControl/ihm16m1.su ./Middlewares/MotorControl/stspin830.d ./Middlewares/MotorControl/stspin830.o ./Middlewares/MotorControl/stspin830.su ./Middlewares/MotorControl/usart_frame_communication_protocol.d ./Middlewares/MotorControl/usart_frame_communication_protocol.o ./Middlewares/MotorControl/usart_frame_communication_protocol.su

.PHONY: clean-Middlewares-2f-MotorControl

