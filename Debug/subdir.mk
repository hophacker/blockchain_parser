################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../analyse.o 

CPP_SRCS += \
../analyze.cpp \
../callback.cpp \
../opcodes.cpp \
../option.cpp \
../parser.cpp \
../rmd160.cpp \
../sha256.cpp \
../util.cpp 

OBJS += \
./analyze.o \
./callback.o \
./opcodes.o \
./option.o \
./parser.o \
./rmd160.o \
./sha256.o \
./util.o 

CPP_DEPS += \
./analyze.d \
./callback.d \
./opcodes.d \
./option.d \
./parser.d \
./rmd160.d \
./sha256.d \
./util.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


