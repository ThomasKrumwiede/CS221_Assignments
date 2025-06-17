/* Problem3.cpp
   Thomas Krumwiede
   12/3/24
   This is the cpp file that contains the main function to test the 
   implementation of the map class for Assignment 2 problem 3 */
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

#include "map.h"



int main() {
    // Create map for int values
    map<int> test1;
    int a1 = 5;
    int a2 = 20;
    int b1 = 10;
    int c1 = 15;
    // test insertion
    test1.set("Adam", a1);
    test1.set("Bill", b1);
    test1.set("Chuck", c1);
    test1.set("Adam", a2); // update the existing key value 

    // display map
    test1.display();

    // test size
    cout << "Size: " << test1.size() << endl;

    // test count
    cout << "Count for 'Adam': " << test1.count("Adam") << endl;
    cout << "Count for 'David': " << test1.count("David") << endl;

    // test erase
    test1.erase("Bill");
    cout << "After erasing 'Bill':" << endl;
    test1.display();

    // test key_comparison based on lexicographical order 
    map<int>::KeyCompare comparison = test1.key_compare(); // declare comparison object
    string key1 = "Adam";
    string key2 = "Chuck";

    // true condition 
    if (comparison(key1, key2)) {
        cout << "Adam is less than Chuck" << endl;
    }
    else {
        cout << "Adam is not less than Chuck" << endl;
    }

    // false condition 
    if (comparison(key2, key1)) {
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

    // test overload operators 
    // test []
    cout << "Test Overload of the [] operator, ['Adam']: " << test1["Adam"] << endl;

    // test == 
    map<int> test2;
    test2.set("Adam", a2);

    // unequal map 
    bool attempt; // variable to hold the return of the == overload 
    attempt = test1 == test2;
    cout << "Does map1 == map2: " << attempt << endl; // should be false

    // equal map 
    test2.set("Chuck", c1);
    cout << "Insert missing pair" << endl;
    attempt = test1 == test2;
    cout << "Does map1 == map2: " << attempt << endl; // should be true

    // Test another type 
    map<char> test3;
    test3.set("Adam", 'a');
    test3.set("Billy", 'b');
    test3.display();

    return 0;
}