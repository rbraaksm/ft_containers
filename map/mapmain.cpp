#include "map.hpp"

#include <map>

	bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int	main(void){
	ft::map<int,int> first;
	// ft::map<char,int> first;

	first[10]=10;
	first[17]=10;
	// first[2]=30;
	// first[1]=30;
	// first[5]=30;
	// first[14]=30;
	// first[16]=50;
	// first[15]=70;
	// first[18]=20;
	// first[17]=70;

	// first.insert(ft::pair<char,int>(9, 30));
	ft::map<int,int>::iterator it = first.begin();
	first.print_tree();
	first.erase(it);
	first.print_tree();
	// first[12]=10;
	// first.print_tree();

//   std::map<char,int> first;

//   first['a']=10;
//   first['b']=30;
//   first['c']=50;
//   first['d']=70;

//   std::map<char,int> second (first.begin(),first.end());

//   std::map<char,int> third (second);

//   std::map<char,int,classcomp> fourth;                 // class as Compare

//   bool(*fn_pt)(char,char) = fncomp;
//   std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	// system("leaks a.out");
	return (0);
}
