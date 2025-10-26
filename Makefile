CC= arm-none-eabi-gcc
CFLAGS= -mcpu=cortex-m4 -mthumb -nostdlib
CPPFLAGS=-DSTM32F410Rx \
	 -Ivendor/CMSIS/Devices/STM32F4/Include \
	 -Ivendor/CMSIS/CMSIS/Core/Include
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/blink.elf
LINKER_FILE= $(SRC)/linker.ld
LDFLAGS= -T $(LINKER_FILE)

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)/system_stm32f4xx.o
		$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(OBJ)/system_stm32f4xx.o: vendor/CMSIS/Devices/STM32F4/Source/Templates/system_stm32f4xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) vendor/CMSIS/Devices/STM32F4/Source/Templates/system_stm32f4xx.c -c -o $@

clean:
		$(RM) $(BINDIR)/* $(OBJ)/*

debug: $(OBJS)
		$(CC) $(OBJS) -g -o $(BINDIR)/$@ $(CFLAGS)
