#ifndef LISTNODE_HPP
# define LISTNODE_HPP

# include <iostream>

template <class T>
class Node{
	public:
		Node*	next;
		Node*	prev;
		T		data;

		explicit Node() : next(NULL), prev(NULL), data(T()){return;}
		explicit Node(T element): next(NULL), prev(NULL), data(T(element)){return;}
		explicit Node(Node* nxt, Node* prev, const T& d = T())
				: next(nxt), prev(prev), data(d){return;}
		Node&	operator=(const Node& rhs){
			if (this != &rhs){
				next = rhs.next;
				prev = rhs.prev;
				data = rhs.data;
			}
			return (*this);
		}

		virtual ~Node(){return;}
		Node*	getNext() const{return (next);}
		Node*	getPrev() const{return (prev);}
};

#endif
