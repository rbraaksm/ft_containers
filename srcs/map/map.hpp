#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "mapNode.hpp"
# include "ft_Pair.hpp"
# include "../list/BidirectionalIterator.hpp"
# include "../Traits.hpp"

// # include <map>
#define CRESET   "\033[0m"
#define CRED     "\033[31m"      /* Red */
#define CGREEN   "\033[32m"      /* Green */
#define CYELLOW  "\033[33m"      /* Yellow */
#define CBLUE    "\033[34m"      /* Blue */

namespace ft{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map{
		public:
		// member types //
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type,mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			typedef mapNode<value_type>						node;
			typedef mapNode<value_type>*					node_pointer;
			typedef ft::pair<const Key,T> 					pair;

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
				explicit value_compare(Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const{return comp(x.first, y.first);}
			};

			private:
				node_pointer	_root;
				node_pointer	_top;
				node_pointer	_bottom;
				Compare			_comp;
				size_t			_size;
				Alloc			_alloc;

			public:
			// member functions //
			// Constructors
				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_root(), _top(new node), _bottom(new node), _comp(comp), _size(0), _alloc(alloc){

					_bottom->_parent = _top;
					_top->_parent = _bottom;
				}

				template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_root(), _top(new node), _bottom(new node), _comp(comp), _size(0), _alloc(alloc){
					_bottom->_parent = _top;
					_top->_parent = _bottom;
					insert(first, last);
				}

				map(const map& x) : _root(), _top(new node), _bottom(new node), _size(0){

					_bottom->_parent = _top;
					_top->_parent = _bottom;
					_alloc = x._alloc;
					insert(x.begin(), x.end());
					// *this = x;
				}

				// Destructor
				~map(){
					clear();
					delete _bottom;
					delete _top;
				}

