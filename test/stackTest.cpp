#include "Catch2.h"

#include "../srcs/Stack.hpp"
#include "../srcs/List.hpp"
#include "../srcs/Vector.hpp"

#include <list>
#include <vector>
#include <stack>
#include <deque>

TEST_CASE("Stack: Constructor", "[Stack]") {
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack
	ft::stack<int> second (myvector);        // stack initialized to copy of deque

	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,std::deque<int> > fourth (mydeque);
}

TEST_CASE("Stack: Size() + Empty()", "[Stack]") {
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;               // empty stack

	ft::stack<int,ft::vector<int> > second;  // empty stack using vector
	ft::stack<int,std::deque<int> > third (mydeque);

	REQUIRE(first.empty() == true);
	REQUIRE(second.empty() == true);
	REQUIRE(third.size() == 3);
}

TEST_CASE("Stack: Top()", "[Stack]") {
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<6;i++) myvector.push_back(i);
	ft::stack<int,ft::vector<int> > mystack (myvector);
	mystack.top() += 5;
	REQUIRE(mystack.top() == 10);
}

TEST_CASE("Stack: Push() + Pop()", "[Stack]") {
	ft::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);
	int i = 4;
	while (!mystack.empty())
	{
		REQUIRE(mystack.top() == i);
		mystack.pop();
		i--;
	}
}

TEST_CASE("Stack: Relational operator overloads", "[Stack]") {
	ft::stack<int> a;
	a.push(10);
	a.push(20);
	a.push(30);
	ft::stack<int> b;
	b.push(10);
	b.push(20);
	b.push(30);
	ft::stack<int> c;
	c.push(30);
	c.push(20);
	c.push(10);

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

TEST_CASE("stack-Empty container constructor", "[stack]")
{
	std::list<int>		real_list(5, 100);
	std::vector<int>	real_vector(3, 100);

	ft::list<int>		own_list(5, 100);
	ft::vector<int>		own_vector(3, 100);


	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	ft::stack<int,ft::list<int> > own5(own_list);

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
	REQUIRE(own5.top() == real5.top());
}

TEST_CASE("stack-empty function", "[stack]")
{
	std::vector<int> real_vector;
	ft::vector<int> own_vector;

	std::list<int> real_list;
	ft::list<int> own_list;


	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	ft::stack<int,ft::list<int> > own5(own_list);

	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own3.empty() == real3.empty());
	REQUIRE(own4.empty() == real4.empty());
	REQUIRE(own5.empty() == real5.empty());

	own1.push(1);
	own2.push(1);
	own3.push(1);
	own4.push(1);
	own5.push(1);
	real1.push(1);
	real2.push(1);
	real3.push(1);
	real4.push(1);
	real5.push(1);

	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own3.empty() == real3.empty());
	REQUIRE(own4.empty() == real4.empty());
	REQUIRE(own5.empty() == real5.empty());

	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own3.empty() == real3.empty());
	REQUIRE(own4.empty() == real4.empty());
	REQUIRE(own5.empty() == real5.empty());
}

TEST_CASE("stack-size function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);


	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	ft::stack<int,ft::list<int> > own5(own_list);

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());

	own1.push(1);
	own2.push(1);
	own3.push(1);
	own4.push(1);
	own5.push(1);
	real1.push(1);
	real2.push(1);
	real3.push(1);
	real4.push(1);
	real5.push(1);

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());

	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

