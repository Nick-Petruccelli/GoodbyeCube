CC= arm-none-eabi-gcc
CFLAGS= -mcpu=cortex-m4 -mthumb -nostdlib
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/blink.elf
LINKER_FILE= $(SRC)/linker.ld
LDFLAGS= -T $(LINKER_FILE)

all: $(BIN)

$(BIN): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ 

clean:
		$(RM) $(BINDIR)/* $(OBJ)/*

debug: $(OBJS)
		$(CC) $(OBJS) -g -o $(BINDIR)/$@ $(CFLAGS)
