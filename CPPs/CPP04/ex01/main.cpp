/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:11:38 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:11:38 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	std::cout << "=== Basic tests from subject ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;  // should not create a leak
	delete i;

	std::cout << "\n\n=== Array of Animals ===" << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];

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

	std::cout << "\n--- Deleting Animals ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		delete animals[idx];
	}

	std::cout << "\n\n=== Deep Copy Test ===" << std::endl;
	std::cout << "\n--- Creating original dog ---" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "I want to play fetch!");
	originalDog->getBrain()->setIdea(1, "I love my owner!");

	std::cout << "\n--- Creating copy of dog ---" << std::endl;
	Dog* copiedDog = new Dog(*originalDog);

	std::cout << "\n--- Original dog's ideas ---" << std::endl;
	std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "\n--- Copied dog's ideas (should be same) ---" << std::endl;
	std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "\n--- Modifying original dog's ideas ---" << std::endl;
	originalDog->getBrain()->setIdea(0, "I want to sleep now");

	std::cout << "\n--- Original dog's new idea ---" << std::endl;
	std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Copied dog's idea (should be unchanged - proving deep "
				 "copy) ---"
			  << std::endl;
	std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Brain addresses (should be different) ---" << std::endl;
	std::cout << "Original Brain: " << originalDog->getBrain() << std::endl;
	std::cout << "Copied Brain: " << copiedDog->getBrain() << std::endl;

	std::cout << "\n--- Deleting dogs ---" << std::endl;
	delete originalDog;
	delete copiedDog;

	std::cout << "\n\n=== Deep Copy Test with Cat ===" << std::endl;
	Cat* originalCat = new Cat();
	originalCat->getBrain()->setIdea(0, "I want tuna!");

	Cat* copiedCat = new Cat(*originalCat);

	std::cout << "Original Cat Brain: " << originalCat->getBrain() << std::endl;
	std::cout << "Copied Cat Brain: " << copiedCat->getBrain() << std::endl;
	std::cout << "Original idea: " << originalCat->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Copied idea: " << copiedCat->getBrain()->getIdea(0)
			  << std::endl;

	delete originalCat;
	delete copiedCat;

	std::cout << "\n\n=== Assignment Operator Test ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "First dog idea");

	Dog dog2;
	dog2.getBrain()->setIdea(0, "Second dog idea");

	std::cout << "Before assignment:" << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	dog2 = dog1;

	std::cout << "\nAfter assignment:" << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\nBrain addresses (should be different):" << std::endl;
	std::cout << "Dog1 Brain: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 Brain: " << dog2.getBrain() << std::endl;

	std::cout << "\n=== End of tests ===" << std::endl;
	return 0;
}
