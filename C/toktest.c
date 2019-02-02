#include <stdio.h>
#include <string.h>

int lastpos = 0;

void iterate(const char *instr, int strpos)
{
	for (int i = lastpos; i < strpos; i++) {
			
		switch (instr[i]) {
			
		case '<':			
			printf("\n%c : %d\n", instr[i], i);
			i = i + 1;			
			iterate(instr, lastpos);
			break;
		case '>':
			printf("\n%c : %d\n", instr[i], i);
			//i = i + 2;
			iterate(instr, lastpos);
			break;
		}
		
		printf("%c", instr[i]);
	}
}

int main(int argc, char *argv[])
{
		// <object nam  e  =  \" p  a  u  l  \" >  <  /  o  b  j  e  c  t  >
		// 012345678910 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
		char *str = "<object name=\"paul\" id=\"test\"></object>";
		char token[64];
		int len = (int)strlen(str);
		iterate(str, len);
		
	return 0;
}