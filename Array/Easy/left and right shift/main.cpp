#include <bits/stdc++.h>
using namespace std;

void leftshiftbyKsteps1(vector<int>& nums, int k);
void leftshiftbyKsteps2(vector<int>& nums, int k);
void rightshiftbyKsteps1(vector<int>& num, int k);
void rightshiftbyKsteps2(vector<int>& num, int k);

int main()
{
    vector<int> num {1,2,3,4,5,6,7};
    //leftshiftbyKsteps1(num, 4);
    //leftshiftbyKsteps2(num, 3);
    //rightshiftbyKsteps1(num, 11);
    rightshiftbyKsteps2(num, 12);
    for(int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}

//brute force
//time: O(n)
//space: O(k)
void leftshiftbyKsteps1(vector<int>& num, int k) {
    vector<int> temp;
    int n = num.size();
    k = k % n;
    for(int i = 0; i < k; i++)
        temp.push_back(num[i]);
    
    for(int i = k; i < n; i++)
        num[i - k] = num[i];
    
    for(int i = n - k; i < n; i++)
        num[i] = temp[i - (n - k)];

}

//optimal
//time: O(2n)
//space: O(1)
void leftshiftbyKsteps2(vector<int>& num, int k) {
    k = k % num.size();
    reverse(num.begin(), num.begin() + k);
    reverse(num.begin() + k, num.end());
    reverse(num.begin(), num.end());    
}

//brute force
//time: O(n)
//space: O(k)
void rightshiftbyKsteps1(vector<int>& num, int k) {
    vector<int> temp;
    int n = num.size();
    k = k % n;
    for(int i = 0; i < n - k; i++)
        temp.push_back(num[i]); 
    
    for(int i = n - k; i < n; i++)
        num[i - (n - k)] = num[i];
    
    for(int i = k; i < n; i++)
        num[i] = temp[i - k];
}

//optimal
//time: O(2n)
//space: O(1)
void rightshiftbyKsteps2(vector<int>& num, int k) {
    k = k % num.size();
    reverse(num.begin(), num.begin() + num.size() - k);
    reverse(num.begin() + num.size() - k, num.end());
    reverse(num.begin(), num.end());    
}