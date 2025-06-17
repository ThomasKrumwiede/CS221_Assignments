/* Problem3.cpp
   Thomas Krumwiede
   12/3/24
   This is the cpp file that contains the main function to test the 
   implementation of the map class for Assignment 2 problem 3*/
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

#include "map.h"


int main() {
    map test1;

    // test insertion
    test1.set("Adam", 30);
    test1.set("Bill", 25);
    test1.set("Chuck", 35);
    test1.set("Adam", 40); // update the existing key value 

    // display map
    test1.display();

    // test size
    std::cout << "Size: " << test1.size() << std::endl;

    // test count
    std::cout << "Count for 'Adam': " << test1.count("Adam") << std::endl;
    std::cout << "Count for 'David': " << test1.count("David") << std::endl;

    // test erase
    test1.erase("Bill");
    std::cout << "After erasing 'Bill':" << std::endl;
    test1.display();

    // test key_comparison based on lexographical order 
    map::KeyCompare compairison = test1.key_compare(); // declair comparison object 
    string key1 = "Adam";
    string key2 = "Chuck";
    // true condition 
    if (compairison(key1, key2)) {
        cout << "Adam is less than Chuck" << endl;
    }
    else {
        cout << "Aadam is not less than Chuck" << endl; 
    }
    // false condition 
    if (compairison(key2, key1)) {
        cout << "Chuck is less than Adam" << endl;
    }
    else {
        cout << "Chuck is not less than Adam" << endl;
    }


    // try to erase a key that does not exist 
    try {
        test1.erase("Bill");
    }
    catch (const out_of_range& e) {
        cout << e.what() << std::endl;
    }

   
    // test overload opperators 
    // test []
    cout << "Test Overload of the [] opperator, ['Aadam']: " << test1["Adam"] << endl;
    // test == 
    map test2;
    test2.set("Adam", 40);
    // unequal map 
    bool attempt; // variable to hold the return of the == overload 
    attempt = test1 == test2;
    cout << "Does map1 == map2: " << attempt << endl; // should be false 
    // equal map 
    test2.set("Chuck", 35);
    cout << "Insert missing pair" << endl;
    attempt = test1 == test2;
    cout << "Does map1 == map2: " << attempt << endl; // should be true 

    return 0;
}