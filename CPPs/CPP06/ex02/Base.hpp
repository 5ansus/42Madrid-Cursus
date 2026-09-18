#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base {
	public:
		virtual ~Base();
};

#include "Base.tpp"


Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
