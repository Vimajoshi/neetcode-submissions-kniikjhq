#include <vector>
#include <utility>

class MyHashMap {
private:
    // A prime number size helps distribute keys more uniformly
    int BUCKET_SIZE;
    std::vector<std::vector<std::pair<int, int>>> table;

    // Hash function to map keys to bucket indices
    int hash(int key) {
        return key % BUCKET_SIZE;
    }

public:
    MyHashMap() {
        BUCKET_SIZE = 10007; 
        table.resize(BUCKET_SIZE);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        // If the key already exists, update its value
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // If the key does not exist, insert the new pair
        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        // Search for the key in the corresponding bucket
        for (const auto& pair : table[idx]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1; // Key not found
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        // Search for the key and erase it if found
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */