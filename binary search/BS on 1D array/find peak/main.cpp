#include <bits/stdc++.h>

using namespace std;

int peak1(vector<int>& nums);
int peak2(vector<int>& nums);

int main()
{
    vector<int> num {3,4,5,6,1,2};
    int n = peak2(num);
	cout << n << endl;
}

//brute force
//time: O(n)
//space: O(1)
int peak1(vector<int>& nums)
{
	int n = nums.size();
	for(int i = 0; i < n; i++)
	{
		if((i == 0 || nums[i] > nums[i - 1]) && (i == n - 1 || nums[i] > nums[i + 1]))
			return i;
	}
	return -1;
}

//orgasmic
//time: O(logn)
//space: O(1)
int peak2(vector<int>& nums)
{
	int n = nums.size();
	int low = 0, high = n - 1;
	int mid;
	while(low <= high)
	{
		if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1]))
			return mid;
		else if(nums[mid] < nums[mid + 1])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}