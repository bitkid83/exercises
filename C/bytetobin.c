#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const int8_t *byte_to_bin(uint8_t x)
{
	static int8_t b[9];
	b[0] = '\0';
	
	uint8_t z;
	int8_t *p = b;
	for (z = 128; z > 0; z >>= 1) {
		uint8_t result = (x & z);
		printf("(%d & %d) = %d\n", x, z, result);
		*p++ = result ? '1' : '0';
		/* if ((x & z) > 0) {
			*p++ = '1';
		} else {
			*p++ = '0';
		} */
	}
	
	return b;
}


int main()
{	
	uint8_t b = 35;
	const int8_t *bs = byte_to_bin(b);
	printf("%s\n", bs);
	return 0;
}