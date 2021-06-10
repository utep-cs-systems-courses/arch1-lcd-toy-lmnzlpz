all: gameMain.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

gameMain.elf: ui_utils.o buzzer.o assemblyCode.o gameMain.o assemblyCode.o shape.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer
ui_utils.o: ui_utils.c ui_utils.h
assemblyCode.o: assemblyCode.s assemblyCode.h
shape.o: shape.c shape.h

clean:
	rm -f *.a *.o *.elf

load: gameMain.elf
	msp430loader.sh $^

