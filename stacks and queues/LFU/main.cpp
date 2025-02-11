//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> h;
    unordered_map<int, list<pair<int, int>>> f;
    int cap;
    int freq;
    LFUCache(int capacity) {
        cap = capacity;
        freq = 1;
    }
    int get(int key) {
        if(h.find(key) != h.end())
        {
            pair<int, int> node = *h[key].second;
            f[h[key].first].erase(h[key].second);
            f[h[key].first + 1].push_back(node);
            if(freq == h[key].first && f[freq].empty()) freq++;
            h[key] = {h[key].first + 1, prev(f[h[key].first + 1].end())};
            return node.second; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(h.find(key) != h.end())
        {
            pair<int, int> node = *h[key].second;
            f[h[key].first].erase(h[key].second);
            f[h[key].first + 1].push_back({key, value});
            if(freq == h[key].first && f[freq].empty()) freq++;
            h[key] = {h[key].first + 1, prev(f[h[key].first + 1].end())};
        }
        else
        {
            if(cap == h.size()){
                h.erase(f[freq].front().first);
                f[freq].pop_front();
            }
            freq = 1;
            f[1].push_back({key, value});
            h[key] = {1, prev(f[1].end())};
        } 
    }
};
    
int main()
{
	
}
