#ifndef BASE_TPP
# define BASE_TPP
# ifndef BASE_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

template <typename V, typename T>
bool isType(V *input, std::string str){
	T *temp = dynamic_cast<T*>(input);
	bool ret = !(temp == NULL);
	if (ret)
		std::cout << "The pointer is type: " << str << std::endl;
	return (ret);
}

template <typename V, typename T>
bool isType(V &input, std::string str){
	try
	{
		T temp = dynamic_cast<T&>(input);
		std::cout << "The object is type: " << str << std::endl;
	}
	catch(const std::exception& e)
	{
		return false;
	}

	return (true);
}

#endif
