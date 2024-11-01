#include <bits/stdc++.h>

using namespace std;

int search1(vector<int>& nums, int target);
int search2(vector<int>& nums, int target);

int main()
{
    vector<int> num {3,4,5,6,1,2};
    int n = search1(num, 5);
	cout << n << endl;
}

//my approach 
//time: O(n) + O(logn)
//space: O(1)
int search1(vector<int>& nums, int target)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	for(int i = 0; i < n - 1; i++)
	{
		if(nums[i] > nums[i + 1])
		{
			if(target >= nums[0]) high = i;
			else low = i + 1;
			break;
		}
	}
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[mid] == target) return mid;
		else if(nums[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

//find the sorted half
//then check if target is in sorted half
//if not then eliminate that half
//orgasmic
//time: O(logn)
//space: O(1)
int search2(vector<int>& nums, int target)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(target == nums[mid]) return mid; 
		else if(nums[low] <= nums[mid])
		{
			if(nums[low] <= target && nums[mid] >= target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		else
		{
			if(nums[mid] <= target && nums[high] >= target)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}