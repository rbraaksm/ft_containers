#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	template<typename T>
	struct Node
	{
		Node*	prev;
		Node*	next;
		T 		val;

		Node(const T& val = T(), Node* prev = NULL, Node* next = NULL) : prev(prev), next(next), val(val) {}
		Node(const Node& other) { *this = other; }
		explicit Node(Node* nxt, Node* prev, const T& d = T())
				: next(nxt), prev(prev), val(d){return;}
		~Node() {}
		Node& operator=(const Node& other)
		{
			prev = other.prev;
			next = other.next;
			val = other.val;
			return *this;
		}
	};
}

#endif
