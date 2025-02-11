//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> h;
    int cap; 
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(h.find(key) != h.end()){
            pair<int, int> p = *h[key];
            l.erase(h[key]);
            l.push_back(p);
            h[key] = prev(l.end());
            return h[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        l.push_back({key, value});
        if(h.find(key) != h.end())
        {
            l.erase(h[key]);
        }
        else if (h.size() == cap){
            int k = (*l.begin()).first;
            l.pop_front();
            h.erase(k);
        }
        h[key] = prev(l.end());
    }
};
    
int main()
{
	
}
