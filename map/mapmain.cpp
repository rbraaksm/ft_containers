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

	first[10]=10;
	first[14]=30;
	first[5]=30;
	first[2]=30;
	first[17]=30;
	first[8]=50;
	// first[4]=30;
	first[7]=30;
	first[14]=20;
	// first[19]=70;
	first[9]=70;
	first[11]=70;
	first[13]=70;
	first[16]=70;
	// first[30]=70;
	first[12]=70;
	first[20]=70;
	first[18]=70;
	first[3]=70;


	first.print_tree();

	/*Top erase */
	// first.erase(20);
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
	// first.erase(7);
	// first.erase(8);

	/* erase */
	first.erase(11);
	first.erase(5);
	first.erase(3);
	first.erase(17);
	first.erase(16);
	first.erase(20);
	first.erase(2);
	first.erase(14);
	first.erase(18);
	
	// first.erase(13);
	// first.erase(7);
	// first.erase(10);
	// first.erase(9);
	first.print_tree();
	
	// first.clear();
	// first.print_tree();
	// first[10]=10;
	// first.print_tree();
	// std::cout << first.size() << std::endl;
	// system("leaks a.out");
	return (0);
}
