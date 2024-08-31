#include <iostream>
using namespace std;
void nTriangle(int n);

int main()
{
    int n;
    cin >> n;
    nTriangle(n);
    return 0;
}

void nTriangle(int n) {
	// Write your code here
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
