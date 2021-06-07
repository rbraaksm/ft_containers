#include "list.hpp"
#include <list>
#include <iostream>

int main(void){
	int sum = 0;
	ft::list<int>	own(5);
	std::list<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}

	ft::list<int>::const_reverse_iterator own_rit = own.rbegin();
	ft::list<int>::const_reverse_iterator old_own_rit;
	std::list<int>::const_reverse_iterator real_rit = real.rbegin();
	std::list<int>::const_reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	// REQUIRE(*own_rit == *real_rit);

	old_own_rit = own_rit++;
	old_real_rit = real_rit++;

	std::cout << *old_own_rit << "\n";
	// REQUIRE(*old_real_rit == *old_own_rit);
	return (0);
}