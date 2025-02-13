#include <bits/stdc++.h>

using namespace std;

//orgasmic, my solution
//time: O(2n)
//space: O(3)
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int start = 0;
    int len = 0;
    for(int i = 0; i < fruits.size(); i++){
        mp[fruits[i]]++;
        while(mp.size() > 2){
            mp[fruits[start]]--;
            if(mp[fruits[start]] == 0) mp.erase(fruits[start]);
            start++;
        }
        len = max(len, i - start + 1);
    }
    return len;
}

//orgasmic
//time: O(n)
//space: O(3)
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int start = 0;
    int len = 0;
    for(int i = 0; i < fruits.size(); i++){
        mp[fruits[i]]++;
        if(mp.size() > 2){
            mp[fruits[start]]--;
            if(mp[fruits[start]] == 0) mp.erase(fruits[start]);
            start++;
        }
        if(mp.size() <= 2) len = max(len, i - start + 1);
    }
    return len;
}


int main()
{
}

