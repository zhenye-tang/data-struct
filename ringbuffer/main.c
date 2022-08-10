#include <stdio.h>
#include <stdlib.h>
#include "ringbuffer.h"

int main()
{
	uint8_t buf[100] = { 0 };
	uint8_t recv_buf[100] = { 0 };
	int len;
	struct ringbuffer* rb;

	for (int i = 0; i < 100; i++)
	{
		buf[i] = i;
	}

	rb = ringbuffer_creat(1024);
	len = ringbuffer_set(rb, buf, sizeof(buf));

	if (len == 0)
	{
		fprintf(stderr, "set data error...\n");
	}

	len = ringbuffer_get(rb, recv_buf, 60);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", recv_buf[i]);
	}

	ringbuffer_delete(rb);
	exit(1);
}