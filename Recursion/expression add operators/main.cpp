#include <bits/stdc++.h>

using namespace std;

vector<string> addOperators(string num, int target);
void findTarget(vector<string> &v, string &num, string n, int ind, long calc, int target, int till_sum, int last_sum_num);

int main()
{
    vector<string> v = addOperators("123", 6);
    for(auto i: v)
        cout << i << endl;
}

void findTarget(vector<string> &v, string &num, string n, int ind, long calc, int target, int till_sum, int last_sum_num)
{
    if(ind == num.size())
    {
        if(calc == target) v.push_back(n);
        return;
    }
    long nn = 0;
    string temp = "";
    for(int i = ind; i < num.size(); i++)
    {
        if(i > ind && num[ind] == '0') break;
        temp = temp + num[i];
        nn = nn * 10 + (num[i] - '0');
        
        findTarget(v, num, n + "*" + temp, i + 1, till_sum - last_sum_num + (calc - till_sum + last_sum_num)*nn, target, till_sum, last_sum_num); 
        findTarget(v, num, n + "+" + temp, i + 1, calc + nn, target, calc + nn, nn);
        findTarget(v, num, n + "-" + temp, i + 1, calc - nn, target, calc - nn, -nn);
    }
    return;
}
vector<string> addOperators(string num, int target) {
    vector<string> v;
    if(num.length() == 1){
        if(num[0] - '0' == target) v.push_back(num);
        return v;
    }
    string n = "";
    long calc = 0;
    vector<char> ch = {'*', '+', '-'};
    for(int i = 0; i < num.length(); i++)
    {
        if(i == 0 && num[i] == '0')
        {
            n = "0";
            findTarget(v, num, n, 1, calc, target, 0, 0);
            break;
        }
        n += num[i];
        calc = calc * 10 + (num[i] - '0');
        findTarget(v, num, n, i + 1, calc, target, 0, 0);
    }
    return v;
}