class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_map<int, bool>> hash;
    vector<int> arr;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(hash.count(val) == 0){
            hash[val][arr.size()] = true;
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(hash.count(val) != 0){
            unordered_map<int, bool> :: iterator it;
            it = hash[val].begin();
            int index = it -> first;

            int temp = arr[arr.size() - 1];
            arr[arr.size() - 1] = arr[index];
            arr[index] = temp;

            hash[val].erase(index);
            if(hash[val].size() == 0){
                hash.erase(val);
            }
            hash[arr[index]][index] = true;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int randomindex = rand();
        randomindex = randomindex%arr.size();

        return arr[randomindex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */