// gcc bubblesort.c -o bubblesort -std=c99

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bubble sort strings and integers

int main(void)
{
	char *string_list[] = 	{ 	"Cut", "Smooth", "Bowstring", 
								"Swoop", "Side Away", "Cube", 
								"Swing Door", "Long Slide", "Slide Left",
								"Dissolve", "Spiral Fade", "Copy Machine",
								"Pirate Ship"
							};
	unsigned int num_strings = sizeof(string_list) / sizeof(char *);
					
	int nums[] = { 5, 9, 20, 3, 11, 6 };
	int num_nums = sizeof(nums) / sizeof(int);
	int a = 0;

	// bubble sort strings
	for (int x = 0; x < num_strings; x++) {
		for (int y = x + 1; y < num_strings; y++) {
			if (strcmp(string_list[x], string_list[y]) > 0) {
				char *tmp = string_list[x];
				string_list[x] = string_list[y];
				string_list[y] = tmp;
			}
		}
	}
	
	for (int m = 0; m < num_strings; m++) {
		printf("%s\n", string_list[m]);
	}
	/* for (int z = 8; z >= 0; z--) {
		printf("%s\n", string_list[z]);
	} */
		
	printf("%d %d\n", num_strings, num_nums);
	
	for (int i = 0; i < num_nums; i++) {		
		for (int j = i + 1; j < num_nums; j++) {		
			if (nums[i] < nums[j]) {
				a = nums[i];
				nums[i] = nums[j];
				nums[j] = a;
			}			
		}
	}
	
	for (int k = 0; k < num_nums; k++) {
		printf("%d ", nums[k]);
	}
	return 0;
}