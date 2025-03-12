#include <bits/stdc++.h>

using namespace std;

//time: O(n*c)
//space: O(c)
int pageFaults(int N, int C, int pages[]){
    // code here
    list<int> cache;
    int faults = 0;
    for(int i = 0; i < N; i++)
    {
        auto it = find(cache.begin(), cache.end(), pages[i]);
        if(it == cache.end())
        {
            if(cache.size() == C) cache.pop_front(); 
            faults++;
        }
        else
        {
            cache.erase(it);
        }
        cache.push_back(pages[i]);
    }
    return faults;
}


int main()
{
}

