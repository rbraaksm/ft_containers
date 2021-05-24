#include "Catch2.h"

#include "../srcs/list/list.hpp"
#include <list>

TEST_CASE("List: Iterator", "[List]") {
	ft::list<std::string> myList;
	std::list<std::string> sysList;
	ft::list<int> myIntList;
	std::string str = "Hello, world!";
	myList.push_back(str);
	sysList.push_back(str);
	myList.push_back("I'm the next King");
	sysList.push_back("I'm the next King");
	myList.push_back("Welcome yourself to the next chapter");
	sysList.push_back("Welcome yourself to the next chapter");
	ft::list<std::string>::iterator myIt = myList.begin();
	std::list<std::string>::iterator sysIt = sysList.begin();

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
		res = (myIt == myList.begin());
		REQUIRE(res == true);
		myIt++;
		myIt++;
		myIt++;
		res = (myIt == myList.end());
		REQUIRE(res == true);
		res = (myIt == myList.begin());
		REQUIRE(res == false);
	}
	SECTION("!= overload") {
		bool res;
		res = (myIt != myList.end());
		REQUIRE(res == true);
		myIt++;
		myIt++;
		res = (myIt != myList.begin());
		REQUIRE(res == true);
		myIt++;
		res = (myIt != myList.end());
		REQUIRE(res == false);
	}
	SECTION("Test (*it)++") {
		myIntList.push_back(1);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 1);
		(*myIntIt)++;
		REQUIRE(*myIntIt == 2);
		*myIntIt++;
		bool res = (myIntIt == myIntList.end());
		REQUIRE(res == true);
	}
	SECTION("Test (*it)--") {
		myIntList.push_back(2);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 2);
		(*myIntIt)--;
		REQUIRE(*myIntIt == 1);
		*myIntIt--;
		bool res = (myIntIt != myIntList.begin());
		REQUIRE(res == true);
	}
	SECTION("Test assignemt with iterator") {
		myIntList.push_back(1);
		myIntList.push_back(8);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 1);
		*myIntIt = 5;
		REQUIRE(*myIntIt == 5);
	}
	SECTION("Test dereference as lvalue") {
		myIntList.push_back(1);
		myIntList.push_back(8);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		*myIntIt++ = 5;
		REQUIRE(*myIntIt == 8);
		myIntIt--;
		REQUIRE(*myIntIt == 5);
	}
	SECTION("Reverse iterator") {
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		ft::list<int>::reverse_iterator rit=mylist.rbegin();
		REQUIRE(*rit == 5);
		rit++;
		REQUIRE(*rit == 4);
		rit--;
		REQUIRE(*rit == 5);
		*rit = 10;
		REQUIRE(*rit == 10);
	}
}

TEST_CASE("List: Push-front", "[List]") {
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_front(2);
	myList.push_front(26);
	ft::list<int>::iterator it = myList.begin();
	REQUIRE(*it == 26);
	it++;
	REQUIRE(*it == 2);
}

TEST_CASE("List: Pop-front", "[List]") {
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.pop_front();
	myList.pop_front();
	ft::list<int>::iterator it = myList.begin();
	REQUIRE(*it == 3);
}

TEST_CASE("List: Pop-back", "[List]") {
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.pop_back();
	myList.pop_back();
	ft::list<int>::iterator it = myList.begin();
	REQUIRE(*it == 1);
}

TEST_CASE("List: Assign", "[List]") {
	ft::list<int>	oneL;
	std::list<int>	twoL;
	twoL.push_back(1);
	twoL.push_back(2);
	twoL.push_back(3);

	oneL.assign(twoL.begin(), twoL.end());
	ft::list<int>::iterator it = oneL.begin();
	REQUIRE(*it == 1);
	it++;
	REQUIRE(*it == 2);
	REQUIRE(oneL.size() == 3);

	oneL.assign(4, 300);
	it = oneL.begin();
	REQUIRE(*it == 300);
	it++;
	REQUIRE(*it == 300);
	REQUIRE(oneL.size() == 4);

	int myint[5] = {1, 2, 3, 4, 5};
	oneL.assign(myint, myint + 5);
	it = oneL.begin();
	REQUIRE(*it == 1);
	it++;
	REQUIRE(*it == 2);
	REQUIRE(oneL.size() == 5);
}

