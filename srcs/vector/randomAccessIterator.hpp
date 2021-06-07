#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP
# include <cstddef>
# include "../Traits.hpp"

namespace ft
{
	template <class T, class Pointer, class Reference,
	        class Category = ft::random_access_iterator_tag>
	class RandomAccessIterator {
	public:
		typedef	RandomAccessIterator<T, T*, T&>				this_type;
		typedef RandomAccessIterator<T, const T*, const T&>	const_type;
		typedef Category									iterator_category;
		typedef T											value_type;
		typedef ptrdiff_t									difference_type;
		typedef T*											pointer;
		typedef T&											reference;

	private:
		pointer _ptr;

	public:
		RandomAccessIterator() : _ptr(NULL)
		{}

		explicit RandomAccessIterator(pointer val) : _ptr(val)
		{}

		RandomAccessIterator(const RandomAccessIterator<T, Pointer, Reference> &og)
		{
			*this = og;
		}

		virtual ~RandomAccessIterator() {}

		RandomAccessIterator &
		operator=(const RandomAccessIterator<T, Pointer, Reference> &x)
		{
			_ptr = x._ptr;
			return (*this);
		}

		reference operator*() const
		{
			return (*_ptr);
		}

		pointer operator->() const
		{
			return &(*_ptr);
		}

		RandomAccessIterator &operator+=(const difference_type &n)
		{
			_ptr += n;
			return (*this);
		}

		RandomAccessIterator &operator-=(const difference_type &n)
		{
			_ptr -= n;
			return (*this);
		}

		RandomAccessIterator operator+(const difference_type &n) const
		{
			RandomAccessIterator<T, Pointer, Reference> tmp(*this);
			tmp._ptr += n;
			return (tmp);
		}

		difference_type operator-(RandomAccessIterator it) const
		{
			return (_ptr - it._ptr);
		}

		RandomAccessIterator operator-(const difference_type &n) const
		{
			RandomAccessIterator<T, Pointer, Reference> tmp(*this);
			tmp._ptr -= n;
			return (tmp);
		}

		RandomAccessIterator operator++(int)
		{
			RandomAccessIterator<T, Pointer, Reference> tmp(*this);
			_ptr++;
			return (tmp);
		}

		RandomAccessIterator operator--(int)
		{
			RandomAccessIterator<T, Pointer, Reference> tmp(*this);
			_ptr--;
			return (tmp);
		}

		RandomAccessIterator &operator++()
		{
			_ptr++;
			return (*this);
		}

		RandomAccessIterator &operator--()
		{
			_ptr--;
			return (*this);
		}

		bool operator==(RandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return (_ptr == rhs._ptr);
		}

		bool operator!=(RandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return !(*this == rhs);
		}

		bool operator<(RandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return ((rhs - *this) > 0);
		}

		bool operator>(RandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return (rhs < *this);
		}

		bool operator<=(RandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return !(rhs < *this);
		}

		bool operator>=(RandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return !(*this < rhs);
		}

		reference operator[](difference_type n) const
		{
			return (_ptr[n]);
		}

		operator RandomAccessIterator<T, const T*, const T&>() const
		{
			return RandomAccessIterator<T, const T*, const T&>(_ptr);
		}

		operator RandomAccessIterator<T, T*, T&>() const
		{
			return RandomAccessIterator<T, T*, T&>(_ptr);
		}

	};

	template <class T, class Pointer, class Reference,
	        class Category = ft::random_access_iterator_tag>
	class ReverseRandomAccessIterator {
	public:
		typedef	ReverseRandomAccessIterator<T, T*, T&>				this_type;
		typedef ReverseRandomAccessIterator<T, const T*, const T&>	const_type;
		typedef Category									iterator_category;
		typedef T											value_type;
		typedef ptrdiff_t									difference_type;
		typedef T*											pointer;
		typedef T&											reference;

	private:
		pointer _ptr;

	public:
		ReverseRandomAccessIterator() : _ptr(NULL){}

		explicit ReverseRandomAccessIterator(pointer val) : _ptr(val)
		{}

		ReverseRandomAccessIterator(const ReverseRandomAccessIterator<T, Pointer, Reference> &og)
		{
			*this = og;
		}

		virtual ~ReverseRandomAccessIterator() {}

		ReverseRandomAccessIterator &
		operator=(const ReverseRandomAccessIterator<T, Pointer, Reference> &x)
		{
			_ptr = x._ptr;
			return (*this);
		}

		reference operator*() const
		{
			return (*_ptr);
		}

		pointer operator->() const
		{
			return &(*_ptr);
		}

		ReverseRandomAccessIterator &operator+=(const difference_type &n)
		{
			_ptr -= n;
			return (*this);
		}

		ReverseRandomAccessIterator &operator-=(const difference_type &n)
		{
			_ptr += n;
			return (*this);
		}

		ReverseRandomAccessIterator operator+(const difference_type &n) const
		{
			ReverseRandomAccessIterator<T, Pointer, Reference> tmp(*this);
			tmp._ptr -= n;
			return (tmp);
		}

		difference_type operator-(ReverseRandomAccessIterator it) const
		{
			return (_ptr - it._ptr);
		}

		ReverseRandomAccessIterator operator-(const difference_type &n) const
		{
			ReverseRandomAccessIterator<T, Pointer, Reference> tmp(*this);
			tmp._ptr += n;
			return (tmp);
		}

		ReverseRandomAccessIterator operator++(int)
		{
			ReverseRandomAccessIterator<T, Pointer, Reference> tmp(*this);
			_ptr--;
			return (tmp);
		}

		ReverseRandomAccessIterator operator--(int)
		{
			ReverseRandomAccessIterator<T, Pointer, Reference> tmp(*this);
			_ptr++;
			return (tmp);
		}

		ReverseRandomAccessIterator &operator++()
		{
			_ptr--;
			return (*this);
		}

		ReverseRandomAccessIterator &operator--()
		{
			_ptr++;
			return (*this);
		}

		bool operator==(ReverseRandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return (_ptr == rhs._ptr);
		}

		bool operator!=(ReverseRandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return !(*this == rhs);
		}

		bool operator<(ReverseRandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return ((rhs - *this) > 0);
		}

		bool operator>(ReverseRandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return (rhs < *this);
		}

		bool operator<=(ReverseRandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return !(rhs < *this);
		}

		bool operator>=(ReverseRandomAccessIterator<T, Pointer, Reference> rhs)
		{
			return !(*this < rhs);
		}

		reference operator[](difference_type n) const
		{
			return (_ptr[-n]);
		}

		operator ReverseRandomAccessIterator<T, const T*, const T&>() const
		{
			return ReverseRandomAccessIterator<T, const T*, const T&>(_ptr);
		}

		operator ReverseRandomAccessIterator<T, T*, T&>() const
		{
			return ReverseRandomAccessIterator<T, T*, T&>(_ptr);
		}

	};

}
#endif