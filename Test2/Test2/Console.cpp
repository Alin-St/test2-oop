#include "Console.h"
#include "Block.h"
#include "House.h"
#include <iostream>
#include <fstream>

Console::Console(Service& _service) : service(_service) {}

void Console::run()
{
	while (true)
	{
		std::cout << "\n\n"
			"1. Add new building\n"
			"2. Show all buildings\n"
			"3. Show all buildings that must be restored, located on a given street\n"
			"4. Save all buildings that must be restored to 'must_be_restored.txt' and all those that can be demolished to 'can_be_demolished.txt'\n"
			"0. Exit\n";

		int command = 0;
		std::cout << "Enter a command: ";
		std::cin >> command;

		if (command == 1)
			this->addNewBuilding();
		else if (command == 2)
			this->showAllBuildings();
		else if (command == 3)
			this->showBuildingsToRestore();
		else if (command == 4)
			this->saveBuildingsToRestoreAndDemolish();
		else if (command == 0)
			break;
		else
			std::cout << "Unknown command\n";
	}
}

void Console::addNewBuilding()
{
	std::cout <<
		"1. Add block of flats\n"
		"2. Add house\n"
		"0. Cancel\n";

	int command = 0;
	std::cout << "Enter a command: ";
	std::cin >> command;

	if (command < 1 || command > 2)
		return;

	std::unique_ptr<Building> building;

	std::string address;
	std::getline(std::cin, address);
	std::cout << "Address: ";
	std::getline(std::cin, address);

	int constructionYear = 0;
	std::cout << "Year: ";
	std::cin >> constructionYear;

	if (command == 1)
	{
		int totalApartments = 0;
		std::cout << "Total apartments: ";
		std::cin >> totalApartments;

		int occupiedApartments = 0;
		std::cout << "Occupied apartments: ";
		std::cin >> occupiedApartments;

		auto block = std::make_unique<Block>();
		block->address = address;
		block->constructionYear = constructionYear;
		block->totalApartments = totalApartments;
		block->occupiedApartments = occupiedApartments;

		building = std::move(block);
	}
	else
	{
		bool isHistorical = false;
		std::cout << "Is historical (1/0): ";
		std::cin >> isHistorical;

		auto house = std::make_unique<House>();
		house->address = address;
		house->constructionYear = constructionYear;
		house->isHistorical = isHistorical;

		building = std::move(house);
	}

	this->service.addBuilding(std::move(building));
	std::cout << "Building added\n";
}

void Console::showAllBuildings()
{
	auto buildings = this->service.getAllBuildings();
	this->printBuildings(buildings, "All buildings:");
}

void Console::showBuildingsToRestore()
{
	std::string street;
	std::getline(std::cin, street);
	std::cout << "Street: ";
	std::getline(std::cin, street);

	auto buildings = this->service.getAllToBeRestored();
	for (size_t i = 0; i < buildings.size(); ++i)
	{
		if (strstr(buildings[i]->address.c_str(), street.c_str()) == nullptr)
		{
			buildings.erase(buildings.begin() + i);
			--i;
		}
	}

	this->printBuildings(buildings, "Buildings to be restored: ");
}

void Console::saveBuildingsToRestoreAndDemolish()
{
	auto toRestore = this->service.getAllToBeRestored();
	std::ofstream fout1("must_be_restored.txt");
	for (auto building : toRestore)
		fout1 << building->toString();

	auto toDemolish = this->service.getAllToBeDemolished();
	std::ofstream fout2("can_be_demolished.txt");
	for (auto building : toDemolish)
		fout2 << building->toString();

	std::cout << "Operation completed\n";
}

void Console::printBuildings(const std::vector<const Building*>& buildings, std::string prompt)
{
	std::cout << prompt << '\n';

	for (size_t i = 0; i < buildings.size(); ++i)
		std::cout << i << ") " << buildings[i]->toString();
}
