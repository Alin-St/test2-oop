#pragma once

#include "Building.h"

class House : public Building
{
public:
	bool isHistorical;

	bool mustBeRestored() const override;
	bool canBeDemolished() const override;
	std::string toString() const override;
};
