#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__

#include <stdint.h>

typedef enum
{
	RINGBUFFER_EMPTY = 0,
	RINGBUFFER_FULL,
	RINGBUFFER_USEAGE,
	RINGBUFFER_MAX
}ringbuffer_stat_t;

struct ringbuffer
{
	uint8_t* ptr;
	uint16_t write_index : 15;
	uint16_t write_flag : 1;
	uint16_t read_index : 15;
	uint8_t read_flag : 1;
	uint16_t buffer_size;
};
typedef struct ringbuffer ringbuffer_t;

struct ringbuffer* ringbuffer_creat(uint16_t size);
void ringbuffer_delete(struct ringbuffer* rb);
int ringbuffer_set(ringbuffer_t* rb, const uint8_t *buf, uint16_t len);
int ringbuffer_get(ringbuffer_t* rb, uint8_t* buf, uint16_t len);

#endif //__RINGBUFFER_H__