#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void log_output(const char* fmt, ...)
{
	va_list args;
	const char* p, * sval;
	int ival;
	double dval;

	va_start(args, fmt);

	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
		case 'd':
			ival = va_arg(args, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(args, double);
			printf("%f", dval);
			break;
		case 's':
				printf("%s", va_arg(args, char *));
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(args);
}

typedef void (*fun_t)(int, int, const char *);

static void caculate_sum(int a, int b, const char *str)
{
	log_output("%d %s", a + b, str);
}

static void do_work(fun_t cb, ...)
{
	va_list args;
	int* arg1, * arg2;
	if (cb != NULL)
	{
		va_start(args, cb);
		arg1 = &va_arg(args, int);
		arg2 = &va_arg(args, int);
		cb(*arg1, *arg2, va_arg(args, char *));
	}
	va_end(args);
}

int main(void)
{
	do_work(caculate_sum, 8, 6,"hello world!");
	return 0;
}