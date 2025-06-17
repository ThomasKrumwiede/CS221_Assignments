#pragma once
#include <iostream>
#include <set>
using namespace std;

struct coin {
	string coinType;
	double coinValue; 
	coin(string name, double value);
	bool operator<(const coin& other) const;
};