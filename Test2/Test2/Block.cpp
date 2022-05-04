#include "Block.h"
#include <ctime>

bool Block::mustBeRestored() const
{
	std::time_t currentTime = std::time(nullptr);
	int currentYear = std::localtime(&currentTime)->tm_year + 1900;
	float occupiedPrecentage = (float)this->occupiedApartments / this->totalApartments;

	return currentYear - this->constructionYear > 40 && occupiedPrecentage > 0.80f;
}

bool Block::canBeDemolished() const
{
	float occupiedPrecentage = (float)this->occupiedApartments / this->totalApartments;
	return occupiedPrecentage < 0.05f;
}

std::string Block::toString() const
{
	return "Type: Block, Address: \"" + this->address + "\", Construction year: " + std::to_string(this->constructionYear) + ", Total apartments: "
		+ std::to_string(this->totalApartments) + ", Occupied apartments: " + std::to_string(this->occupiedApartments) + "\n";
}
