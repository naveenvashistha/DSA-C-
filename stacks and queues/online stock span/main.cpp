//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//orgasmic
//time: O(2n)
//space: O(n)
class StockSpanner {
public:
    vector<int> money;
    int i;
    stack<int> st;
    StockSpanner() {
        i = -1;
    }
    
    int next(int price) {
        int ans;
        i++;
        while(!st.empty() && money[st.top()] <= price)
            st.pop();
        if(!st.empty()) ans = i - st.top(); 
        else ans = i + 1;
        st.push(i);
        money.push_back(price);
        return ans;
    }
};

int main()
{
    StockSpanner s;
    cout << s.next(100) << endl;
    cout << s.next(80) << endl;
    cout << s.next(60) << endl;
    cout << s.next(70) << endl;
    cout << s.next(60) << endl;
}
