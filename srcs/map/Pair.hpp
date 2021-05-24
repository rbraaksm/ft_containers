#pragma once

namespace ft {

    template<class T1, class T2>
    struct pair {

		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair() : first(first_type()), second(second_type()) {}

		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
       
	    pair(const T1& x, const T2& y) : first(x), second(y) {}

        template< class U1, class U2 >
        pair(const std::pair<U1, U2>& p) : first(p.first), second(p.second) {}

		pair&		operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}

	};

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ) {
		pair<T1, T2> ret;

		ret.first = t;
		ret.second = u;

		return (ret);
	}

    template< class T1, class T2 >
    bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template<class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template<class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { 
		return !(lhs == rhs);
	}

    template<class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (rhs < lhs);
	}

    template<class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { 
		return !(rhs < lhs); 
	}

    template<class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs < rhs); 
	}
}


