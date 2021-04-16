#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "../list/BidirectionalIterator.hpp"
# include "../Traits.hpp"

namespace ft{
	template < class Key,											// map::key_type
           class T,													// map::mapped_type
           class Compare = std::less<Key>,							// map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >	// map::allocator_type
           > class map{
			   public:
			   	typedef Key										key_type;
				typedef T										mapped_type;
				typedef std::pair<const key_type,mapped_type>	value_type;
				typedef Compare									key_compare;
				typedef Alloc									allocator_type;
				typedef T&										reference;
				typedef const T&								const_reference;
				typedef T*										pointer;
				typedef const T*								const_pointer;
				typedef mapNode<value_type>						node;
				typedef mapNode<value_type>*					node_pointer;
				
				typedef bidirectionalIterator<value_type, node_pointer, Alloc>			iterator;
				typedef constBidirectionalIterator<value_type, node_pointer, Alloc>		const_iterator;
				typedef revBidirectionalIterator<value_type, node_pointer, Alloc>		reverse_iterator;
				typedef constRevBidirectionalIterator<value_type, node_pointer, Alloc>	const_reverse_iterator;

				typedef ptrdiff_t		difference_type;
				typedef size_t			size_type;
		   };
}
#endif