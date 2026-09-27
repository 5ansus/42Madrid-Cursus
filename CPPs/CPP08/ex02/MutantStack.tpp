/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 18:34:18 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 19:36:02 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP
# ifndef MUTANT_STACK_HPP
#  error __FILE__ has to be included only from its .hpp
# endif

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(){}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other)
	: std::stack<T, Container>(other){}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other){
	if (this == &other)
		return *this;

	std::stack<T, Container>::operator=(other);
	return this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(){
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(){
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const{
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const{
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(){
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(){
	return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const{
	return this->c.rend();
}


template <typename T, typename Container>
std::ostream& operator<<(std::ostream &os, const MutantStack<T, Container> &stack) {
	os << "Stack {";
	for (typename MutantStack<T>::const_reverse_iterator iter = stack.rbegin(); iter < stack.rend(); ++iter){
		os << " " << *iter;
	}
	os << " }";
	return os;
}

#endif
