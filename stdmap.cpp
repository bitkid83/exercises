// std::map exercises
// compile with g++ --std=c++11 or --std=c++0x

#include <iostream>
#include <string>
#include <map>


void print_table( std::map<char, int> &m )
{
	for (const auto &kv : m) {
		std::cout << kv.first << "=>" << kv.second << '\n';
	}	
}

int main(int argc, char *argv[])
{
	// std::map<int, std::string> table;
	
	// table[1] = "Paul Hindt";
	// table[2] = "Laura Schug";
	
	// print_table(table);
	
	std::map<char, int> mymap;
	std::map<char, int>::iterator iter;
	
	// first insert function version (single parameter)
	mymap.insert ( std::pair<char, int>( 'a', 100 ) );
	mymap.insert ( std::pair<char, int>( 'z', 2600 ) );
	
	//mymap.erase( 'z' ); 		// erase by key
	//iter = mymap.find( 'a' ); 	
	//mymap.erase( iter );		// erase by iterator
	
	// iterates the map and finds if element char already exists, bool returns result
	std::pair<std::map<char, int>::iterator, bool> ret;
	ret = mymap.insert ( std::pair<char, int>( 'z', 500 ) );
	std::cout << "Value already exists for element 'z': " << ret.first->second << '\n';
	
	iter = mymap.begin();
	mymap.insert( iter, std::pair<char, int>( 'b', 200 ) );
	mymap.insert( iter, std::pair<char, int>( 'c', 300 ) );

	//iter = mymap.find('a');
	//mymap.erase( iter, mymap.end() ); // erase by range, erase all elements from element to std::map::end();
	
	// contents of entire map (pre-C++11 for loop)
	//for ( iter = mymap.begin(); iter != mymap.end(); iter++ ) {
	//	std::cout << iter->first << "=>" << iter->second << '\n';
	//}
	
	// for (const auto &keyval : mymap) {
		// std::cout << keyval.first << "=>" << keyval.second << '\n';
	// }
	
	print_table(mymap);
	
	return 0;
}