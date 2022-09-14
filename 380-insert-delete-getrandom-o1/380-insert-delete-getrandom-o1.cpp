class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> table;
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool insert(int val) {
        if(table.count(val)) return false;
        table[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!table.count(val)) return false;
        int idx = table[val];
        swap(nums[idx], nums.back());
        table[nums[idx]] = idx;
        table.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */