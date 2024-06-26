#ifndef DEF_WHATEVER
#define DEF_WHATEVER

template< typename T >

T const &	max(T const & x, T const & y){
	return (x > y ? x : y);
}

template< typename T >

T const &	min(T const & x, T const & y){
	return (x < y ? x : y);
}

template< typename T >

void	swap(T & x, T & y){
	T temp = y;
	y = x;
	x = temp;
}

#endif