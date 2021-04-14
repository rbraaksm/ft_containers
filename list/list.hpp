#ifndef LIST_HPP
# define LIST_HPP

# include "listNode.hpp"
# include "BidirectionalIterator.hpp"
# include "Traits.hpp"
# include <memory>
# include <iterator>
# include <algorithm>

// https://www.cplusplus.com/reference/list/list/

namespace ft{
    template < class T, class Alloc = std::allocator<T> >
    class list{
        public:
		// member types //
            typedef T           	value_type;
            typedef Alloc       	allocator_type;
            typedef T          		&reference;
            typedef const T     	&const_reference;
            typedef T           	*pointer;
            typedef const T     	*const_pointer;
            typedef Node<T>			*node_pointer;

			typedef bidirectionalIterator<value_type, node_pointer>			iterator;
			typedef constBidirectionalIterator<value_type, node_pointer>	const_iterator;
			typedef revBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
			typedef constRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;

			typedef ptrdiff_t		difference_type;
			typedef size_t			size_type;

		private:
			template <typename U>
			void swap(U& x, U& y) {
				U tmp = x;
				x = y;
				y = tmp;
			}

			node_pointer	_head;
			node_pointer	_tail;
			size_type		_size;
			allocator_type	_allocator;

		public:
		// member functions //
		// Constructors
		explicit list(const allocator_type &alloc = allocator_type()) : _allocator(alloc){
			_head = new Node<value_type>();
			_tail = new Node<value_type>();
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
		}

		explicit list(size_type n, const value_type& val = value_type(),
			 const allocator_type& alloc = allocator_type()) : _allocator(alloc) {
			_head = new Node<value_type>();
			_tail = new Node<value_type>();
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(n, val);
		}

		template <class InputIterator>
  		list(InputIterator first, InputIterator last,
		  const allocator_type& alloc = allocator_type()) : _allocator(alloc){
			_head = new Node<value_type>();
			_tail = new Node<value_type>();
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(first, last);
		}

		list(const list& x){
			_head = new Node<value_type>();
			_tail = new Node<value_type>();
			_head->_next = _tail;
			_tail->_prev = _head;
			_size = 0;
			assign(x.begin(), x.end());
		}

		// Destructor
		virtual ~list(){
			clear();
			delete _head;
			delete _tail;
		}

		// Assignment operator
		list&	operator=(const list& x){
			if (this != &x){
				clear ();
				_head->_next = _tail;
				_tail->_prev = _head;
				assign(x.begin(), x.end());
			}
			return (*this);
		}

		// Iterators
		iterator begin(){return (iterator(_head->_next));}
		const_iterator begin() const{return (const_iterator(_head->_next));}
		iterator end(){return (iterator(_tail));}
		const_iterator end() const{return (const_iterator(_tail));}
		reverse_iterator rbegin() {return (reverse_iterator(_tail->_prev));}
		const_reverse_iterator rbegin() const {return (const_reverse_iterator(_tail->_prev));}
		reverse_iterator rend() {return (reverse_iterator(_head));}
		const_reverse_iterator rend() const {return (const_reverse_iterator(_head));}

		// Capacity
		bool empty() const{
			if (_size == 0)
				return (true);
			return (false);
		}

		size_type size() const{return (_size);}
		size_type max_size() const{return (this->_allocator.max_size());}

		// Element access
		reference front(){return (_head->_next->_data);}
		const_reference front() const{return (_head->_next->_data);}
		reference back(){return (_tail->_prev->_data);}
		const_reference back() const{return (_tail->_prev->_data);}

		// Modifiers
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last,
				typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		void assign(size_type n, const value_type& val){
			clear();
			for (; n > 0; n--)
				push_back(val);
		}

		void push_front(const value_type& val){
			Node<value_type> *node = new Node<value_type>(val);
			_head->_next->_prev = node;
			node->_next = _head->_next;
			node->_prev = _head;
			_head->_next = node;
		}

		void pop_front(){
			if (_size){
				Node<value_type>* node = _head->_next;
				_head->_next = _head->_next->_next;
				_head->_next->_prev = _head;
				_size--;
				delete node;
			}
		}

		void push_back(const value_type& val){
			Node<value_type>* node = new Node<value_type>(val);
			node->_prev = _tail->_prev;
			_tail->_prev->_next = node;
			_tail->_prev = node;
			node->_next = _tail;
			_size++;
		}

		void pop_back(){
			if (_size){
				Node<value_type>* node = _tail->_prev;
				_tail->_prev = _tail->_prev->_prev;
				_tail->_prev->_next = _tail;
				_size--;
				delete node;
			}
		}

		iterator insert(iterator position, const value_type& val){
			Node<value_type>* pointer = position.getPtr();
			Node<value_type>* node = new Node<value_type>(pointer->_next, pointer->_prev, val);
			pointer->_prev = node;
			node->_prev->_next = node;
			_size++;
			return (iterator(node));
		}

