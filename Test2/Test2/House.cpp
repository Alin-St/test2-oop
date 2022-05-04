#include "House.h"
#include <ctime>

bool House::mustBeRestored() const
{
	std::time_t currentTime = std::time(nullptr);
	int currentYear = std::localtime(&currentTime)->tm_year + 1900;
	return currentYear - this->constructionYear > 100;
}

bool House::canBeDemolished() const
{
	return !this->isHistorical;
}

std::string House::toString() const
{
	return "Type: House, Address: \"" + this->address + "\", Construction year: " + std::to_string(this->constructionYear) +
		", Is Historical: " + std::to_string(this->isHistorical) + "\n";
}
