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
	std::cout << "Tests from subject\n" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;  // should not create a leak
	delete i;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "\nArray of Animals" << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];

	std::cout << "\nCreating Dogs\n" << std::endl;
	for (int idx = 0; idx < arraySize / 2; idx++) {
		animals[idx] = new Dog();
	}

	std::cout << "\nCreating Cats\n" << std::endl;
	for (int idx = arraySize / 2; idx < arraySize; idx++) {
		animals[idx] = new Cat();
	}

	std::cout << "\nMaking sounds\n" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}

	std::cout << "\nDeleting Animals\n" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		delete animals[idx];
	}

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "\n\nDeep Copy Test\n" << std::endl;
	std::cout << "\nCreating original dog\n" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "I want to play!");
	originalDog->getBrain()->setIdea(1, "I love my owner!");

	std::cout << "\nCreating copy of dog\n" << std::endl;
	Dog* copiedDog = new Dog(*originalDog);

	std::cout << "\nOriginal dog's ideas\n" << std::endl;
	std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "\nCopied dog's ideas (should be same)\n" << std::endl;
	std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "\nModifying original dog's ideas\n" << std::endl;
	originalDog->getBrain()->setIdea(0, "I want to sleep now");

	std::cout << "\nOriginal dog's new idea\n" << std::endl;
	std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nCopied dog's idea (should be unchanged - proving deep "
				 "copy)\n"
			  << std::endl;
	std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nBrain addresses (should be different)\n" << std::endl;
	std::cout << "Original Brain: " << originalDog->getBrain() << std::endl;
	std::cout << "Copied Brain: " << copiedDog->getBrain() << std::endl;

	std::cout << "\nDeleting dogs" << std::endl;
	delete originalDog;
	delete copiedDog;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "\n\nDeep Copy Test with Cat\n" << std::endl;
	Cat* originalCat = new Cat();
	originalCat->getBrain()->setIdea(0, "I want tuna!");

	Cat* copiedCat = new Cat(*originalCat);

	std::cout << "\nOriginal Cat Brain: " << originalCat->getBrain() << std::endl;
	std::cout << "Copied Cat Brain: " << copiedCat->getBrain() << std::endl;
	std::cout << "\nOriginal idea: " << originalCat->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Copied idea: " << copiedCat->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << std::endl;

	delete originalCat;
	delete copiedCat;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "\n\nAssignment Operator Test\n" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "First dog idea");

	Dog dog2;
	dog2.getBrain()->setIdea(0, "Second dog idea");

	std::cout << "\nBefore assignment:\n" << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	dog2 = dog1;

	std::cout << "\nAfter assignment:\n" << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\nBrain addresses (should be different):" << std::endl;
	std::cout << "Dog1 Brain: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 Brain: " << dog2.getBrain() << std::endl;
	std::cout << std::endl;
	return 0;
}
