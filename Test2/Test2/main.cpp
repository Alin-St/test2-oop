#include "Console.h"
#include "Block.h"
#include "House.h"

void addSomeData(Service& service);

int main()
{
	{
		Service service;
		Console console(service);

		addSomeData(service);

		console.run();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}

void addSomeData(Service& service)
{
	auto block = std::make_unique<Block>();
	block->address = "Str. Lalelelor, nr 5; !restore, demolish"; block->constructionYear = 2010; block->totalApartments = 40; block->occupiedApartments = 1;
	service.addBuilding(std::move(block));

	block = std::make_unique<Block>();
	block->address = "Str. Soarelui, nr 96; restore, !demolish"; block->constructionYear = 1900; block->totalApartments = 25; block->occupiedApartments = 24;
	service.addBuilding(std::move(block));

	auto house = std::make_unique<House>();
	house->address = "Str. Unirii, Loc Bistrita, nr 10; !restore, demolish"; house->constructionYear = 2010; house->isHistorical = false;
	service.addBuilding(std::move(house));

	house = std::make_unique<House>();
	house->address = "Str. Andrei Muresanu, Loc Cluj, nr 8; restore, !demolish"; house->constructionYear = 1900; house->isHistorical = true;
	service.addBuilding(std::move(house));
}