TEST_CASE("List: Insert", "[List]") {
	ft::list<int> mylist;
	ft::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^
	REQUIRE(*it == 2);
	mylist.insert (it,10);                        // 1 10 2 3 4 5
	REQUIRE(mylist.size() == 6);
	// "it" still points to number 2                           ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
	REQUIRE(mylist.size() == 8);
	--it;       // it points now to the second 20            ^
	REQUIRE(*it == 20);
	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	// 1 10 20 30 30 20 2 3 4 5
	//               ^
	it--;
	REQUIRE(*it == 30);
	REQUIRE(mylist.size() == 10);
}

TEST_CASE("List: Erase", "[List]") {
	ft::list<int> mylist;
	ft::list<int>::iterator it1,it2;
	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);
										// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); 		// ^^
	advance (it2,6);				// ^                 ^
	++it1;								//    ^              ^
	REQUIRE(mylist.size() == 9);
	REQUIRE(*it1 == 20);
	REQUIRE(*it2 == 70);
	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^
	REQUIRE(*it1 == 30);
	REQUIRE(*it2 == 70);
	REQUIRE(mylist.size() == 8);
	it2 = mylist.erase (it2);	// 10 30 40 50 60 80 90
								//    ^           ^
	++it1;						//       ^        ^
	--it2;						//       ^     ^
	REQUIRE(*it1 == 40);
	REQUIRE(*it2 == 60);
	REQUIRE(mylist.size() == 7);
	it1 = mylist.erase (it1,it2);		// 10 30 60 80 90
										//       ^
	REQUIRE(*it1 == 60);
	REQUIRE(*it2 == 60);
	REQUIRE(mylist.size() == 5);
}

TEST_CASE("List: Swap", "[List]") {
	ft::list<int> first (3,100);   // three ints with a value of 100
	ft::list<int> second (5,200);  // five ints with a value of 200

	first.swap(second);

	ft::list<int>::iterator it=first.begin();
	REQUIRE(*it == 200);
	REQUIRE(first.size() == 5);
	it = second.begin();
	REQUIRE(*it == 100);
	REQUIRE(second.size() == 3);
}

TEST_CASE("List: Resize", "[List]") {
	ft::list<int> mylist;

	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.resize(5);
	REQUIRE(mylist.size() == 5);
	mylist.resize(8,100);
	REQUIRE(mylist.size() == 8);
	mylist.resize(12);
	REQUIRE(mylist.size() == 12);
}

