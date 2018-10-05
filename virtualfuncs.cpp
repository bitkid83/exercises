#include <iostream>
#include <string>

class Base
{
public:	
  	Base(const std::string &input) { fString = input; }

  	virtual void print() {    	
    	std::cout << fString << std::endl;
  	}

private:
  	std::string fString;
};

class Derived : public Base
{
public:
	Derived(const std::string &input) : Base(input) {}
	void print() {
    	std::cout << "I am virtual!" << std::endl;
	}
};

int main() {  
	Derived *d = new Derived("new Derived");
	d->print();
	Base *b = new Base("new Base");
	b->print();
	Base *db = new Derived("new Derived");
	db->print();

	Base *bp;
	Derived dv("derived variable");
	bp = &dv;
	bp->print();
}