#include <stdio.h>
#include <stdint.h>

struct bitfield_s {
	unsigned char b : 3; // 3-bit field
	// 5-bit padding inserted by compiler because char is 8-bit
};

typedef struct bitfield_s bitfield_t;
int main(void) {
	bitfield_t bf;
	bf.b = 5; // 101 binary 3-bit
	bf.b ^= 1 << 3; // 1101 binary = 13 decimal, which overflows 3-bit char bitfield in the struct. compiler truncates it to max value of the bitfield.
	// if we make the bitfield 4 bits then we will print the expected value, 13
	printf("%d\n", bf.b);
	
	uint32_t data[10];
	data[0] = 11;
	data[1] = 12;
	data[2] = 13;
	data[3] = 14;
	data[4] = 15;
	data[5] = 16;
	data[6] = 17;
	data[7] = 18;
	data[8] = 19;
	data[9] = 20;
	uint32_t *pdata = data; 	
	printf("%d\n", *pdata); // dereferencing pdata gives us data[0]
	pdata++; // increment pdata by one uint32, which will give us data[1]
	printf("%d\n", *pdata); // prints 12
	return 0;
}

