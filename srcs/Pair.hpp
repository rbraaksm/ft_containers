#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1		first_type;
		typedef T2		second_type;
		T1				first;
		T2				second;

		pair() : first(first_type()), second(second_type()){}

		template<class U, class V>
		pair (const pair< U, V > &pr) : first(pr.first), second(pr.second){}

		template<class U, class V>
		pair (pair< U, V > &pr) : first(pr.first), second(pr.second){}
		pair (const pair &pr) : first(pr.first), second(pr.second){}
		pair (const first_type& a, const second_type& b) : first(a), second(b){}

		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		pair<T1, T2> new_pair;

		new_pair.first = x;
		new_pair.second = y;

		return (new_pair);
	}

	template <class T1, class T2>
	bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return (lhs.first == rhs.first && lhs.second == rhs.second);}

	template <class T1, class T2>
	bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return (lhs.first != rhs.first && lhs.second != rhs.second);}

	template <class T1, class T2>
	bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));}

	template <class T1, class T2>
	bool operator<= (const pair<T1, T2>& lhs, const pair<T1,T2>& rhs){return !(rhs < lhs);}

	template <class T1, class T2>
	bool operator>  (const pair<T1, T2>& lhs, const pair<T1,T2>& rhs){return (rhs < lhs);}

	template <class T1, class T2>
	bool operator>= (const pair<T1, T2>& lhs, const pair<T1,T2>& rhs){return !(lhs < rhs);}
}

#endif
