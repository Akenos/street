#include <iostream>
#include "SimulationsObjekt.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <vector>

double Globaltime = 0.0;
using namespace std;

vector<unique_ptr<Fahrzeug>> get_data_set()
{
	vector<unique_ptr<Fahrzeug>> gg;
	gg.push_back(make_unique<PKW>("pkw1", 75, 5));
	gg.push_back(make_unique<PKW>("pkw2", 70, 10));
	gg.push_back(make_unique<PKW>("pkw3", 50, 5));
	gg.emplace_back(make_unique<Fahrrad>("fr1", 40));
	gg.emplace_back(make_unique<Fahrrad>("fr2", 15));
	gg.emplace_back(make_unique<Fahrrad>("fr3", 70));
	return std::move(gg);
}

vector<unique_ptr<Fahrzeug>> get_data_set_input()
{
	vector<unique_ptr<Fahrzeug>> gg;

	int num_of_pkw = 3;
	for (int i = 0; i < num_of_pkw; i++)
	{
		string name;
		double max_speed;
		double verbrauch;
		cin >> name >> max_speed >> verbrauch;
		gg.push_back(make_unique<PKW>(name, max_speed, verbrauch));
	}
	for (int i = 0; i < 3; i++)
	{
		string name;
		double max_speed;
		cin >> name >> max_speed;
		gg.push_back(make_unique<Fahrrad>(name, max_speed));
	}
	return gg;
}

void vAufgabe_2()
{
	vector<unique_ptr<Fahrzeug>> gg = get_data_set();

	PKW::vKopf();
	cout << endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (int j = 0; j < gg.size(); j++)
		{
			gg.at(j)->vSimulieren();
			gg.at(j)->vAusgeben(cout) << endl;
		}
		cout << endl;

		if (i > 0 && i % 3 == 0)
		{
			for (int j = 0; j < gg.size(); j++)
			{
				gg.at(j)->Tanken();
			}
		}
		Globaltime++;
	}
};
void vAufgabe_1()
{

	SimulationsObjekt p("jabus_auto");
	std::cout << std::endl;
	SimulationsObjekt::vKopf();
	std::cout << p << std::endl;

	Fahrzeug p1("ZZZ_auto", -100);
	std::cout << std::endl;
	Fahrzeug::vKopf();
	std::cout << p1 << std::endl;

	PKW pkw("ZZZ_pkw", 100, 5);
	std::cout << std::endl;
	PKW::vKopf();
	std::cout << pkw << std::endl;

	Fahrrad bike("BIKE", 40);
	for (size_t i = 0; i < 5; i++)
	{
		bike.vSimulieren();
		Globaltime++;
		cout << bike << endl;
	}

	std::cout << std::endl;
	Fahrzeug::vKopf();
	std::cout << bike << std::endl;
}

void vAufgabe_1a()
{
	vector<unique_ptr<Fahrzeug>> gg;
	for (int i = 0; i < 3; i++)
	{
		string name;
		double max_speed;
		cin >> name >> max_speed;
		gg.push_back(make_unique<Fahrzeug>(name, max_speed));
	}
	Fahrzeug::vKopf();
	for (const auto &fz : gg)
	{
		cout << endl;
		cout << *fz;
	}
}

int main()
{
	vAufgabe_2();
	return 0;
}
