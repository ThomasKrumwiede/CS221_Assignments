/*Problem1.cpp
CS221 Assignment 1 Problem 1
Thomas Krumwiede
10/25/24
This file contains the main function for testing problem one and two functions
compareTotalMoney() and compareTotalCoins() that are necessary for testing*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "coin.h"
#include "Purse.h"
using namespace std;

int compareTotalMoney(const void* a, const void* b) {
	const purse* purseA = *(const purse**)a;	//derefference the void* and set it so a purse*
	const purse* purseB = *(const purse**)b;    //derefference the void* and set it so a purse*
	
	//compare the totalMoney in each purse 
	if (purseA->totalMoney() < purseB->totalMoney()) return -1;
	if (purseA->totalMoney() > purseB->totalMoney()) return 1;
	return 0;
}

int compareTotalCoins(const void* a, const void* b) {
	const purse* purseA = *(const purse**)a;	//derefference the void* and set it so a purse*
	const purse* purseB = *(const purse**)b;    //derefference the void* and set it so a purse*

	//calculate the total number of coins in each purse 
	int aTotal = 0; 
	int bTotal = 0;

	aTotal = purseA->countQuarters() + purseA->countDimes() + purseA->countNickels() + purseA->countPennies();
	bTotal = purseB->countQuarters() + purseB->countDimes() + purseB->countNickels() + purseB->countPennies();

	//Compare the total number of coins in each purse 
	if (aTotal < bTotal) return -1;
	if (aTotal > bTotal) return 1;
	return 0;

}
int main() {
	//initalize values for coin 
	coin penny("Penny", .01);
	coin nickel("Nickel", .05);
	coin dime("Dime", .10);
	coin quarter("Quarter", .25); 

	//initalize the multiset to be added to purse 
	multiset<coin> coinList= { penny, nickel, dime, quarter, quarter, nickel, dime, penny, penny, penny };

	//initalize the purse 
	purse Purse1;
	Purse1.add(coinList); 

	//test the totalMoney memberfunction 
	cout << "The total ammount of change in the purse is: $" << Purse1.totalMoney() << endl;

	//test the countPennies method
	cout << "The total number of pennies in the purse is: " << Purse1.countPennies() << endl;

	//test the countNickles method
	cout << "The total number of nickels in the purse is: " << Purse1.countNickels() << endl;

	//test the countDimes method
	cout << "The total number of dimes in the purse is: " << Purse1.countDimes() << endl;

	//test the countQuarters method
	cout << "The total number of quarters in the purse is: " << Purse1.countQuarters() << endl;

	//Test the payment method
	double x = .57;
	Purse1.pay(x);
	cout << "Payment is $" << x <<" , the new total ammount in the purse is : " << Purse1.totalMoney() << endl;


	// test the totalMoney memberfunction
	cout << "The total ammount of change in the purse is: $" << Purse1.totalMoney() << endl;

	//test the countPennies method
	cout << "The total number of pennies in the purse is: " << Purse1.countPennies() << endl;

	//test the countNickles method
	cout << "The total number of nickels in the purse is: " << Purse1.countNickels() << endl;

	//test the countDimes method
	cout << "The total number of dimes in the purse is: " << Purse1.countDimes() << endl;

	//test the countQuarters method
	cout << "The total number of quarters in the purse is: " << Purse1.countQuarters() << endl;


	//Part 2:
	//initalize the the purses for the array 
	multiset<coin> coinList2 = { penny, nickel, dime, nickel, dime, penny, penny, penny };
	purse Purse2;
	Purse2.add(coinList2);

	multiset<coin> coinList3 = { penny, nickel, dime, quarter, nickel, dime, penny };
	purse Purse3;
	Purse3.add(coinList3);

	multiset<coin> coinList4 = { penny, dime, quarter, quarter,  dime};
	purse Purse4;
	Purse4.add(coinList4);

	multiset<coin> coinList5 = { penny, dime, quarter, quarter,  dime, quarter, quarter, nickel, penny };
	purse Purse5;
	Purse5.add(coinList5);

	multiset<coin> coinList6 = { penny, dime, dime, penny, penny, nickel};
	purse Purse6;
	Purse6.add(coinList6);

	//Problem 1 Part B
	//create the array the purses will be stored in 
	purse* purseArray[] = { &Purse1, &Purse2, &Purse3, &Purse4, &Purse5, &Purse6 };
	
	cout << '\n' << "Problem 1 Part B" << endl;

	for (int i = 0; i < 6; i++) {
		cout << "The total ammount of change in Purse" << i + 1 << " is : $" << purseArray[i]->totalMoney() << endl;
	}


	//Qsort the total money in a purse from smallest to largest 
	int size = sizeof(purseArray) / sizeof(purseArray[0]);
	qsort(purseArray, size, sizeof(purse*), compareTotalMoney);
	for (int i = 0; i < 6; i++) {
		cout << "The total ammount in Purse" << i + 1 << " is : $" << purseArray[i]->totalMoney() << endl;
	}

	//Qsort to compar the total number of coins in each purse from smallest to largest
	qsort(purseArray, size, sizeof(purse*), compareTotalCoins);
	for (int i = 0; i < 6; i++) {
		cout << "The total ammount in Purse" << i + 1 << " is : $" << purseArray[i]->totalMoney() << endl;
	}


	//Problem 1 part C
	cout << '\n' << "Problem 1 Part C" << endl;

	//create the colection of purses 
	vector<purse> purses = { Purse1, Purse2, Purse3, Purse4, Purse5, Purse6 };
	
	//diplay the total ammount each purse had before it is sorted 
	cout << "Purse collection prior to the sort:" << endl;
	for (int i = 0; i < purses.size(); i++) {
		cout << "Purse " << (i + 1) << " has total money: $" << purses[i].totalMoney() << endl;
	};
	
	//sort the total ammount of 
	sort(purses.begin(), purses.end());

	//diplay the total ammount each purse had before it is sorted 
	cout << '\n' << "Purse collection after the sort:" << endl;
	for (int i = 0; i < purses.size(); i++) {
		cout << "Purse " << (i + 1) << " has total money: $" << purses[i].totalMoney() << endl;
	};

}