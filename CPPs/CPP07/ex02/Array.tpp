#ifndef ARRAY_TPP
# define ARRAY_TPP
# ifndef ARRAY_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

template <typename T>
Array<T>::Array()
: _size(0), _memory(new T[0]){
}

template <typename T>
Array<T>::Array(unsigned int elements)
: _size(elements), _memory(new T[elements]){
}

template <typename T>
Array<T>::Array(const Array<T>  &other)
: _size(other._size), _memory(new T[other._size]){
	for (unsigned int i = 0; i < other._size; i++){
		_memory[i] = other._memory[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>  &other){
	if (this == &other)
		return *this;
	T *new_memory = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++){
		new_memory[i] = other._memory[i];
	}
	delete[] _memory;
	_memory = new_memory;
	_size = other._size;
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] _memory;
}

template <typename T>
unsigned int Array<T>::size() const{
	return _size;
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= _size)
		throw std::exception();
	return _memory[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _size)
		throw std::exception();
	return _memory[index];
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const Array<T> &array){
	os << "Start of the array. Size(" << array.size() << ")" << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
		os << "\tindex-" << i << ": " << array[i] << std::endl;
	os << "End of array";
	return os;
}

// template <typename T>
// const char* Array<T>::ArrayException::what() const throw() {
// 	return "Error: Value out of bounds.";
// }

#endif
