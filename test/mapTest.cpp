/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapTest.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: renebraaksma <renebraaksma@student.42.f      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 11:14:55 by sam           #+#    #+#                 */
/*   Updated: 2021/06/05 12:37:54 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Catch2.h"
#include "../srcs/map/map.hpp"

#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

TEST_CASE("Map: Constructors", "[Map]") {
	ft::map<char,int> first;

	// first['a']=10;
	// first['b']=30;
	// first['c']=50;
	// first['d']=70;

	// ft::map<char,int> second (first.begin(),first.end());

	// ft::map<char,int> third (second);

	// ft::map<char,int,classcomp> fourth;                 // class as Compare
	// fourth['a']=10;
	// fourth['b']=30;
	// fourth['c']=50;
	// fourth['d']=70;

	// bool(*fn_pt)(char,char) = fncomp;
	// ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	// fifth['a']=10;
	// fifth['b']=30;
	// fifth['c']=50;
	// fifth['d']=70;

	// REQUIRE(first['b'] == 30);
	// REQUIRE(first['c'] == 50);

	// REQUIRE(second['b'] == 30);
	// REQUIRE(second['c'] == 50);

	// REQUIRE(third['b'] == 30);
	// REQUIRE(third['c'] == 50);

	// REQUIRE(fourth['b'] == 30);
	// REQUIRE(fourth['c'] == 50);

	// REQUIRE(fifth['b'] == 30);
	// REQUIRE(fifth['c'] == 50);
}

// TEST_CASE("Map: Insert + empty + size", "[Map]") {
// 	ft::map<char,int> mymap;
// 	REQUIRE(mymap.empty() == true);
// 	// first insert function version (single parameter):
// 	mymap.insert ( ft::pair<char,int>('a',100) );
// 	mymap.insert ( ft::pair<char,int>('z',200) );

// 	ft::pair<ft::map<char,int>::iterator,bool> ret;
// 	ret = mymap.insert ( ft::pair<char,int>('z',500) );
// 	REQUIRE(ret.second == false);

// 	// second insert function version (with hint position):
// 	ft::map<char,int>::iterator it = mymap.begin();
// 	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
// 	mymap.insert (it, ft::pair<char,int>('c',400));	  // no max efficiency inserting
// 	REQUIRE(mymap.size() == 4);

// 	// third insert function version (range insertion):
// 	ft::map<char,int> anothermap;
// 	anothermap.insert(mymap.begin(), mymap.end());
// 	REQUIRE(mymap.size() == 4);
// }

// TEST_CASE("Map: Find", "[Map]") {
// 	ft::map<char,int> mymap;
// 	// first insert function version (single parameter):
// 	mymap.insert ( ft::pair<char,int>('a',100) );
// 	mymap.insert ( ft::pair<char,int>('z',200) );

// 	// second insert function version (with hint position):
// 	ft::map<char,int>::iterator it;
// 	it = mymap.find('a');
// 	bool res = it == mymap.begin();
// 	REQUIRE(res == true);
// 	it = mymap.find('x');
// 	res = it == mymap.end();
// 	REQUIRE(res == true);
// }

// TEST_CASE("Map: Iterators", "[Map]") {
// 	ft::map<int, int> myMap;

// 	myMap.insert(ft::make_pair(9, 9));
// 	myMap.insert(ft::make_pair(3, 3));
// 	myMap.insert(ft::make_pair(8, 8));
// 	myMap.insert(ft::make_pair(0, 0));
// 	myMap.insert(ft::make_pair(7, 7));
// 	myMap.insert(ft::make_pair(6, 6));
// 	myMap.insert(ft::make_pair(5, 5));
// 	myMap.insert(ft::make_pair(4, 4));
// 	myMap.insert(ft::make_pair(2, 2));
// 	myMap.insert(ft::make_pair(1, 1));

// 	ft::map<int, int>::iterator it = myMap.begin();
// 	for (int i = 0; i < 10; ++i) {
// 		REQUIRE(i == it->second);
// 		++it;
// 	}
// 	it = myMap.end();
// 	--it;
// 	for (int i = 9; i != 0; --i) {
// 		REQUIRE(i == it->second);
// 		--it;
// 	}
// 	ft::map<int, int>::reverse_iterator rit = myMap.rbegin();
// 	for (int i = 9; i != 0; --i) {
// 		REQUIRE(i == rit->second);
// 		++rit;
// 	}
// 	rit = myMap.rend();
// 	--rit;
// 	for (int i = 0; i < 10; ++i) {
// 		REQUIRE(i == rit->second);
// 		--rit;
// 	}
// }

// TEST_CASE("Map: Erase", "[Map]") {
// 	ft::map<char,int> mymap;
// 	ft::map<char,int>::iterator it;

// 	// insert some values:
// 	mymap.insert(ft::make_pair('a', 10));
// 	mymap.insert(ft::make_pair('b', 20));
// 	mymap.insert(ft::make_pair('c', 30));
// 	mymap.insert(ft::make_pair('d', 40));
// 	mymap.insert(ft::make_pair('e', 50));
// 	mymap.insert(ft::make_pair('f', 60));

// 	it=mymap.find('b');
// 	mymap.erase (it);                   // erasing by iterator

// 	mymap.erase ('c');                  // erasing by key

// 	it=mymap.find ('e');
// 	mymap.erase ( it, mymap.end() );    // erasing by range

// 	// show content:
// 	it=mymap.begin();
// 	REQUIRE(mymap.size() == 2);
// 	REQUIRE(it->second == 10);
// 	++it;
// 	REQUIRE(it->second == 40);
// }

// TEST_CASE("Map: [] overload", "[Map]") {
// 	ft::map<char,int> mymap;

// 	mymap['x'] = 100;
// 	mymap['y'] = 200;
// 	mymap['z'] = 300;

// 	REQUIRE(mymap['x'] == 100);
// 	REQUIRE(mymap['y'] == 200);
// 	REQUIRE(mymap['z'] == 300);
// }

// TEST_CASE("Map: Swap", "[Map]") {
// 	ft::map<char,int> foo,bar;
// 	ft::map<char,int>::iterator it;

// 	foo['x']=100;
// 	foo['y']=200;

// 	bar['a']=11;
// 	bar['b']=22;
// 	bar['c']=33;

// 	foo.swap(bar);

// 	REQUIRE(foo.size() == 3);
// 	REQUIRE(foo['a'] == 11);
// 	REQUIRE(foo['b'] == 22);
// 	REQUIRE(foo['c'] == 33);
// 	it = foo.begin();
// 	REQUIRE(it->second == 11);

// 	REQUIRE(bar.size() == 2);
// 	REQUIRE(bar['x'] == 100);
// 	REQUIRE(bar['y'] == 200);
// 	it = bar.begin();
// 	REQUIRE(it->second == 100);
// }

// TEST_CASE("Map: Count", "[Map]") {
// 	ft::map<char,int> mymap;

// 	mymap['x'] = 100;
// 	mymap['y'] = 200;
// 	mymap['z'] = 300;

// 	REQUIRE(mymap.count('x') == 1);
// 	REQUIRE(mymap.count('a') == 0);
// }

// TEST_CASE("Map: upper/lower bound", "[Map]") {
// 	ft::map<char,int> mymap;
// 	ft::map<char,int>::iterator itlow,itup;

// 	mymap['a']=20;
// 	mymap['b']=40;
// 	mymap['c']=60;
// 	mymap['d']=80;
// 	mymap['e']=100;

// 	itlow=mymap.lower_bound ('b');  // itlow points to b
// 	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
// 	REQUIRE(itlow->first == 'b');
// 	REQUIRE(itup->first == 'e');
// }

// TEST_CASE("Map: equal_range", "[Map]") {
// 	ft::map<char,int> mymap;

// 	mymap['a']=10;
// 	mymap['b']=20;
// 	mymap['c']=30;

// 	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
// 	ret = mymap.equal_range('b');

// 	REQUIRE(ret.first->first == 'b');
// 	REQUIRE(ret.second->first == 'c');
// }


// TEST_CASE("map-Empty container constructor", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// }

// TEST_CASE("map-Range constructor", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(sum, sum));
// 		real.insert(std::pair<int, int>(sum, sum));
// 		sum += 1;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::iterator	real_it = real.begin();
// 	ft::map<int, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	std::map<int, int>	real2(real.begin(), real.end());
// 	ft::map<int, int>	own2(own.begin(), own.end());

// 	REQUIRE(own2.size() == real2.size());
// 	REQUIRE(own2.empty() == real2.empty());

// 	real_it = real2.begin();
// 	own_it = own2.begin();
// 	while (own_it != own2.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-copy constructor", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(sum, sum));
// 		real.insert(std::pair<int, int>(sum, sum));
// 		sum += 1;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::iterator	real_it = real.begin();
// 	ft::map<int, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	std::map<int, int>	real2(real);
// 	ft::map<int, int>	own2(own);

// 	REQUIRE(own2.size() == real2.size());
// 	REQUIRE(own2.empty() == real2.empty());

// 	real_it = real2.begin();
// 	own_it = own2.begin();
// 	while (own_it != own2.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-assign content", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(sum, sum));
// 		real.insert(std::pair<int, int>(sum, sum));
// 		sum += 1;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::iterator	real_it = real.begin();
// 	ft::map<int, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	std::map<int, int>	real2;
// 	ft::map<int, int>	own2;

// 	own2 = own;
// 	real2 = real;

// 	REQUIRE(own2.size() == real2.size());
// 	REQUIRE(own2.empty() == real2.empty());

// 	real_it = real2.begin();
// 	own_it = own2.begin();
// 	while (own_it != own2.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// // /*-----------------ITERATORS-----------------*/
// TEST_CASE("map-begin function", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(sum, sum));
// 		real.insert(std::pair<int, int>(sum, sum));
// 		sum += 1;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::iterator	real_it = real.begin();
// 	ft::map<int, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-end function", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	int random = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(random, sum));
// 		real.insert(std::pair<int, int>(random, sum));
// 		sum += 1;
// 		random % 2 == 0 ? random += 4 : random *= 2;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::iterator	real_it = real.begin();
// 	ft::map<int, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	std::map<int, int>::iterator	real_ite = real.end();
// 	ft::map<int, int>::iterator		own_ite = own.end();

