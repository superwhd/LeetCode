class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        top = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool alreadyIn = !!pos.count(val);
        top++;
        if (q.size() < top) {
            q.push_back(0);
        } 
        q[top - 1] = val;
        pos[val].insert(top - 1);
        return !alreadyIn;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!pos.count(val)) {
            return false;
        }
        int valPos = *(pos[val].begin());
        swap(q[valPos], q[top - 1]);
        pos[val].erase(valPos);        
        pos[q[valPos]].insert(valPos);
        pos[q[valPos]].erase(top - 1);
        top--;
        if (pos[val].empty()) {
            pos.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return q[rand() % top];
    }
private:
    vector<int> q;
    int top;
    unordered_map<int, unordered_multiset<int>> pos;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
