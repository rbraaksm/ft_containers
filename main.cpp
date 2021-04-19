#include "./list/list.hpp"
#include "./vector/vector.hpp"
#include <iostream>
#include <vector>
# include <iterator>



int	main(void){
	ft::vector<int> first(3, 100);
	std::cout << first.capacity() << "\n";
	std::vector<int> second(3, 100);
	std::cout << second.capacity() << "\n";
	// ft::vector<int>::iterator it;
	// ft::vector<int>::iterator itx;
	// std::vector<int>second;
	// std::vector<int>::iterator i;
	// std::vector<int>::iterator ix;

	// first.push_back(1);                // four ints with value 100
	// second.push_back(1);                // four ints with value 100
	// first.push_back(10);                // four ints with value 100
	// second.push_back(10);                // four ints with value 100
	// first.push_back(100);                // four ints with value 100
	// second.push_back(100);                // four ints with value 100
	// first.push_back(1000);                // four ints with value 100
	// second.push_back(1000);                // four ints with value 100

	// it = first.begin();
	// i = second.begin();

	// ++it;
	// ++i;

	// it = first.insert(it, 200);
	// i = second.insert(i, 200);

	// std::cout << "IT: " << *it << "\n";
	// std::cout << "I:  " << *i << "\n";

	// ++it;
	// ++i;
	// std::cout << "IT: " << *it << "\n";
	// std::cout << "I:  " << *i << "\n";

	// it = first.insert(it, 2000);
	// i = second.insert(i, 2000);

	// std::cout << "IT: " << *it << "\n";
	// std::cout << "I:  " << *i << "\n";

	// it = first.begin();
	// i = second.begin();

	// it++;
	// i++;

	// itx = it;
	// ix = i;

	// std::cout << "IT: " << *it << "\n";
	// std::cout << "I:  " << *i << "\n";

	// first.insert(it, 10, 3000);
	// second.insert(i, 10, 3000);

	// // it++;
	// // it++;

	// std::cout << "IT: " << *it << "\n";
	// std::cout << "I:  " << *i << "\n";

	// i = second.begin();
	// it = first.begin();
	// it = first.insert(it, 2000); // Hier zit de segfault
	// i = second.insert(i, 2000);

	// // std::cout << "First x:   ";
	// // for (it = first.begin(); it != itx; ++it)
	// // 	std::cout << ' ' << *it;
	// // std::cout << "\n";
	// // std::cout << "Secon x:   ";
	// // for (i = second.begin(); i != ix; ++i)
	// // 	std::cout << ' ' << *i;
	// // std::cout << "\n";
	// std::cout << "First end: ";
	// for (it = first.begin(); it != first.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << "\n";

	// std::cout << "Secon end: ";
	// for (i = second.begin(); i != second.end(); ++i)
	// 	std::cout << ' ' << *i;
	// std::cout << "\n\n\n\n\n\n\n\n\n";
	// system("leaks a.out");
	// ft::vector<int> myvector (3,100);
  	// ft::vector<int>::iterator it;

	//   it = myvector.begin();
	//   it = myvector.insert ( it , 200 );

	//   myvector.insert (it,2,300);

	//   // "it" no longer valid, get a new one:
	//   it = myvector.begin();

	//   std::vector<int> anothervector (2,400);
	//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

	//   int myarray [] = { 501,502,503 };
	//   myvector.insert (myvector.begin(), myarray, myarray+3);

	//   std::cout << "myvector contains:";
	//   for (it=myvector.begin(); it<myvector.end(); it++)
	//     std::cout << ' ' << *it;
	//   std::cout << '\n';
	// ft::vector<int> myvector;
	// ft::vector<int>::iterator it;

  	// // set some values (from 1 to 10)
	//   for (int i=1; i<=10; i++) myvector.push_back(i);

	//   // erase the 6th element
	//   it = myvector.begin() + 5;
	//   myvector.erase (it);

	//   // erase the first 3 elements:
	//   std::cout << *it << "\n";
	//   myvector.erase (myvector.end(),myvector.end()-1);
	//   std::cout << *it << "\n";
	//   std::cout << "Cap: " << myvector.capacity() << "\n";
	//   std::cout << "myvector contains:";
	//   for (unsigned i=0; i<myvector.size(); ++i)
	//     std::cout << ' ' << myvector[i];
	//   std::cout << '\n';
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';
//   std::cout << "Capacity: " << foo.capacity() << "\n";
//  std::cout << "Size: " << foo.size() << "\n\n";


//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
//     std::cout << "Capacity: " << bar.capacity() << "\n";
//   std::cout << "Size: " << bar.size() << "\n\n";


//   foo.swap(bar);
//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';
//   std::cout << "Capacity: " << foo.capacity() << "\n";
//  std::cout << "Size: " << foo.size() << "\n\n";


//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
//     std::cout << "Capacity: " << bar.capacity() << "\n";
//   std::cout << "Size: " << bar.size() << "\n\n";
//   ft::vector<int> second(5, 100);                // four ints with value 100
// 	ft::vector<int> third(second.begin(), second.end());  // iterating through second
// 	std::cout << third.capacity() << "\n";
// 	(void)third;
// ft::vector<int> first;                                // empty vector of ints
// 	// REQUIRE(first.capacity() == 0);
// 	std::cout << "First == 0 mine == " << first.capacity() << "\n";
// 	ft::vector<int> second(5, 100);                // four ints with value 100
// 	// REQUIRE(second.capacity() == 5);
// 	std::cout << "Second == 5 mine == " << second.capacity() << "\n";
// 	ft::vector<int> third(second.begin(), second.end());  // iterating through second
// 	// REQUIRE(third.capacity() == 5);
// 	std::cout << "Third == 5 mine == " << third.capacity() << "\n";
// 	ft::vector<int> fourth(third);                       // a copy of third
// 	std::cout << "Fourth == 5 mine == " << fourth.capacity() << "\n";
	// int myints[] = {16, 2, 77, 29, 66};
	// ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	// std::cout << "Fifth == 5 mine == " << fifth.capacity() << "\n";
  return 0;
}