#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor);


int main()
{
    cout << divide(-2147483648, -1) << endl;
}

//in this algo, we are basically taking a chunk out of dividend till we can
//and we are taking the piece out(one at a time) which is equal to divisor*(representaion of quotient in terms of 2s power)
//and while taking that chunk out, we are adding that 2s power and eventually it will add up to quotient itself because we have represented the quotient in 2s power itself earlier
//orgasmic
//time: O((logN)^2)
//space: O(1)
int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    long long temp = 1;
    bool isNegative = false;
    long long count = 0;
    if(dividend < 0 && divisor > 0) isNegative = true;
    else if(dividend > 0 && divisor < 0) isNegative = true;
    long long D = abs((long long)dividend);
    long long d = abs((long)divisor);
    while(D >= d)
    {
        int i = 0;
        //loop to figure out the largest power of 2 * divisor that we can take out from dividend
        while((d << i) <= D)
        {
            i++;
        }
        //storing 2^i because that will be our quotient
        count += (temp << (i - 1));
        //taking the chunk out of dividend
        D -= (d << (i - 1));
    }
    if(!isNegative)
    {
        if(count > INT_MAX) return INT_MAX;
        return (int)count;
    }
    return (int)-count; 
}