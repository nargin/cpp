/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:21:56 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 19:38:51 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int		main(void)
{
	Animal*	animals[] = {new Dog(), new Cat()};

	std::cout << std::endl;
	std::cout << "Animal:" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 2; i++)
		delete animals[i];
	return (0);
}