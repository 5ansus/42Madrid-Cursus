#include "Base.hpp"
#include <ctime>


int main(){
	srand(time(NULL));
	Base *obj;
	for (int i = 0; i < 10; i++)
	{
		obj = generate();
		identify(*obj);
		identify(obj);
	}
}
