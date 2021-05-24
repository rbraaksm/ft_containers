#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../Traits.hpp"
# include "randomAccessIterator.hpp"
# include <memory>
# include <iterator>
# include <algorithm>

namespace ft{
    template < class T, class Alloc = std::allocator<T> >
    class vector{
        public:
		// member types //
            typedef T           	value_type;
            typedef Alloc       	allocator_type;
            typedef T          		&reference;
            typedef const T     	&const_reference;
            typedef T           	*pointer;
            typedef const T     	*const_pointer;

			typedef randomAccessIterator<value_type>			iterator;
			typedef constRandomAccessIterator<value_type>		const_iterator;
			typedef revRandomAccessIterator<value_type>			reverse_iterator;
			typedef constRevRandomAccessIterator<value_type>	const_reverse_iterator;

			typedef ptrdiff_t		difference_type;
			typedef size_t			size_type;

		private:
			template <typename U>
			void swap(U& x, U& y) {
				U tmp = x;
				x = y;
				y = tmp;
			}

			allocator_type	_allocator;
			pointer			_array;
			size_type		_capacity;
			size_type		_size;

		public:
		// member functions //
		// Constructors
		explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _array(NULL), _capacity(0), _size(0){}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _array(NULL), _capacity(n), _size(n){
			_array = new value_type[n];
			for (size_type i = 0; i < n; i++)
				_array[i] = val;
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0): _allocator(alloc) {
			_capacity = last - first;
			_size = 0;
			_array = new value_type[_capacity];
			assign(first, last);}

		vector(const vector& x){
			_size = 0;
			_capacity = 0;
			*this = x;
		}

		// Destructor
		virtual ~vector(){delete[] _array;}

		// Assignment operator
		vector&	operator=(const vector& x){
			if (this != &x){
				if (_capacity){clear();}
				_capacity = x._capacity;
				_size = x._size;
				_array = new value_type[_capacity];
				assign(x.begin(), x.end());
			}
			return (*this);
		}

		// Iterators
		iterator begin(){return (iterator(_array));}
		const_iterator begin() const{return (const_iterator(_array));}
		iterator end(){return (iterator(&_array[_size]));}
		const_iterator end() const{return (const_iterator(&_array[_size]));}
		reverse_iterator rbegin() {return (reverse_iterator(&_array[_size - 1]));}
		const_reverse_iterator rbegin() const {return (const_reverse_iterator(&_array[_size - 1]));}
		reverse_iterator rend() {return (reverse_iterator(_array - 1));}
		const_reverse_iterator rend() const {return (const_reverse_iterator(_array - 1));}

		// Capacity
		size_type size() const{return (_size);}
		size_type max_size() const{return (_allocator.max_size());}

		void resize(size_type n, value_type val = value_type()){
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}

		size_type capacity() const{return (_capacity);}

		bool empty()const{
			if (_size)
				return (false);
			return (true);
		}

		void reserve(size_type n){
			if (n <= _capacity)
				return ;
			_capacity = (_capacity == 0 ? 1 : _capacity * 2);
			pointer tmp = new value_type[_capacity];
			for (size_type i = 0; i < _size; ++i)
				tmp[i] = _array[i];
			delete[] _array;
			_array = tmp;
		}

		// Element access
		reference operator[](size_type n){return (*(_array + n));}
		const_reference operator[](size_type n) const{return (*(_array + n));}

		reference at(size_type n){
			if (n < _size)
				return (*(_array + n));
			throw (std::out_of_range("N out of range"));
		}

		const_reference at(size_type n) const{
			if (n < _size)
				return (*(_array + n));
			throw (std::out_of_range("N out of range"));
		}

		reference front(){return (_array[0]);}
		const_reference front() const{return (_array[0]);}
		reference back(){return (_array[_size-1]);}
		const_reference back() const{return (_array[_size-1]);}

		// Modifiers
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last,
				typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			clear();
			for (; first != last; ++first)
				push_back(*first);
		}

		void assign(size_type n, const value_type& val){
			clear();
			for (; n > 0; n--)
				push_back(val);
		}

		void push_back(const value_type& val){
			if (_size == _capacity)
				reserve(_size + 1);
			_array[_size] = val;
			++_size;
		}

		void pop_back(){
			if (_size == 0)
				return ;
			_size--;
			_allocator.destroy(_array + _size);
		}

		void clear(){
			if (_size == 0)
				return ;
			for (; _size > 0; --_size)
				_allocator.destroy(_array + _size);
		}

		iterator insert(iterator position, const value_type& val){
			size_type n = position - begin();
			insert(position, 1, val);
			return (iterator(&_array[n]));
		}

		void insert(iterator position, size_type n, const value_type& val){
			vector tmp;
			iterator it = begin();
			for (; it != position; ++it)
				tmp.push_back(*it);
			for (size_type i = 0; i < n; ++i)
				tmp.push_back(val);
			for (it = end(); position != it; ++position)
				tmp.push_back(*position);
			assign(tmp.begin(), tmp.end());
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0){
			vector tmp;
			iterator it = begin();
			for (; it != position; ++it)
				tmp.push_back(*it);
			for (; first != last; ++first)
				tmp.push_back(*first);
			for (it = end(); position != it; ++position)
				tmp.push_back(*position);
			assign(tmp.begin(), tmp.end());
		}

		iterator erase(iterator position){
			vector tmp;
			iterator it = begin();
			for (; it != position; ++it)
				tmp.push_back(*it);
			++position;
			for (it = end(); position != it; ++position)
				tmp.push_back(*position);
			assign(tmp.begin(), tmp.end());
			return (position);
		}

		iterator erase(iterator first, iterator last){
			vector tmp;
			iterator it = begin();
			for (; it != first; ++it)
				tmp.push_back(*it);
			for (it = end(); last != it; ++last)
				tmp.push_back(*last);
			assign(tmp.begin(), tmp.end());
			return (last);
		}

		void swap(vector& x){
			swap(_capacity, x._capacity);
			swap(_size, x._size);
			swap(_array, x._array);
		}

		allocator_type get_allocator() const { return this->_allocator; }
};

// Relational operators
	template <class T, class Alloc>
  	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y){ x.swap(y); }

	template <class value_type, class allocator_type>
	bool operator== (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {
		if (lhs.size() != rhs.size()) {return (false);}
		typename ft::vector<value_type>::iterator lhsIt = lhs.begin();
		typename ft::vector<value_type>::iterator rhsIt = rhs.begin();
		while (lhsIt != lhs.end() && rhsIt != rhs.end()) {
			if (!(*lhsIt == *rhsIt)) {return (false);}
			++lhsIt;
			++rhsIt;
		}
		return (true);
	}

	template<class value_type, class allocator_type>
	bool operator!=(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {return (!(lhs == rhs));}

	template<class value_type, class allocator_type>
	bool operator<(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

	template<class value_type, class allocator_type>
	bool operator<=(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {return (!(rhs < lhs));}

	template<class value_type, class allocator_type>
	bool operator>(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {return (rhs < lhs);}

	template<class value_type, class allocator_type>
	bool operator>=(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {return (!(lhs < rhs));}
}

#endif