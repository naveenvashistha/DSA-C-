#include <bits/stdc++.h>

using namespace std;


//time: O(wordlist length x each word length x 26)
//space: O(wordlist length)
class Solution {
public:
    int ladderLength(string beginWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> mp(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        mp.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == targetWord) return steps;

            for(int i = 0; i < word.length(); i++)
            {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if(mp.find(word) != mp.end())
                    {
                        q.push({word, steps + 1});
                        mp.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;   
    }
};