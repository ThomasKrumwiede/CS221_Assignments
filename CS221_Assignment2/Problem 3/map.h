/* map.h
   Thomas Krumwiede 
   12/3/24
   This is the header file that declares the map class
   and holds the template implementation required for Assignment 2 problem 3*/
#pragma once
#include <iostream>
#include <vector>
#include <List>
#include <exception>

using namespace std;

template <typename T>
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
        @peram string&, T 
        @return void */
    void set(const string& key, T value);

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
        @return T& */
    T& operator[](const string& key); // overlaod of []
    /*  Function to overload ==
        @peram map&
        @return bool */
    bool operator==(const map<T>& other)const;  // overload of ==

private:
    const int TABLE_SIZE = 10; // Fixed size for hash table
    vector<list<pair<string, T>>> table; // Hash table
    int num_elements; // Tracks the number of key-value pairs in the map

    /*  Hash function for strings
        @peram string&
        @return size_t */
    size_t hash(const string& key) const;
};

template <typename T>
map<T>::map() {
    table = vector<list<pair<string, T>>>(TABLE_SIZE);
    num_elements = 0;
}

template <typename T>
size_t map<T>::hash(const string& key) const {
    int sum = 0;

    // Sum the ASCII values of characters in the key
    for (size_t i = 0; i < key.length(); ++i) {
        char ch = key[i];
        sum += static_cast<int>(ch);
    }

    // Return the bucket index
    return sum % TABLE_SIZE;
}

// Function to return the number of key-value pairs in the map
template <typename T>
int map<T>::size() const {
    return num_elements;
}

// Function to return the number of elements with a specific key
template <typename T>
int map<T>::count(const string& key) const {
    size_t index = hash(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            return 1; // Key found
        }
    }
    return 0; // Key not found
}

// Function to erase a key-value pair identified by the key
template <typename T>
void map<T>::erase(const string& key) {
    size_t index = hash(key);
    auto& chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            chain.erase(it);
            --num_elements;
            return;
        }
    }
    throw out_of_range("Key not found: " + key);
}


// Function to insert a key-value pair into the map
template <typename T>
void map<T>::set(const string& key, T value) {
    size_t index = hash(key);
    auto& chain = table[index];

    // Check if the key already exists
    for (auto& pair : chain) {
        if (pair.first == key) {
            pair.second = value; // Update the value if key exists
            return;
        }
    }

    // Key does not exist, insert a new key-value pair
    chain.emplace_back(key, value);
    ++num_elements;
}

// Function to display the contents of the hash map (for testing purposes)
template <typename T>
void map<T>::display() const {
    for (size_t i = 0; i < table.size(); ++i) {
        cout << "Bucket " << i << ": ";
        for (const auto& pair : table[i]) {
            cout << "{" << pair.first << ": " << pair.second << "} ";
        }
        cout << endl;
    }
}

// Key_compare function
template <typename T>
typename map<T>::KeyCompare map<T>::key_compare() const {
    return KeyCompare();
}

// Operator Overloads:

// Overload of []
template <typename T>
T& map<T>::operator[](const string& key) {
    size_t index = hash(key);
    list<pair<string, T>>& location = table[index]; // Get the bucket (list of pairs)

   // Check if the key exists
    for (auto iter = location.begin(); iter != location.end(); ++iter) {
        if (iter->first == key) {
            return iter->second; // Return a const reference to the value
        }
    }

    // If key is not found, throw an exception
    throw out_of_range("out_of_range, Key not found: " + key);
}

// Overload of == 
template <typename T>
bool map<T>::operator==(const map<T>& other) const {
    // Check if the sizes are different
    if (num_elements != other.num_elements) {
        return false;
    }

    // Iterate through all buckets in this map
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        const list<pair<string, T>>& thisBucket = table[i];
        const list<pair<string, T>>& otherBucket = other.table[i];

        // Compare the size of the buckets
        if (thisBucket.size() != otherBucket.size()) {
            return false;
        }

        // Compare all elements in the buckets
        for (const pair<string, T>& thisPair : thisBucket) {
            bool found = false;
            for (const pair<string, T>& otherPair : otherBucket) {
                if (thisPair == otherPair) { // Compare keys and values
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false; // A mismatch was found
            }
        }
    }

    // If all checks pass, the maps are equal
    return true;
}