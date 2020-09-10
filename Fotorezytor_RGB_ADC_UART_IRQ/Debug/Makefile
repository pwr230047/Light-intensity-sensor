################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c \
../usart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
usart.o

OBJS_AS_ARGS +=  \
main.o \
usart.o

C_DEPS +=  \
main.d \
usart.d

C_DEPS_AS_ARGS +=  \
main.d \
usart.d

OUTPUT_FILE_PATH +=Fotorezytor_RGB_ADC_UART_IRQ.elf

OUTPUT_FILE_PATH_AS_ARGS +=Fotorezytor_RGB_ADC_UART_IRQ.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000UL  -I"G:\Atmel Studio\7.0\Packs\Atmel\ATmega_DFP\1.4.351\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328pb -B "G:\Atmel Studio\7.0\Packs\Atmel\ATmega_DFP\1.4.351\gcc\dev\atmega328pb" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./usart.o: .././usart.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000UL  -I"G:\Atmel Studio\7.0\Packs\Atmel\ATmega_DFP\1.4.351\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328pb -B "G:\Atmel Studio\7.0\Packs\Atmel\ATmega_DFP\1.4.351\gcc\dev\atmega328pb" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Fotorezytor_RGB_ADC_UART_IRQ.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328pb -B "G:\Atmel Studio\7.0\Packs\Atmel\ATmega_DFP\1.4.351\gcc\dev\atmega328pb"  
	@echo Finished building target: $@
	"G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Fotorezytor_RGB_ADC_UART_IRQ.elf" "Fotorezytor_RGB_ADC_UART_IRQ.hex"
	"G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Fotorezytor_RGB_ADC_UART_IRQ.elf" "Fotorezytor_RGB_ADC_UART_IRQ.eep" || exit 0
	"G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Fotorezytor_RGB_ADC_UART_IRQ.elf" > "Fotorezytor_RGB_ADC_UART_IRQ.lss"
	"G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Fotorezytor_RGB_ADC_UART_IRQ.elf" "Fotorezytor_RGB_ADC_UART_IRQ.srec"
	"G:\Atmel Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Fotorezytor_RGB_ADC_UART_IRQ.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Fotorezytor_RGB_ADC_UART_IRQ.elf" "Fotorezytor_RGB_ADC_UART_IRQ.a" "Fotorezytor_RGB_ADC_UART_IRQ.hex" "Fotorezytor_RGB_ADC_UART_IRQ.lss" "Fotorezytor_RGB_ADC_UART_IRQ.eep" "Fotorezytor_RGB_ADC_UART_IRQ.map" "Fotorezytor_RGB_ADC_UART_IRQ.srec" "Fotorezytor_RGB_ADC_UART_IRQ.usersignatures"
	