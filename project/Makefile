# makefile configuration

COMMON_OBJECTS =
CPU            = ms430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS        = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC             = msp430-elf-gcc
AS             = msp430-elf-as

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} Main.o led.o buzzer.o switches.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *~ *.elf
