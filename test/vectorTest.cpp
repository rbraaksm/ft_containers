#include "Catch2.h"
#include "../srcs/Vector.hpp"

TEST_CASE("Vector: Iterator", "[Vector]") {
	ft::vector<std::string> myVec;
	std::vector<std::string> sysVec;
	ft::vector<int> myIntVec;
	std::string str = "Hello, world!";
	myVec.push_back(str);
	sysVec.push_back(str);
	myVec.push_back("I'm the next King");
	sysVec.push_back("I'm the next King");
	myVec.push_back("Welcome yourself to the next chapter");
	sysVec.push_back("Welcome yourself to the next chapter");
	ft::vector<std::string>::iterator myIt = myVec.begin();
	std::vector<std::string>::iterator sysIt = sysVec.begin();

	SECTION("Increment") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
		++myIt;
		++sysIt;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("Decrement") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
		myIt--;
		sysIt--;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("-> overload") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt->data() == *sysIt->data());
	}
	SECTION("* overload") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("== overload") {
		bool res;
		res = (myIt == myVec.begin());
		REQUIRE(res == true);
		myIt++;
		myIt++;
		myIt++;
		res = (myIt == myVec.end());
		REQUIRE(res == true);
		res = (myIt == myVec.begin());
		REQUIRE(res == false);
	}
	SECTION("!= overload") {
		bool res;
		res = (myIt != myVec.end());
		REQUIRE(res == true);
		myIt++;
		myIt++;
		res = (myIt != myVec.begin());
		REQUIRE(res == true);
		myIt++;
		res = (myIt != myVec.end());
		REQUIRE(res == false);
	}
	SECTION("Test (*it)++") {
		myIntVec.push_back(1);
		ft::vector<int>::iterator myIntIt = myIntVec.begin();
		REQUIRE(*myIntIt == 1);
		(*myIntIt)++;
		REQUIRE(*myIntIt == 2);
		*myIntIt++;
		bool res = (myIntIt == myIntVec.end());
		REQUIRE(res == true);
	}
	SECTION("Test (*it)--") {
		myIntVec.push_back(2);
		ft::vector<int>::iterator myIntIt = myIntVec.begin();
		REQUIRE(*myIntIt == 2);
		(*myIntIt)--;
		REQUIRE(*myIntIt == 1);
		*myIntIt--;
		bool res = (myIntIt != myIntVec.begin());
		REQUIRE(res == true);
	}
	SECTION("Test assignemt with iterator") {
		myIntVec.push_back(1);
		myIntVec.push_back(8);
		ft::vector<int>::iterator myIntIt = myIntVec.begin();
		REQUIRE(*myIntIt == 1);
		*myIntIt = 5;
		REQUIRE(*myIntIt == 5);
	}
	SECTION("Test dereference as lvalue") {
		myIntVec.push_back(1);
		myIntVec.push_back(8);
		ft::vector<int>::iterator myIntIt = myIntVec.begin();
		*myIntIt++ = 5;
		REQUIRE(*myIntIt == 8);
		myIntIt--;
		REQUIRE(*myIntIt == 5);
	}
	SECTION("Reverse iterator") {
		ft::vector<int> myvector;
		for (int i=1; i<=5; ++i) myvector.push_back(i);

		ft::vector<int>::reverse_iterator rit=myvector.rbegin();
		REQUIRE(*rit == 5);
		rit++;
		REQUIRE(*rit == 4);
		rit--;
		REQUIRE(*rit == 5);
		*rit = 10;
		REQUIRE(*rit == 10);
	}
	SECTION("Test - + += -+ overloads") {
		myIntVec.push_back(2);
		myIntVec.push_back(3);
		myIntVec.push_back(4);
		myIntVec.push_back(5);
		myIntVec.push_back(6);
		ft::vector<int>::iterator it = myIntVec.begin();
		REQUIRE(*it == 2);
		it = it + 1;
		REQUIRE(*it == 3);
		it + 1;
		REQUIRE(*it == 3);
		it = it - 1;
		REQUIRE(*it == 2);
		int i = *it + *it;
		REQUIRE(i == 4);
		it += 3;
		REQUIRE(*it == 5);
	}
}

