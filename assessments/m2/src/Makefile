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
CPPFLAGS = $(INCLUDES)
ifeq ($(PLATFORM),HOST)

	# Compiler Flags and Defines
	CC = gcc
	CPPFLAGS += -DHOST
	SIZE = size

else 
	#(MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld

	CFLAGS += 		
		-mcpu=cortex-m4 \
		-mthumb\
		-march=armv7e-m \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16 \
		--specs=nosys.specs \
	LDFLAGS = -T ../msp432p401r.lds
	CPPFLAGS = -DMSP432
	SIZE = arm-none-eabi-size


endif

OBJS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

ASMS = $(SOURCES:.c=.s)

PRES = $(SOURCES:.c=.asm)

TARGET = main

%.o : %.c
	 $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.asm : %.c
	 $(CC) $(CFLAGS) $(CPPFLAGS) $< -S -o $@

%.i : %.c
	 $(CC) $(CFLAGS) $(CPPFLAGS) $< -E -o $@

%.d : %.c
	 $(CC) $(CFLAGS) $(CPPFLAGS) $< -M -o $@



$(TARGET).out : $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET).out

.PHONY:compile-all
compile-all: $(OBJS)

# Deletes all compiled files
.PHONY:clean
clean:
	rm -f *.o *.asm *.i *.out *.map










