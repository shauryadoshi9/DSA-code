/*
================================================================================
EXPERIMENT - 10
Aim: Implement the Static Hashing using any one method.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
Steps:
1) Store the string of data in array.
2) Take static Hash array of 26 character size.
3) Make the modulo hash function and store data at respective hash location in static hash array:
   Hash location = int(character) mode 26
4) If the location is already filled then fill the next location with overflow condition (Linear Probing).
5) Display the open addressing hash table with static hash array.
================================================================================
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int TABLE_SIZE = 26;
const char EMPTY_SLOT = '-';

class StaticHashTable {
private:
    char hashTable[TABLE_SIZE];
    int count;

public:
    StaticHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = EMPTY_SLOT;
        }
        count = 0;
    }

    // Step 3: Modulo hash function
    int hashFunction(char ch) {
        char upper = toupper(ch);
        if (upper >= 'A' && upper <= 'Z') {
            return (upper - 'A') % TABLE_SIZE;
        }
        return ((int)ch) % TABLE_SIZE;
    }

    // Insert character with linear probing
    void insert(char ch) {
        if (count >= TABLE_SIZE) {
            cout << "Hash Table Overflow! Table is completely full. Cannot insert '" << ch << "'.\n";
            return;
        }

        int index = hashFunction(ch);
        int originalIndex = index;
        int probes = 0;

        // Step 4: If location is already filled, fill next location with linear probing
        while (hashTable[index] != EMPTY_SLOT) {
            cout << "Collision at index " << index << " for character '" << ch << "'. Probing next slot...\n";
            index = (index + 1) % TABLE_SIZE;
            probes++;
            if (index == originalIndex) {
                cout << "Hash Table Overflow! No empty slot found.\n";
                return;
            }
        }

        hashTable[index] = ch;
        count++;
        cout << "Character '" << ch << "' stored at index " << index 
             << " (Probes: " << probes << ").\n";
    }

    // Insert entire string into the hash table
    void insertString(const string &str) {
        cout << "\n--- Inserting String: \"" << str << "\" ---\n";
        for (int i = 0; i < (int)str.length(); i++) {
            if (isalpha(str[i])) {
                insert(str[i]);
            }
        }
    }

    // Search for a character in the hash table
    int search(char ch) {
        int index = hashFunction(ch);
        int originalIndex = index;

        while (hashTable[index] != EMPTY_SLOT) {
            if (toupper(hashTable[index]) == toupper(ch)) {
                return index; // Found
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break;
        }
        return -1; // Not found
    }

    // Step 5: Display the open addressing hash table with static hash array
    void display() {
        cout << "\n===================================================\n";
        cout << "  STATIC HASH TABLE (Open Addressing / Linear Probing)\n";
        cout << "===================================================\n";
        cout << "Index\tKey / Character\n";
        cout << "---------------------------------------------------\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << "\t";
            if (hashTable[i] == EMPTY_SLOT) {
                cout << "[ EMPTY ]\n";
            } else {
                cout << "    " << hashTable[i] << "\n";
            }
        }
        cout << "---------------------------------------------------\n";
        cout << "Total Elements Stored: " << count << " / " << TABLE_SIZE << "\n";
    }
};

int main() {
    StaticHashTable ht;
    string data;

    cout << "========================================\n";
    cout << "   STATIC HASHING (LINEAR PROBING)\n";
    cout << "========================================\n";

    // Step 1: Store the string of data from user at runtime
    cout << "Enter a string of data to insert into Hash Table: ";
    cin >> data;

    // Step 2 & 3 & 4: Insert with modulo 26 hash and linear probing
    ht.insertString(data);

    // Step 5: Display hash table
    ht.display();

    // Runtime Dynamic Search
    char searchChar;
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        cout << "\nEnter a character to search in hash table: ";
        cin >> searchChar;
        int pos = ht.search(searchChar);
        if (pos != -1) {
            cout << "Character '" << searchChar << "' found at index " << pos << ".\n";
        } else {
            cout << "Character '" << searchChar << "' NOT found in hash table.\n";
        }

        cout << "Do you want to search another character? (y/n): ";
        cin >> cont;
    }

    return 0;
}
