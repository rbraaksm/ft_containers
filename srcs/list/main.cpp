#include "list.hpp"

#include <list>
#include <math.h>

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

int main(void){
    ft::list<double>	own;
	std::list<double>	real;

	own.push_back(12.15); real.push_back(12.15);
	own.push_back(2.72); real.push_back(2.72);
	own.push_back(73.0); real.push_back(73.0);
	own.push_back(12.77); real.push_back(12.77);
	own.push_back(3.14); real.push_back(3.14);
	own.push_back(12.77); real.push_back(12.77);
	own.push_back(73.35); real.push_back(73.35);
	own.push_back(72.25); real.push_back(72.25);
	own.push_back(15.3); real.push_back(15.3);
	own.push_back(72.25); real.push_back(72.25);

	ft::list<double>::iterator		own_it = own.begin();
	std::list<double>::iterator		real_it = real.begin();

    std::cout << "OWN LIST\n";
    for(own_it = own.begin(); own_it != own.end(); ++own_it)
        std::cout << " " << *own_it;
        std::cout << "\n";
    std::cout << "REAL LIST\n";
    for(real_it = real.begin(); real_it != real.end(); ++real_it)
        std::cout << " " << *real_it;
        std::cout << "\n\n";

	own.sort();
	real.sort();
	
	own.unique();
	real.unique();

	own.unique(same_integral_part);
	real.unique(same_integral_part);

    std::cout << "OWN LIST\n";
    for(own_it = own.begin(); own_it != own.end(); ++own_it)
        std::cout << " " << *own_it;
        std::cout << "\n";
    std::cout << "REAL LIST\n";
    for(real_it = real.begin(); real_it != real.end(); ++real_it)
        std::cout << " " << *real_it;
        std::cout << "\n\n";

    // std::cout << "Own: " << own.size() << std::endl;
    // std::cout << "Real: " << real.size() << std::endl;
    // std::cout << "Own: " << own.empty() << std::endl;
    // std::cout << "Real: " << real.empty() << std::endl;
    // std::cout << "Own: " << own.front() << std::endl;
    // std::cout << "Real: " << real.front() << std::endl;
    // std::cout << "Own: " << own.back() << std::endl;
    // std::cout << "Real: " << real.back() << std::endl;


	while (own_it != own.end())
	{
        std::cout << "Own:  " << *own_it << std::endl;
        std::cout << "Real: " << *real_it << std::endl;

		++own_it;
		++real_it;
	}

	own.unique(is_near());
	real.unique(is_near());

	own_it = own.begin();
	real_it = real.begin();

	while (own_it != own.end())
	{
        std::cout << "Own:  " << *own_it << std::endl;
        std::cout << "Real: " << *real_it << std::endl;

		++own_it;
		++real_it;
	}
	// while (real_it != real.end())
	// {
	// 	REQUIRE(*own_it == *real_it);
	// 	++own_it;
	// 	++real_it;
	// }
	
	// REQUIRE(own.size() == real.size());
	// REQUIRE(own.empty() == real.empty());
	// REQUIRE(own.front() == real.front());
	// REQUIRE(own.back() == real.back());

	// own_it = own.begin();
	// real_it = real.begin();
	
	// while (own_it != own.end())
	// {
	// 	REQUIRE(*own_it == *real_it);
	// 	++own_it;
	// 	++real_it;
	// }


    // std::cout << "Own: " << own.size() << std::endl;
    // std::cout << "Real: " << real.size() << std::endl;
    // std::cout << "Own: " << own.empty() << std::endl;
    // std::cout << "Real: " << real.empty() << std::endl;
    // std::cout << "Own: " << own.front() << std::endl;
    // std::cout << "Real: " << real.front() << std::endl;
    // std::cout << "Own: " << own.back() << std::endl;
    // std::cout << "Real: " << real.back() << std::endl;

}