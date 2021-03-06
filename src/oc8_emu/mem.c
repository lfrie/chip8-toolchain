#include "oc8_emu/mem.h"

#include "oc8_emu/cpu.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

oc8_emu_mem_t g_oc8_emu_mem;

static const uint8_t FONT_DATA[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0X90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
};

void oc8_emu_init_mem() {
  memset(&g_oc8_emu_mem, 0, sizeof(g_oc8_emu_mem));
  memcpy(g_oc8_emu_mem.ram + OC8_EMU_FONT_HEXA_ADDR, FONT_DATA,
         sizeof(FONT_DATA));
}

void oc8_emu_load_rom(const void *rom_bytes, unsigned rom_size) {
  unsigned max_size = OC8_EMU_RAM_SIZE - OC8_EMU_ROM_ADDR;
  if (rom_size > max_size) {
    fprintf(
        stderr,
        "oc8_emu_load_rom failed: rom size is %u, max size is %u. Aborting !\n",
        rom_size, max_size);
    exit(1);
  }

  memcpy(g_oc8_emu_mem.ram + OC8_EMU_ROM_ADDR, rom_bytes, rom_size);
  g_oc8_emu_cpu.reg_pc = OC8_EMU_ROM_ADDR;
}

void oc8_emu_load_rom_file(const char *path) {
  unsigned max_size = OC8_EMU_RAM_SIZE - OC8_EMU_ROM_ADDR;

  FILE *is = fopen(path, "rb");
  if (is == NULL) {
    fprintf(stderr,
            "oc8_emu_load_rom_file: Cannot open file %s: %s. Aborting !\n",
            path, strerror(errno));
    exit(1);
  }

  fseek(is, 0, SEEK_END);
  unsigned long rom_size = ftell(is);
  if (rom_size > (unsigned long)max_size) {
    fprintf(stderr,
            "oc8_emu_load_rom_file failed: file %s is of size is %lu, max size "
            "is %u. Aborting !\n",
            path, rom_size, max_size);
    exit(1);
  }

  fseek(is, 0, SEEK_SET);
  uint8_t *buf = (uint8_t *)malloc(rom_size);

  if (!rom_size || fread(buf, 1, rom_size, is) != rom_size) {
    fprintf(stderr,
            "oc8_emu_load_rom_file: Cannot read file %s: %s. Aborting !\n",
            path, strerror(errno));
    exit(1);
  }

  oc8_emu_load_rom(buf, (unsigned)rom_size);
  free(buf);
  fclose(is);
}
