################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mdlmg/mdlmg.c 

OBJS += \
./mdlmg/mdlmg.o 

C_DEPS += \
./mdlmg/mdlmg.d 


# Each subdirectory must supply rules for building sources it contributes
mdlmg/%.o: ../mdlmg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/chengm/myLinux/eclipse_prjs/downloader/mdlmg" -I"/home/chengm/myLinux/eclipse_prjs/downloader/mposition" -I"/home/chengm/myLinux/eclipse_prjs/downloader" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


