#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include <algorithm>

namespace ft {
	template<typename T, class Category = std::random_access_iterator_tag>
	class randomAccessIterator {
		public:
			typedef T 						value_type;
			typedef value_type& 			reference;
			typedef value_type* 			pointer;
			typedef size_t 					size_type;
			typedef ptrdiff_t				difference_type;
			typedef Category				iterator_category;
			typedef randomAccessIterator	type;

		protected:
			pointer _ptr;

		public:
			randomAccessIterator() : _ptr(NULL) {}
			randomAccessIterator(pointer node) : _ptr(node) {}
			randomAccessIterator(const type& obj) {*this = obj;}
			virtual ~randomAccessIterator() {}

			randomAccessIterator& operator=(const randomAccessIterator& obj) {
				if (&obj != this) {
					_ptr = obj._ptr;
				}
				return (*this);
			}

			randomAccessIterator operator++(int) {
				randomAccessIterator ret(*this);
				_ptr++;
				return (ret);
			}

			randomAccessIterator& operator++() { // Overload prefix ++
				_ptr++;
				return (*this);
			}

			randomAccessIterator operator+(difference_type n) {
				randomAccessIterator ret(*this);
				ret._ptr += n;
				return (ret);
			}

			randomAccessIterator operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}

			randomAccessIterator operator--(int) { // Overload postfix -
				randomAccessIterator ret(*this);
				_ptr--;
				return (ret);
			}

			randomAccessIterator& operator--() { // Overload prefix -
				_ptr--;
				return (*this);
			}

			randomAccessIterator operator-(difference_type n) {
				randomAccessIterator ret(*this);
				ret._ptr -= n;
				return (ret);
			}

			difference_type operator-(randomAccessIterator it) {
				int ret;
				ret = _ptr - it.getPtr();
				return (ret);
			}

