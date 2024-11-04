#include <bits/stdc++.h>

using namespace std;

int findsingle1(vector<int>& nums);
int findsingle2(vector<int>& nums);
int findsingle3(vector<int>& nums);
int findsingle4(vector<int>& nums);

int main()
{
    vector<int> num {3,4,5,6,1,2};
    int n = findsingle1(num);
	cout << n << endl;
}

//brute force (my approach)
//time: O(n)
//space: O(1)
int findsingle1(vector<int>& nums)
{
	int n = nums.size();
	if(n == 1) return nums[0];
	else if(nums[0] != nums[1]) return nums[0];
	else if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

	for(int i = 1; i < n - 1; i++)
	{
		if(nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
			return nums[i];
	}
	return -1;
}

//brute force (my approach)
//time: O(n)
//space: O(1)
int findsingle2(vector<int>& nums)
{
	int n = nums.size();
	int xorr = 0;

	for(int i = 0; i < n; i++)
	{
		xorr = xorr ^ nums[i];
	}
	return xorr;
}

//brute force (my approach)
//time: O(n)
//space: O(1)
int findsingle3(vector<int>& nums)
{
	int n = nums.size();
	if(n == 1) return nums[0];

	for(int i = 0; i < n; i = i + 2)
	{
		if(nums[i] - nums[i + 1] != 0)
			return nums[i];
	}
	return -1;
}

//orgasmic (my approach)
//time: O(logn)
//space: O(1)
int findsingle4(vector<int>& nums)
{
	int n = nums.size();
	int low = 1, high = n - 2, mid;
	if(n == 1) return nums[0];
	else if(nums[0] != nums[1]) return nums[0];
	else if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
		else if((mid % 2 == 0 && nums[mid + 1] == nums[mid]) || (mid % 2 != 0 && nums[mid - 1] == nums[mid])) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

