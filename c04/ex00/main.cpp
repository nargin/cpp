/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:21:56 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:19:34 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int		main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongJ = new WrongCat();

	std::cout << std::endl;
	std::cout << "Animal:" << std::endl;
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "Dog:" << std::endl;
	std::cout << "Type: " << j->getType() << std::endl;
	j->makeSound();
	std::cout << std::endl;
	std::cout << "Cat:" << std::endl;
	std::cout << "Type: " << i->getType() << std::endl;
	i->makeSound();
	std::cout << std::endl;
	std::cout << "WrongAnimal:" << std::endl;
	std::cout << "Type: " << wrongMeta->getType() << std::endl;
	wrongMeta->makeSound();
	std::cout << std::endl;
	std::cout << "WrongCat:" << std::endl;
	std::cout << "Type: " << wrongJ->getType() << std::endl;
	wrongJ->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongJ;
	return (0);
}