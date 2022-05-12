// #include <stdbool.h>
// #include <stdint.h>
// #include <stdio.h>

// #include <stdbool.h>
// #include <stdint.h>
#include "util.h"

#ifndef COMMON_H
#define COMMON_H

typedef u8 byte;
typedef u16 word;
typedef u32 dword;
typedef u64 qword;

// Binary Operations
bool common_bit_set(long long value, byte position);

// Byte Bit Operations
void common_set_bitb(byte *variable, byte position);
void common_unset_bitb(byte *variable, byte position);
void common_toggle_bitb(byte *variable, byte position);
void common_modify_bitb(byte *variable, byte position, bool set);

// Word Bit Operations
void common_set_bitw(word *variable, byte position);
void common_unset_bitw(word *variable, byte position);
void common_toggle_bitw(word *variable, byte position);
void common_modify_bitw(word *variable, byte position, bool set);

// Double Word Bit Operations
void common_set_bitd(dword *variable, byte position);
void common_unset_bitd(dword *variable, byte position);
void common_toggle_bitd(dword *variable, byte position);
void common_modify_bitd(dword *variable, byte position, bool set);

// Quad Word Bit Operations
void common_set_bitq(qword *variable, byte position);
void common_unset_bitq(qword *variable, byte position);
void common_toggle_bitq(qword *variable, byte position);
void common_modify_bitq(qword *variable, byte position, bool set);

#endif
