/* map.h
   Thomas Krumwiede 
   12/3/24
   This is the header file that declares the map class required for Assignment 2 problem 3*/
#pragma once
#include <iostream>
#include <vector>
#include <List>

using namespace std;

class map {
public:
    /*  Default constructor : initializes an empty hash table
        @peram void 
        @return void */
    map();

    
    /*  Function to return the number of key-value pairs in the map
        @peram void
        @return int */
    int size() const;


     /*  Function to return the number of elements with a specific key
        @peram string&
        @return int */
    int count(const string& key) const;

     /*  Function to erase a key-value pair identified by the key
        @peram string&
        @return void */
    void erase(const string& key);

    /*  Function to insert a key-value pair into the map
        @peram string&, int 
        @return void */
    void set(const string& key, int value);

     /*  Function to display the contents of the hash map (for testing / debugging)
        @peram void
        @return void */
    void display() const;

    // Struct to define KeyCompare object required for key_comapare()
    struct KeyCompare {
        bool operator()(const string& key1, string& key2)const {
            return key1 < key2; // compare lexigraphically 
        }
    };

     /*  Function to return key comparison object
        @peram void
        @return void */
    KeyCompare key_compare() const; 

    //Operator Overloads 
    /*  Function to overload []
        @peram string&
        @return int& */
    int& operator[](const string& key); // overlaod of []
    /*  Function to overload ==
        @peram map&
        @return bool */
    bool operator==(const map& other)const;  // overload of ==

private:
    const int TABLE_SIZE = 10; // Fixed size for hash table
    vector<list<pair<string, int>>> table; // Hash table
    int num_elements; // Tracks the number of key-value pairs in the map

    /*  Hash function for strings
        @peram string&
        @return size_t */
    size_t hash(const string& key) const;
};