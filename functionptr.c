#include <stdio.h>
#include <stdlib.h>
typedef struct my_struct {
	int index;
	const char *name;
} my_struct_t;

my_struct_t init_my_struct(int i, const char *n)
{
	my_struct_t s;
	s.index = i;
	s.name = n;
	
	return s;
}

void fill_my_struct(int i, const char *n, my_struct_t *s)
{
	my_struct_t tmp;
	tmp.index = i;
	tmp.name = n;
	
	*s = tmp;
}

int calculate(int x, int y)
{
	int z = x * y;
	return z;
}

void func_ingest(void (*f)(void))
{
	if (f != NULL) {
		// http://stackoverflow.com/questions/9053658/correct-format-specifier-to-print-pointer-address
		// omitting the cast is undefined behavior when printing address of pointer
		printf("%p\n", (void *)f);
		
		f();
	}
	return;
}

int main()
{
	int (*f_ptr)(int, int) = &calculate;
	printf("%p, %p\n", (void *)&calculate, (void *)f_ptr);
	
	// passing previous function pointer to func_ingest function, and calling the function pointer from there
	// casting to (void(*)(void)) allows any args. would this situation be safer with VA_ARGS?
	func_ingest((void(*)(void))f_ptr);
	printf("%d\n", f_ptr(12, 12));
	
	my_struct_t (*f_mystruct)(int, const char *);
	f_mystruct = &init_my_struct;
	f_mystruct(42, "Paul Hindt");
	
	my_struct_t foostruct;
	void (*fp_filler)(int, const char *, my_struct_t *);
	fp_filler = &fill_my_struct;
	fp_filler(99, "filler", &foostruct);
	printf("%d, %s\n", foostruct.index, foostruct.name);
	

	return 0;
	
}