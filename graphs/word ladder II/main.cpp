#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        int minn = INT_MAX;
        q.push({beginWord});
        st.erase(beginWord);
        while(!q.empty())
        {
            int size = q.size();
            unordered_set<string> temp;
            for(int i = 0; i < size; i++)
            {
                if(q.front().back() == endWord){
                    if(minn >= q.front().size()){
                        ans.push_back(q.front());
                        minn = q.front().size();
                        q.pop();
                        continue;
                    }
                    return ans;
                }
                for(int j = 0; j < q.front().back().size(); j++)
                {
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        vector<string> v = q.front();
                        string word = v.back();
                        word[j] = c;
                        if(st.find(word) != st.end()){
                            v.push_back(word);
                            temp.insert(word);
                            q.push(v);
                        }
                    }
                }
                q.pop();
            } 
            for(auto i: temp) st.erase(i);
        }
        return ans;
}