TEST_CASE("Vector: Constructors", "[Vector]") {
	// constructors used in the same order as described above:
	ft::vector<int> first;                                // empty vector of ints
	REQUIRE(first.capacity() == 0);
	ft::vector<int> second(5, 100);                // four ints with value 100
	REQUIRE(second.capacity() == 5);
	ft::vector<int> third(second.begin(), second.end());  // iterating through second
	REQUIRE(third.capacity() == 5);
	ft::vector<int> fourth(third);                       // a copy of third
	REQUIRE(fourth.capacity() == 5);

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16, 2, 77, 29, 66};
	ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	REQUIRE(fifth.capacity() == 5);
	REQUIRE(fifth.front() == 16);
	REQUIRE(fifth.back() == 66);

	ft::vector<int> sixt = fifth;
	REQUIRE(sixt.capacity() == 5);
	REQUIRE(sixt.front() == 16);
	REQUIRE(sixt.back() == 66);
}

TEST_CASE("Vector: Resize", "[Vector]") {
	ft::vector<int> myvector;
	std::vector<int> realvector;

	// set some initial content:
	for (int i=1;i<6;i++) myvector.push_back(i);
	for (int i=1;i<6;i++) realvector.push_back(i);

	myvector.resize(5);
	realvector.resize(5);
	REQUIRE(myvector.capacity() == realvector.capacity());
	REQUIRE(myvector.size() == realvector.size());
	REQUIRE(myvector.front() == realvector.front());
	REQUIRE(myvector.back() == realvector.back());
	myvector.resize(8,100);
	realvector.resize(8,100);
	REQUIRE(myvector.capacity() == realvector.capacity());
	REQUIRE(myvector.size() == realvector.size());
	REQUIRE(myvector.front() == realvector.front());
	REQUIRE(myvector.back() == realvector.back());
	myvector.resize(12);
	realvector.resize(12);
	REQUIRE(myvector.capacity() == realvector.capacity());
	REQUIRE(myvector.size() == realvector.size());
	REQUIRE(myvector.front() == realvector.front());
	REQUIRE(myvector.back() == realvector.back());
}

TEST_CASE("Vector: [] operator overload", "[Vector]") {
	ft::vector<int> myvector;

	for (int i = 0; i < 6; i++) myvector.push_back(i);

	for (int i = 0; i < 6; i++) {
		REQUIRE(myvector[i] == i);
	}
}

TEST_CASE("Vector: At", "[Vector") {
	ft::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	for (unsigned i=0; i<myvector.size(); i++)
		REQUIRE(myvector.at(i) == i);

	REQUIRE_THROWS_AS(myvector.at(10), std::out_of_range);
}

TEST_CASE("Vector: Insert", "[Vector]") {
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;
	std::vector<int> realvector (3,100);
	std::vector<int>::iterator rit;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	rit = realvector.begin();
	rit = realvector.insert ( rit , 200 );
	// myvector contains: 200 100 100 100
	REQUIRE(myvector.size() == realvector.size());
	REQUIRE(myvector.capacity() == realvector.capacity());
	REQUIRE(myvector.at(0) == realvector.at(0));
	REQUIRE(myvector.at(2) == realvector.at(2));


	myvector.insert (it,2,300);
	realvector.insert (rit,2,300);
	// myvector contains: 300 300 200 100 100 100
	REQUIRE(myvector.size() == realvector.size());
	REQUIRE(myvector.capacity() == realvector.capacity());
	REQUIRE(myvector.at(0) == realvector.at(0));
	REQUIRE(myvector.at(2) == realvector.at(2));

}

TEST_CASE("Vector: Erase", "[Vector]") {
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	SECTION("Erase end") {
		// erase the 6th element
		myvector.erase (myvector.begin()+9);
		// myvector contains: 1 2 3 4 5 7 8 9 10
		REQUIRE(myvector.size() == 9);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.back() == 9);
	}
	SECTION("Erase 1 element") {
		// erase the 6th element
		myvector.erase (myvector.begin()+5);
		// myvector contains: 1 2 3 4 5 7 8 9 10
		REQUIRE(myvector.size() == 9);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.at(4) == 5);
		REQUIRE(myvector.at(5) == 7);

		myvector.erase (myvector.begin());
		REQUIRE(myvector.size() == 8);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.at(0) == 2);
	}
	SECTION("Erase range from begin") {
		myvector.erase (myvector.begin(), myvector.begin()+5);
		REQUIRE(myvector.size() == 5);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.at(0) == 6);
		REQUIRE(myvector.at(1) == 7);
	}
	SECTION("Erase range from middle") {
		myvector.erase (myvector.begin()+1, myvector.begin()+5);
		REQUIRE(myvector.size() == 6);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.at(0) == 1);
		REQUIRE(myvector.at(1) == 6);
	}
	SECTION("Erase range until end - 1") {
		myvector.erase (myvector.begin()+5, myvector.begin()+9);
		REQUIRE(myvector.size() == 6);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.at(4) == 5);
		REQUIRE(myvector.at(5) == 10);
	}
	SECTION("Erase range until end") {
		myvector.erase (myvector.begin()+5, myvector.end());
		REQUIRE(myvector.size() == 5);
		REQUIRE(myvector.capacity() == 16);
		REQUIRE(myvector.at(4) == 5);
	}
}

