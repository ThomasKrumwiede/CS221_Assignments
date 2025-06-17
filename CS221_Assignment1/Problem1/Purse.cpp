/*Purse.cpp
CS221 Assignment 1 Problem 1
Thomas Krumwiede
10/25/24
This file contains the functions for class purse*/
#include <iostream>
#include <set>
#include "Purse.h"
using namespace std;

//Method to add a multiset of coins to the purse 
void purse::add(const std::multiset<coin>& newCoins) {
	coinMultiset.insert(newCoins.begin(), newCoins.end());
}

//Method to get the total ammount of money in a purse 
double purse::totalMoney() const{
	double purseMoney = 0;

	multiset<coin>::iterator pos;
	for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
		purseMoney += pos->coinValue;
	}

	return purseMoney;
}

//Method to complete a payment 
void purse::pay(double paymentAmmount) {

	//Make sure the payment ammount in not more than the total
	if (paymentAmmount > totalMoney()) {
		cout << "Warning: Payment is greater than the money in the purse" << endl;
	}

	//Pay with quarters 
	while (paymentAmmount >= .25 && countQuarters() > 0) {
		multiset<coin>::iterator pos = coinMultiset.find(coin("Quarter", .25));
		if (pos != coinMultiset.end()) {
			coinMultiset.erase(pos);
			paymentAmmount -= .25;
			cout << "Quarter removed" << endl;
		}
	}

	//Pay with dimes 
	while (paymentAmmount >= .10 && countDimes() > 0) {
		multiset<coin>::iterator pos = coinMultiset.find(coin("Dimes", .10));
		if (pos != coinMultiset.end()) {
			coinMultiset.erase(pos);
			paymentAmmount -= .10;
			cout << "Dime removed" << endl;
		}
	}

	//Pay with nickles 
	while (paymentAmmount >= .05 && countNickels() > 0) {
		multiset<coin>::iterator pos = coinMultiset.find(coin("Nickel", .05));
		if (pos != coinMultiset.end()) {
			coinMultiset.erase(pos);
			paymentAmmount -= .05;
			cout << "Nickle removed" << endl;
		}
	}

	//Pay with pennies
	while (paymentAmmount > 0 && countPennies() > 0) {
		multiset<coin>::iterator pos = coinMultiset.find(coin("Penny", .01));
		if (pos != coinMultiset.end()) {
			coinMultiset.erase(pos);
			paymentAmmount -= .01;
			cout << "Penny removed" << endl;
		}
	}

	if (paymentAmmount == 0) cout << "You have payed with exact change" << endl;
	if (paymentAmmount != 0) cout << "No exact change" << endl;
}

//Method to count pennies
int purse::countPennies() const {
	int pennyCount = 0;

	multiset<coin>::iterator pos;
	for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
		if (pos->coinType == "Penny") pennyCount += 1;
	}

	return pennyCount;
}

//Method to count nickles
int purse::countNickels() const {
	int nickelCount = 0;

	multiset<coin>::iterator pos;
	for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
		if (pos->coinType == "Nickel") 	nickelCount += 1;
	}

	return nickelCount;
}

//Method to count nickles
int purse::countDimes() const {
	int dimeCount = 0;

	multiset<coin>::iterator pos;
	for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
		if (pos->coinType == "Dime") dimeCount += 1;
	}

	return dimeCount;
}

//Method to count nickles
int purse::countQuarters() const{
	int quarterCount = 0;

	multiset<coin>::iterator pos;
	for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
		if (pos->coinType == "Quarter") quarterCount += 1;
	}

	return quarterCount;
}

//operator overload of < for comparison 
bool purse::operator<(const purse& other) const {
	return totalMoney() < other.totalMoney();
}

