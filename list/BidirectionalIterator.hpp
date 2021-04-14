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
				if (&obj != this){
					_ptr = obj._ptr;
				}
				return (*this);
			}

			bidirectionalIterator	operator++(int) {
				bidirectionalIterator	ret(*this);
				_ptr = _ptr->getNext();
				return (ret);
			}

			bidirectionalIterator&	operator++() {
				_ptr = _ptr->getNext();
				return (*this);
			}

			bidirectionalIterator	operator--(int) {
				bidirectionalIterator	ret(*this);
				_ptr = _ptr->getPrev();
				return (ret);
			}

			bidirectionalIterator&	operator--() {
				_ptr = _ptr->getPrev();
				return (*this);
			}

			reference	operator*() {return (_ptr->_data);}
			pointer	operator->() {return (&(this->_ptr->_data));}

			bool	operator==(const bidirectionalIterator &obj) {return (_ptr == obj._ptr);}
			bool	operator!=(const bidirectionalIterator &obj) {return (_ptr != obj._ptr);}
			bool	operator>=(const bidirectionalIterator &obj) {return (_ptr >= obj._ptr);}

			node_pointer getPtr() const {return _ptr;}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class constBidirectionalIterator: public bidirectionalIterator<T, N> {
		public:
			typedef T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef N                           node_pointer;
			typedef size_t						size_type;
			typedef ptrdiff_t					difference_type;
			typedef Category					iterator_category;
			typedef constBidirectionalIterator	type;

			constBidirectionalIterator(): bidirectionalIterator<T, N>() {}
			explicit constBidirectionalIterator(node_pointer node): bidirectionalIterator<T, N>(node) {}
			virtual ~constBidirectionalIterator() {}
			constBidirectionalIterator(const constBidirectionalIterator& obj): bidirectionalIterator<T,N>(obj) { *this = obj;}
			constBidirectionalIterator(const bidirectionalIterator<T, N>& obj): bidirectionalIterator<T,N>(obj) { *this = obj;}

			constBidirectionalIterator& operator=(const constBidirectionalIterator& obj) {
				if (&obj != this) {
					this->_ptr = obj.getPtr();
				}
				return (*this);
			}
			constBidirectionalIterator& operator=(const bidirectionalIterator<T, N>& obj) {
				if (&obj != this) {
					this->_ptr = obj.getPtr();
				}
				return (*this);
			}
			const_reference	operator*() {return (this->_ptr->_data);}
			const_pointer	operator->() {return &this->_ptr->_data;}

			bool	operator==(const constBidirectionalIterator &obj) {return (this->_ptr == obj._ptr);}
			bool	operator!=(const constBidirectionalIterator &obj) {return (this->_ptr != obj._ptr);}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class revBidirectionalIterator {
		public:
			typedef T							value_type;
			typedef value_type&					reference;
			typedef value_type*					pointer;
			typedef N                           node_pointer;
			typedef size_t						size_type;
			typedef ptrdiff_t					difference_type;
			typedef Category					iterator_category;
			typedef revBidirectionalIterator	type;

		protected:
			node_pointer _ptr;

		public:
			revBidirectionalIterator(): _ptr(NULL) {}
			explicit revBidirectionalIterator(node_pointer node): _ptr(node) {}
			virtual ~revBidirectionalIterator() {}
			revBidirectionalIterator(const revBidirectionalIterator& obj) { *this = obj;}

			revBidirectionalIterator& operator=(const revBidirectionalIterator& obj) {
				if (&obj != this) {
					_ptr = obj._ptr;
				}
				return (*this);
			}

			revBidirectionalIterator	operator++(int) {
				revBidirectionalIterator	ret(*this);
				_ptr = _ptr->getPrev();
				return (ret);
			}

			revBidirectionalIterator&	operator++() {
				_ptr = _ptr->getPrev();
				return (*this);
			}

			revBidirectionalIterator	operator--(int) {
				revBidirectionalIterator	ret(*this);
				_ptr = _ptr->getNext();
				return (ret);
			}

			revBidirectionalIterator&	operator--() {
				_ptr = _ptr->getNext();
				return (*this);
			}

			reference	operator*() {return (_ptr->_data);}
			pointer	operator->() {return (&this->_ptr->_data);}

			bool	operator==(const revBidirectionalIterator &obj) {return (_ptr == obj._ptr);}
			bool	operator!=(const revBidirectionalIterator &obj) {return (_ptr != obj._ptr);}

			node_pointer getPtr() const {return (_ptr);}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class constRevBidirectionalIterator: public revBidirectionalIterator<T, N> {
		public:
			typedef T								value_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef N								node_pointer;
			typedef size_t							size_type;
			typedef ptrdiff_t						difference_type;
			typedef Category						iterator_category;
			typedef constRevBidirectionalIterator	type;

			constRevBidirectionalIterator(): revBidirectionalIterator<T, N>() {}
			explicit constRevBidirectionalIterator(node_pointer node): revBidirectionalIterator<T, N>(node) {}
			virtual ~constRevBidirectionalIterator() {}
			constRevBidirectionalIterator(const constRevBidirectionalIterator& obj): revBidirectionalIterator<T, N>(obj) { *this = obj;}
			constRevBidirectionalIterator(const revBidirectionalIterator<T, N>& obj): revBidirectionalIterator<T, N>(obj) { *this = obj;}

			constRevBidirectionalIterator& operator=(const constRevBidirectionalIterator& obj) {
				if (&obj != this) {
					this->_ptr = obj.getPtr();
				}
				return (*this);
			}

			constRevBidirectionalIterator& operator=(const revBidirectionalIterator<T, N>& obj) {
				if (&obj != this) {
					this->_ptr = obj.getPtr();
				}
				return (*this);
			}

			const_reference	operator*() {return (this->_ptr->_data);}
			const_pointer	operator->() {return (&this->_ptr->_data);}

			bool	operator==(const constRevBidirectionalIterator &obj) {return (this->_ptr == obj._ptr);}
			bool	operator!=(const constRevBidirectionalIterator &obj) {return (this->_ptr != obj._ptr);}
	};

}
