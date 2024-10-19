#include <bits/stdc++.h>

using namespace std;

bool palindrome1(string s);
bool palindrome2(int i, int j, string s);

int main()
{
	string s;
	cin >> s;
	cout << palindrome1(s) << endl;
	cout << palindrome2(0, s.size() - 1, s) << endl; 
}

//time - O(n)
//space - O(1)
bool palindrome1(string s) {
	int left = 0, right = s.size() - 1;
	while (left < right)
	{
		if (!isalnum(s[left]))
			left++;
		else if (!isalnum(s[right]))
			right--;
		else if (tolower(s[left]) != tolower(s[right]))
		{
			return false;
		}
		else
		{
			right--;
			left++;
		}
	}
	return true;
}

//time - O(n)
//space - O(n)
bool palindrome2(int i, int j, string s)
{
	if (i >= j)
	{
		return true;
	}
	if (!isalnum(s[i]))
		i++;
	else if (!isalnum(s[j]))
		j--;
	else if (tolower(s[i] != tolower(s[j])))
		return false;
	else
	{
		i++;
		j--;
	}
	bool res = palindrome2(i, j, s);
	if (res == true) return true;
	else return false;
}