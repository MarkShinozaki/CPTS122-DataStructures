# Hash Tables in C++

## Introduction to Hash Tables 

**A hash table (or hash map) is a data structure that provides fast insertion, deletion, and lookup operations. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.**

### Key Concepts 

#### Hash Function

A hash function is a function that takes an input (or "key") and returns an integer (the "hash code"), which is typically used to index an array.

#### Collision Handling
Since different keys can produce the same hash code, collisions must be handled. There are several methods to handle collisions:

- **Chaining:** Each bucket is independent, and contains a list of entries that map to the bucket.
- **Open Addressing:** All entry records are stored in the array itself.

#### Load Factor

The load factor of a hash table is the ratio of the number of elements to the number of buckets. Maintaining a load factor less than 1 helps in achieving constant time complexity for insertion, deletion, and search operations.

### Example of Hash Table with Chaining
#### Hash Table Interface
```c++
template <typename K, typename V>
class HashTable {
public:
    virtual void insert(const K& key, const V& value) = 0;
    virtual bool remove(const K& key) = 0;
    virtual bool search(const K& key, V& value) const = 0;
    virtual ~HashTable() {}
};
```
#### Hash Table Implementation using Chaining 
```c++
#include <iostream>
#include <list>
#include <vector>
#include <utility>
using namespace std;

template <typename K, typename V>
class ChainedHashTable : public HashTable<K, V> {
private:
    vector<list<pair<K, V>>> table;
    int capacity;
    int size;
    
    int hashFunction(const K& key) const {
        return static_cast<int>(key) % capacity;
    }

public:
    ChainedHashTable(int cap) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    void insert(const K& key, const V& value) override {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
        size++;
    }

    bool remove(const K& key) override {
        int index = hashFunction(key);
        auto& cell = table[index];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    bool search(const K& key, V& value) const override {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    ChainedHashTable<int, string> hashTable(10);

    hashTable.insert(1, "one");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");

    string value;
    if (hashTable.search(2, value)) {
        cout << "Found: " << value << endl;
    } else {
        cout << "Not Found" << endl;
    }

    hashTable.remove(2);

    if (hashTable.search(2, value)) {
        cout << "Found: " << value << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
```
### Conclusion 

Hash tables are a powerful data structure that offer efficient insertion, deletion, and lookup operations. By using a hash function and handling collisions effectively, hash tables can provide constant time complexity for these operations in the average case. The example above demonstrates how to implement a hash table using chaining for collision handling in C++.




























--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(18)%20Sorting">Part 18: Sorting</a>
</p>
