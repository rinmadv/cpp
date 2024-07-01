#ifndef DEF_MutantStack
#define DEF_MutantStack

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include <iterator>
#include "../includes/Format.hpp"

#define DEBUG true


template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}
    ~MutantStack() {}

    MutantStack<T>& operator=(const MutantStack<T>& rhs) {
        if (this != &rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    const_iterator end() const {
        return std::stack<T>::c.end();
    }

    reverse_iterator rbegin() {
        return std::stack<T>::c.rbegin();
    }

    const_reverse_iterator rbegin() const {
        return std::stack<T>::c.rbegin();
    }

    reverse_iterator rend() {
        return std::stack<T>::c.rend();
    }

    const_reverse_iterator rend() const {
        return std::stack<T>::c.rend();
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& stack) {
    os << "[ ";
    for (typename MutantStack<T>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        os << *it << " ";
    }
    os << "]";
    return os;
}


#endif