			randomAccessIterator operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}

			bool operator==(const randomAccessIterator& obj) {return (_ptr == obj._ptr);}
			bool operator!=(const randomAccessIterator& obj) {return (_ptr != obj._ptr);}
			bool operator>=(const randomAccessIterator& obj) {return (_ptr >= obj._ptr);}
			bool operator<=(const randomAccessIterator& obj) {return (_ptr <= obj._ptr);}
			bool operator>(const randomAccessIterator& obj) {return (_ptr > obj._ptr);}
			bool operator<(const randomAccessIterator& obj) {return (_ptr < obj._ptr);}

			reference operator*() {return (*_ptr);}
			pointer operator->() {return (*(&(_ptr)));}
			reference	operator[](difference_type n) {return (*(_ptr + n));}
			pointer getPtr() const {return (_ptr);}
	};

	template<typename T, class Category = std::random_access_iterator_tag>
	class constRandomAccessIterator: public randomAccessIterator<T> {
	public:
		typedef T 							value_type;
		typedef value_type& 				reference;
		typedef value_type* 				pointer;
		typedef const value_type& 			const_reference;
		typedef const value_type* 			const_pointer;
		typedef size_t 						size_type;
		typedef ptrdiff_t 					difference_type;
		typedef Category 					iterator_category;
		typedef constRandomAccessIterator 	type;

		constRandomAccessIterator() : randomAccessIterator<T>(NULL) {}
		explicit constRandomAccessIterator(pointer node) : randomAccessIterator<T>(node) {}
		constRandomAccessIterator(const constRandomAccessIterator& obj) {*this = obj;}
		constRandomAccessIterator(const randomAccessIterator<T>& obj) {*this = obj;}

		constRandomAccessIterator& operator=(const constRandomAccessIterator& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return (*this);
		}

		constRandomAccessIterator& operator=(const randomAccessIterator<T>& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return (*this);
		}

		virtual ~constRandomAccessIterator() {}

		const_reference operator*() {return (*this->_ptr);}
		const_pointer operator->() {return *(&(this->_ptr));}
		const_reference	operator[](difference_type n) {return (*(this->_ptr + n));}
	};

	template<typename T, class Category = std::random_access_iterator_tag>
	class revRandomAccessIterator {
	public:
		typedef T 						value_type;
		typedef value_type& 			reference;
		typedef value_type* 			pointer;
		typedef size_t 					size_type;
		typedef ptrdiff_t 				difference_type;
		typedef Category 				iterator_category;
		typedef revRandomAccessIterator type;

	protected:
		pointer _ptr;

	public:
		revRandomAccessIterator() : _ptr(NULL) {}
		explicit revRandomAccessIterator(pointer node) : _ptr(node) {}
		revRandomAccessIterator(const revRandomAccessIterator& obj) {*this = obj;}

		revRandomAccessIterator& operator=(const revRandomAccessIterator& obj) {
			if (&obj != this) {
				_ptr = obj._ptr;
			}
			return (*this);
		}

		virtual ~revRandomAccessIterator() {}

		bool operator==(const revRandomAccessIterator& obj) {return (_ptr == obj._ptr);}
		bool operator!=(const revRandomAccessIterator& obj) {return (_ptr != obj._ptr);}

		reference operator*() {return (*_ptr);}
		pointer operator->() {return *(&(_ptr));}

		revRandomAccessIterator operator++(int) { // Overload postfix ++
			revRandomAccessIterator ret(*this);
			_ptr--;
			return (ret);
		}

		revRandomAccessIterator& operator++() { // Overload prefix ++
			_ptr--;
			return (*this);
		}

		revRandomAccessIterator operator+(difference_type n) {
			revRandomAccessIterator ret(*this);
			ret._ptr -= n;
			return (ret);
		}

		revRandomAccessIterator operator+=(difference_type n) {
			_ptr -= n;
			return (_ptr);
		}

		revRandomAccessIterator operator--(int) { // Overload postfix -
			revRandomAccessIterator ret(*this);
			_ptr++;
			return (ret);
		}

		revRandomAccessIterator& operator--() { // Overload prefix -
			_ptr++;
			return (*this);
		}

		revRandomAccessIterator operator-(difference_type n) {
			revRandomAccessIterator ret(*this);
			ret._ptr += n;
			return (ret);
		}

		revRandomAccessIterator operator-=(difference_type n) {
			_ptr += n;
			return (_ptr);
		}

		bool operator>=(const revRandomAccessIterator& obj) {return (_ptr >= obj._ptr);}
		bool operator<=(const revRandomAccessIterator& obj) {return (_ptr <= obj._ptr);}
		bool operator>(const revRandomAccessIterator& obj) {return (_ptr > obj._ptr);}
		bool operator<(const revRandomAccessIterator& obj) {return (_ptr < obj._ptr);}

		reference	operator[](difference_type n) {return (*(_ptr + n));}
		pointer getPtr() const {return (_ptr);}
	};

	template<typename T, class Category = std::random_access_iterator_tag>
	class constRevRandomAccessIterator: public revRandomAccessIterator<T> {
	public:
		typedef T 								value_type;
		typedef value_type& 					reference;
		typedef value_type* 					pointer;
		typedef const value_type& 				const_reference;
		typedef const value_type*	 			const_pointer;
		typedef size_t 							size_type;
		typedef ptrdiff_t 						difference_type;
		typedef Category 						iterator_category;
		typedef constRevRandomAccessIterator	self_type;

		constRevRandomAccessIterator() : revRandomAccessIterator<T>(NULL) {}
		explicit constRevRandomAccessIterator(pointer node) : revRandomAccessIterator<T>(node) {}
		constRevRandomAccessIterator(const constRevRandomAccessIterator& obj) {*this = obj;}
		constRevRandomAccessIterator(const revRandomAccessIterator<T>& obj) {*this = obj;}
		constRevRandomAccessIterator& operator=(const constRevRandomAccessIterator& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return (*this);
		}

		constRevRandomAccessIterator& operator=(const revRandomAccessIterator<T>& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return (*this);
		}

		virtual ~constRevRandomAccessIterator() {}
		const_reference operator*() {return (*this)->_ptr;}
		const_pointer operator->() {return *(&(this->_ptr));}
		const_reference	operator[](difference_type n) {return (*(this->_ptr + n));}
	};

}

#endif