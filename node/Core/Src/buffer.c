/*
 * buffer.c
 *
 *  Created on: May 4, 2024
 *      Author: NHAN
 */
#include "buffer.h"
void buffer_init(Buffer* buffer){
	buffer->front =0;
	buffer->rear = 0;
	buffer->size = 0;
}

uint8_t read_buffer(Buffer* buffer, uint8_t* data, uint8_t size){
	// count: bytes read success full
	uint8_t count = 0;
	if (buffer->data == NULL ) return 0;
	if (buffer->size == 0) return 0;

	for (int i = 0; i < size; ++i){
		data[i] = buffer->data[buffer->front];
		buffer->front++;
		buffer->size++;
		count++;
		if (buffer->front > MAX_BUFFER_SIZE){
				buffer->front = 0;
		}
		// buffer is empty cannot read more
		if (buffer->front == buffer->rear) return count;
	}
	return count;

}
uint8_t write_buffer(Buffer* buffer, uint8_t* data, uint8_t size){
	// count: bytes write success full
	uint8_t count = 0;
	if (data == NULL) return 0;
	if(buffer->size == MAX_BUFFER_SIZE) return 0;

	for (int i = 0; i < size; ++i){
		buffer->data[buffer->rear] = data[i];
		buffer->rear++;
		buffer->size--;
		count++;
		if (buffer->rear > MAX_BUFFER_SIZE){
				buffer->rear = 0;
		}
		// buffer is full can not write more
		if ( buffer->rear == buffer->front) return count;
	}
	return count;
}
