#include "vector.hpp"
#include <vector>

int main(void){
    int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::const_reverse_iterator old_own_rit;
	std::vector<int>::const_reverse_iterator real_rit = real.rbegin();
	std::vector<int>::const_reverse_iterator old_real_rit;


	++own_rit;
	++real_rit;
    std::cout << "Own: " << own.size() << std::endl;
    for (ft::vector<int>::iterator it = own.begin(); it != own.end(); ++it)
        std::cout << " " << *it;
    std::cout << "\n";
    std::cout << "Real: " << real.size() << std::endl;
    for (std::vector<int>::iterator it = real.begin(); it != real.end(); ++it)
        std::cout << " " << *it;
    std::cout << "\n\n";
    std::cout << "Own: " << *own_rit << std::endl;
    std::cout << "Real: " << *real_rit << std::endl;
	// REQUIRE(*own_rit == *real_rit);
	
	// old_own_rit = own_rit++;
	// old_real_rit = real_rit++;
	// REQUIRE(*old_real_rit == *old_own_rit);
}