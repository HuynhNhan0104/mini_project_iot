/*
 * buffer.h
 *
 *  Created on: May 4, 2024
 *      Author: NHAN
 */

#ifndef INC_BUFFER_H_
#define INC_BUFFER_H_
#include "stdint.h"
#include "stdio.h"
#define MAX_BUFFER_SIZE              300
typedef struct {
	uint8_t data [MAX_BUFFER_SIZE];
	uint8_t front;
	uint8_t rear;
	uint8_t size;
} Buffer;
void buffer_init(Buffer* buffer);
uint8_t read_buffer(Buffer* buffer, uint8_t* data, uint8_t size);
uint8_t write_buffer(Buffer* buffer, uint8_t* data, uint8_t size);
#endif /* INC_BUFFER_H_ */
