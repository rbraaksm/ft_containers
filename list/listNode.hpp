#ifndef LISTNODE_HPP
# define LISTNODE_HPP

# include <iostream>

template <class T>
class Node{

	public:
		Node*	_next;
		Node*	_prev;
		T		_data;
		explicit Node() : _next(NULL), _prev(NULL), _data(T()){return;}
		explicit Node(T element): _next(NULL), _prev(NULL), _data(T(element)) {return;}
		explicit Node(Node* nxt, Node* prev, const T& d = T())
				: _next(nxt), _prev(prev), _data(d){return;}
		Node&	operator=(const Node& rhs){
			if (this != &rhs){
				_next = rhs._next;
				_prev = rhs._prev;
				_data = rhs._data;
			}
			return (*this);
		}

		virtual ~Node(){return ;}
		Node*	getNext() const{return (_next);}
		Node*	getPrev() const{return (_prev);}
		T	getData() {return (_data);}
};

#endif
