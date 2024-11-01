#include <bits/stdc++.h>

using namespace std;

bool search1(vector<int>& nums, int target);
bool search2(vector<int>& nums, int target);

int main()
{
    vector<int> num {3,4,5,6,1,2};
    bool n = search1(num, 5);
	cout << n << endl;
}

//my approach 
//time: O(n) + O(logn)
//space: O(1)
bool search1(vector<int>& nums, int target)
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
		if(nums[mid] == target) return true;
		else if(nums[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return false;
}

//find the sorted half
//then check if target is in sorted half, if yes eliminate other half
//if not then eliminate that half
//handle edge case: arr[mid] == arr[low] == arr[high] by simply incrementing low and decrementing high
//orgasmic
//time: O(logn)
//space: O(1)
bool search2(vector<int>& nums, int target)
{
	int n = nums.size();
	int low = 0, high = n - 1, mid;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(target == nums[mid]) return true;
		else if(nums[low] == nums[mid] && nums[mid] == nums[high]) 
		{
			low++;
			high--;
		} 
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
	return false;
}