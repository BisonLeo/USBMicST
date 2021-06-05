#ifndef __FIR_PROCESS_H
#define __FIR_PROCESS_H
#include <stdint.h>
#include <stddef.h>

void fir_init(void);
void fir_process(int16_t* inbuff, int16_t* outbuff, size_t size);
#endif