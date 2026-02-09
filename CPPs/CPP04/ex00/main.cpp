/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:11:01 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:11:01 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Testing Animal, Dog, and Cat ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n=== Getting Types ===" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n=== Making Sounds ===" << std::endl;
	i->makeSound();	 // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n=== Deleting Animals ===" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n=== Testing WrongAnimal and WrongCat ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n=== Getting Wrong Types ===" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << "\n=== Making Wrong Sounds ===" << std::endl;
	wrongCat->makeSound();	// will output the WrongAnimal sound (not virtual!)
	wrongMeta->makeSound();

	std::cout << "\n=== Deleting Wrong Animals ===" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n\n=== Additional Tests ===" << std::endl;
	Dog basicDog;
	Cat basicCat;

	std::cout << "\n=== Direct makeSound calls ===" << std::endl;
	basicDog.makeSound();
	basicCat.makeSound();

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	Dog dog2(basicDog);
	dog2.makeSound();

	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	Cat cat2;
	cat2 = basicCat;
	cat2.makeSound();

	std::cout << "\n=== End of tests ===" << std::endl;
	return 0;
}
