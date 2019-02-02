#include <inttypes.h>
#include <stdio.h>

uint32_t uint32_le_to_be(uint32_t val)
{
	uint32_t tmp = 	((val & 0xFF000000) >> 24) 	| 
					((val & 0x00FF0000) >> 8) 	| 
					((val & 0x0000FF00) << 8) 	| 
					((val & 0x000000FF) << 24);
					
	return tmp;
}

int main()
{
	//uint32_t myInt32 = UINT32_MAX - 1;
	uint32_t myUint32 = 2684419854;
	char intstring[512];
	//sprintf(intstring, "UINT32_MAX %u, 0x%08X", myUint32, myUint32);
	//printf(intstring);
	FILE *txtfile = fopen("intprint.txt", "w+");
	
	char uint_string[] = {};
	for (uint32_t i = UINT32_MAX; i > UINT32_MAX - 65535; i = i - 1024) {

		sprintf(uint_string, "%u : 0x%08X\n", i, i);
		fprintf(txtfile, uint_string);

	}
	fclose(txtfile);
	
	uint32_t val = 3735928559;
	printf("Little Endian : 0x%08X\n", val);
	printf("Big Endian : 0x%08X\n", uint32_le_to_be(val));
	//printf("0x%08X\n", val);
	//uint32_t tmp = ((val & 0xFF000000) >> 24) | ((val & 0x00FF0000) >> 8) | ((val & 0x0000FF00) << 8) | ((val & 0x000000FF) << 24);
	//printf("0x%08X\n", tmp);
	//printf("UINT32_MAX : %u", myInt32);
	return 0;
}