TEST_CASE("Vector: Swap", "[Vector]") {
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	REQUIRE(foo.size() == 5);
	REQUIRE(foo.capacity() == 5);
	REQUIRE(bar.size() == 3);
	REQUIRE(bar.capacity() == 3);
}

TEST_CASE("Vector: Relational operator overloads", "[Vector]") {
	ft::vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	ft::vector<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	ft::vector<int> c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);

	REQUIRE((a == b) == true);
	REQUIRE((b != c) == true);
	REQUIRE((b < c) == true);
	REQUIRE((c > b) == true);
	REQUIRE((a <= b) == true);
	REQUIRE((a >= b) == true);

	REQUIRE((a <= b) == true);
	REQUIRE((a > b) == false);
	REQUIRE((a < b) == false);
	REQUIRE((a != b) == false);
	REQUIRE((b > c) == false);
	REQUIRE((b == c) == false);
	REQUIRE((b != c) == true);
}

TEST_CASE("Vector: subtracting two iterators", "[Vector]") {
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it2;

	it = myvector.begin();
	it2 = myvector.end();
	REQUIRE(it2 - it == 3);
}

// /*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("vector-default constructor", "[vector]")
{
	ft::vector<int> 	own;
	std::vector<int> 	real;

	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-size and value constructor", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int> 	real(5, 3);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-iterator instanciation", "[vector]")
{
	ft::vector<int>		own(6, 100);
	std::vector<int>	real(6, 100);

	ft::vector<int>		own2(own.begin(), own.end());
	std::vector<int>	real2(real.begin(), real.end());

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.capacity() == real2.capacity());
	REQUIRE(own2[0] ==  real2[0]);
	REQUIRE(own2[1] == real2[1]);

	own.clear();
	real.clear();
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 1;
	}
	own.pop_back();
	real.pop_back();

	ft::vector<int> 	own3(own.begin() + 1, own.end());
	std::vector<int>	real3(real.begin() + 1, real.end());

	REQUIRE(own3.size() == real3.size());
	REQUIRE(own3.capacity() == real3.capacity());
	REQUIRE(own3[0] == real3[0]);
	REQUIRE(own3[1] == real3[1]);
}

TEST_CASE("vector-copy constructor", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);

	ft::vector<int> 	own2(own1);
	std::vector<int> 	real2(real1);

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
}

TEST_CASE("operator= function", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);

	ft::vector<int> own2;
	std::vector<int> real2;

	own2 = own1;
	real2 = real1;

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
	REQUIRE(own2.capacity() == real2.capacity());
}


/*-----------------ITERATORS-----------------*/
TEST_CASE("vector-begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);

	ft::vector<int>::iterator own_it = own.begin();
	std::vector<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-const begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);

	ft::vector<int>::const_iterator own_it = own.begin();
	std::vector<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);

	ft::vector<int>::iterator own_ite = own.end();
	std::vector<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-const end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);

	ft::vector<int>::const_iterator own_ite = own.end();
	std::vector<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}

	ft::vector<int>::reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::reverse_iterator old_own_rit;
	std::vector<int>::reverse_iterator real_rit = real.rbegin();
	std::vector<int>::reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);

	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-const rbegin function", "[vector]")
{
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
	REQUIRE(*own_rit == *real_rit);

	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}

	ft::vector<int>::reverse_iterator own_rite = own.rend();
	ft::vector<int>::reverse_iterator old_own_rite;
	std::vector<int>::reverse_iterator real_rite = real.rend();
	std::vector<int>::reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);

	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

TEST_CASE("vector-const rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}

	ft::vector<int>::const_reverse_iterator own_rite = own.rend();
	ft::vector<int>::const_reverse_iterator old_own_rite;
	std::vector<int>::const_reverse_iterator real_rite = real.rend();
	std::vector<int>::const_reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);

	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}