// 	--real_ite;
// 	--own_ite;
// 	--real_ite;
// 	--own_ite;
// 	own_it = own.begin();
// 	real_it = real.begin();
// 	while (real_it != real_ite)
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-rbegin function", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(sum, sum));
// 		real.insert(std::pair<int, int>(sum, sum));
// 		sum += 1;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::reverse_iterator	real_it = real.rbegin();
// 	ft::map<int, int>::reverse_iterator		own_it = own.rbegin();

// 	++real_it;
// 	++own_it;
// 	REQUIRE(real_it->first == own_it->first);
// 	REQUIRE(real_it->second == own_it->second);

// 	while (own_it != own.rend())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-rend function", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	int sum = 1;
// 	int random = 1;
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		own.insert(ft::pair<int, int>(random, sum));
// 		real.insert(std::pair<int, int>(random, sum));
// 		sum += 1;
// 		random % 2 == 0 ? random += 4 : random *= 2;
// 	}

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	std::map<int, int>::reverse_iterator	real_it = real.rbegin();
// 	ft::map<int, int>::reverse_iterator		own_it = own.rbegin();

// 	while (own_it != own.rend())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	std::map<int, int>::reverse_iterator	real_ite = real.rend();
// 	ft::map<int, int>::reverse_iterator		own_ite = own.rend();

