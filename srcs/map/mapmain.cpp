#include "map.hpp"

#include <map>

	bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int	main(void){
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap.insert(ft::make_pair('a', 10));
	mymap.insert(ft::make_pair('b', 20));
	mymap.insert(ft::make_pair('c', 30));
	mymap.insert(ft::make_pair('d', 40));
	mymap.insert(ft::make_pair('e', 50));
	mymap.insert(ft::make_pair('f', 60));

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	// mymap.erase ( it, ++it );    // erasing by range
	// it=mymap.find ('f');
	// mymap.erase(it);
	// mymap.erase ( it, ++it );    // erasing by range
	mymap.erase ( it, mymap.end() );    // erasing by range
	std::cout << "_size = " << mymap.size() << std::endl;
	mymap.print_tree();

	return (0);
}
