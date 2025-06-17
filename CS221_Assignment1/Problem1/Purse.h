#pragma once
#include <iostream>
#include <set>
#include "coin.h"
using namespace std;

class purse {
public:

	/*Method to add a multiset of coins to the purse 
	@Peram miltiset<cion>&
	@return void*/
	void add(const std::multiset<coin>& newCoins);

	/*Method to get the total ammount of money in a purse 
	@Peram void
	@return double*/
	double totalMoney() const;

	/*Method to complete a payment 
	@Peram double
	@return void*/
	void pay(double paymentAmmount);

	/*Method to count pennies
	@Peram double
	@return void*/
	int countPennies() const;

	/*Method to count nickles
	@Peram void
	@return int*/
	int countNickels() const;

	/*Method to count nickles
	@Peram void
	@return int*/
	int countDimes() const;

	/*Method to count nickles
	@Peram void
	@return int*/
	int countQuarters() const;


	/*overload of < for comparison
	@Peram Purse&
	@return bool*/
	bool operator<(const purse& other) const;

private:
	multiset<coin> coinMultiset;
};