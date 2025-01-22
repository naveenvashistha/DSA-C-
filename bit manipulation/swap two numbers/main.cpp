#include <bits/stdc++.h>

using namespace std;

pair<int, int> get(int a, int b);
pair<int, int> get1(int a, int b);


int main()
{
    pair<int, int> p = get(70, 20);
}

//time: O(1)
//space: O(1)
pair<int, int> get(int a, int b){
    //complete the function here
    a = a + b;
    b = a - b;
    a = a - b;
    return {a, b};
}

//time: O(1)
//space: O(1)
pair<int, int> get1(int a, int b){
    //complete the function here
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}

