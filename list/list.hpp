#ifndef LIST_HPP
# define LIST_HPP

// # include <cstddef>
// # include <cstdlib>
# include <memory>
# include <iterator>
# include <algorithm>

// https://www.cplusplus.com/reference/list/list/

namespace ft{
    template < class T, class Alloc = std::allocator<T> >
    class list{
        public:
            typedef T           value_type;
            typedef Alloc       allocator_type;
            typedef T           &reference;
            typedef const T     &const_reference;
            typedef T           *pointer;
            typedef const T     *const_pointer;
            typedef
    };
}
#endif
