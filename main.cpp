#include "./list/list.hpp"

	// / a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

	bool mycomparison (double first, double second)
	{ return ( int(first)<int(second) ); }

int	main(void){
	ft::list<double>::iterator it;
	ft::list<double> first, second;


	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	std::cout << "List:";
	for (it=first.begin(); it!=first.end(); ++it)
	    std::cout << ' ' << *it;
	std::cout << "\n";
	first.sort();
	std::cout << "List:";
	for (it=first.begin(); it!=first.end(); ++it)
	    std::cout << ' ' << *it;
	std::cout << "\n";

	// second.push_back (1.7);
	// second.push_back (7.1);
	// second.push_back (1.4);
	// second.sort();
	// std::cout << "IX:";
	// for (it=second.begin(); it!=second.end(); ++it)
	//     std::cout << ' ' << *it;
	// std::cout << "\n\n";


	// it = second.begin();

	// first.merge(second);
	// double* ptr = &(*it);

	// 	std::cout << "First:";
	//   for (it=first.begin(); it!=first.end(); ++it)
	//     std::cout << ' ' << *it;
	// std::cout << "\n";
	// 	std::cout << "Second:";
	//   for (it=second.begin(); it!=second.end(); ++it)
	//     std::cout << ' ' << *it;
	// std::cout << "\n\n";

	// second.push_back (2.1);

	// first.merge(second,mycomparison);
	// // // first contains: 1.4 2.2 2.9 2.1 3.1 3.7 7.1
	// // REQUIRE(first.size() == 7);
	// // REQUIRE(first.front() == 1.4);

	// 	std::cout << "First:";
	//   for (it=first.begin(); it!=first.end(); ++it)
	//     std::cout << ' ' << *it;
	// std::cout << "\n\n";
	// std::cout << first.front() << std::endl;
	// std::cout << first.back() << std::endl;
	return (0);
}