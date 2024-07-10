TRIPLE := riscv32-unknown-elf
AS := $(TRIPLE)-gcc
CC := $(TRIPLE)-gcc
CXX := $(TRIPLE)-g++
DUMP := $(TRIPLE)-objdump
SIZE := $(TRIPLE)-size

SRCDIR := src
OUTDIR := out
TARGET := $(OUTDIR)/main
HDRS := $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*.hpp)
SRCS := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*.cpp)

TARGET_MCU := CH32V003

FUNDIR := ch32v003fun

GENERATED_LD_FILE:=$(OUTDIR)/generated_ch32v003.ld
TARGET_MCU_LD:=0
LINKER_SCRIPT+=$(GENERATED_LD_FILE)

.phony: flash clean

SYSTEM_SRCS := \
	$(FUNDIR)/ch32v003fun/ch32v003fun.c

CFLAGS:= \
	-g -Os \
	-nostdlib \
	-Isrc -Wall -Wextra \
	-flto -ffunction-sections -fdata-sections -fmessage-length=0 -msmall-data-limit=8

CFLAGS += \
	-static-libgcc \
	-march=rv32ec -mabi=ilp32e -DCH32V003=1 \
	-I $(FUNDIR)/extralibs \
  -I /usr/include/newlib \
	-I $(FUNDIR)/ch32v003fun

LDFLAGS := \
	-T $(LINKER_SCRIPT) -Wl,--gc-sections \
	-L $(FUNDIR)/misc -lgcc

$(TARGET).bin: $(TARGET).elf
	$(TRIPLE)-size $^
	$(TRIPLE)-objdump -S $^ > $(TARGET).lst
	$(TRIPLE)-objdump -t $^ > $(TARGET).map
	$(TRIPLE)-objcopy -O binary $< $(TARGET).bin
	$(TRIPLE)-objcopy -O ihex $< $(TARGET).hex

$(TARGET).elf: $(SRCS) $(HDRS) $(LINKER_SCRIPT) $(OUTDIR)/system.o
	@mkdir -p $(OUTDIR)
	$(CC) -o $@ $(SRCS) $(OUTDIR)/system.o $(CFLAGS) $(LDFLAGS)

$(OUTDIR)/system.o: $(SYSTEM_SRCS)
	@mkdir -p $(OUTDIR)
	$(CC) -c -o $@ $(SYSTEM_SRCS) $(CFLAGS)

$(GENERATED_LD_FILE) :
	@mkdir -p $(OUTDIR)
	$(PREFIX)-gcc -E -P -x c -DTARGET_MCU=$(TARGET_MCU) -DMCU_PACKAGE=$(MCU_PACKAGE) -DTARGET_MCU_LD=$(TARGET_MCU_LD) $(FUNDIR)/ch32v003fun/ch32v003fun.ld > $(GENERATED_LD_FILE)

flash: $(TARGET).bin
	wlink flash $<

clean:
	rm -rf $(OUTDIR)

