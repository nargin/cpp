/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:21:56 by romaurel          #+#    #+#             */
/*   Updated: 2023/06/14 20:09:34 by romaurel         ###   ########.fr       */
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
	const Animal* meta = new Animal();

	std::cout << std::endl;
	std::cout << "Animal type: " << meta->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Abstract: ";
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	return (0);
}