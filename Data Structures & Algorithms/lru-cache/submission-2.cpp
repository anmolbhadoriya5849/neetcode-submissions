class LRUCache {
public:

    int capa;
    unordered_map<int,pair<int,int>> mp;
    int timer;

    LRUCache(int capacity) {
        capa = capacity;
        timer = 0;
    }
    
    int get(int key) {
        if(mp.count(key)){
            mp[key].second = ++timer;
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.size() == capa && !mp.count(key)){
            int lru = INT_MAX;
            int rem = -1;
            for(auto x : mp){
                if(x.second.second < lru){
                    lru = x.second.second;
                    rem = x.first;
                }
            }
            mp.erase(rem);
            mp[key] = {value, ++timer};
            return;
        }

        if(mp.count(key)){
            mp[key] = {value, ++timer};
        }
        else{
            mp[key] = {value, ++timer};
        }
    }
};
