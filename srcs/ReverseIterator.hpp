#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

template <class Iterator >
class ReverseIterator {
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::size_type			size_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;

	protected:
		Iterator	ptr;

	public:
		ReverseIterator() : ptr(){}
		ReverseIterator(const iterator_type& x) : ptr(x){}
		ReverseIterator(const ReverseIterator& x) : ptr(x.ptr){}

		template<typename Iter>
		ReverseIterator(const ReverseIterator<Iter>& x) : ptr(x.base()){}
		~ReverseIterator(){}
		ReverseIterator&	operator=(const ReverseIterator& x){
			ptr = x.ptr;
			return (*this);
		}

		iterator_type	base() const{return this->ptr;}
		reference	operator*(){return (*ptr);}
		pointer		operator->(){return (&operator*());}

		ReverseIterator&	operator++(){
			--ptr;
			return (*this);
		}
		ReverseIterator	operator++(int){
			ReverseIterator	tmp(*this);
			--ptr;
			return (tmp);
		}
		ReverseIterator&	operator--(){
			++ptr;
			return (*this);
		}
		ReverseIterator	operator--(int){
			ReverseIterator	tmp(*this);
			++ptr;
			return (tmp);
		}
	};

template <typename Iterator>
bool	operator==(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs){return (lhs.base() == rhs.base());}

template <typename Iterator>
bool	operator<(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs){return (rhs.base() < lhs.base());}

template <typename Iterator>
bool	operator!=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs){return !(lhs == rhs);}

template <typename Iterator>
bool	operator>(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs){return (rhs < lhs);}

template <typename Iterator>
bool	operator<=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs){return !(rhs < lhs);}

template <typename Iterator>
bool	operator>=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs){return !(lhs < rhs);}

#endif
