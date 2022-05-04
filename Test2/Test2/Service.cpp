#include "Service.h"
#include <fstream>

void Service::addBuilding(std::unique_ptr<Building>&& building)
{
	this->buildings.push_back(std::move(building));
}

std::vector<const Building*> Service::getAllBuildings() const
{
	std::vector<const Building*> result;

	for (auto& building : this->buildings)
		result.push_back(building.get());

	return result;
}

std::vector<const Building*> Service::getAllToBeRestored() const
{
	std::vector<const Building*> result;

	for (auto& building : this->buildings)
	{
		if (building->mustBeRestored())
			result.push_back(building.get());
	}

	return result;
}

std::vector<const Building*> Service::getAllToBeDemolished() const
{
	std::vector<const Building*> result;

	for (auto& building : this->buildings)
	{
		if (building->canBeDemolished())
			result.push_back(building.get());
	}

	return result;
}

void Service::writeToFile(std::string filename, std::vector<const Building*> buildings)
{
	std::ofstream fout(filename);

	for (auto building : buildings)
		fout << building->toString();
}
