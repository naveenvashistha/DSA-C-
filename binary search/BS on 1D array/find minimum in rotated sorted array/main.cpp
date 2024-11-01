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
			return nums[i + 1];
	}
	return nums[0];
}

//declare minimum element as min of mid and minimum element
//check if low<=mid<=high, if yes then return min of low and minimum element
//if not then go to unsorted half
//orgasmic (my approach)
//time: O(logn)
//space: O(1)
int findmin2(vector<int>& nums)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	int min_ele = INT_MAX;

	while(low <= high)
	{
		mid = (low + high) / 2;
		min_ele = min(min_ele, nums[mid]);
		if(nums[low] <= nums[mid] && nums[mid] <= nums[high])
			return min(nums[low], min_ele);
		else if(nums[low] <= nums[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return min_ele;
}

//check if low<=mid<=high, if yes then return min of low and minimum element
//if not then record min of min element and low
//go to unsorted half and repeat
//orgasmic (striver's approach)
//time: O(logn)
//space: O(1)
int findmin3(vector<int>& nums)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	int min_ele = INT_MAX;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[low] <= nums[mid] && nums[mid] <= nums[high])
			return min(min_ele, nums[low]);
		else if(nums[low] <= nums[mid])
		{
			min_ele = min(min_ele, nums[low]);
			low = mid + 1;
		}
		else
		{
			min_ele = min(min_ele, nums[mid]);
			high = mid - 1;
		}
	}
	return min_ele;
}