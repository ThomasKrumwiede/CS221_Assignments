//Thomas Krumwiede 
//CS 221
//Assignment 1 Problem 1

#include <iostream>
#include <set>
#include "coin.h"
#include "purse.h"
using namespace std;


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

	//create the array the purses will be stored in 
	purse* purseArray[] = { &Purse1, &Purse2, &Purse3, &Purse4, &Purse5, &Purse6 };
	
	cout << '\n' << "Problem 1 Part B" << endl;

	for (int i = 0; i < 6; i++) {
		cout << "The total ammount of change in Purse" << i + 1 << " is : $" << purseArray[i]->totalMoney() << endl;
	}


}