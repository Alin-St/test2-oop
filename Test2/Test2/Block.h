#pragma once

#include "Building.h"

class Block : public Building
{
public:
	int totalApartments = 0;
	int occupiedApartments = 0;

	bool mustBeRestored() const override;
	bool canBeDemolished() const override;
	std::string toString() const override;
};