// 	--real_ite;
// 	--own_ite;
// 	--real_ite;
// 	--own_ite;
// 	own_it = own.rbegin();
// 	real_it = real.rbegin();
// 	while (real_it != real_ite)
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// // /*-----------------CAPACITY-----------------*/
// TEST_CASE("map-empty function", "[map]")
// {
// 	ft::map<std::string, int>	own;
// 	std::map<std::string, int>	real;

// 	REQUIRE(own.empty() == real.empty());

// 	own.insert(ft::pair<std::string, int>("test", 1));
// 	real.insert(std::pair<std::string, int>("test", 1));

// 	REQUIRE(own.empty() == real.empty());
// }

// TEST_CASE("map-size function", "[map]")
// {
// 	ft::map<std::string, int>	own;
// 	std::map<std::string, int>	real;

// 	own.insert(ft::pair<std::string, int>("try", 1));
// 	own.insert(ft::pair<std::string, int>("to", 1));
// 	own.insert(ft::pair<std::string, int>("do", 1));
// 	own.insert(ft::pair<std::string, int>("this", 1));

// 	real.insert(std::pair<std::string, int>("try", 1));
// 	real.insert(std::pair<std::string, int>("to", 1));
// 	real.insert(std::pair<std::string, int>("do", 1));
// 	real.insert(std::pair<std::string, int>("this", 1));

// 	REQUIRE(own.size() == real.size());

// 	std::map<std::string, int>::iterator	real_it = real.begin();
// 	ft::map<std::string, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	own.erase("try");
// 	real.erase("try");

// 	REQUIRE(own.size() == real.size());

