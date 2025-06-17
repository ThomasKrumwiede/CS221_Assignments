/*coin.cpp
CS221 Assignment 1 Problem 1
Thomas Krumwiede
10/25/24
This file contains the functions for the coin struct*/
#include <iostream>
#include <set>
#include "coin.h"
using namespace std;

coin::coin(string name, double value)
{
	coinType = name;
	coinValue = value;
}

bool coin::operator<(const coin& other) const {
	return coinValue < other.coinValue;
}