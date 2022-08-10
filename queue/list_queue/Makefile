all:stack_queue

stack_queue:queue.o main.o double_list.o
	$(CC) $^ -o $@

clean:
	rm stack_queue *.o -rf