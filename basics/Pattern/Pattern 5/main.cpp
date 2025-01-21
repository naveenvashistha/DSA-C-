#include <iostream>
using namespace std;
void seeding(int n);

int main()
{
    int n;
    cin >> n;
    seeding(n);
    return 0;
}

void seeding(int n) {
	// Write your code here.
	for (int i = n; i > 0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}