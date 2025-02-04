
#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& ast);
vector<int> asteroidCollision1(vector<int>& ast); 

int main()
{
    vector<int> n = {4,2,1};
    vector<int> ans = asteroidCollision1(n);
    for(auto i: ans)
        cout << i << " ";
    cout << endl;
}

//my solution (a little verbose)
//time: O(2n)
//space: O(n)
vector<int> asteroidCollision(vector<int>& ast) {
    vector<int> ans;
    for(int i: ast)
    {
        if(ans.empty()){ 
            ans.push_back(i);
        }
        else if((ans.back() > 0 && i > 0) || (ans.back() < 0 && i < 0)){
            ans.push_back(i);
        }
        else if(ans.back() < 0 && i > 0) ans.push_back(i);
        else if(ans.back() > 0 && i < 0)
        {
            bool equal = true;
            while(!ans.empty() && (ans.back() > 0 && i < 0))
            {
                if(abs(i) > abs(ans.back()))
                {
                    ans.pop_back();
                }
                else if(abs(i) == abs(ans.back()))
                {
                    equal = false;
                    ans.pop_back();
                    break;
                }
                else{
                    equal = false;
                    break;
                }
            }
            if(equal) ans.push_back(i);
        }
    }
    return ans;
}

//orgasmic(strivers)
//time: O(2n)
//space: O(n)
vector<int> asteroidCollision1(vector<int>& ast)
{
    vector<int> ans;
    for(int i: ast)
    {
        if(i > 0) ans.push_back(i);
        else
        {
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(i))
                ans.pop_back();
            if(!ans.empty() && ans.back() == abs(i))
                ans.pop_back();
            else if(ans.empty() || ans.back() < 0)
                ans.push_back(i);
        }
    }
    return ans;
}