#pragma once

#include <string>

class Building
{
public:
	std::string address;
	int constructionYear = 0;

	virtual bool mustBeRestored() const = 0;
	virtual bool canBeDemolished() const = 0;
	virtual std::string toString() const = 0;

	virtual ~Building() = default;
};