// 	own.erase("to");
// 	real.erase("to");

// 	REQUIRE(own.size() == real.size());

// 	own.erase("do");
// 	real.erase("do");

// 	REQUIRE(own.size() == real.size());

// 	own.erase("this");
// 	real.erase("this");

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// }

// TEST_CASE("map-max_size function", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	// REQUIRE(own.max_size() == real.max_size());
// }


// // /*-----------------ELEMENT ACCES-----------------*/
// TEST_CASE("map-operator[] function", "[map]")
// {
// 	ft::map<char,std::string> 	own;
// 	std::map<char,std::string> 	real;


// 	own['a'] = "an element";
// 	own['b'] = "another element";
// 	own['c'] = own['b'];
// 	real['a'] = "an element";
// 	real['b'] = "another element";
// 	real['c'] = real['b'];

// 	REQUIRE(own.size() == real.size());

// 	std::map<char, std::string>::iterator		real_it = real.begin();
// 	ft::map<char, std::string>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }


// // /*-----------------INSERT-----------------*/
// TEST_CASE("map-insert function first version single element", "[map]")
// {
// 	ft::map<char,int>	own;
// 	std::map<char,int>	real;


// 	// first insert function version (single parameter):
// 	own.insert ( ft::pair<char,int>('a',100) );
// 	own.insert ( ft::pair<char,int>('z',200) );
// 	real.insert ( std::pair<char,int>('a',100) );
// 	real.insert ( std::pair<char,int>('z',200) );

// 	ft::pair<ft::map<char,int>::iterator,bool> own_ret;
// 	std::pair<std::map<char,int>::iterator,bool> real_ret;

// 	own_ret = own.insert ( ft::pair<char,int>('z',500) );
// 	real_ret = real.insert ( std::pair<char,int>('z',500) );

// 	REQUIRE(own_ret.second == real_ret.second);

// 	std::map<char, int>::iterator		real_it = real.begin();
// 	ft::map<char, int>::iterator		own_it = own.begin();

// 	REQUIRE(own.size() == real.size());
// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-insert function second version with hint position", "[map]")
// {
// 	ft::map<char,int>	own;
// 	std::map<char,int>	real;


// 	// first insert function version (single parameter):
// 	own.insert ( ft::pair<char,int>('a',100) );
// 	own.insert ( ft::pair<char,int>('z',200) );
// 	real.insert ( std::pair<char,int>('a',100) );
// 	real.insert ( std::pair<char,int>('z',200) );

// 	ft::pair<ft::map<char,int>::iterator,bool> own_ret;
// 	std::pair<std::map<char,int>::iterator,bool> real_ret;

// 	own_ret = own.insert ( ft::pair<char,int>('z',500) );
// 	real_ret = real.insert ( std::pair<char,int>('z',500) );

// 	REQUIRE(own_ret.second == real_ret.second);


// 	std::map<char, int>::iterator		real_it = real.begin();
// 	ft::map<char, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	// second insert function version (with hint position):
// 	real_it = real.begin();
// 	own_it = own.begin();

// 	std::map<char, int>::iterator		real_it_return;
// 	ft::map<char, int>::iterator		own_it_return;

// 	own.insert(own_it, ft::pair<char,int>('b',300));
// 	own_it_return = own.insert(own_it, ft::pair<char,int>('c',400));
// 	real.insert(real_it, std::pair<char,int>('b',300));
// 	real_it_return = real.insert(real_it, std::pair<char,int>('c',400));

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own_it_return->first == real_it_return->first);
// 	REQUIRE(own_it_return->second == real_it_return->second);

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-insert function third version range insertion", "[map]")
// {
// 	ft::map<char,int>	own;
// 	std::map<char,int>	real;


// 	// first insert function version (single parameter):
// 	own.insert( ft::pair<char,int>('a',100) );
// 	own.insert( ft::pair<char,int>('z',200) );
// 	real.insert( std::pair<char,int>('a',100) );
// 	real.insert( std::pair<char,int>('z',200) );

// 	ft::pair<ft::map<char,int>::iterator,bool> own_ret;
// 	std::pair<std::map<char,int>::iterator,bool> real_ret;

// 	own_ret = own.insert ( ft::pair<char,int>('z',500) );
// 	real_ret = real.insert ( std::pair<char,int>('z',500) );

// 	REQUIRE(own_ret.second == real_ret.second);

