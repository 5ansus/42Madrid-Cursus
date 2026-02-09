/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:12:43 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:12:43 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	std::cout << "=== Testing Abstract Class ===" << std::endl;
	std::cout << "\nThis line should NOT compile if uncommented:" << std::endl;
	std::cout << "// AAnimal* animal = new AAnimal();" << std::endl;
	std::cout << "(AAnimal is abstract and cannot be instantiated)\n"
			  << std::endl;

	// Uncommenting the following line should cause a compilation error:
	// AAnimal* animal = new AAnimal();

	std::cout << "=== Basic tests ===" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << "\n--- Making sounds ---" << std::endl;
	j->makeSound();
	i->makeSound();

	std::cout << "\n--- Getting types ---" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << "\n--- Deleting ---" << std::endl;
	delete j;
	delete i;

	std::cout << "\n\n=== Array of AAnimals ===" << std::endl;
	const int arraySize = 6;
	AAnimal* animals[arraySize];

	std::cout << "\n--- Creating Dogs ---" << std::endl;
	for (int idx = 0; idx < arraySize / 2; idx++) {
		animals[idx] = new Dog();
	}

	std::cout << "\n--- Creating Cats ---" << std::endl;
	for (int idx = arraySize / 2; idx < arraySize; idx++) {
		animals[idx] = new Cat();
	}

	std::cout << "\n--- Making sounds ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}

	std::cout << "\n--- Deleting AAnimals ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		delete animals[idx];
	}

	std::cout << "\n\n=== Deep Copy Test ===" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "Chase the cat!");
	originalDog->getBrain()->setIdea(1, "Eat treats!");

	Dog* copiedDog = new Dog(*originalDog);

	std::cout << "\nOriginal ideas:" << std::endl;
	std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "\nCopied ideas:" << std::endl;
	std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "\nModifying original..." << std::endl;
	originalDog->getBrain()->setIdea(0, "Take a nap");

	std::cout << "\nOriginal idea 0: " << originalDog->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Copied idea 0 (unchanged): "
			  << copiedDog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nBrain addresses:" << std::endl;
	std::cout << "Original: " << originalDog->getBrain() << std::endl;
	std::cout << "Copied: " << copiedDog->getBrain() << std::endl;

	delete originalDog;
	delete copiedDog;

	std::cout << "\n\n=== Direct instantiation test ===" << std::endl;
	Dog directDog;
	Cat directCat;

	directDog.makeSound();
	directCat.makeSound();

	std::cout << "\n=== End of tests ===" << std::endl;
	return 0;
}