		void insert(iterator position, size_type n, const value_type& val){
			for (size_type i = 0; i < n; i++)
				insert(position, val);
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			for(; first != last; ++first)
				insert(position, *first);
		}

		iterator erase(iterator position){
			Node<value_type>* node = position.getPtr();
			node->_prev->_next = node->_next;
			node->_next->_prev = node->_prev;
			delete node;
			--_size;
			return (++position);
		}

		iterator erase(iterator first, iterator last){
			while (first != last)
				first = erase(first);
			return (first);
		}

		void clear(){
			while (_size)
				pop_back();
		}

		void swap(list& x){
			Node<value_type>*	head = _head;
			Node<value_type>*	tail = _tail;
			size_type			size = _size;
			allocator_type		alloc = _allocator;
			_head = x._head;
			_tail = x._tail;
			_size = x._size;
			_allocator = x._allocator;
			x._head = head;
			x._tail = tail;
			x._size = size;
			x._allocator = alloc;
		}

		void resize(size_type n, value_type val = value_type()){
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}

		// Operations
		void splice(iterator position, list& x){
			splice(position, x, x.begin(), x.end());
		}

		void splice(iterator position, list& x, iterator i){
			Node<value_type>* node = i.getPtr();
			Node<value_type>* tmp = position.getPtr();
			node->_prev->_next = node->_next;
			node->_next->_prev = node->_prev;
			--x._size;

			tmp->_prev->_next = node;
			node->_next = tmp;
			node->_prev = tmp->_prev;
			tmp->_prev = node;
			++_size;
		}

		void splice(iterator position, list& x, iterator first, iterator last){
			for(; first != last; splice(position, x, first++)){}
		}

		void remove(const value_type& val){
			for (iterator it = begin(); it != end(); ++it)
				if (*it == val)
					erase(it);
		}

		template <class Predicate>
  		void remove_if(Predicate pred){
			for (iterator it = begin(); it != end(); ++it)
				if (pred(*it))
					erase(it);
		  }

		void unique(){
			for(iterator it = begin(); it != end(); ++it)
				while (*it == it.getPtr()->_next->_data){
					erase(it);
					--it;}
		}

		template <class BinaryPredicate>
  		void unique(BinaryPredicate binary_pred){
			for(iterator it = begin(); it != end(); ++it)
				while (binary_pred(*it, it.getPtr()->_next->_data)){
					erase(it);
					--it;}
  		}

		void merge(list& x){
			if (&x == this)
				return ;
			iterator ix = x.begin();
			iterator it = begin();
			for(; it != end(); ++it){
				while (*it > *ix){
					splice(it, x, ix);
					ix = x.begin();}
			}
			if (x._size)
				splice(end(), x);
		}

		template <class Compare>
  		void merge (list& x, Compare comp){
			if (&x == this)
				return ;
			iterator ix;
			iterator it = begin();
			for(; x._size && it != end(); ++it){
				ix = x.begin();
				if (comp(*ix, *it))
					splice(it, x, ix);
			}
			if (x._size)
				splice(end(), x);
  		}

		void sort(){
			for(iterator it = begin(); it != end(); ++it)
				if (*it < it.getPtr()->_prev->_data){
					swap(it.getPtr()->_data, it.getPtr()->_prev->_data);
					it = begin();
				}
		}

		template <class Compare>
  		void sort(Compare comp){
			for(iterator it = begin(); it != end(); ++it)
				if (comp(*it, it.getPtr()->_prev->_data)){
					swap(it.getPtr()->_data, it.getPtr()->_prev->_data);
					it = begin();
				}
		}

		void reverse(){
			if (size() <= 1)
				return ;
			Node<value_type>* node = _head->_next;
			for(; node != _tail; node = node->_prev)
				swap(node->_next, node->_prev);
			swap(_head->_next, _head->_prev);
			swap(_tail->_next, _tail->_prev);
			swap(_head, _tail);
		}
};

// Relational operators
	template <class value_type, class allocator_type>
	bool operator== (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {
		if (lhs.size() != rhs.size()) {return (false);}
		typename ft::list<value_type>::iterator lhsIt = lhs.begin();
		typename ft::list<value_type>::iterator rhsIt = rhs.begin();
		while (lhsIt != lhs.end() && rhsIt != rhs.end()) {
			if (!(*lhsIt == *rhsIt)) {return (false);}
			++lhsIt;
			++rhsIt;
		}
		return (true);
	}

	template<class value_type, class allocator_type>
	bool operator!=(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs) {return !(lhs == rhs);}

	template<class value_type, class allocator_type>
	bool operator<(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs) {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class value_type, class allocator_type>
	bool operator<=(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs) {return (!(rhs < lhs));}

	template<class value_type, class allocator_type>
	bool operator>(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs){return (rhs < lhs);}

	template<class value_type, class allocator_type>
	bool operator>=(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs) {return (!(lhs < rhs));}
}

#endif
