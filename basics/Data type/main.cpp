#include <iostream>
using namespace std;

int dataTypeSize(string str);

int main()
{
    string dataType;
    cin >> dataType;
    cout << dataTypeSize(dataType);
}

//time - O(1)
//space - O(1)
int dataTypeSize(string str)
{
        // your code here
        if (str == "Character")
        {
            return sizeof(char);
        }
        else if (str == "Integer" || str == "Float")
        {
            return sizeof(int);
        }
        else if (str == "Long" || str == "Double")
        {
            return sizeof(long);
        }
        else
        {
            return -1;
        }
}