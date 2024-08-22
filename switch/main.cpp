#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double switchCase(int choice, vector<double> &arr);

int main()
{
    int choice;
    vector<double> num;
    cout << "choice: ";
    cin >> choice;
    if (choice == 1)
    {
        double R;
        cout << "R: ";
        cin >> R;
        num.push_back(R);
    }
    else if (choice == 2)
    {
        double L, B;
        cout << "L & B: ";
        cin >> L >> B;
        num.push_back(L);
        num.push_back(B);
    }
    cout << "Area: " << switchCase(choice, num);
}

double switchCase(int choice, vector<double> &arr) {
        // code here
        double area;
        switch (choice)
        {
            case 1:
                area = 3.14 * pow(arr[0], 2);
                return area;
            
            case 2:
                area = arr[0] * arr[1];
                return area;
            
            default:
                cout << "Wrong choice" << endl;
                return 0;
        }
    }