TEST_CASE("List: Splice", "[List]") {
	ft::list<int> mylist1, mylist2;
	ft::list<int>::iterator it;
	ft::list<int>::iterator ptrIt;

	SECTION("Functionality") {
		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2
		mylist1.splice (it, mylist2);
		// mylist1: 1 10 20 30 2 3 4
		// mylist2 (empty)
		// "it" still points to 2 (the 5th element)
		REQUIRE(mylist1.size() == 7);
		REQUIRE(mylist2.empty() == true);
		REQUIRE(*it == 2);

		mylist2.splice (mylist2.begin(),mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		REQUIRE(mylist1.size() == 6);
		REQUIRE(mylist2.size() == 1);

		it = mylist1.begin();
		std::advance(it,3);           // "it" points to 30
		REQUIRE(*it == 30);

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		// mylist1 contains: 30 3 4 1 10 20
		// mylist2 contains: 2
		REQUIRE(mylist1.size() == 6);
		REQUIRE(mylist2.size() == 1);
	}
	SECTION("Check pointers") {
		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		// Save the ptr to _data of 1st element in L2
		ptrIt =  mylist2.begin();
		int* ptr = &(*ptrIt);

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
		// mylist2 (empty)

		// Get ptr to _data of the second element in L1 (10 from L2)
		ptrIt = mylist1.begin();
		ptrIt++;
		int* ptr2 = &(*ptrIt);
		// ptr and ptr2 should be the same because the element was moved without destructing it
		REQUIRE(ptr == ptr2);
	}
}

TEST_CASE("List: Remove", "[List]") {
	int myints[]= {17,89,7,7};
	ft::list<int> mylist (myints,myints+4);

	mylist.remove(7);
	// mylist contains: 17 7 14
	REQUIRE(mylist.size() == 2);
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};
TEST_CASE("List: Remove_if", "[List]") {
	int myints[]= {15,36,7,17,20,39,4,1};
	ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

	mylist.remove_if (single_digit);           // 15 36 17 20 39

	mylist.remove_if (is_odd());               // 36 20
	REQUIRE(mylist.size() == 2);
}

TEST_CASE("List: Front() + Back()", "[List]") {
	ft::list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	// now front equals 77, and back 22

	mylist.front() -= mylist.back();
	REQUIRE(mylist.front() == 55);
}

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

TEST_CASE("List: Sort", "[List]") {
	ft::list<std::string> mylist;
	ft::list<std::string>::iterator it;
	mylist.push_back ("Three");
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	mylist.sort();
//	mylist contains: Three Three one two
	it = mylist.begin();
	REQUIRE(*it == "Three");
	std::advance(it, 2);
	REQUIRE(*it == "one");
	std::advance(it, 1);
	REQUIRE(*it == "two");

	mylist.sort(compare_nocase);
//	mylist contains: one Three Three two
	it = mylist.begin();
	REQUIRE(*it == "one");
	std::advance(it, 2);
	REQUIRE(*it == "Three");
	std::advance(it, 1);
	REQUIRE(*it == "two");
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};
TEST_CASE("List: Unique", "[List]") {
	SECTION("Doubles") {
		double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};
		std::list<double> mylist(mydoubles, mydoubles + 10);

		mylist.sort();                //  2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();            //  2.72, 3.14, 12.15, 12.77, 15.3,  72.25, 73.0,  73.35
		REQUIRE(mylist.size() == 8);
		REQUIRE(mylist.back() == 73.35);
		mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15, 15.3,  72.25, 73.0

		mylist.unique(is_near());           //  2.72, 12.15, 72.25
		REQUIRE(mylist.size() == 3);
		REQUIRE(mylist.back() == 72.25);

		// mylist contains: 2.72 12.15 72.25
	}

	SECTION("Only ones") {
		double myOnes[]={ 1, 1, 1, 1 };
		std::list<double> mylist (myOnes,myOnes+4);

		mylist.sort();

		mylist.unique();
		REQUIRE(mylist.size() == 1);
		REQUIRE(*mylist.begin() == 1);

		mylist.unique (same_integral_part);

		mylist.unique (is_near());
		REQUIRE(mylist.size() == 1);
		REQUIRE(*mylist.begin() == 1);
	}
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }
TEST_CASE("List: Merge", "[List]") {
	ft::list<double> first, second;
	ft::list<double>::iterator it;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	it = second.begin();
	double* ptr = &(*it);

	first.merge(second);
	// first contains: 1.4 2.2 2.9 3.1 3.7 7.1
	REQUIRE(first.size() == 6);
	REQUIRE(first.front() == 1.4);
	REQUIRE(first.back() == 7.1);
	it = first.begin();
	double* ptr2 = &(*it);
	REQUIRE(ptr == ptr2);
	std::advance(it, 4);
	REQUIRE(*it == 3.7);
	// (second is now empty)
	REQUIRE(second.empty() == true);

	second.push_back (2.1);

	first.merge(second,mycomparison);
	// first contains: 1.4 2.2 2.9 2.1 3.1 3.7 7.1
	REQUIRE(first.size() == 7);
	REQUIRE(first.front() == 1.4);
	REQUIRE(first.back() == 7.1);
	it = first.begin();
	std::advance(it, 3);
	REQUIRE(*it == 2.1);
	// (second is now empty)
	REQUIRE(second.empty() == true);
}

