#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>

# include "ListNode.hpp"
# include "ListIterator.hpp"
# include "ReverseIterator.hpp"
# include "Utils.hpp"
# include "Traits.hpp"

namespace ft{
	template<class T, class Alloc = std::allocator<T> >
	class list{
		public:
			typedef	T					value_type;
			typedef Alloc 				allocator_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;

			typedef ListIterator<value_type, pointer, reference>				iterator;
			typedef ListIterator<value_type, const_pointer, const_reference>	const_iterator;
			typedef ReverseIterator<iterator>									reverse_iterator;
			typedef ReverseIterator<const_iterator>								const_reverse_iterator;

			typedef ptrdiff_t			difference_type;
			typedef size_t				size_type;

			private:
				Node<value_type>*	_head;
				Node<value_type>*	_tail;
				size_t				_size;
				allocator_type		_alloc;

			public:
			/* Constructors */
				explicit list(const allocator_type &alloc = allocator_type()) :
				_head(new Node<value_type>()),
				_tail(new Node<value_type>()),
				_size(0),
				_alloc(alloc){
					_head->next = _tail;
					_tail->prev = _head;
				}

				explicit list(size_type n, const value_type& val = value_type(),
				 const allocator_type& alloc = allocator_type()) :
					_head(new Node<value_type>()),
					_tail(new Node<value_type>()),
					_size(0),
					_alloc(alloc){
						_head->next = _tail;
						_tail->prev = _head;
						assign(n, val);
					}

				template <class InputIterator>
		  		list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
					_head(new Node<value_type>()),
					_tail(new Node<value_type>()),
					_size(0),
					_alloc(alloc){
						_head->next = _tail;
						_tail->prev = _head;
						assign(first, last);
					}

				list(const list& x) :
					_head(new Node<value_type>()),
					_tail(new Node<value_type>()),
					_size(0),
					_alloc(x._alloc){
						_head->next = _tail;
						_tail->prev = _head;
						assign(x.begin(), x.end());
					}

			/* Destructor */
				virtual ~list(){
					clear();
					delete _head;
					delete _tail;
				}

			/* Assignment operator */
				list&	operator=(const list& x){
					if (this != &x){
						clear ();
						_head->next = _tail;
						_tail->prev = _head;
						assign(x.begin(), x.end());
					}
					return (*this);
				}

			/* Iterators */
				iterator				begin(){return (iterator(_head->next));}
				const_iterator			begin() const{return (const_iterator(_head->next));}
				iterator				end(){return (iterator(_tail));}
				const_iterator			end() const{return (const_iterator(_tail));}
				reverse_iterator		rbegin(){return (reverse_iterator(_tail->prev));}
				const_reverse_iterator	rbegin() const {return (const_reverse_iterator(_tail->prev));}
				reverse_iterator		rend(){return (reverse_iterator(_head));}
				const_reverse_iterator	rend() const {return (const_reverse_iterator(_head));}

			/* Capacity */
				bool empty() const{
					if (_size == 0)
						return (true);
					return (false);
				}

				size_type size() const{return (_size);}
				size_type max_size() const{return (_alloc.max_size());}

			/* Element access */
				reference 			front(){return (_head->next->data);}
				const_reference 	front() const{return (_head->next->data);}
				reference 			back(){return (_tail->prev->data);}
				const_reference 	back() const{return (_tail->prev->data);}

			/* Modifiers */
				template<class InputIterator>
				void assign(InputIterator first, InputIterator last,
						typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0){
					clear();
					for (; first != last; ++first)
						push_back(*first);
				}

				void assign(size_type n, const value_type& val){
					clear();
					for (; n > 0; n--)
						push_back(val);
				}

				void push_front(const value_type& val){
					Node<value_type> *node = new Node<value_type>(val);
					_head->next->prev = node;
					node->next = _head->next;
					node->prev = _head;
					_head->next = node;
					++_size;
				}

				void pop_front(){
					if (_size){
						Node<value_type>* node = _head->next;
						_head->next = _head->next->next;
						_head->next->prev = _head;
						_size--;
						delete node;
					}
				}

				void push_back(const value_type& val){
					Node<value_type>* node = new Node<value_type>(val);
					node->prev = _tail->prev;
					_tail->prev->next = node;
					_tail->prev = node;
					node->next = _tail;
					_size++;
				}

				void pop_back(){
					if (_size){
						Node<value_type>* node = _tail->prev;
						_tail->prev = _tail->prev->prev;
						_tail->prev->next = _tail;
						_size--;
						delete node;
					}
				}

				iterator insert(iterator position, const value_type& val){
					Node<value_type>* pointer = position.getNode();
					Node<value_type>* node = new Node<value_type>(pointer->next, pointer->prev, val);
					node->prev = pointer->prev;
					node->next = pointer;
					pointer->prev->next = node;
					pointer->prev = node;
					_size++;
					return (iterator(node));
				}

