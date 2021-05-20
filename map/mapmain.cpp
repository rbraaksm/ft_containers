#include "map.hpp"

#include <map>

	bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int	main(void){
	ft::map<int,int> first;
	// ft::map<char,int> first;

	first[100]=10;
	first[50]=30;
	first[140]=30;
	// first[20]=30;
	// first[170]=30;
	// first[80]=50;
	first[70]=30;
	// first[150]=20;
	// first[90]=70;
	first[110]=70;
	// first[130]=70;
	// first[160]=70;
	// // first[30]=70;
	// first[120]=70;
	// first[200]=70;
	// first[180]=70;
	// first[30]=70;
	// first[125]=70;
	// first[135]=70;
	// first[132]=70;
	// first[150]=70;
	// first[136]=70;


	// first.erase(170);
	// first.print_tree();

	/*Top erase */
	// first.print_tree();
	// first.erase(100);
	// first.erase(70);
	// first.erase(110);
	// first.erase(50);
	// first.erase(140);
	// first.print_tree();
	// first.erase(18);
	// first.erase(17);
	// first.erase(16);
	// first.erase(15);
	// first.erase(14);
	// first.erase(13);
	// first.print_tree();


	/*Bottom erase */
	// first.erase(2);
	// first.erase(3);
	// first.erase(5);
	// first.erase(70);
	// first.erase(30);
	// first.erase(20);
	// first.erase(136);
	// first.print_tree();
	// first.erase(140);
	// first.print_tree();

	// first.erase(130);
	// first.print_tree();
	// first.erase(120);
	// first.print_tree();
	// first.erase(136);
	// first.print_tree();
	// first.erase(125);
	// first.print_tree();
	// first.erase(135);
	// first.print_tree();
	// first.erase(160);
	// first.print_tree();

	// first.erase(12);
	// first.erase(13);
	// first.erase(11);

	/* erase */
	// first.erase(11);
	// first.erase(5);
	// first.erase(3);
	// first.erase(17);
	// first.erase(16);
	// first.erase(20);
	// first.erase(2);
	// first.erase(14);
	// first.erase(18);

	// first.print_tree();
	// first.erase(13);
	// first.erase(7);
	// // first.erase(10);
	// // first.erase(9);
	// // first.erase(12);
	// first.erase(8);
	// first.print_tree();

	first.clear();
	first.print_tree();
	// first[10]=10;
	std::cout << first.size() << std::endl;
	// first.clear();
	// std::cout << first.size() << std::endl;
	// first.print_tree();
	// system("leaks a.out");
	return (0);
}