TEST_CASE("List: Reverse", "[List]") {
	ft::list<int> mylist;

	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.reverse();
	REQUIRE(mylist.size() == 9);
	REQUIRE(mylist.front() == 9);
	REQUIRE(mylist.back() == 1);
}

TEST_CASE("List: Relational operator overloads", "[List]") {
	ft::list<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	ft::list<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	ft::list<int> c;
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

TEST_CASE("list-Empty container constructor", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("list-Fill constructor", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-Range constructor", "[list]")
{
	ft::list<int>		own(6, 100);
	ft::list<int>		own2(own.begin(), own.end());
	std::list<int>		real(6, 100);
	std::list<int>		real2(real.begin(), real.end());

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	own_it = own2.begin();
	real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());

	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-Copy constructor", "[list]")
{
	ft::list<int>		own(6, 100);
	ft::list<int>		own2(own);
	std::list<int>		real(6, 100);
	std::list<int>		real2(real);


	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());
}

TEST_CASE("list-Assign content", "[list]")
{
	ft::list<int>		own(6, 100);
	ft::list<int>		own2;
	std::list<int>		real(6, 100);
	std::list<int>		real2;

	own2 = own;
	real2 = real;
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());
	
}

/* ------------ ITERATORS ------------ */
TEST_CASE("list-begin function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::iterator own_it = own.begin();
	std::list<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("list-const begin function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::const_iterator own_it = own.begin();
	std::list<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("list-end function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::iterator own_ite = own.end();
	std::list<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("list-const end function", "[list]")
{
	ft::list<int> 	own(4, 3);
	std::list<int> 	real(4, 3);
	
	ft::list<int>::const_iterator own_ite = own.end();
	std::list<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("list-rbegin function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::reverse_iterator own_rit = own.rbegin();
	ft::list<int>::reverse_iterator old_own_rit;
	std::list<int>::reverse_iterator real_rit = real.rbegin();
	std::list<int>::reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("list-const rbegin function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
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
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("list-rend function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::reverse_iterator own_rite = own.rend();
	ft::list<int>::reverse_iterator old_own_rite;
	std::list<int>::reverse_iterator real_rite = real.rend();
	std::list<int>::reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

TEST_CASE("list-const rend function", "[list]")
{
	int sum = 0;
	ft::list<int>		own(5);
	std::list<int>		real(5);

	for(int i = 0; i < 5; i++)
	{
		real.push_back(sum);
		own.push_back(sum);
		sum += 1;
	}
	
	ft::list<int>::const_reverse_iterator own_rite = own.rend();
	ft::list<int>::const_reverse_iterator old_own_rite;
	std::list<int>::const_reverse_iterator real_rite = real.rend();
	std::list<int>::const_reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

/* ------------ CAPACITY ------------ */

TEST_CASE("list-empty function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.empty() == real.empty());
	
	ft::list<int>	own2(5, 100);
	std::list<int>	real2(5, 100);

	real2.clear();
	own2.clear();
	
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("list-size function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	
	ft::list<int>	own2(5, 100);
	std::list<int>	real2(5, 100);

	REQUIRE(own.size() == real.size());

	real2.clear();
	own2.clear();
	
	REQUIRE(own.size() == real.size());
}

/* ------------ ELEMENT ACCESS ------------ */

TEST_CASE("list-front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 40;
	const int tim = 100;
	
	
	for (int i  = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	own.push_front(tim);
	real.push_front(tim);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	const int tim = 100;
	int sum = 40;
	
	
	for (int i  = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	own.push_back(tim);
	real.push_back(tim);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

/* ------------ MODIFIERS ------------ */
TEST_CASE("list-assign with iterators", "[list]")
{
	ft::list<int>		own1(5, 100);
	ft::list<int>		own2;
	std::list<int>		real1(5, 100);
	std::list<int>		real2;


	own2.assign(own1.begin(), own1.end());
	real2.assign(real1.begin(), real1.end());

	ft::list<int>::iterator own_it = own2.begin();
	std::list<int>::iterator real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-assign size n and type val")
{
	ft::list<int>	own;
	std::list<int>	real;
	own.assign(6, 100);
	real.assign(6, 100);
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-push_front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_front(sum);
		real.push_front(sum);
		sum += 11;
	}
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-pop_front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_front(sum);
		real.push_front(sum);
		sum += 11;
	}
	for (int i = 0; i < 5; ++i)
	{
		own.pop_front();
		real.pop_front();
	}
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-push_back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 11;
	}
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-pop_back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 11;
	}
	
	for (int i = 0; i < 5; ++i)
	{
		REQUIRE(own.back() == real.back());
		REQUIRE(own.size() == real.size());
		own.pop_back();
		real.pop_back();
	}
	
	own.push_back(2000);
	real.push_back(2000);
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	own.pop_back();
	real.pop_back();
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	
}

TEST_CASE("list-insert single element", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;

	own.insert(own_it, 1000);
	real.insert(real_it, 1000);
	
	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-insert fill", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;

	own.insert(own_it, 5, 1000);
	real.insert(real_it, 5, 1000);

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-insert range", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2(4, 2000);
	std::list<int>	real;
	std::list<int>	real2(4, 2000);

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;
	
	own.insert(own_it, own2.begin(), own2.end());
	real.insert(real_it, real2.begin(), real2.end());

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-erase single element", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	
	++own_it; ++own_it;
	++real_it; ++real_it;
	
	own.erase(own_it);
	real.erase(real_it);

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-erase range element", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 5;
	}

	ft::list<int>::iterator		own_it = own.begin();
	ft::list<int>::iterator		own_ite = own.end();
	
	std::list<int>::iterator	real_it = real.begin();
	std::list<int>::iterator	real_ite = real.end();
	
	++own_it; ++own_it;
	++real_it; ++real_it;
	
	own.erase(own_it, own_ite);
	real.erase(real_it, real_ite);

	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-swap ", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	ft::list<int>	own3;
	std::list<int>	real;
	std::list<int>	real2;
	std::list<int>	real3;
	int sum = 10;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 11;
	}
	own2.swap(own);
	real2.swap(real);
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.front() == real2.front());
	REQUIRE(own2.back() == real2.back());

	ft::swap(own3, own2);
	std::swap(real3, real2);

	REQUIRE(own3.size() == own3.size());
	REQUIRE(own3.empty() == own3.empty());
	REQUIRE(own3.front() == own3.front());
	REQUIRE(own3.back() == own3.back());

	
}

TEST_CASE("list-resize", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);
	REQUIRE(own.size() == real.size());
	
	own.resize(10, 200);
	real.resize(10, 200);
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	
	own.resize(4, 50);
	real.resize(4, 50);
	
	REQUIRE(own.back() == real.back());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.front() == real.front());
}

TEST_CASE("list-clear", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);
	
	int sum = 10;
	for (int i = 0; i < 2; ++i)
	{
		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());
		REQUIRE(own.front() == real.front());
		REQUIRE(own.back() == real.back());

		own.clear();
		real.clear();

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());
		REQUIRE(own.front() == real.front());
		REQUIRE(own.back() == real.back());

		own.assign(5, sum);
		real.assign(5, sum);
		sum += 123;
	}
}

/* ------------ OPERATIONS ------------ */

TEST_CASE("list-splice version 1", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;

	for (int i = 1; i < 5; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	for (int i = 5; i < 7; ++i)
	{
		own2.push_back(i); 
		real2.push_back(i);
	}
	
	own.splice(own.end(), own2);
	real.splice(real.end(), real2);

	
	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();

	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-splice version 2", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;

	for (int i = 1; i < 5; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	for (int i = 5; i < 7; ++i)
	{
		own2.push_back(i); 
		real2.push_back(i);
	}
	
	ft::list<int>::iterator		own_it = own2.begin();
	std::list<int>::iterator	real_it = real2.begin();
	
	own.splice(own.end(), own2, own_it);
	real.splice(real.end(), real2, real_it);
	
	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-splice version 3", "[list]")
{
	ft::list<int>	own;
	ft::list<int>	own2;
	std::list<int>	real;
	std::list<int>	real2;

	for (int i = 1; i < 5; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	for (int i = 5; i < 10; ++i)
	{
		own2.push_back(i); 
		real2.push_back(i);
	}
	
	ft::list<int>::iterator		own_it = own2.begin();
	ft::list<int>::iterator		own_ite = own2.end();

	std::list<int>::iterator	real_it = real2.begin();
	std::list<int>::iterator	real_ite = real2.end();
	
	own.splice(own.end(), own2, own_it, own_ite);
	real.splice(real.end(), real2, real_it, real_ite);
	
	own_it = own.begin();
	real_it = real.begin();

	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-remove", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	for (int i = 1; i < 10; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	} 
	
	own.remove(5);
	real.remove(5);

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
	for (int i = 1; i < 10; ++i)
	{
		own.push_back(100); 
		real.push_back(100);
	}

	own_it = own.begin();
	real_it = real.begin();
	
	own.remove(100);
	real.remove(100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-remove_if", "[list]")
{
	ft::list<int> own;
	std::list<int> real;

	for (int i = 1; i < 16; ++i)
	{
		own.push_back(i); 
		real.push_back(i);
	}

	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	own.remove_if(single_digit);           // 10 11 12 13 14 15 
	own.remove_if(is_odd());               // 10 12 14
	real.remove_if(single_digit);           // 10 11 12 13 14 15
	real.remove_if(is_odd());               // 10 12 14

	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-unique version 1", "[list]")
{
	ft::list<int> own;
	std::list<int> real;

	int suma = 1;
	int sumb = 1;

	
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(suma);
		own.push_back(sumb);
		real.push_back(suma);
		real.push_back(sumb);
		suma += 1;
		sumb += 1;
	}
	// 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10
	own.unique();
	real.unique();
	// 1 2 3 4 5 6 7 8 9 10
	ft::list<int>::iterator		own_it = own.begin();
	std::list<int>::iterator	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
	own.push_back(10); own.push_back(10); own.push_back(10);
	real.push_back(10); real.push_back(10); real.push_back(10);
	// 1 2 3 4 5 6 7 8 9 10 10 10 10 

	own.unique();
	real.unique();

	own_it = own.begin();
	real_it = real.begin();
	
	// 1 2 3 4 5 6 7 8 9 10
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}

	own.clear();
	real.clear();

	own.push_back(1);
	own.push_back(1);
	real.push_back(1);
	real.push_back(1);
	
	own.unique();
	real.unique();

	own_it = own.begin();
	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}

	own.clear();
	real.clear();
	
	own.push_back(1);
	real.push_back(1);
	
	own.unique();
	real.unique();

	own_it = own.begin();
	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	own.clear();
	real.clear();
	
	own.unique();
	real.unique();

	own_it = own.begin();
	real_it = real.begin();
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-unique version 2", "[list]")
{
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

	own.sort();
	real.sort();
	
	own.unique();
	real.unique();

	own.unique(same_integral_part);
	real.unique(same_integral_part);

	ft::list<double>::iterator		own_it = own.begin();
	std::list<double>::iterator		real_it = real.begin();

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}

	own.unique(is_near());
	real.unique(is_near());

	own_it = own.begin();
	real_it = real.begin();

	while (real_it != real.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	own_it = own.begin();
	real_it = real.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
	
}

TEST_CASE("list-merge version 1", "[list]")
{
	ft::list<double>	own1;
	ft::list<double>	own2;
	std::list<double>	real1; 
	std::list<double>	real2;

	own1.push_back (3.1);
	own1.push_back (2.2);
	own1.push_back (2.9);	
	own2.push_back (3.7);
	own2.push_back (7.1);
	own2.push_back (1.4);
	
	real1.push_back (3.1);
	real1.push_back (2.2);
	real1.push_back (2.9);	
	real2.push_back (3.7);
	real2.push_back (7.1);
	real2.push_back (1.4);
	
	own1.sort();
	own2.sort();
	real1.sort();
	real2.sort();	
	
	own1.merge(own2);
	real1.merge(real2);

	ft::list<double>::iterator		own_it = own1.begin();
	std::list<double>::iterator		real_it = real1.begin();
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own1.back() == real1.back());

	while (own_it != own1.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-merge version 2", "[list]")
{
	ft::list<double>	own1;
	ft::list<double>	own2;
	std::list<double>	real1; 
	std::list<double>	real2;

	own1.push_back (3.1);
	own1.push_back (2.2);
	own1.push_back (2.9);	
	own2.push_back (3.7);
	own2.push_back (7.1);
	own2.push_back (1.4);
	
	real1.push_back (3.1);
	real1.push_back (2.2);
	real1.push_back (2.9);	
	real2.push_back (3.7);
	real2.push_back (7.1);
	real2.push_back (1.4);
	
	own1.sort();
	own2.sort();
	real1.sort();
	real2.sort();	
	
	own1.merge(own2, mycomparison);
	real1.merge(real2, mycomparison);

	ft::list<double>::iterator		own_it = own1.begin();
	std::list<double>::iterator		real_it = real1.begin();
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own1.back() == real1.back());

	while (own_it != own1.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-sort version 1", "[list]")
{
	ft::list<std::string>	own;
	std::list<std::string>	real;
	
	real.push_back ("one");
	real.push_back ("two");
	real.push_back ("Three");

	own.push_back ("one");
	own.push_back ("two");
	own.push_back ("Three");

	real.sort();
	own.sort();

	std::list<std::string>::iterator	real_it = real.begin();
	ft::list<std::string>::iterator		own_it = own.begin();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-sort version 2", "[list]")
{
	ft::list<std::string>	own;
	std::list<std::string>	real;
	
	real.push_back ("one");
	real.push_back ("two");
	real.push_back ("Three");

	own.push_back ("one");
	own.push_back ("two");
	own.push_back ("Three");

	real.sort(compare_nocase);
	own.sort(compare_nocase);

	std::list<std::string>::iterator	real_it = real.begin();
	ft::list<std::string>::iterator		own_it = own.begin();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("list-reverse", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	for (int i = 0; i < 10; ++i) own.push_back(i);
	for (int i = 0; i < 10; ++i) real.push_back(i);

	own.reverse();
	real.reverse();
	
	std::list<int>::iterator	real_it = real.begin();
	ft::list<int>::iterator		own_it = own.begin();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());

	while (own_it != own.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

/* ------------ OBSERVERS ------------ */

TEST_CASE("list-get_allocator", "[list]")
{
	ft::list<int>		own;
	std::list<int>		real;

	int *p_own;
	int *p_real;
	bool own_return = false;
	bool real_return = false;
	unsigned int i_own;
	unsigned int i_real;

	// allocate an array with space for 5 elements using list's allocator:
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

/* ------------ RELATIONAL OPERATORS ------------ */

TEST_CASE("list-operation overloaders", "[list]")
{
	ft::list<int> 	own(4, 200);
	ft::list<int> 	own2(4, 100);
	ft::list<int> 	own3(4, 200);
	std::list<int>	real(4, 200);
	std::list<int>	real2(4, 100);
	std::list<int>	real3(4, 200);


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