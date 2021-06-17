#include "Catch2.h"

#include "Queue.hpp"
#include <deque>
#include <queue>
#include <list>

TEST_CASE("Queue: Constructor", "[Queue]") {
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::list<int> mylist (2,200);        // list with 2 elements

	ft::queue<int> first;                    // empty queue
	ft::queue<int> second (mylist);         // queue initialized to copy of deque

	ft::queue<int,ft::list<int> > third;  // empty queue using list
	ft::queue<int,std::deque<int> > fourth (mydeque);
}

TEST_CASE("Queue: Size() + Empty()", "[Queue]") {
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::list<int> mylist (2,200);        // list with 2 elements

	ft::queue<int> first;             // empty queue
	ft::queue<int,ft::list<int> > second;  // empty queue using list
	ft::queue<int,std::deque<int> > third (mydeque);

	REQUIRE(first.empty() == true);
	REQUIRE(second.empty() == true);
	REQUIRE(third.size() == 3);
}

TEST_CASE("Queue: Back()", "[Queue]") {
	ft::list<int> mylist;

	// set some initial content:
	for (int i=1;i<6;i++) mylist.push_back(i);
	ft::queue<int,ft::list<int> > myqueue (mylist);
	myqueue.back() += 5;
	REQUIRE(myqueue.back() == 10);
}

TEST_CASE("Queue: Front()", "[Queue]") {
	ft::list<int> mylist;

	// set some initial content:
	for (int i=1;i<6;i++) mylist.push_back(i);
	ft::queue<int,ft::list<int> > myqueue (mylist);
	myqueue.front() += 5;
	REQUIRE(myqueue.front() == 6);
}

TEST_CASE("Queue: Push() + Pop()", "[Queue]") {
	ft::queue<int> myqueue;

	for (int i=0; i<5; ++i) myqueue.push(i);
	int i = 0;
	while (!myqueue.empty())
	{
		REQUIRE(myqueue.front() == i);
		myqueue.pop();
		i++;
	}
}

TEST_CASE("Queue: Relational operator overloads", "[Queue]") {
	ft::queue<int> a;
	a.push(10);
	a.push(20);
	a.push(30);
	ft::queue<int> b;
	b.push(10);
	b.push(20);
	b.push(30);
	ft::queue<int> c;
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

/*-----------------MEMBER FUNCTIONS-----------------*/

TEST_CASE("queue-Empty container constructor", "[queue]")
{
	std::list<int> real_list;
	ft::list<int> own_list;

	std::deque<int> real_deck(5, 100);

	std::queue<int> real1;                 // empty queue
	std::queue<int> real2(real_deck);       // queue initialized to copy of deque
	std::queue<int,std::list<int> > real3; // empty queue with list as underlying container
	std::queue<int,std::list<int> > real4(real_list);

	ft::queue<int,ft::list<int> > own3; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own4(own_list);

	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
}

TEST_CASE("queue-Copy Constructor", "[queue]")
{
	std::list<int> 					real_list1(2,200);         // list with 2 elements
	ft::list<int> 					own_list1(2,200);         // list with 2 elements

	std::queue<int,std::list<int> > real1(real_list1);
	ft::queue<int,ft::list<int> >	own1(own_list1);

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own1.back() == real1.back());
}

TEST_CASE("queue-empty function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());

	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);

	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());

	while (!own_queue.size())
	{
		own_queue.pop();
		real_queue.pop();
	}
	while (!own1.size())
	{
		own1.pop();
		real1.pop();
	}
	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());
}

TEST_CASE("queue-size function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	REQUIRE(own_queue.size() == real_queue.size());
	REQUIRE(own1.size() == real1.size());

	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);

	REQUIRE(own_queue.size() == real_queue.size());
	REQUIRE(own1.size() == real1.size());
}

TEST_CASE("queue-front function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	real_queue.push(100);
	own_queue.push(100);
	own1.push(100);
	real1.push(100);

	REQUIRE(own_queue.front() == real_queue.front());
	REQUIRE(own1.front() == real1.front());

	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);

	REQUIRE(own_queue.front() == real_queue.front());
	REQUIRE(own1.front() == real1.front());
}

TEST_CASE("queue-back function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	real_queue.push(100);
	own_queue.push(100);
	own1.push(100);
	real1.push(100);

	REQUIRE(own_queue.back() == real_queue.back());
	REQUIRE(own1.back() == real1.back());

	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);

	REQUIRE(own_queue.back() == real_queue.back());
	REQUIRE(own1.back() == real1.back());
}

TEST_CASE("queue-push function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	int sum = 10;

	for (int i = 0; i < 10; ++i)
	{
		own_queue.push(sum);
		real_queue.push(sum);
		own1.push(sum);
		real1.push(sum);
		sum += 13;
	}
	REQUIRE(own_queue.back() == real_queue.back());
	REQUIRE(own1.back() == real1.back());
	REQUIRE(own_queue.front() == real_queue.front());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own_queue.size() == real_queue.size());
	REQUIRE(own1.size() == real1.size());

	while (!own_queue.size())
	{
		REQUIRE(own_queue.front() == real_queue.front());
		REQUIRE(own1.front() == real1.front());
		own_queue.pop();
		real_queue.pop();
		own1.pop();
		real1.pop();
	}
	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());
}

/* ------------ RELATIONAL OPERATORS ------------ */

TEST_CASE("queue-relational operators", "[queue]")
{
	ft::queue<int> own_queue1;
	ft::queue<int> own_queue2;
	ft::queue<int> own_queue3;

	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own2; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own3; // empty queue with list as underlying container

	int sum = 10;

	for (int i = 0; i < 10; ++i)
	{
		own_queue1.push(sum);
		own_queue2.push(sum);
		own1.push(sum);
		own2.push(sum);
		sum += 13;
	}
	while (!own_queue1.size())
	{
		own_queue1.pop();
		own_queue2.pop();
		own1.pop();
		own2.pop();
	}
	own_queue3.push(2000);
	own3.push(2000);
	REQUIRE((own1 == own2) == true);
	REQUIRE((own2 == own3) == false);
	REQUIRE((own_queue1 == own_queue2) == true);
	REQUIRE((own_queue2 == own_queue3) == false);

	REQUIRE((own1 != own2) == false);
	REQUIRE((own2 != own3) == true);
	REQUIRE((own_queue1 != own_queue2) == false);
	REQUIRE((own_queue2 != own_queue3) == true);

	REQUIRE((own1 < own2) == false);
	REQUIRE((own_queue2 < own_queue1) == false);
	REQUIRE((own1 < own3) == true);
	REQUIRE((own_queue2 < own_queue3) == true);

	REQUIRE((own1 <= own2) == true);
	REQUIRE((own_queue2 <= own_queue1) == true);
	REQUIRE((own1 <= own3) == true); //
	REQUIRE((own_queue2 <= own_queue3) == true); //

	REQUIRE((own1 >= own2) == true);
	REQUIRE((own_queue2 >= own_queue1) == true);
	REQUIRE((own1 > own3) == false);
	REQUIRE((own_queue2 > own_queue3) == false);

	REQUIRE((own1 >= own2) == true);
	REQUIRE((own_queue2 >= own_queue1) == true);
	REQUIRE((own1 > own3) == false);
	REQUIRE((own_queue2 > own_queue3) == false);
}