#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){

}

Base* generate(void){
	Base *ret;
	int random = rand() % 3;
	switch (random) {
		case 0:
			ret = new A;
			break;
		case 1:
			ret = new B;
			break;
		case 2:
			ret = new C;
			break;
	}
	return ret;
}

void identify(Base *p){

	if (isType<Base, A>(p, "A"))
		return ;
	if (isType<Base, B>(p, "B"))
		return ;
	if (isType<Base, C>(p, "C"))
		return ;
}

void identify(Base &p){

	if (isType<Base, A>(p, "A"))
		return ;
	if (isType<Base, B>(p, "B"))
		return ;
	if (isType<Base, C>(p, "C"))
		return ;
}
