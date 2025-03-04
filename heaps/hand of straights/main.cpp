#include <bits/stdc++.h>

using namespace std;

//my solution
//time: O(nlogn)
//space: O(n)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size() % groupSize != 0) return false;
    map<int, int> mp;
    for(int i: hand) mp[i]++;
    while(!mp.empty())
    {
        int count = groupSize;
        int j = 0;
        int start = mp.begin()->first;
        for(auto ele: mp)
        {
            if(count == 0) break;
            if(ele.first != start + j) return false;
            mp[ele.first]--;
            if(mp[ele.first] == 0) mp.erase(ele.first);
            count--;
            j++; 
        }
        if(count != 0) return false;
    }
    return true;
}

//orgasmic
//time: O(nlogn)
//space: O(1)
bool pairpossible(vector<int>& hand, int i, int groupSize, int n)
{
    int next = hand[i] + 1;
    hand[i] = -1;
    i++;
    groupSize--;
    while(i < n && groupSize)
    {
        if(hand[i] > next) return false;
        else if(hand[i] == next)
        {
            next = hand[i] + 1;
            hand[i] = -1;
            groupSize--;
        }
        i++;
    }
    if(groupSize == 0) return true;
    return false;
}
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size() % groupSize != 0) return false;
    sort(hand.begin(), hand.end());
    for(int i = 0; i < hand.size(); i++)
    {
        if(hand[i] >= 0){
            if(!pairpossible(hand, i, groupSize, hand.size())) return false;
        }
    }
    return true;
}

int main()
{
}

