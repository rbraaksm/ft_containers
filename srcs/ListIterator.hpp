#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include <memory>
# include <cstddef>

# include "ListNode.hpp"

namespace ft {
	template <typename T, typename Pointer, typename Reference>
	class ListIterator {
		public:
			typedef ListIterator<T, Pointer, Reference>			this_type;
			typedef ListIterator<T, T*, T&>						iterator;
			typedef ListIterator<T, const T*, const T&>			const_iterator;
			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;
			typedef T											value_type;
			typedef Node<T>*									node_pointer;
			typedef Pointer										pointer;
			typedef Reference									reference;
			typedef std::bidirectional_iterator_tag				iterator_category;

			node_pointer	ptr;
			ListIterator() : ptr(NULL){}
			ListIterator(const node_pointer elem) : ptr(elem){}
			ListIterator(const iterator& x) : ptr(const_cast<node_pointer>(x.ptr)){}
			~ListIterator(){}

			this_type&	operator=(const iterator& x){
				ptr = x.ptr;
				return (*this);
			}

			reference operator*() const {return (ptr->data);}
			pointer   operator->() const {return &(ptr->data);}

			this_type& operator++(){
				ptr = ptr->next;
				return (*this);
			}

			this_type  operator++(int){
				this_type	tmp(*this);
				ptr = ptr->next;
				return (tmp);
			}

			this_type& operator--(){
				ptr = ptr->prev;
				return (*this);
			}

			this_type  operator--(int){
				this_type	tmp(*this);
				ptr = ptr->prev;
				return (tmp);
			}

			node_pointer getNode(){return (ptr);}

			template<typename T2, typename P, typename R>
			friend inline bool operator==(const this_type& lhs, const ListIterator<T2, P, R>& rhs){return (lhs.ptr == rhs.ptr);}

			template<typename T2, typename P, typename R>
			friend inline bool operator!=(const this_type& lhs, const ListIterator<T2, P, R>& rhs){return !(lhs == rhs); }
		};
}

#endif
