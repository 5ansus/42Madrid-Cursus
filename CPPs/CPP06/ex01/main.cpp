/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/18 19:09:50 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/18 19:26:10 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data datos;
	datos.building = "Norte3";
	datos.name = "Santiago";
	datos.surname = "Fernandez";

	std::cout << "Datos struct original" << std::endl;
	std::cout << "\tBuilding: " << datos.building << std::endl;
	std::cout << "\tName: " << datos.name << std::endl;
	std::cout << "\tSurname: " << datos.surname << std::endl;
	std::cout << "---------------------------------" << std::endl;



	uintptr_t serializado = Serializer::serialize(&datos);
	Data *ptr_data = Serializer::deserialize(serializado);

	std::cout << "Datos puntero deserializado" << std::endl;
	std::cout << "\tBuilding: " << ptr_data->building << std::endl;
	std::cout << "\tName: " << ptr_data->name << std::endl;
	std::cout << "\tSurname: " << ptr_data->surname << std::endl;
	std::cout << "---------------------------------" << std::endl;



	if (datos.building != ptr_data->building)
	{
		std::cerr << "Los datos de buidling no son los mismos" << std::endl;
		return 1;
	}
	if (datos.name != ptr_data->name)
	{
		std::cerr << "Los datos de name no son los mismos" << std::endl;
		return 1;
	}
	if (datos.surname != ptr_data->surname)
	{
		std::cerr << "Los datos de buidling no son los mismos" << std::endl;
		return 1;
	}

	std::cout << "Todos los datos son correctos" << std::endl;
}