				// Operator
				 map& operator=(const map& x){
					 if (this != &x){
						clear();
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

				mapped_type& operator[](const key_type& k){
					if (findNode(_root, k) == NULL)
						return ((*((insert(ft::make_pair(k,mapped_type()))).first)).second);
					return (findNode(_root, k)->_data.second);
				}

				// Modifiers
				ft::pair<iterator,bool> insert(const value_type& val){
					node_pointer tmp = new node(val);
					if (empty())
						return (set_root(tmp));
					return (leaf(tmp));
				}

				iterator	insert(iterator position, const pair& val){
					if (position->first == val.first)
						return (position);
					else
						return (insert(val).first);
				}

				template <class InputIterator>
				void insert (InputIterator first, InputIterator last,
							typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
					while (first != last) {
						
						insert(*first);
						++first;
					}
				}
				// template <class InputIterator>
  				// void	insert(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last){
				// 	  for (; first != last; ++first)
				// 	  	insert(++first);
				// }

				void	erase(iterator position){
					node* look = findNode(position.getPtr(), position->first);
					if (look && _size)
						deleteNode(look);
				}

				size_type	erase(const key_type& k){
					node* look = findNode(_root, k);
					if (look)
						return (deleteNode(look));
					return (0);
				}

				void	erase(iterator first, iterator last){
					for (; first != last;){
						iterator tmp(first);
						++first;
						erase(tmp);
						}
				}

				void swap(map& x){
					swap(_root, x._root);
					swap(_bottom, x._bottom);
					swap(_top, x._top);
					swap(_size, x._size);
					swap(_alloc, x._alloc);
					swap(_comp, x._comp);
				}

				void	clear(){
					erase(begin(), end());
				}

				// Observers
				key_compare	key_comp() const { return (_comp);}
				value_compare value_comp() const{ return (_comp);}

				//Operations
				iterator find(const key_type& k){
					node*	return_node = findNode(_root, k);
					if (return_node)
						return (iterator(return_node));
					else
						return (end());
				}

				const_iterator find(const key_type& k) const{
					node*	return_node = findNode(_root, k);
					if (return_node)
						return (const_iterator(return_node));
					else
						return (end());
				}

				size_type count(const key_type& k) const{
					if (findNode(_root, k))
						return (1);
					else
						return (0);
				}

				iterator lower_bound(const key_type& k){
					iterator it = begin();
					for (; it != end(); it++)
					{
						if (!_comp(it->first, k))
							break ;
					}
					return (it);
				}

				const_iterator lower_bound(const key_type& k) const{
					const_iterator it = begin();
					for (; it != end(); it++)
					{
						if (!_comp(it->first, k))
							break ;
					}
					return (it);
				}

				iterator upper_bound(const key_type& k){
					iterator it = begin();
					for (; it != end(); it++)
					{
						if (_comp(k, it->first))
							break ;
					}
					return (it);
				}

				const_iterator upper_bound(const key_type& k) const{
					const_iterator it = begin();
					for (; it != end(); it++){
						if (_comp(k, it->first))
							break ;
					}
					return (it);
				}

				ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const{
					const_iterator it = lower_bound(k);
					const_iterator it2 = upper_bound(k);
					return (ft::make_pair<const_iterator, const_iterator>(it, it2));
				}

				ft::pair<iterator,iterator>	equal_range(const key_type& k){
					iterator it = lower_bound(k);
					iterator it2 = upper_bound(k);
					return (ft::make_pair<iterator, iterator>(it, it2));
				}

				void				print_node(std::string root_path)
					{
						node_pointer tmp = _root;

						std::cout << ".";
						for (int i = 0; root_path[i]; ++i){
							if (root_path[i] == 'L'){
								if (tmp->_left == NULL)
									return ;
								tmp = tmp->_left;
							}
							if (root_path[i] == 'R'){
								if (tmp->_right == NULL)
									return ;
								tmp = tmp->_right;
							}
						}
						if (tmp->_data.first){
								std::cout << CYELLOW << tmp->_data.first << CRESET;
						}
					}

				void	print_tree()
					{
							std::string root_path;
							int layer = 0;
							root_path = "";
							int starting_tabs = 16;
							int starting_gap = 16;
							while (layer < 5)
							{
								root_path.clear();
								int tmp_tabs = starting_tabs;
								int tmp_gap = starting_gap;
								for (int tmp_layer = layer; tmp_layer; --tmp_layer)
								{
									root_path.append("L");
									tmp_gap = tmp_gap / 2;
									tmp_tabs -= tmp_gap;
								}
								while (root_path.find('L') != std::string::npos){
									if (root_path.find('R') == std::string::npos)
										for (; tmp_tabs; --tmp_tabs)
											std::cout << "   ";
									else
										for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
											std::cout << "   ";
									print_node(root_path);
									size_t L_found = root_path.find_last_of('L');
									root_path[L_found] = 'R';
									++L_found;
									for (;L_found != root_path.size(); ++L_found){
										root_path[L_found] = 'L';
									}
								}
								if (root_path.find('R') == std::string::npos)
									for (; tmp_tabs; --tmp_tabs)
										std::cout << "   ";
								else
									for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
										std::cout << "   ";
								print_node(root_path);
								std::cout << std::endl << std::endl << std::endl;
								layer++;
							}
					}



			private:
				template < typename U >
				void	swap(U& a, U& b)
					{
						U tmp = a;
						a = b;
						b = tmp;
					}

				node*	getLargest(node* income){
					while (income && income->_right)
						income = income->_right;
					return (income);
				}

				int	deleteRoot(){
					node* tmproot = _root;
					if (_size == 1){
						_bottom->_parent = _top;
						_top->_parent = _bottom;
						_root = NULL;
					}
					else if (_root->_left == _bottom){
						_bottom->_parent = _root->_right;
						_root->_right->_parent->_left = _bottom;
						_root = _root->_right;
					}
					else if (_root->_right == _top){
						_bottom->_parent = _root->_left;
						_root->_left->_parent->_right = _bottom;
						_root = _root->_left;

					}
					else if (_root->_right && _root->_left) {
						node* tmp = getLargest(_root->_left);
						if (tmp->_parent->_right == tmp){
							if (tmp->_left)
								tmp->_parent->_right = tmp->_left;
							else
								tmp->_parent->_right = tmp->_right;
						}
						_root->_left->_parent = tmp;
						_root->_right->_parent = tmp;
						tmp->_right = _root->_right;
						if (tmp->_left != _bottom)
							tmp->_left = _root->_left;
						tmp->_parent = NULL;
						_root = tmp;
					}
					--_size;
					if (_size != 0)
						delete tmproot;
					balance(_root);
					return (1);
				}

				int	deleteBottom(node *income){
					if (income && income->_right)
						income = income->_right;
					node* tmp = _bottom->_parent;
					node* bottomparent = _bottom->_parent->_parent;
					if (_bottom->_parent == income){
						_bottom->_parent->_parent->_left = _bottom;
						_bottom->_parent = _bottom->_parent->_parent;
					}
					else{
						node* bottomnext = income;
						while (bottomnext && bottomnext->_left)
							bottomnext = bottomnext->_left;
						bottomnext->_left = _bottom;
						_bottom->_parent = bottomnext;
						income->_parent = bottomparent;
						bottomparent->_left = income;
					}
					balance(tmp);
					delete tmp;
					--_size;
					return (1);
				}

				int	deleteTop(node *income){
					node* tmp = _top->_parent;

					node* bottomparent = _top->_parent->_parent;
					if (_top->_parent->_parent == _root && income->_left == NULL){
						_root->_right = _top;
						_top->_parent = _root;
					}
					else{
						if (income && income->_left)
							income = income->_left;
						if (_top->_parent == income){
							_top->_parent->_parent->_right = _top;
							_top->_parent = _top->_parent->_parent;
						}
						else{
							node* bottomnext = income;
							while (bottomnext && bottomnext->_right)
								bottomnext = bottomnext->_right;
							bottomnext->_right = _top;
							_top->_parent = bottomnext;
							income->_parent = bottomparent;
							bottomparent->_right = income;
						}
					}
					balance(tmp);
					delete tmp;
					--_size;
					return (1);
				}

				int	deleteEnd(node* income){
					node* tmp = income->_parent;
					if (tmp->_right == income)
						tmp->_right = NULL;
					else
						tmp->_left = NULL;
					balance(tmp);
					delete income;
					--_size;
					return (1);
				}

				void	setParentLargest(node* largest){
					node* tmp = NULL;
					if (largest->_left)
						tmp = largest->_left;
					if (tmp){
						if (largest->_parent->_right == largest)
							largest->_parent->_right = tmp;
						else
							largest->_parent->_left = tmp;
						tmp->_parent = largest->_parent;
					}
					else{
						if (largest->_parent->_right == largest)
							largest->_parent->_right = largest->_right;
						else
							largest->_parent->_left = largest->_left;
					}
				}

				void	setIncomeParent(node* income, node* largest){
					/* set parent income */
					if (income->_parent->_right == income)
						income->_parent->_right = largest;
					else
						income->_parent->_left = largest;
					largest->_parent = income->_parent;

					/* set income left */
					if (income->_left){
						largest->_left = income->_left;
						income->_left->_parent = largest;

					}

					/* set income right */
					if (income->_right){
						largest->_right = income->_right;
						income->_right->_parent = largest;
					}
				}

				int	deleteNode(node* income){
					if (income->_parent == NULL)
						return (deleteRoot());
					else if (income == _top->_parent)
						return (deleteTop(_top->_parent));
					else if (income == _bottom->_parent)
						return (deleteBottom(_bottom->_parent));
					else if (income->_right == NULL && income->_left == NULL)
						return (deleteEnd(income));

					node* largest = NULL;
					if (income->_left)
						largest = getLargest(income->_left);
					else
						largest = income->_right;

					setParentLargest(largest);
					setIncomeParent(income, largest);
					balance(largest);
					delete income;
					--_size;
					return (1);
				}

				void	rightRotation(node* income)
				{
					node*	Y = income->_left;

					income->_left = Y->_right;
					if (Y->_right)
						Y->_right->_parent = income;

					Y->_right = income;
					Y->_parent = income->_parent;

					if (income->_parent && income->_parent->_left == income)
						income->_parent->_left = Y;
					else if (income->_parent)
						income->_parent->_right = Y;

					income->_parent = Y;

					if (Y->_parent == NULL)
						_root = Y;
				}

				void	leftRotation(node* income)
				{
					node*	Y = income->_right;

					income->_right = Y->_left;

					if (Y->_left)
						Y->_left->_parent = income;

					Y->_left = income;
					Y->_parent = income->_parent;

					if (income->_parent && income->_parent->_left == income)
						income->_parent->_left = Y;
					else if (income->_parent)
						income->_parent->_right = Y;

					income->_parent = Y;
					if (Y->_parent == NULL)
						_root = Y;
				}

				node*	findNode(node* income, const key_type& val) const{
					if (income == NULL || income == _bottom || income == _top)
						return (NULL);
					if (income->_data.first == val)
						return (income);
					if (income->_data.first > val && income->_left && income->_left != _bottom)
						return (findNode(income->_left, val));
					if (income->_data.first < val && income->_right && income->_right != _top)
						return (findNode(income->_right, val));
					return (NULL);
				}

				ft::pair<iterator,bool> set_root(const node_pointer tmp) {

					_root = tmp;
					_bottom->_parent = _root;
					_top->_parent = _root;
					_bottom->_parent->_left = _bottom;
					_top->_parent->_right = _top;
					++_size;
					return (ft::make_pair(iterator(_root), true));
				}

				int		height(node *income, int h){
					if (income == _root || income == _bottom || income == _top || income == NULL)
						return (h);
					int lx = height(income->_left, h + 1);
					int rx = height(income->_right, h + 1);
					if (lx > rx)
						return (lx);
					else
						return (rx);
				}

				void	balance(node *income){
					int	diff;
					while (income)
					{
						diff = height(income->_left, 0) - height(income->_right, 0);
						if (diff < -1 && (height(income->_right->_left, 0) - height(income->_right->_right, 0)) < 0)
							leftRotation(income);
						else if (diff < -1 && (height(income->_right->_left, 0) - height(income->_right->_right, 0)) >= 0){
							rightRotation(income->_right);
							leftRotation(income);
						}
						else if (diff > 1 && (height(income->_left->_left, 0) - height(income->_left->_right, 0)) > 0)
							rightRotation(income);
						else if (diff > 1 && (height(income->_left->_left, 0) - height(income->_left->_right, 0)) <= 0){
							leftRotation(income->_left);
							rightRotation(income);
						}
						income = income->_parent;
					}
				}

				ft::pair<iterator,bool> leaf(const node_pointer tmp){
					node* check = findNode(_root, tmp->_data.first);
					if (check)
						return ft::make_pair(iterator(check), false);
					node_pointer current = _root;
					node_pointer parent = NULL;

					while (current && current != _bottom && current != _top){
						parent = current;
						if (_comp(tmp->_data.first, current->_data.first))
							current = current->_left;
						else
							current = current->_right;
					}
					tmp->_parent = parent;
					if (_comp(tmp->_data.first, parent->_data.first)){
						if (parent->_left == _bottom){
							tmp->_left = _bottom;
							_bottom->_parent = tmp;
						}
						parent->_left = tmp;
					}
					else{
						if (parent->_right == _top){
							tmp->_right = _top;
							_top->_parent = tmp;
						}
						parent->_right = tmp;
					}
					++_size;
					balance(tmp);
					return (ft::make_pair(iterator(tmp), true));
				}
		   };
}
#endif
