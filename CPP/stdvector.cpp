#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>

//alias to std::cout
std::ostream &p = std::cout;

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1, 2, 3, 4, 5 };
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int)); // todo: is there a better way in STL to get vec size?

	p << '\n' << "Capacity: " << vec.capacity() << '\n';
	p << "sizeof(arr): " << sizeof(arr) << "\n";
	p << "sizeof(int): " << sizeof(int) << "\n";
	p << "sizeof(arr) / sizeof(int)" << sizeof(arr) / sizeof(int) << "\n";

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		p << '|' << *it;
	}

	vec.clear();
	p << '\n' << "Capacity: " << vec.capacity();
	for (int i = 0; i < 100; i++) {		
		vec.push_back(i);
		p << '\n' << vec[i];		
	}
	
	p << '\n' << "Capacity: " << vec.capacity();
	return 0;
}

