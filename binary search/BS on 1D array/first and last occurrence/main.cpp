#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target);
int findfloor(vector<int>& nums, int target);
int findceil(vector<int>& nums, int target);

int main()
{
    vector<int> num {1,2,3,4};
    vector<int> n = searchRange(num, 5);
    for(int i: n)
		cout << i << " ";
	cout << endl;
}

//orgasmic
//time: O(2*logn) if sorted and O(nlogn + logn) if not sorted
//space: O(1)
vector<int> searchRange(vector<int>& nums, int target) {
	int f = findfloor(nums, target);
	int c = findceil(nums, target);
	return {f,c};
}

int findfloor(vector<int>& nums, int target)
{
	int low = 0;
	int high = nums.size() - 1;
	int mid, ans = -1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[mid] == target)
		{
			ans = mid;
			low = mid + 1;
		}
		else if(nums[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return ans;
}

int findceil(vector<int>& nums, int target)
{
	int low = 0;
	int high = nums.size() - 1;
	int mid, ans = -1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[mid] == target)
		{
			ans = mid;
			high = mid - 1;
		}
		else if(nums[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return ans;
}