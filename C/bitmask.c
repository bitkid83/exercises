// bit masking example

#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

uint32_t make_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	uint32_t color = 0x00000000;
	return color = (((((((color | r) << 8) | g) << 8) | b) << 8) | a);
}

uint8_t get_color_component(uint32_t color, uint8_t component)
{
	uint32_t mask_r = 0xFF000000;
	uint32_t mask_g = 0x00FF0000;
	uint32_t mask_b = 0x0000FF00;
	uint32_t mask_a = 0x000000FF;
	
	uint8_t result = 0;

	switch (component) {
	case 0: // red
		result = (color & mask_r) >> 24;
		// color =  0xABCDEF00;
		// mask_r = 0xFF000000;
		// result = color & mask_r = 0xAB000000;
		// result = result >> 24 = 0x000000AB = 0xAB
		break;
	case 1: // green
		result = (color & mask_g) >> 16;
		break;
	case 2: //blue
		result = (color & mask_b) >> 8;
		break;
	case 3: // alpha
		result = (color & mask_a);
		break;
	}

	return result;
}

int main()
{
	uint32_t color = make_color(0xB1, 0xAC, 0x34, 0xFF);
	uint8_t r = get_color_component(color, 0);
	uint8_t g = get_color_component(color, 1);
	uint8_t b = get_color_component(color, 2);
	uint8_t a = get_color_component(color, 3);
	
	return 0;
}