// 	std::map<char, int>::iterator		real_it = real.begin();
// 	ft::map<char, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	// second insert function version (with hint position):
// 	real_it = real.begin();
// 	own_it = own.begin();

// 	std::map<char, int>::iterator		real_it_return;
// 	ft::map<char, int>::iterator		own_it_return;

// 	own.insert(own_it, ft::pair<char,int>('b',300));
// 	own_it_return = own.insert(own_it, ft::pair<char,int>('c',400));
// 	real.insert(real_it, std::pair<char,int>('b',300));
// 	real_it_return = real.insert(real_it, std::pair<char,int>('c',400));

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own_it_return->first == real_it_return->first);
// 	REQUIRE(own_it_return->second == real_it_return->second);

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	 // third insert function version (range insertion):
// 	ft::map<char,int> own2;
// 	std::map<char,int> real2;

// 	// case where a key_value already exists
// 	own2.insert( ft::pair<char,int>('a',100) );
// 	real2.insert( std::pair<char,int>('a',100) );

// 	// own2.insert(own.begin(), own.find('c'));
// 	own2.insert(own.begin(), own.find('c'));
// 	real2.insert(real.begin(), real.find('c'));

// 	real_it = real2.begin();
// 	own_it = own2.begin();

// 	REQUIRE(own2.size() == real2.size());

// 	while (own_it != own2.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-erase function version 1 erasing by iterator", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	std::map<char, int>::iterator		real_it;
// 	ft::map<char, int>::iterator		own_it;

// 	// insert some values:
// 	own['a'] = 10;
// 	own['b'] = 20;
// 	own['c'] = 30;
// 	own['d'] = 40;
// 	own['e'] = 50;
// 	own['f'] = 60;

// 	real['a'] = 10;
// 	real['b'] = 20;
// 	real['c'] = 30;
// 	real['d'] = 40;
// 	real['e'] = 50;
// 	real['f'] = 60;

// 	own_it = own.find('b');
// 	real_it = real.find('b');
// 	own.erase(own_it);                   // erasing by iterator
// 	real.erase(real_it);                   // erasing by iterator

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	REQUIRE(own.size() == real.size());

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-erase function version 2 erasing by key", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete only root
// 	own.insert(ft::pair<int, int>(6, 8));
// 	real.insert(std::pair<int, int>(6, 8));

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	own.erase(6);
// 	real.erase(6);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete root with one right child
// 	own.insert(ft::pair<int, int>(6, 8));
// 	own.insert(ft::pair<int, int>(10, 8));
// 	real.insert(std::pair<int, int>(6, 8));
// 	real.insert(std::pair<int, int>(10, 8));

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	own.erase(6);
// 	real.erase(6);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.erase(10);
// 	real.erase(10);

// 	// Delete root with one left Child
// 	own.insert(ft::pair<int, int>(6, 8));
// 	real.insert(std::pair<int, int>(6, 8));
// 	own.insert(ft::pair<int, int>(4, 8));
// 	real.insert(std::pair<int, int>(4, 8));

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	own.erase(6);
// 	real.erase(6);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.erase(4);
// 	real.erase(4);

// 	// Delete Root with 2 children
// 	own.insert(ft::pair<int, int>(15, 15));
// 	own.insert(ft::pair<int, int>(10, 10));
// 	own.insert(ft::pair<int, int>(20, 20));
// 	own.insert(ft::pair<int, int>(5, 5));
// 	own.insert(ft::pair<int, int>(19, 19));
// 	own.insert(ft::pair<int, int>(25, 25));
// 	own.insert(ft::pair<int, int>(13, 13));

// 	real.insert(std::pair<int, int>(15, 15));
// 	real.insert(std::pair<int, int>(10, 10));
// 	real.insert(std::pair<int, int>(20, 20));
// 	real.insert(std::pair<int, int>(5, 5));
// 	real.insert(std::pair<int, int>(19, 19));
// 	real.insert(std::pair<int, int>(25, 25));
// 	real.insert(std::pair<int, int>(13, 13));

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.erase(6);
// 	real.erase(6);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete a Leaf Node Max
// 	own.erase(25);
// 	real.erase(25);
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete a Leaf Node Min
// 	own.erase(5);
// 	real.erase(5);
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete with only one Son and is the Min Node
// 	own.erase(10);
// 	real.erase(10);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete with only one Son and is the Max Node
// 	own.erase(20);
// 	real.erase(20);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	own.insert(ft::pair<int, int>(15, 15));
// 	own.insert(ft::pair<int, int>(10, 10));
// 	own.insert(ft::pair<int, int>(20, 20));
// 	own.insert(ft::pair<int, int>(5, 5));
// 	own.insert(ft::pair<int, int>(19, 19));
// 	own.insert(ft::pair<int, int>(25, 25));
// 	own.insert(ft::pair<int, int>(13, 13));

