#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <memory>
# include <cstddef>

# include "ReverseIterator.hpp"

namespace ft {

	template < typename T, typename Pointer, typename Reference, class Category = std::random_access_iterator_tag >
	class RandomAccessIterator {
		public:
			typedef RandomAccessIterator<T, Pointer, Reference>		type;
			typedef RandomAccessIterator<T, T*, T&>					iterator;
			typedef RandomAccessIterator<T, const T*, const T&>		const_iterator;
			typedef T												value_type;
			typedef Pointer											pointer;
			typedef Reference										reference;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
			typedef	Category										iterator_category;

			pointer	array;
		public:
			RandomAccessIterator() : array(NULL){}
			RandomAccessIterator(const pointer elem) : array(elem){}
			RandomAccessIterator(const iterator& x) : array(const_cast<pointer>(x.array)){}
			virtual ~RandomAccessIterator(){}

			type&	operator=(const iterator& x){
				this->array = x.array;
				return *(this);
			}

			type	operator++(int){
				type tmp(*this);
				++this->array;
				return (tmp);
			}

			type&	operator++(){
				this->array++;
				return *(this);
			}

			type	operator+(difference_type n) const{
				type tmp(*this);
				tmp.array += n;
				return (tmp);
			}

			type&	operator+=(difference_type n){
				this->array += n;
				return *(this);
			}

			type	operator--(int){
				type tmp(*this);
				--this->array;
				return (tmp);
			}

			type&	operator--(){
				--this->array;
				return *(this);
			}

			difference_type	operator-(RandomAccessIterator it) const{return (this->array - it.array);}

			type	operator-(difference_type n) const{
				type tmp(*this);
				tmp -= n;
				return (tmp);
			}

			type&	operator-=(difference_type n){
				this->array -= n;
				return *(this);
			}

			reference	operator*(){return *(this)->array;}
			pointer		operator->(){return *(&(this->array));}

			template<typename T2, typename P, typename R, class C>
			friend inline bool operator==(const type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs){return (lhs.array == rhs.array);}

			template<typename T2, typename P, typename R, class C>
			friend inline bool operator!=(const type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs){ return !(lhs == rhs); }

			template<typename T2, typename P, typename R, class C>
			friend inline bool operator<(const type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs){return (lhs.array < rhs.array);}

			template<typename T2, typename P, typename R, class C>
			friend inline bool operator>(const type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs){ return (rhs < lhs); }

			template<typename T2, typename P, typename R, class C>
			friend inline bool operator<=(const type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs){ return !(rhs < lhs); }

			template<typename T2, typename P, typename R, class C>
			friend inline bool operator>=(const type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs){ return !(lhs < rhs); }

			reference	operator[](difference_type n){return (*(this->array + n));}
	};

	template <typename T, typename P, typename R, typename C>
	RandomAccessIterator<T,P,R,C>	operator+(typename RandomAccessIterator<T,P,R,C>::difference_type n, const RandomAccessIterator<T,P,R,C>& x){return x + n;}


	template <class Iterator >
	class ReverseRandomAccessIterator : public ReverseIterator<Iterator> {
		public:
			typedef ReverseIterator<Iterator>	Base;
			typedef Iterator 					iterator_type;
			using typename Base::pointer;
			using typename Base::reference;
			using typename Base::size_type;
			using typename Base::difference_type;
			using typename Base::iterator_category;

			ReverseRandomAccessIterator() : Base(){}
			ReverseRandomAccessIterator(const iterator_type& x) : Base(x){}
			ReverseRandomAccessIterator(const ReverseRandomAccessIterator& x) : Base(x.ptr){}

			template<typename Iter>
			ReverseRandomAccessIterator(const ReverseIterator<Iter>& x) : Base(x.base()){}
			~ReverseRandomAccessIterator(){}
			ReverseRandomAccessIterator&	operator=(const ReverseRandomAccessIterator& x){
				this->ptr = x.ptr;
				return *(this);
			}

			ReverseRandomAccessIterator	operator+(difference_type n) const{return (ReverseRandomAccessIterator(this->ptr - n));}
			ReverseRandomAccessIterator&	operator+=(difference_type n){
				this->ptr -= n;
				return  *this;
			}

			ReverseRandomAccessIterator	operator-(difference_type n) const{return (ReverseRandomAccessIterator(this->ptr + n));}
			ReverseRandomAccessIterator&	operator-=(difference_type n){
				this->ptr += n;
				return *(this);
			}

			reference	operator[](difference_type n){return *(*this + n);}
	};

	template<typename Iterator>
	typename ReverseRandomAccessIterator<Iterator>::difference_type operator-(const ReverseRandomAccessIterator<Iterator>& lhs, const ReverseRandomAccessIterator<Iterator>& rhs){return (lhs.base() - rhs.base());}

	template<typename IteratorL, typename IteratorR>
	typename ReverseRandomAccessIterator<IteratorL>::difference_type operator-(const ReverseRandomAccessIterator<IteratorL>& lhs, const ReverseRandomAccessIterator<IteratorR>& rhs){return (lhs.base() - rhs.base());}

	template <typename Iterator>
	ReverseRandomAccessIterator<Iterator>	operator+(typename ReverseRandomAccessIterator<Iterator>::difference_type n, const ReverseRandomAccessIterator<Iterator>& x){return ReverseRandomAccessIterator<Iterator>(x.base() - n);}
}

#endif
