#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringbuffer.h"

struct ringbuffer* ringbuffer_creat(uint16_t size)
{
	ringbuffer_t* rb;

	rb = (ringbuffer_t*)malloc(sizeof(*rb));
	if (rb == NULL)
	{
		fprintf(stderr,"mallo fail....\n");
		exit(1);
	}

	rb->read_flag = 0;
	rb->read_index = 0;
	rb->write_flag = 0;
	rb->write_index = 0;

	rb->buffer_size = size;
	rb->ptr = (uint8_t *)malloc(size);
	if (rb->ptr == NULL)
	{
		fprintf(stderr, "mallo fail....\n");
		exit(1);
	}
	memset(rb->ptr,0, rb->buffer_size);
	return rb;
}

void ringbuffer_delete(struct ringbuffer* rb)
{
	if (rb != NULL)
	{
		free(rb->ptr);
		free(rb);
	}
	else
	{
		fprintf(stderr, "rb == NULL....\n");
	}
}

static ringbuffer_stat_t ringbuffer_stat_get(ringbuffer_t *rb)
{
	if ((rb->write_index - rb->read_index == 0) && (rb->read_flag - rb->write_flag == 0))
	{
		return RINGBUFFER_EMPTY;
	}
	else if((rb->write_index - rb->read_index == 0) && (rb->read_flag - rb->write_flag != 0))
	{
		return RINGBUFFER_FULL;
	}

	return RINGBUFFER_USEAGE;
}

static uint16_t ringbuffer_space_len(ringbuffer_t* rb)
{
	ringbuffer_stat_t stat = ringbuffer_stat_get(rb);
	uint16_t len = 0;
	switch (stat)
	{
	case RINGBUFFER_FULL:
		len = 0;
		break;
	case RINGBUFFER_EMPTY:
		len = rb->buffer_size;
		break;
	case RINGBUFFER_USEAGE:
		{
			if (rb->write_index < rb->read_index)
			{
				len = rb->read_index - rb->write_index;
			}
			else
			{
				len = rb->buffer_size - (rb->write_index - rb->read_index);
			}
		}
		break;
	default:
		fprintf(stderr,"ringbuffer_space_len error\n");
		break;
	}
	return len;
}

int ringbuffer_set(ringbuffer_t* rb, const uint8_t* buf, uint16_t len)
{
	uint16_t lenght;
	lenght = ringbuffer_space_len(rb);

	if (lenght == 0)
		return 0;

	if (lenght < len)
		len = lenght;
	
	if (rb->buffer_size - rb->write_index > len)
	{
		memcpy(&rb->ptr[rb->write_index], buf,len);
		rb->write_index += len;
		return len;
	}

	memcpy(&rb->ptr[rb->write_index], buf, rb->buffer_size - rb->write_index);
	memcpy(&rb->ptr[0], &buf[rb->buffer_size - rb->write_index], len - (rb->buffer_size - rb->write_index));
	rb->write_index = (len - (rb->buffer_size - rb->write_index));
	rb->write_flag = ~rb->write_flag;

	return len;
}

int ringbuffer_get(ringbuffer_t* rb, uint8_t* buf, uint16_t len)
{
	uint16_t lenght;
	lenght = ringbuffer_space_len(rb);

	if (lenght == 0)
		return 0;

	if (lenght < len)
		len = lenght;

	if (rb->buffer_size - rb->read_index > len)
	{
		memcpy(buf,&rb->ptr[rb->read_index], len);
		rb->read_index += len;
		return len;
	}

	memcpy(buf, &rb->ptr[rb->read_index], rb->buffer_size - rb->read_index);
	memcpy(&buf[rb->buffer_size - rb->read_index], &rb->ptr[0], len - (rb->buffer_size - rb->read_index));
	rb->read_index = (len - (rb->buffer_size - rb->read_index));
	rb->read_flag = ~rb->read_index;

	return len;
}