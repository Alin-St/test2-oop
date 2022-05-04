#pragma once

#include "Building.h"
#include <vector>
#include <memory>

class Service
{
	std::vector<std::unique_ptr<Building>> buildings;

public:
	Service() = default;
	Service(const Service&) = delete;
	Service& operator=(const Service&) = delete;

	void addBuilding(std::unique_ptr<Building>&& building);
	std::vector<const Building*> getAllBuildings() const;
	std::vector<const Building*> getAllToBeRestored() const;
	std::vector<const Building*> getAllToBeDemolished() const;

	static void writeToFile(std::string filename, std::vector<const Building*> buildings);
};
