#ifndef MAPNODE_HPP
# define MAPNODE_HPP

# include <iostream>

namespace ft{
	template <class T>
	class mapNode{
		public:
			typedef T			value_type;
			typedef	T&			reference;
			typedef const T&	const_reference;
			typedef	T*			pointer;
			typedef	const T*	const_pointer;

			mapNode*	_parent;
			mapNode*	_left;
			mapNode*	_right;
			T			_data;
			int			_height;

			explicit mapNode(value_type const& val = value_type()): _parent(NULL), _left(NULL), _right(NULL), _data(val), _height(0) {}
			mapNode(const mapNode<T>& x) : _parent(x._parent), _left(x._left), _right(x._right), _data(x._data){}
			virtual ~mapNode() {};
			mapNode& operator=(const mapNode& obj) {
				if (this != &obj) {
					_parent = obj._parent;
					_left = obj._left;
					_right = obj._right;
					_data = obj._data;
					_height = obj._height;
				}
				return (*this);
			}

			mapNode*	getNext() {
				mapNode* next = this;

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
				return next;
			}
	};
}
#endif