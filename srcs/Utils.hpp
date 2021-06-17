#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft{
	template <typename U>
	void swap(U& x, U& y) {
		U tmp = x;
		x = y;
		y = tmp;
	}

	template <class Iterator1, class Iterator2>
	bool equal(Iterator1 first1, Iterator1 last1, Iterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template<typename value_type>
	struct less: public ft::binary_function<value_type, value_type, bool> {
		bool	operator()(const value_type& x, const value_type& y) const {
			return (x < y);
		}
	};
}

#endif
