#pragma once

#include "Service.h"

class Console
{
private:
	Service& service;

public:
	Console(Service& _service);

	void run();

	void addNewBuilding();
	void showAllBuildings();
	void showBuildingsToRestore();
	void saveBuildingsToRestoreAndDemolish();

private:
	void printBuildings(const std::vector<const Building*>& buildings, std::string prompt);
};
