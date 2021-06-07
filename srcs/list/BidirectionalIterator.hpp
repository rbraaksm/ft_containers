#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

#include "Node.hpp"
#include <stddef.h>

namespace ft
{

	// template<class T> class ListIterator;
	template<class T, class N> class ConstListIterator;

	template<class T, class N, class Category = std::bidirectional_iterator_tag >
	class ListIterator
	{
		public:
			typedef T 					value_type;
			typedef value_type* 		pointer;
			typedef value_type& 		reference;
			typedef const value_type& 	const_reference;
			typedef ptrdiff_t			difference_type;
			typedef Node<value_type>*	node_pointer;
			typedef Category			iterator_category;

		protected:
			node_pointer	node;

		public:
			ListIterator() : node(NULL) {}
			ListIterator(const ListIterator& other) : node(other.node) {}
			ListIterator(Node<value_type>* node) : node(node) {}
			~ListIterator() {}
			ListIterator& operator=(const ListIterator& other)
			{
				node = other.node;
				return *this;
			}

			bool operator==(const ListIterator& other) const
			{ return node == other.node; }

			bool operator!=(const ListIterator& other) const
			{ return node != other.node; }

			reference operator*() const
			{ return node->val; }

			pointer operator->() const
			{ return &(node->val); }

			ListIterator operator++()
			{
				node = node->next;
				return *this;
			}

			ListIterator operator++(int)
			{
				ListIterator cpy(*this);
				node = node->next;
				return cpy;
			}

			ListIterator operator--()
			{
				node = node->prev;
				return *this;
			}

			ListIterator operator--(int)
			{
				ListIterator cpy(*this);
				node = node->prev;
				return cpy;
			}

			Node<T>* getNode()
			{
				return node;
			}

			operator ConstListIterator<T, N>() const { return ConstListIterator<T, N>(node); }
			operator ListIterator<T, N>() const { return ListIterator<T, N>(node); }
	};

	template<class T, class N>
	class ConstListIterator : public ListIterator<T, N>
	{
		public:
		
			// typedef T const & const_reference;
			// typedef T const * const_pointer;

			ConstListIterator() : ListIterator<T, N>(){}
			ConstListIterator& operator=(const ConstListIterator& other)
			{
				ListIterator<T, N>::operator=(other);
				return *this;
			}

			ConstListIterator(Node<T>* node)
			{
				this->node = node;
			}

			// const_reference operator*() const
			// { return this->node->val; }

			// const_pointer operator->() const
			// { return &(this->node->val); }

			// operator ReverseConstListIterator<T>() const { return ReverseConstListIterator<T>(this->node); }
	};
}

#endif
