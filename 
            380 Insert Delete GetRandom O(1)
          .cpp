class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        top = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pos.count(val)) {
            return false;
        }
        top++;
        if (q.size() < top) {
            q.push_back(0);
        } 
        q[top - 1] = val;
        pos[val] = top - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!pos.count(val)) {
            return false;
        }
        int valPos = pos[val];
        swap(q[valPos], q[top - 1]);
        pos[q[valPos]] = valPos;
        top--;
        pos.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return q[rand() % top];
    }
private:
    vector<int> q;
    int top;
    map<int, int> pos;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
