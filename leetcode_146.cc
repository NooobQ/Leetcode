class LRUCache {
public:
    LRUCache(int capacity) :_cap(capacity){    }
    
    int get(int key) {
        auto _it=_map.find(key);
        if(_it!=_map.end())
        {
            int value=_it->second->second;
            _list.erase(_it->second);
            _list.push_front(pair<int,int>(key,value));
            _map[key]=_list.begin();
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        auto _it=_map.find(key);
        if(_it!=_map.end())
            _list.erase(_it->second);
        
        _list.push_front(pair<int,int>(key,value));
        _map[key]=_list.begin();
        if(_list.size()>_cap)
        {
            int key=_list.back().first;
            _map.erase(key);
            _list.pop_back();
        }
    }
private:
    list<pair<int,int> > _list;
    unordered_map< int , list<pair<int,int> >::iterator > _map;
    int _cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
