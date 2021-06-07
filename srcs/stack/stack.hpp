#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft{
	template <class T, class Container = vector<T> >
	class stack{
		// Member types
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type		_ctype;

		public:
		// Member functions
			explicit stack(const container_type& ctnr = container_type()) : _ctype(ctnr){}
			bool empty() const{return (_ctype.empty());}
			size_type size() const{return (_ctype.size());}
			value_type& top(){return (_ctype.back());}
			const value_type& top() const {return (_ctype.back());}
			void push (const value_type& val){return (_ctype.push_back(val));}
			void pop(){return (_ctype.pop_back());}

			template <class value_type, class ctnr>
			friend bool operator==(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs);

			template <class value_type, class ctnr>
			friend bool operator<(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs);
	};

		// Relational operators
			template <class value_type, class ctnr>
			bool operator==(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs){return (lhs._ctype == rhs._ctype);}

			template <class value_type, class ctnr>
			bool operator<(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs){return (lhs._ctype < rhs._ctype);}

			template <class value_type, class ctnr>
			bool operator!=(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs){return !(lhs == rhs);}

			template <class value_type, class ctnr>
			bool operator<=(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs){return !(rhs < lhs);}

			template <class value_type, class ctnr>
			bool operator>(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs){return (rhs < lhs);}

			template <class value_type, class ctnr>
			bool operator>=(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs){return !(lhs < rhs);}
}
#endif
