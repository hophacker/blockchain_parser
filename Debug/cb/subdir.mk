################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cb/allBalances.cpp \
../cb/closure.cpp \
../cb/dumpTX.cpp \
../cb/help.cpp \
../cb/pristine.cpp \
../cb/rewards.cpp \
../cb/simpleStats.cpp \
../cb/sql.cpp \
../cb/taint.cpp \
../cb/transactions.cpp 

OBJS += \
./cb/allBalances.o \
./cb/closure.o \
./cb/dumpTX.o \
./cb/help.o \
./cb/pristine.o \
./cb/rewards.o \
./cb/simpleStats.o \
./cb/sql.o \
./cb/taint.o \
./cb/transactions.o 

CPP_DEPS += \
./cb/allBalances.d \
./cb/closure.d \
./cb/dumpTX.d \
./cb/help.d \
./cb/pristine.d \
./cb/rewards.d \
./cb/simpleStats.d \
./cb/sql.d \
./cb/taint.d \
./cb/transactions.d 


# Each subdirectory must supply rules for building sources it contributes
cb/%.o: ../cb/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


