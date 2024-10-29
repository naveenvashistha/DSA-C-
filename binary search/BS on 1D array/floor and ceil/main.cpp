#include <bits/stdc++.h>

using namespace std;

pair<int,int> floor_ceil1(vector<int>& nums, int n, int target);
pair<int,int> floor_ceil2(vector<int>& nums, int n, int target);
int findfloor(vector<int>& nums, int n, int target);
int findceil(vector<int>& nums, int n, int target);

int main()
{
    vector<int> num {1,2,3,4};
    pair<int,int> n = floor_ceil1(num, 4, 5);
    cout << n.first << " " << n.second << endl;
}

//orgasmic (my approach)
//time: O(logn) if sorted and O(nlogn + logn) if not sorted
//space: O(1)
pair<int, int> floor_ceil1(vector<int>& a, int n, int x) {
    int low = 0;
	int high = n - 1;
	int mid, ans = n;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(a[mid] == x) return {a[mid] , a[mid]};
		if(a[mid] > x)
		{
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	if(ans == 0) return {-1, a[ans]};
	else if(ans == n) return {a[ans - 1], -1};
	return {a[ans - 1], a[ans]};
}

//orgasmic (striver's)
//time: O(2*logn)
//space: O(1)
pair<int,int> floor_ceil2(vector<int>& nums, int n, int target) {
    int f = findfloor(nums, n, target);
    int c = findceil(nums, n, target);
    return {f, c};
}

int findfloor(vector<int>& nums, int n, int target)
{
    int low = 0;
	int high = n - 1;
	int mid, ans = -1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[mid] <= target)
		{
			ans = nums[mid];
			low = mid + 1;
		}
		else high = mid - 1;
	}
    return ans;
}

int findceil(vector<int>& nums, int n, int target)
{
    int low = 0;
	int high = n - 1;
	int mid, ans = -1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(nums[mid] >= target)
		{
			ans = nums[mid];
			high = mid - 1;
		}
		else low = mid + 1;
	}
    return ans;
}