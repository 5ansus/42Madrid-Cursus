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
	std::cout << "Testing Animal, Dog, and Cat" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nGetting Types" << std::endl;
	std::cout << j->getType() << "" << std::endl;
	std::cout << i->getType() << "" << std::endl;
	std::cout << meta->getType() << "" << std::endl;

	std::cout << "\nMaking Sounds" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\nDeleting Animals" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "\nTesting WrongAnimal and WrongCat" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nGetting Wrong Types" << std::endl;
	std::cout << wrongCat->getType() << "" << std::endl;

	std::cout << "\nMaking Wrong Sounds" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\nDeleting Wrong Animals" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "\nAdditional Tests" << std::endl;
	Dog basicDog;
	Cat basicCat;

	std::cout << "\nDirect makeSound calls" << std::endl;
	basicDog.makeSound();
	basicCat.makeSound();

	std::cout << "\nCopy Constructor Test" << std::endl;
	Dog dog2(basicDog);
	dog2.makeSound();

	std::cout << "\nAssignment Operator Test" << std::endl;
	Cat cat2;
	cat2 = basicCat;
	cat2.makeSound();

	return 0;
}
