#include <bits/stdc++.h>

using namespace std;

int findmin1(vector<int>& nums);
int findmin2(vector<int>& nums);

int main()
{
    vector<int> num {3,4,5,6,1,2};
    int n = findmin1(num);
	cout << n << endl;
}

//brute force (my approach)
//time: O(n)
//space: O(1)
int findmin1(vector<int>& nums)
{
	int n = nums.size();
	for(int i = 0; i < n - 1; i++)
	{
		if(nums[i] > nums[i + 1])
		{
			return i + 1;
		}
	}
	return 0;
}

//orgasmic (my approach)
//time: O(logn)
//space: O(1)
int findmin2(vector<int>& nums)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	int min_ele = INT_MAX;
	int min_ele_indx;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(min_ele > nums[mid])
		{
			min_ele = nums[mid];
			min_ele_indx = mid;
		}
		if(nums[low] <= nums[mid] && nums[mid] <= nums[high])
		{
			if(min_ele > nums[low])
				return low;
			return min_ele_indx;
		}
		else if(nums[low] <= nums[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return min_ele_indx;
}


//orgasmic (striver's approach)
//time: O(logn)
//space: O(1)
int findmin3(vector<int>& nums)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	int min_ele = INT_MAX;
	int min_ele_indx;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[low] <= nums[mid] && nums[mid] <= nums[high])
		{
			if(min_ele > nums[low])
				return low;
			return min_ele_indx;
		}
		else if(nums[low] <= nums[mid])
		{
			if(nums[low] < min_ele)
			{
				min_ele_indx = low;
				min_ele = nums[low];
			}
			low = mid + 1;
		}
		else
		{
			if(nums[mid] < min_ele)
			{
				min_ele_indx = mid;
				min_ele = nums[mid];
			}
			high = mid - 1;
		}
	}
	return min_ele_indx;
}