				void insert(iterator position, size_type n, const value_type& val){
					for (size_type i = 0; i < n; i++)
						insert(position, val);
				}

				template<class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last,
							typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0){
					for(; first != last; ++first)
						insert(position, *first);
				}

				iterator erase(iterator position){
					Node<value_type>* node = position.getNode();
					node->prev->next = node->next;
					node->next->prev = node->prev;
					delete node;
					--_size;
					return (++position);
				}

				iterator erase(iterator first, iterator last){
					while (first != last)
						first = erase(first);
					return (first);
				}

				void clear(){
					while (_size)
						pop_back();
				}

				void swap(list& x){
					ft::swap(_head, x._head);
					ft::swap(_tail, x._tail);
					ft::swap(_size, x._size);
					ft::swap(_alloc, x._alloc);
				}

				void resize(size_type n, value_type val = value_type()){
					while (n < _size)
						pop_back();
					while (n > _size)
						push_back(val);
				}

			/* Operations */
				void splice(iterator position, list& x){
					splice(position, x, x.begin(), x.end());
				}

				void splice(iterator position, list& x, iterator i){
					Node<value_type>* node = i.getNode();
					Node<value_type>* tmp = position.getNode();
					node->prev->next = node->next;
					node->next->prev = node->prev;
					--x._size;

					tmp->prev->next = node;
					node->next = tmp;
					node->prev = tmp->prev;
					tmp->prev = node;
					++_size;
				}

				void splice(iterator position, list& x, iterator first, iterator last){
					for(; first != last; splice(position, x, first++)){}
				}

				void remove(const value_type& val){
					for (iterator it = begin(); it != end(); ++it)
						if (*it == val)
							erase(it);
				}

				template <class Predicate>
		  		void remove_if(Predicate pred){
					for (iterator it = begin(); it != end(); ++it)
						if (pred(*it))
							erase(it);
				  }

				void unique(){
					for(iterator it = begin(); it != end();)
						if (*it == it.getNode()->next->data)
							it = erase(it);
						else
							++it;
				}

				template <class BinaryPredicate>
		  		void unique(BinaryPredicate binary_pred){
					for (iterator it = ++begin() ;it != this->end(); ++it)
						if (binary_pred(*it, it.getNode()->prev->data))
							erase(it);
		  		}

				void merge(list& x){
					if (&x == this)
						return ;
					iterator ix = x.begin();
					iterator it = begin();
					for(; it != end(); ++it){
						while (*it > *ix){
							splice(it, x, ix);
							ix = x.begin();}
					}
					if (x._size)
						splice(end(), x);
				}

				template <class Compare>
		  		void merge (list& x, Compare comp){
					if (&x == this)
						return ;
					iterator ix;
					iterator it = begin();
					for(; x._size && it != end(); ++it){
						ix = x.begin();
						if (comp(*ix, *it))
							splice(it, x, ix);
					}
					if (x._size)
						splice(end(), x);
		  		}

				void sort(){
					for(iterator it = begin(); it != end(); ++it)
						if (*it < it.getNode()->prev->data){
							ft::swap(it.getNode()->data, it.getNode()->prev->data);
							it = begin();
						}
				}

				template <class Compare>
		  		void sort(Compare comp){
					for(iterator it = begin(); it != end(); ++it)
						if (comp(*it, it.getNode()->prev->data)){
							ft::swap(it.getNode()->data, it.getNode()->prev->data);
							it = begin();
						}
				}

				void reverse(){
					if (size() <= 1)
						return ;
					Node<value_type>* node = _head->next;
					for(; node != _tail; node = node->prev)
						ft::swap(node->next, node->prev);
					ft::swap(_head->next, _head->prev);
					ft::swap(_tail->next, _tail->prev);
					ft::swap(_head, _tail);
				}

			/* Observers */
				allocator_type get_allocator() const{ return (_alloc);}
	};

	/* Relational operators */
	template <class T, class Alloc>
	bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}

	template <class value_type, class allocator_type>
	void swap(list<value_type, allocator_type>& x, list<value_type, allocator_type>& y){ x.swap(y);}

	template<class value_type, class allocator_type>
	bool operator!=(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs){return !(lhs == rhs);}

	template<class value_type, class allocator_type>
	bool operator<(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs){return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

	template<class value_type, class allocator_type>
	bool operator<=(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs){return (!(rhs < lhs));}

	template<class value_type, class allocator_type>
	bool operator>(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs){return (rhs < lhs);}

	template<class value_type, class allocator_type>
	bool operator>=(const list<value_type, allocator_type>& lhs, const list<value_type, allocator_type>& rhs){return (!(lhs < rhs));}
}


#endif
