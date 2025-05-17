#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // code here
    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    s.erase(beginWord);
    vector<vector<string>> ans;
    while(!q.empty())
    {
        int size = q.size();
        vector<string> w;
        for(int i = 0; i < size; i++)
        {
            if(q.front().back() == endWord){
                ans.push_back(q.front());
                q.pop();
                continue;
            }
            for(int j = 0; j < beginWord.length(); j++)
            {
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    vector<string> wordVec = q.front();
                    string word = wordVec.back();
                    word[j] = ch;
                    if(s.find(word) != s.end()){
                        wordVec.push_back(word);
                        q.push(wordVec);
                        w.push_back(word);
                    }
                }
            }
            q.pop();
        }
        for(auto e: w) s.erase(e);
    }
    return ans;
}