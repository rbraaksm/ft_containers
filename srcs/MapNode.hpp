#ifndef MAPNODE_HPP
# define MAPNODE_HPP

# include <iostream>

namespace ft{
	template <class T>
	class node{
		public:
			node*	_parent;
			node*	_left;
			node*	_right;
			T		_data;

			explicit node(T const& val = T()): _parent(NULL), _left(NULL), _right(NULL), _data(val){}
			node(const node<T>& x) : _parent(x._parent), _left(x._left), _right(x._right), _data(x._data){}
			virtual ~node(){};
			node& operator=(const node& obj){
				if (this != &obj){
					_parent = obj._parent;
					_left = obj._left;
					_right = obj._right;
					_data = obj._data;
				}
				return (*this);
			}

			node*	getNext(){
				node* next = this;

				if (next->_right)
				{
					next = next->_right;
					while (next->_left)
						next = next->_left;
				}
				else if (next == next->_parent->_left)
					next = next->_parent;
				else if (next == next->_parent->_right)
				{
					while (next != next->_parent->_left)
						next = next->_parent;
					next = next->_parent;
				}
				return (next);
			}

			node*		getPrev(){
				node* next = this;
				node* tmp = next->_parent;
				if (next->_left)
				{
					next = next->_left;
					while (next->_right)
						next = next->_right;
					return (next);
				}
				while (tmp && next == tmp->_left)
				{
					tmp = tmp->_parent;
					next = next->_parent;
				}
				if (!tmp){
					while (next->_right != NULL)
						next = next->_right;
					tmp = next->_right;
				}
				return (tmp);
			}
	};
}
#endif
