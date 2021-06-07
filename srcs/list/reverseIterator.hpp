#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "Node.hpp"
#include <stddef.h>

namespace ft
{
	template<class T, class N, class Category = std::bidirectional_iterator_tag > class ReverseListIterator;
	template<class T, class N> class ConstReverseListIterator;

	template<class T, class N, class Category>
	class ReverseListIterator
	{
		public:
			typedef T value_type;
			typedef value_type* pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef ptrdiff_t difference_type;
			typedef Node<value_type>*	node_pointer;
			typedef Category			iterator_category;

		protected:
			node_pointer node;

		public:
			ReverseListIterator() : node(NULL) {}
			ReverseListIterator(const ReverseListIterator& other) : node(other.node) {}
			ReverseListIterator(Node<value_type>* node) : node(node) {}
			~ReverseListIterator() {}
			ReverseListIterator& operator=(const ReverseListIterator& other)
			{
				node = other.node;
				return *this;
			}

			bool operator==(const ReverseListIterator& other) const
			{ return node == other.node; }

			bool operator!=(const ReverseListIterator& other) const
			{ return node != other.node; }

			reference operator*() const
			{ return node->val; }

			pointer operator->() const
			{ return &(node->val); }

			ReverseListIterator operator++()
			{
				node = node->prev;
				return (*this);
			}

			ReverseListIterator operator++(int)
			{
				ReverseListIterator cpy(*this);
				node = node->prev;
				return cpy;
			}

			ReverseListIterator operator--()
			{
				node = node->next;
				return *this;
			}

			ReverseListIterator operator--(int)
			{
				ReverseListIterator cpy(*this);
				node = node->next;
				return cpy;
			}

			Node<T>* getNode()
			{
				return node;
			}

			operator ConstReverseListIterator<T, N>() const { return ConstReverseListIterator<T, N>(node); }
			// operator ListIterator<T>() const { return ListIterator<T, N>(node); }
	};

	template<class T, class N>
	class ConstReverseListIterator : public ReverseListIterator<T, N>
	{
		public:
			// typedef T const & const_reference;
			// typedef T const * const_pointer;

			ConstReverseListIterator() : ReverseListIterator<T, N>(){}
			ConstReverseListIterator& operator=(const ConstReverseListIterator& other)
			{
				ReverseListIterator<T, N>::operator=(other);
				return *this;
			}

			ConstReverseListIterator(Node<T>* node)
			{
				this->node = node;
			}

			// const_reference operator*() const
			// { return this->node->val; }

			// const_pointer operator->() const
			// { return &(this->node->val); }

			operator ConstListIterator<T, N>() const { return ConstListIterator<T, N>(this->node); }
	};
}

#endif
