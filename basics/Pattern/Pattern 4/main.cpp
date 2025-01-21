#include <iostream>
using namespace std;
void triangle(int n);

int main()
{
    int n;
    cin >> n;
    triangle(n);
    return 0;
}

void triangle(int n) {
	// Write your code here
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << i + 1 << " ";
		}
		cout << endl;
	}
}