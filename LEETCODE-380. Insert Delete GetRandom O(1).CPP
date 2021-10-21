#define pb push_back
class RandomizedSet {
    
    vector<int>v;
    unordered_map<int,int>m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val))
            return false;
        v.pb(val);
        m[val]=v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val))
            return false;
        int ind=m[val];
        m[v.back()]=ind;
        v[ind]=v.back();
        v.pop_back();
        m.erase(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }