#pragma once

namespace ft{
	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class bidirectionalIterator {
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef bidirectionalIterator		type;

	protected:
		node_pointer _ptr;

	public:
		bidirectionalIterator(): _ptr(NULL) {}
		explicit bidirectionalIterator(node_pointer node): _ptr(node) {}
		bidirectionalIterator(const bidirectionalIterator& obj) { *this = obj;}
		virtual ~bidirectionalIterator() {}
		bidirectionalIterator& operator=(const bidirectionalIterator& obj) {
			if (&obj != this) {_ptr = obj._ptr;}
			return *this;
		}

		 // Overload postfix ++
		bidirectionalIterator	operator++(int) {
			bidirectionalIterator	ret(*this);
			_ptr = _ptr->getNext();
			return ret;
		}

		// Overload prefix ++
		bidirectionalIterator&	operator++() {
			_ptr = _ptr->getNext();
			return *this;
		}

		// Overload postfix --
		bidirectionalIterator	operator--(int) {
			bidirectionalIterator	ret(*this);
			_ptr = _ptr->getPrev();
			return ret;
		}

		// Overload prefix --
		bidirectionalIterator&	operator--() {_ptr = _ptr->getPrev();return *this;}
		reference	operator*() {return _ptr->_data;}
		pointer	operator->() {return &this->_ptr->_data;}

		bool	operator==(const bidirectionalIterator &obj) {return (_ptr == obj._ptr);}
		bool	operator!=(const bidirectionalIterator &obj) {return (_ptr != obj._ptr);}
		bool	operator>=(const bidirectionalIterator &obj) {return (_ptr >= obj._ptr);}

		node_pointer getPtr() const {return _ptr;}
	};
}
