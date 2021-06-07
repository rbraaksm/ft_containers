#include "../srcs/vector/vector.hpp"
#include <vector>

int	main(void){
ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	own_vector_string.push_back("my");
	own_vector_string.push_back("name");
	own_vector_string.push_back("is");
	own_vector_string.push_back("Tim");

	real_vector_string.push_back("my");
	real_vector_string.push_back("name");
	real_vector_string.push_back("is");
	real_vector_string.push_back("Tim");

	ft::vector<std::string>::reverse_iterator own_it = own_vector_string.rbegin();
	std::vector<std::string>::reverse_iterator real_it = real_vector_string.rbegin();
	ft::vector<int> 	own_vector_int;
	std::vector<int>	real_vector_int;

	for (int i = 0; i < 10; ++i) own_vector_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_vector_int.push_back(i);

	ft::vector<int>::reverse_iterator own_it2 = own_vector_int.rbegin();
	std::vector<int>::reverse_iterator real_it2 = real_vector_int.rbegin();

		own_it = own_it + 2;
		real_it = real_it + 2;
		// own_it2 = own_it2 + 3;
		// real_it2 = real_it2 + 3;

		std::cout << *own_it << std::endl;
		std::cout << *real_it << std::endl;
		// REQUIRE(*own_it == *real_it);
		// REQUIRE(*own_it2 == *real_it2);

		int own_res = *own_it2 + *own_it2;
		int real_res = *real_it2 + *real_it2;

		// REQUIRE(own_res == real_res);


	return (0);
}