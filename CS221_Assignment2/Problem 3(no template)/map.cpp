/* map.cpp
   Thomas Krumwiede
   12/3/24
   This is the cpp file that contains the imlementation of
   the map class required for Assignment 2 problem 3*/
#include "map.h"
#include <stdexcept>

using namespace std;



// Default constructor: initializes an empty hash table
map::map() {
    table = vector<list<pair<string, int>>>(TABLE_SIZE);
    num_elements = 0;
}

size_t map::hash(const string& key) const{
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
int map::size() const {
    return num_elements;
}

// Function to return the number of elements with a specific key
int map::count(const string & key) const {
    size_t index = hash(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            return 1; // Key found
        }
    }
    return 0; // Key not found
}

// Function to erase a key-value pair identified by the key
void map::erase(const string & key) {
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
void map::set(const string& key, int value) {
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
void map::display() const {
    for (size_t i = 0; i < table.size(); ++i) {
        cout << "Bucket " << i << ": ";
        for (const auto& pair : table[i]) {
            cout << "{" << pair.first << ": " << pair.second << "} ";
        }
        cout << endl;
    }
}

// Key_compare function 
map::KeyCompare map::key_compare() const {
    return KeyCompare{};
}

// Operator Overloads:

// Overload of []
int& map::operator[](const string& key) {
    size_t index = hash(key);
    list<pair<string, int>>& location = table[index]; // Get the bucket (list of pairs)

   // Check if the key exists
    for (list<pair<string, int>>::iterator it = location.begin(); it != location.end(); ++it) {
        if (it->first == key) {
            return it->second; // Return a const reference to the value
        }
    }

    // If key is not found, throw an exception
    throw out_of_range("out_of_range, Key not found: " + key);
}

// Overload of == 
bool map::operator==(const map& other) const {
    // Check if the sizes are different
    if (num_elements != other.num_elements) {
        return false;
    }

    // Iterate through all buckets in this map
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        const list<pair<string, int>>& thisBucket = table[i];
        const list<pair<string, int>>& otherBucket = other.table[i];

        // Compare the size of the buckets
        if (thisBucket.size() != otherBucket.size()) {
            return false;
        }

        // Compare all elements in the buckets
        for (const pair<string, int>& thisPair : thisBucket) {
            bool found = false;
            for (const pair<string, int>& otherPair : otherBucket) {
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