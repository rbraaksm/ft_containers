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
			// bool	_isBlack;
			// bool 	_nil;

			explicit mapNode(value_type const& val = value_type()): _parent(NULL), _left(NULL), _right(NULL), _data(val) {}
			mapNode(const mapNode<T>& x) : _data(x._data), _parent(x._parent), _left(x._left), _right(x._right){}
			virtual ~mapNode() {};
			mapNode& operator=(const mapNode& obj) {
				if (this != &obj) {
					_data = obj._data;
					_left = obj._left;
					_right = obj._right;
					_parent = obj._parent;
					// _isBlack = obj._isBlack;
					// _nil = obj._nil;
				}
				return *this;
			}
	};
}
#endif