/*-----------------Capcity-----------------*/
TEST_CASE("vector-size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-max_size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	own.clear();
	real.clear();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.max_size() == real.max_size());
}

TEST_CASE("vector-resize function", "[vector]")
{
	ft::vector<int> 	own(8, 5);
	std::vector<int> 	real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[1] == real[1]);
}

TEST_CASE("vector-capacity function", "[vector]")
{
	ft::vector<int> own(8, 5);
	std::vector<int> real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-empty function", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int>	real(5, 3);

	ft::vector<int> 	empty_own;
	std::vector<int>	empty_real;

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(empty_own.empty() == empty_real.empty());
}

TEST_CASE("vector-reserve function", "[vector]")
{
	ft::vector<int>		own(6, 10);
	std::vector<int>	real(6, 10);

	own.reserve(100);
	real.reserve(100);

	REQUIRE(own.capacity() == real.capacity());

	// try
	// {
	// 	own.reserve(own.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// try
	// {
	// 	real.reserve(real.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}



/*-----------------Element Access-----------------*/
TEST_CASE("vector-operator[] function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real[i] = sum;
		own[i] = sum;
		sum += 1;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);
}

TEST_CASE("vector-at function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	REQUIRE(own.at(0) == real.at(0));
	REQUIRE(own.at(1) == real.at(1));
	REQUIRE(own.at(2) == real.at(2));
	REQUIRE(own.at(3) == real.at(3));
	try
	{
		own.at(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		real.at(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST_CASE("vector-front function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}

	REQUIRE(own.front() == real.front());
}

TEST_CASE("vector-back function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}

	REQUIRE(own.back() == real.back());
}


/*-----------------Modifiers-----------------*/

TEST_CASE("vector-assign fucntion with itarators", "[vector]")
{
	ft::vector<int>		own1(5, 100);
	ft::vector<int>		own2;
	std::vector<int>	real1(5, 100);
	std::vector<int>	real2;

	own2.assign(own1.begin(), own1.begin() + 3);
	real2.assign(real1.begin(), real1.begin() + 3);

	ft::vector<int>::iterator own_it = own2.begin();
	std::vector<int>::iterator real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.capacity() == real2.capacity());
	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("vector-assign function with n and val", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	own.assign(20, 20);
	real.assign(20 , 20);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
	REQUIRE(own.at(3) == real.at(3));
	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-push_back function", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	int sum = 10;
	for(int i = 0; i < 4; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-pop_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;

	for(int i = 0; i < 4; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own.size() == real.size());
	own.pop_back();
	real.pop_back();
	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-insert function", "[vector]")
{
	ft::vector<int>		own(6, 100);
	std::vector<int>	real(6, 100);

	ft::vector<int>::iterator	it_own = own.begin();
	std::vector<int>::iterator	it_real = real.begin();

	it_own = own.insert(it_own, 200);
	it_real = real.insert(it_real, 200);
	//  200 100 100 100 100 100 100
	//  ^
	REQUIRE(*it_own == *it_real);

	own.insert(it_own, 2, 300);
	real.insert(it_real, 2, 300);
	// 300 300 200 100 100 100 100 100 100
	// ^   ^

	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);

	ft::vector<int> 	own1(2, 400);
	std::vector<int>	real2(2, 400);

	it_own = own.begin();
	it_real = real.begin();

	own.insert(it_own + 2, own1.begin(), own1.end());
	real.insert(it_real + 2, real2.begin(), real2.end());
	// 300 300 400 400 200 100 100 100 100 100 100
	//         ^   ^
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);

	int myarray[] = {101, 102, 103};

	it_own = ft::vector<int>::iterator(myarray);

	own.insert(own.begin(), it_own, it_own + 3);
	real.insert(real.begin(), myarray, myarray + 3);
	// 101 102 103 300 300 400 400 200 100 100 100 100 100 100
	// ^   ^   ^

	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own.size() == real.size());

}

TEST_CASE("vector-erase function", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;
	int sum = 0;

	ft::vector<int>::iterator	it_own;
	std::vector<int>::iterator	it_real;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 1;
	}
	//  0 1 2 3 4 5 6 7 8 9

	it_own = own.erase(own.begin() + 4);
	it_real = real.erase(real.begin() + 4);
	// 0 1 2 3 5 6 7 8 9
	//         ^

	REQUIRE(own[4] == real[4]);
	REQUIRE(*it_own == *it_real);

	it_own = own.erase(own.begin(), own.end() - 4);
	it_real = real.erase(real.begin(), real.end() - 4);
	// 6 7 8 9
	// ^

	REQUIRE(own[0] == real[0]);
	REQUIRE(*it_own == *it_real);
}

TEST_CASE("vector-swap function", "[vector]")
{
	ft::vector<int> 	own(4, 100);
	ft::vector<int> 	own2(5, 300);
	ft::vector<int>		own3;
	std::vector<int> 	real(4, 100);
	std::vector<int>	real2(5, 300);
	std::vector<int>	real3;

	own.swap(own2);
	real.swap(real2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);

	ft::swap(own3, own2);
	std::swap(real3, real2);

	REQUIRE(own3.size() == real3.size());
	REQUIRE(own3.capacity() == real3.capacity());
	REQUIRE(own3[0] == real3[0]);
	REQUIRE(own3[1] == real3[1]);
	REQUIRE(own3[2] == real3[2]);

}

TEST_CASE("vector-clear function", "[vector]")
{
	ft::vector<int>		own(10, 100);
	std::vector<int>	real(10, 100);

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-get_allocator function", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	int *p_own;
	int *p_real;
	bool own_return = false;
	bool real_return = false;
	unsigned int i_own;
	unsigned int i_real;

	// allocate an array with space for 5 elements using vector's allocator:
  	p_own = own.get_allocator().allocate(5);
  	p_real = real.get_allocator().allocate(5);

	if (!p_own)
		own_return = false;
	else
		own_return = true;

	if (!p_real)
		real_return = false;
	else
		real_return = true;

	REQUIRE(own_return == real_return);

  	// construct values in-place on the array:
  	for (i_own = 0; i_own < 5; i_own++) own.get_allocator().construct(&p_own[i_own],i_own);
  	for (i_real = 0; i_real < 5; i_real++) real.get_allocator().construct(&p_real[i_real],i_real);

	REQUIRE(p_own[0] == p_real[0]);
	REQUIRE(p_own[1] == p_real[1]);
	REQUIRE(p_own[2] == p_real[2]);
	REQUIRE(p_own[3] == p_real[3]);

  	// destroy and deallocate:
	for (i_own = 0; i_own < 3; i_own++) own.get_allocator().destroy(&p_own[i_own]);
	for (i_real = 0; i_real < 3; i_real++) own.get_allocator().destroy(&p_own[i_real]);

	REQUIRE(p_own[0] == p_real[0]);
	REQUIRE(p_own[1] == p_real[1]);

	own.get_allocator().deallocate(p_own,5);
	real.get_allocator().deallocate(p_real,5);

	if (!p_own)
		own_return = false;
	else
		own_return = true;

	if (!p_real)
		real_return = false;
	else
		real_return = true;

	REQUIRE(own_return == real_return);
}

/*-----------------Relational Operators-----------------*/
TEST_CASE("vector-operation overloaders", "[vector]")
{
	ft::vector<int> 	own(4, 200);
	ft::vector<int> 	own2(4, 100);
	ft::vector<int> 	own3(4, 200);
	std::vector<int>	real(4, 200);
	std::vector<int>	real2(4, 100);
	std::vector<int>	real3(4, 200);


	REQUIRE((own == own3) == true);
	REQUIRE((own == own2) == false);
	REQUIRE((real == real3) == true);
	REQUIRE((real == real2) == false);

	REQUIRE((own != own3) == false);
	REQUIRE((own != own2) == true);
	REQUIRE((real != real3) == false);
	REQUIRE((real != real2) == true);

	REQUIRE((own < own2) == false);
	REQUIRE((own2 < own3) == true);
	REQUIRE((real < real2) == false);
	REQUIRE((real2 < real3) == true);

	REQUIRE((own < own3) == false);
	REQUIRE((own <= own3) == true);
	REQUIRE((real < real3) == false);
	REQUIRE((real <= real3) == true);

	REQUIRE((own > own2) == true);
	REQUIRE((own2 > own3) == false);
	REQUIRE((real > real2) == true);
	REQUIRE((real2 > real3) == false);

	REQUIRE((own > own3) == false);
	REQUIRE((own >= own3) == true);
	REQUIRE((real > real3) == false);
	REQUIRE((real >= real3) == true);
}

