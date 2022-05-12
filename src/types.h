#ifndef TYPES_H
#define TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
typedef u32 size_t;
typedef u32 uintptr_t;
typedef float f32;
typedef double f64;

typedef u8 bool;

#ifndef true
#define true (1)
#endif

#ifndef false
#define false (0)
#endif

#ifndef NULL
#define NULL (0)
#endif

#endif // TYPES_H