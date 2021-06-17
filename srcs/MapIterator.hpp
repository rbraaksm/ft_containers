#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <memory>
# include <cstddef>

namespace ft {
	template < typename T, typename Pointer, typename Reference>
	class MapIterator {
		public:
			typedef MapIterator<T, Pointer, Reference>	this_type;
			typedef MapIterator<T, T*, T&>				iterator;
			typedef MapIterator<T, const T*, const T&>	const_iterator;
			typedef size_t								size_type;
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef Pointer								pointer;
			typedef Reference							reference;
			typedef node<T>*							node_pointer;
			typedef std::bidirectional_iterator_tag		iterator_category;

			node_pointer	ptr;
			MapIterator() : ptr(NULL){}
			MapIterator(const node_pointer element) : ptr(element){}
			MapIterator(const iterator& x) : ptr(const_cast<node_pointer>(x.ptr)){}

			this_type&	operator=(const const_iterator& obj){
				ptr = obj.ptr;
				return (*this);
			}

			virtual ~MapIterator(){}

			MapIterator	operator++(int){
				MapIterator	tmp(*this);
				ptr = ptr->getNext();
				return (tmp);
			}

			MapIterator&	operator++(){
				ptr = ptr->getNext();
				return (*this);
			}

			MapIterator	operator--(int){
				MapIterator	tmp(*this);
				ptr = ptr->getPrev();
				return (tmp);
			}

			MapIterator&	operator--(){
				ptr = ptr->getPrev();
				return (*this);
			}

			reference	operator*(){return (ptr->_data);}
			pointer		operator->(){return (&(ptr->_data));}
			node_pointer getPtr() const{return ptr;}

			template<typename T2, typename P, typename R>
			friend inline bool operator==(const this_type& lhs, const MapIterator<T2, P, R>& rhs){return (lhs.ptr == rhs.ptr);}

			template<typename T2, typename P, typename R>
			friend inline bool operator!=(const this_type& lhs, const MapIterator<T2, P, R>& rhs){ return !(lhs == rhs); }
		};
}

#endif
