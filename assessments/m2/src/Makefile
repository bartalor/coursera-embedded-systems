#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

CFLAGS = \
	-Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99 \

# Architectures Specific Flags

ifeq ($(PLATFORM),HOST)

	# Compiler Flags and Defines
	CC = gcc
	CPPFLAGS = $(INCLUDES) -DHOST
	SIZE = size

else 
	#(MSP432)

	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	LINKER_FILE = ../msp432p401r.lds

	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld

	CFLAGS += 		
		-mcpu=$(CPU) \
		-mthumb\
		-march=$(ARCH) \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16 \
		--specs=$(SPECS) \
	LDFLAGS = -T $(LINKER_FILE)
	CPPFLAGS = $(INCLUDES) -DMSP432
	SIZE = arm-none-eabi-size


endif

OBJS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

ASMS = $(SOURCES:.c=.s)

PRES = $(SOURCES:.c=.asm)


%.o : %.c
	 $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.asm : %.c
	 $(CC) $(CFLAGS) $(CPPFLAGS) $< -S -o $@

%.i : %.c
	 $(CC) $(CFLAGS) $(CPPFLAGS) $< -E -o $@

%.d : %.c
	 $(CC) $(CFLAGS) $(CPPFLAGS) $< -M -o $@


main.out : main.c $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SOURCES) main.c $(LDFLAGS) -o main.out

.PHONY: all	
all: $(OBJ)

.PHONY: build
build: main.out


# Deletes all compiled files
.PHONY:clean
clean:
	rm -f *.o *.asm *.i *.out *.map