// 	real.insert(std::pair<int, int>(15, 15));
// 	real.insert(std::pair<int, int>(10, 10));
// 	real.insert(std::pair<int, int>(20, 20));
// 	real.insert(std::pair<int, int>(5, 5));
// 	real.insert(std::pair<int, int>(19, 19));
// 	real.insert(std::pair<int, int>(25, 25));
// 	real.insert(std::pair<int, int>(13, 13));

// 	// Delete a node which has two sons
// 	own.erase(20);
// 	real.erase(20);

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// }

// TEST_CASE("map-erase function version 3 erasing by range", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	std::map<char, int>::iterator		real_it;
// 	ft::map<char, int>::iterator		own_it;

// 	// insert some values:
// 	own['a'] = 10;
// 	own['b'] = 20;
// 	own['c'] = 30;
// 	own['d'] = 40;
// 	own['e'] = 50;
// 	own['f'] = 60;

// 	real['a'] = 10;
// 	real['b'] = 20;
// 	real['c'] = 30;
// 	real['d'] = 40;
// 	real['e'] = 50;
// 	real['f'] = 60;

// 	own_it = own.find('b');
// 	real_it = real.find('b');
// 	own.erase(own_it);                   // erasing by iterator
// 	real.erase(real_it);                   // erasing by iterator

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	REQUIRE(own.size() == real.size());

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	own_it = own.find ('e');
// 	real_it = real.find('e');
// 	own.erase ( own_it, own.end() );    // erasing by range
// 	real.erase ( real_it, real.end() );    // erasing by range

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	REQUIRE(own.size() == real.size());

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-swap function", "[map]")
// {
// 	ft::map<char,int> own;
// 	ft::map<char,int> own2;
// 	ft::map<char,int> own3;

// 	std::map<char,int> real;
// 	std::map<char,int> real2;
// 	std::map<char,int> real3;

// 	own['x']=100;
// 	own['y']=200;

// 	own2['a']=11;
// 	own2['b']=22;
// 	own2['c']=33;

// 	real['x']=100;
// 	real['y']=200;

// 	real2['a']=11;
// 	real2['b']=22;
// 	real2['c']=33;

// 	own.swap(own2);
// 	real.swap(real2);

// 	REQUIRE(own.size() == real.size());

// 	std::map<char, int>::iterator		real_it = real.begin();
// 	ft::map<char, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-clear function", "[map]")
// {
// 	std::map<char,int>	real;
// 	ft::map<char,int>	own;


// 	own['x'] = 100;
// 	own['y'] = 200;
// 	own['z'] = 300;

// 	real['x'] = 100;
// 	real['y'] = 200;
// 	real['z'] = 300;

// 	REQUIRE(own.size() == real.size());

// 	std::map<char, int>::iterator		real_it = real.begin();
// 	ft::map<char, int>::iterator		own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	own.clear();
// 	real.clear();

// 	own['a'] = 1101;
// 	own['b'] = 2202;

// 	real['a'] = 1101;
// 	real['b'] = 2202;

