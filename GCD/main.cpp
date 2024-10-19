#include <bits/stdc++.h>

using namespace std;

vector<int> lcmAndGCD1(int A, int B);
vector<int> lcmAndGCD2(int A, int B);

int main()
{
    int A, B;
    cin >> A >> B;
    vector<int> v1 = lcmAndGCD1(A, B);
    vector<int> v2 = lcmAndGCD2(A, B);
    cout << "LCM & HCF by method 1 is: " << v1[0] << " " << v1[1] << endl;
    cout << "LCM & HCF by method 2 is: " << v2[0] << " " << v2[1] << endl;
}

//time - O(logn)
//space - O(1)
vector<int> lcmAndGCD1(int A, int B){
    // code here
    int temp;
    int product = A*B;
    while (A != B)
    {
        temp = min(A, B);
        A = max(A, B) - min(A, B);
        B = temp;
    }
    return {product / A, A};
}

//time - O(log min(a,b))
//space - O(1)
vector<int> lcmAndGCD2(int A, int B){
    // code here
    int product = A*B;
    while (A != 0 && B != 0)
    {
        if (A > B)
        {
            A = A % B;
        }
        else
        {
            B = B % A;
        }
    }
    if (A == 0) return {product / B, B};
    return {product / A, A};
}