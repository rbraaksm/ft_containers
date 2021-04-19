#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "mapNode.hpp"
# include "../list/BidirectionalIterator.hpp"
# include "../Traits.hpp"

# include <map>

namespace ft{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map{
		public:
		// member types //
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

			class value_compare: public std::binary_function<value_type,value_type,bool> {
			friend class map;
			protected:
				Compare comp;
				explicit value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
			};

			private:
				node_pointer*	_root;
				node_pointer*	_top;
				node_pointer*	_bottom;
				Compare			_comp;
				size_t			_size;
				Alloc			_alloc;

			public:
			// member functions //
			// Constructors
				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_root(), _top(new node_pointer()), _bottom(new node_pointer()), _comp(comp), _size(0), _alloc(alloc){
						// _bottom->_parent = _top;
						// _top->_parent = _bottom;
					}

				template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_root(), _top(new node_pointer()), _bottom(new node_pointer()), _comp(comp), _size(0), _alloc(alloc){
						_bottom->_parent = _top;
						_top->_parent = _bottom;
						// insert(first, last);
						(void)first;
						(void)last;
					}

				map(const map& x) : _root(), _top(new node_pointer()), _bottom(new node_pointer()){
					_bottom->_parent = _top;
					_top->_parent = _bottom;
					*this = x;
				}

				// Destructor
				~map(){
					// clear();
					delete _bottom;
					delete _top;
				}

				// Operator
				 map& operator=(const map& x){
					 if (this != &x){
						// clear();
						_alloc = x._alloc;
						_comp = x._comp;
						insert(x.begin(), x.end());
					 }
					return (*this);
				}

				// Iterators
				iterator begin() {return iterator(_bottom->_parent);}
				const_iterator begin() const {return const_iterator(_bottom->_parent);}
				iterator end() {return iterator(_top);}
				const_iterator end() const {return const_iterator(_top);}
				reverse_iterator rbegin() {return reverse_iterator(_top->_parent);}
				const_reverse_iterator rbegin() const {return const_reverse_iterator(_top->_parent);}
				reverse_iterator rend() {return reverse_iterator(_bottom);}
				const_reverse_iterator rend() const {return const_reverse_iterator(_bottom);}

				// Capacity
				bool empty() const{
					if (_size)
						return (false);
					return (true);
				}

				size_type size() const{return (_size);}
				size_type max_size() const{return (_alloc.max_size());}
				mapped_type& operator[](const key_type& k){ return ((*((insert(make_pair(k,mapped_type()))).first)).second);}

				// Modifiers
				// pair<iterator,bool> insert(const value_type& val){

				// }
				std::pair<iterator,bool> insert (const value_type& val) {
					return (std::inserter(val));}
		   };
}
#endif