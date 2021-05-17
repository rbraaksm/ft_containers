/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Pair.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 14:35:23 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/05/04 16:37:56 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

# include <iostream>

namespace ft
{
	/* This class couples together a pair of values, 
	which may be of different types (T1 and T2). 
	The individual values can be accessed through 
	its public members first and second.*/
	template <class T1, class T2> 
	struct pair
	{
		typedef T1		first_type;
		typedef T2		second_type;
		/* ------------ MEMBER VARIABLES ------------ */

		T1				first;
		T2				second;
		/* ------------ MEMBER FUNCTIONS ------------ */

		/* EMPTY CONTAINER CONSTRUCTOR--> Constructs an empty 
		container, with no elements. */
		pair() : first(first_type()), second(second_type()) { return; }

		/* COPY CONSTRUCTOR--> Constructs a container with a 
		copy of each of the elements in x, in the same order. */
		template<class U, class V> 
		pair (const pair< U, V > &pr) : first(pr.first), second(pr.second) { return; }

		template<class U, class V>
		pair (pair< U, V > &pr) : first(pr.first), second(pr.second) { return; }
		
		pair (const pair &pr) : first(pr.first), second(pr.second) { return; }

		/* INITIALIZATION CONSTRUCTOR--> Constructs a container with a 
		copy of each of the elements in x, in the same order. */
		pair (const first_type& a, const second_type& b) : first(a), second(b) { return; }

		/* Assigns pr as the new content for the pair object
		Member first is assigned pr.first, and member second
		is assigned pr.second. */
		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return *this;
		}
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		pair<T1, T2> new_pair;

		new_pair.first = x;
		new_pair.second = y;

		return new_pair;
	}

	template <class T1, class T2>
	bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first != rhs.first && lhs.second != rhs.second;
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); 
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1, T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1, T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }

	template <class T1, class T2>
	bool operator>= (const pair<T1, T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

} // end of namespac ft

#endif