// 	REQUIRE(own.size() == real.size());

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	while (own_it != own.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// // /*-----------------OBSERVERS-----------------*/
// TEST_CASE("map-key_comp function", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	ft::map<char,int>::key_compare own_compare = own.key_comp();
// 	std::map<char,int>::key_compare real_compare = real.key_comp();

// 	own['a'] = 100;
// 	own['b'] = 200;
// 	own['c'] = 300;

// 	real['a'] = 100;
// 	real['b'] = 200;
// 	real['c'] = 300;
// 	char highest_own = own.rbegin()->first;     // key value of last element
// 	char highest_real = real.rbegin()->first;     // key value of last element

// 	REQUIRE(own_compare(own.begin()->first, highest_own) == real_compare(real.begin()->first, highest_real) );
// }

// TEST_CASE("map-value_comp function", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	ft::map<char,int>::iterator own_it = own.begin();
// 	std::map<char,int>::iterator real_it = real.begin();

// 	own['a'] = 100;
// 	own['b'] = 200;
// 	own['c'] = 300;

// 	real['a'] = 100;
// 	real['b'] = 200;
// 	real['c'] = 300;
// 	ft::pair<char, int> highest_own = *own.rbegin();    // key value of last element
// 	std::pair<char, int> highest_real = *real.rbegin();     // key value of last element

// 	REQUIRE(own.value_comp()(*own_it, highest_own) == real.value_comp()(*real_it, highest_real) );
// }

// // /*-----------------OPERATIONS-----------------*/
// TEST_CASE("map-find function", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	ft::map<char,int>::iterator own_it;
// 	std::map<char,int>::iterator real_it;

// 	own['a'] = 50;
// 	own['b'] = 100;
// 	own['c'] = 150;
// 	own['d'] = 1233;
// 	own['e'] = 533;
// 	own['f'] = 1876;
// 	own['g'] = 1928;
// 	own['h'] = 4887;

// 	real['a'] = 50;
// 	real['b'] = 100;
// 	real['c'] = 150;
// 	real['d'] = 1233;
// 	real['e'] = 533;
// 	real['f'] = 1876;
// 	real['g'] = 1928;
// 	real['h'] = 4887;

// 	own_it = own.find('b');
// 	real_it = real.find('b');
// 	if (own_it != own.end() && real_it != real.end())
// 	{
// 		real.erase(real_it);
// 		own.erase(own_it);
// 	}
// 	own_it = own.find('f');
// 	real_it = real.find('f');

// 	own.erase(own_it, own.end());
// 	real.erase(real_it, real.end());

// 	real_it = real.begin();
// 	own_it = own.begin();

// 	REQUIRE(own.size() == real.size());

// 	while (real_it != real.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}
// }

// TEST_CASE("map-count function", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	own['a'] = 50;
// 	own['b'] = 100;
// 	own['c'] = 150;
// 	own['d'] = 1233;
// 	own['e'] = 533;
// 	own['f'] = 1876;
// 	own['g'] = 1928;
// 	own['h'] = 4887;

// 	real['a'] = 50;
// 	real['b'] = 100;
// 	real['c'] = 150;
// 	real['d'] = 1233;
// 	real['e'] = 533;
// 	real['f'] = 1876;
// 	real['g'] = 1928;
// 	real['h'] = 4887;

// 	ft::map<char,int>::iterator own_it = own.begin();
// 	std::map<char,int>::iterator real_it = real.begin();

// 	REQUIRE(own.size() == real.size());

// 	while (real_it != real.end())
// 	{
// 		REQUIRE(own_it->first == real_it->first);
// 		REQUIRE(own_it->second == real_it->second);
// 		++own_it;
// 		++real_it;
// 	}

// 	REQUIRE(own.count('a') == real.count('a'));
// 	REQUIRE(own.count('b') == real.count('b'));

// 	own_it = own.find('b');
// 	real_it = real.find('b');

// 	if (own_it != own.end() && real_it != real.end())
// 	{
// 		real.erase(real_it);
// 		own.erase(own_it);
// 	}

// 	REQUIRE(own.count('b') == real.count('b'));
// 	REQUIRE(own.count('z') == real.count('z'));

// }

// TEST_CASE("map-lower_bound function", "[map]")
// {
// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	ft::map<char,int>::iterator			own_itlow;
// 	ft::map<char,int>::const_iterator	own_itlow_const;
// 	std::map<char,int>::iterator		real_itlow;
// 	std::map<char,int>::const_iterator	real_itlow_const;

// 	own['a'] = 20;
// 	own['b'] = 40;
// 	own['c'] = 60;
// 	own['d'] = 80;
// 	own['e'] = 100;

// 	real['a'] = 20;
// 	real['b'] = 40;
// 	real['c'] = 60;
// 	real['d'] = 80;
// 	real['e'] = 100;

// 	own_itlow = own.lower_bound('b');
// 	real_itlow = real.lower_bound('b');

// 	REQUIRE(own_itlow->first == real_itlow->first);
// 	REQUIRE(own_itlow->second == real_itlow->second);

// 	own_itlow = own.lower_bound('c');
// 	real_itlow = real.lower_bound('c');

// 	REQUIRE(own_itlow->first == real_itlow->first);
// 	REQUIRE(own_itlow->second == real_itlow->second);

// 	own_itlow_const = own_itlow;
// 	real_itlow_const = real.lower_bound('a');

// 	// REQUIRE(own_itlow_const->first == real_itlow_const->first);
// 	// REQUIRE(own_itlow_const->second == real_itlow_const->second);

// 	// own.erase('b');
// 	// real.erase('b');

// 	// own_itlow = own.lower_bound('b');
// 	// real_itlow = real.lower_bound('b');


// 	// REQUIRE(own_itlow->first == real_itlow->first);
// 	// REQUIRE(own_itlow->second == real_itlow->second);

// 	// own_itlow_const = own.lower_bound('b');
// 	// real_itlow_const = real.lower_bound('b');

// 	// REQUIRE(own_itlow_const->first == real_itlow_const->first);
// 	// REQUIRE(own_itlow_const->second == real_itlow_const->second);

// }

// TEST_CASE("map-upper_bound function", "[map]")
// {

// 	ft::map<char,int> own;
// 	std::map<char,int> real;

// 	ft::map<char,int>::iterator			own_itup;
// 	ft::map<char,int>::const_iterator	own_itup_const;
// 	std::map<char,int>::iterator		real_itup;
// 	std::map<char,int>::const_iterator	real_itup_const;

// 	own['a'] = 20;
// 	own['b'] = 40;
// 	own['c'] = 60;
// 	own['d'] = 80;
// 	own['e'] = 100;

// 	real['a'] = 20;
// 	real['b'] = 40;
// 	real['c'] = 60;
// 	real['d'] = 80;
// 	real['e'] = 100;

// 	own_itup = own.upper_bound('b');
// 	real_itup = real.upper_bound('b');

// 	REQUIRE(own_itup->first == real_itup->first);
// 	REQUIRE(own_itup->second == real_itup->second);

// 	own_itup = own.upper_bound('c');
// 	real_itup = real.upper_bound('c');

// 	REQUIRE(own_itup->first == real_itup->first);
// 	REQUIRE(own_itup->second == real_itup->second);

// 	own_itup_const = own.upper_bound('a');
// 	real_itup_const = real.upper_bound('a');

// 	REQUIRE(own_itup_const->first == real_itup_const->first);
// 	REQUIRE(own_itup_const->second == real_itup_const->second);

// 	own.erase('d');
// 	real.erase('d');

// 	own_itup = own.upper_bound('c');
// 	real_itup = real.upper_bound('c');

// 	REQUIRE(own_itup->first == real_itup->first);
// 	REQUIRE(own_itup->second == real_itup->second);

// 	own_itup_const = own.upper_bound('c');
// 	real_itup_const = real.upper_bound('c');

// 	REQUIRE(own_itup_const->first == real_itup_const->first);
// 	REQUIRE(own_itup_const->second == real_itup_const->second);

// }

// TEST_CASE("map-equal range function", "[map]")
// {
// 	std::map<char,int>	real;
// 	ft::map<char,int>	own;


// 	own['a'] = 20;
// 	own['b'] = 40;
// 	own['c'] = 60;
// 	own['d'] = 80;
// 	own['e'] = 100;

// 	real['a'] = 20;
// 	real['b'] = 40;
// 	real['c'] = 60;
// 	real['d'] = 80;
// 	real['e'] = 100;

// 	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator>	real_ret;
// 	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator>		own_ret;

// 	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator>	real_ret_const;
// 	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator>		own_ret_const;

// 	own_ret = own.equal_range('b');
// 	real_ret = real.equal_range('b');

// 	REQUIRE(own_ret.first->first == real_ret.first->first);
// 	REQUIRE(own_ret.first->second == real_ret.first->second);
// 	REQUIRE(own_ret.second->first == real_ret.second->first);
// 	REQUIRE(own_ret.second->second == real_ret.second->second);


// 	real_ret_const = real.equal_range('d');
// 	own_ret_const = own.equal_range('d');

// 	REQUIRE(own_ret_const.first->first == real_ret_const.first->first);
// 	REQUIRE(own_ret_const.first->second == real_ret_const.first->second);
// 	REQUIRE(own_ret_const.second->first == real_ret_const.second->first);
// 	REQUIRE(own_ret_const.second->second == real_ret_const.second->second);

// 	own.erase('b');
// 	real.erase('b');

// 	own_ret = own.equal_range('b');
// 	real_ret = real.equal_range('b');

// 	REQUIRE(own_ret.first->first == real_ret.first->first);
// 	REQUIRE(own_ret.first->second == real_ret.first->second);
// 	REQUIRE(own_ret.second->first == real_ret.second->first);
// 	REQUIRE(own_ret.second->second == real_ret.second->second);
// }