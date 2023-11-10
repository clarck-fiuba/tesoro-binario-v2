################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BMPTablero.cpp \
../src/Carta.cpp \
../src/Casillero.cpp \
../src/EasyBMP.cpp \
../src/Ficha.cpp \
../src/FuncionalidadCartas.cpp \
../src/Jugador.cpp \
../src/Main.cpp \
../src/Tablero.cpp \
../src/TesoroBinario.cpp 

OBJS += \
./src/BMPTablero.o \
./src/Carta.o \
./src/Casillero.o \
./src/EasyBMP.o \
./src/Ficha.o \
./src/FuncionalidadCartas.o \
./src/Jugador.o \
./src/Main.o \
./src/Tablero.o \
./src/TesoroBinario.o 

CPP_DEPS += \
./src/BMPTablero.d \
./src/Carta.d \
./src/Casillero.d \
./src/EasyBMP.d \
./src/Ficha.d \
./src/FuncionalidadCartas.d \
./src/Jugador.d \
./src/Main.d \
./src/Tablero.d \
./src/TesoroBinario.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