TEST_CASE("stack-top function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);


	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3(real_vector);
	std::stack<int,std::vector<int> > real4(real_vector);
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;
	ft::stack<int,ft::vector<int> > own3(own_vector);
	ft::stack<int,ft::vector<int> > own4(own_vector);
	ft::stack<int,ft::list<int> > own5(own_list);


	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	own1.push(1);
	own2.push(1);
	own3.push(1);
	own4.push(1);
	own5.push(1);
	real1.push(1);
	real2.push(1);
	real3.push(1);
	real4.push(1);
	real5.push(1);

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

TEST_CASE("stack-push function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);


	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3(real_vector);
	std::stack<int,std::vector<int> > real4(real_vector);
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;
	ft::stack<int,ft::vector<int> > own3(own_vector);
	ft::stack<int,ft::vector<int> > own4(own_vector);
	ft::stack<int,ft::list<int> > own5(own_list);

	int sum = 22;

	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	for (int i = 0; i < 10; ++i)
	{
		own1.push(sum);
		own2.push(sum);
		own3.push(sum);
		own4.push(sum);
		own5.push(sum);
		real1.push(sum);
		real2.push(sum);
		real3.push(sum);
		real4.push(sum);
		real5.push(sum);
		sum += 14;
	}

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());


	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

TEST_CASE("stack-pop function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);


	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3(real_vector);
	std::stack<int,std::vector<int> > real4(real_vector);
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;
	ft::stack<int,ft::vector<int> > own3(own_vector);
	ft::stack<int,ft::vector<int> > own4(own_vector);
	ft::stack<int,ft::list<int> > own5(own_list);

	int sum = 22;

	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	for (int i = 0; i < 10; ++i)
	{
		own1.push(sum);
		own2.push(sum);
		own3.push(sum);
		own4.push(sum);
		own5.push(sum);
		real1.push(sum);
		real2.push(sum);
		real3.push(sum);
		real4.push(sum);
		real5.push(sum);
		sum += 14;
	}

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	for (int i = 0; i < 5; ++i)
	{
		own1.pop();
		own2.pop();
		own3.pop();
		own4.pop();
		own5.pop();
		real1.pop();
		real2.pop();
		real3.pop();
		real4.pop();
		real5.pop();
	}

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

/* ------------ RELATIONAL OPERATORS ------------ */

TEST_CASE("stack-relational operators", "[stack]")
{
	ft::stack<int> own_stack1;
	ft::stack<int> own_stack2;
	ft::stack<int> own_stack3;

	ft::stack<int,ft::list<int> > own_list1; // empty stack with list as underlying container
	ft::stack<int,ft::list<int> > own_list2; // empty stack with list as underlying container
	ft::stack<int,ft::list<int> > own_list3; // empty stack with list as underlying container
	ft::stack<int,ft::vector<int> > own_vector1; // empty stack with vector as underlying container
	ft::stack<int,ft::vector<int> > own_vector2; // empty stack with vector as underlying container
	ft::stack<int,ft::vector<int> > own_vector3; // empty stack with vector as underlying container

	int sum = 10;

	for (int i = 0; i < 10; ++i)
	{
		own_stack1.push(sum);
		own_stack2.push(sum);
		own_list1.push(sum);
		own_list2.push(sum);
		own_vector1.push(sum);
		own_vector2.push(sum);

		sum += 13;
	}
	while (!own_stack1.size())
	{
		own_stack1.pop();
		own_stack2.pop();
		own_list1.pop();
		own_list2.pop();
		own_vector1.pop();
		own_vector2.pop();
	}
	own_stack3.push(2000);
	own_list3.push(2000);
	own_vector3.push(2000);

	REQUIRE((own_list1 == own_list2) == true);
	REQUIRE((own_list2 == own_list3) == false);
	REQUIRE((own_vector1 == own_vector2) == true);
	REQUIRE((own_vector2 == own_vector3) == false);
	REQUIRE((own_stack1 == own_stack2) == true);
	REQUIRE((own_stack2 == own_stack3) == false);

	REQUIRE((own_list1 != own_list2) == false);
	REQUIRE((own_list2 != own_list3) == true);
	REQUIRE((own_vector1 != own_vector2) == false);
	REQUIRE((own_vector2 != own_vector3) == true);
	REQUIRE((own_stack1 != own_stack2) == false);
	REQUIRE((own_stack2 != own_stack3) == true);

	REQUIRE((own_list1 < own_list2) == false);
	REQUIRE((own_list1 < own_list3) == true);
	REQUIRE((own_vector1 < own_vector2) == false);
	REQUIRE((own_vector1 < own_vector3) == true);
	REQUIRE((own_stack2 < own_stack1) == false);
	REQUIRE((own_stack2 < own_stack3) == true);

}