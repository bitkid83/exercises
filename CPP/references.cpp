#include <stdio.h>
#include <tchar.h>
#include <iostream>

struct Data
{
	int x, y;
};

//Swap two ints, passing by reference
void swap(int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

//Swap two "Data" structs, passing by reference
void swap(Data &x, Data &y)
{
	Data tmp;
	tmp = x;
	x = y;
	y = tmp;
}

//Swap two "Data" structs, passing by a pointer to "Data"
void pswap(Data *x, Data *y)
{
	Data *tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Swap two integers, passing by reference
	int i = 1;
	int j = 2;

	swap(i, j);
	
	std::cout << "i = " << i << std::endl;
	std::cout << "j = " << j << std::endl;

	//Swap two "Data" structs, passing by reference
	Data a = { 10, 20 };
	Data b = { 30, 40 };
	swap(a, b);

	std::cout << "a.x = " << a.x << std::endl;
	std::cout << "a.y = " << a.y << std::endl;
	std::cout << "b.x = " << b.x << std::endl;
	std::cout << "b.y = " << b.y << std::endl;

	Data *c = &a;
	Data *d = &b;
	pswap(c, d);

	std::cout << "c->x = " << c->x << std::endl;
	std::cout << "c->y = " << c->y << std::endl;
	std::cout << "d->x = " << d->x << std::endl;
	std::cout << "d->y = " << d->y << std::endl;

	return 0;
}

