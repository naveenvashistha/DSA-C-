#include <bits/stdc++.h>

using namespace std;

double minimiseMaxDistance1(vector<int> &arr, int k);
double minimiseMaxDistance2(vector<int> &arr, int k);
double minimiseMaxDistance3(vector<int> &arr, int k);
int calGasStations(vector<int> arr, double mid);

int main()
{
    vector<int> arr = {25, 12, 8, 14, 19};
    double n = minimiseMaxDistance1(arr, 5);
    // double n = minimiseMaxDistance2(arr, 5);
    cout << n << endl;
}

//brute force
//time: O(k*n + n)
//sapce: O(n - 1)
double minimiseMaxDistance1(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
    double maxDist;
    int max_ind;
    vector<int> stationsPlaced(n - 1, 0);
    //inserting one gas station at a time between max distance apart consecutive gas stations
    for(int i = 0; i < k; i++)
    {
        maxDist = -1;
        max_ind = 0;
        //selecting the max dist index and value
        for(int j = 0; j < n - 1; j++)
        {
            double stationLength = (double)(arr[j + 1] - arr[j]) / (double)(stationsPlaced[j] + 1);
            if(stationLength > maxDist)
            {
                maxDist = stationLength;
                max_ind = j;
            }
        }
        stationsPlaced[max_ind]++;
    }
    maxDist = -1;
    for(int j = 0; j < n - 1; j++)
    {
        double stationLength = (double)(arr[j + 1] - arr[j]) / (double)(stationsPlaced[j] + 1);
        if(stationLength > maxDist)
        {
            maxDist = stationLength;
        }
    }
    return maxDist;	
}

//better
//time: O(n*logn + k*logn)
//space: O(n - 1) + O(n - 1)
double minimiseMaxDistance2(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
    vector<int> stationsPlaced(n - 1, 0);
    priority_queue<pair<double, int>> stationLength;

    for(int i = 0; i < n - 1; i++)
    {
        stationLength.push({arr[i + 1] - arr[i], i});
    } 
    //inserting one gas station at a time between max distance apart consecutive gas stations
    for(int i = 0; i < k; i++)
    {
        pair<int, int> maxx = stationLength.top();
        stationLength.pop();
        stationsPlaced[maxx.second]++;
        double length = (arr[maxx.second + 1] - arr[maxx.second]) / (double)(stationsPlaced[maxx.second] + 1);
        stationLength.push({length, maxx.second});
    }
    return stationLength.top().first;
}

//orgasmic
//time: O(n*log(maxx dist between two consec stations) + n)
//space: O(1)
double minimiseMaxDistance3(vector<int> &arr, int k)
{
    int n = arr.size();
    double maxDist = -1;
    for(int j = 0; j < n - 1; j++)
    {
        double stationLength = (double)(arr[j + 1] - arr[j]);
        maxDist = max(maxDist, stationLength);
    }
    double low = 0, high = maxDist, mid;
    while(high - low > 1e-6)
    {
        mid = (low + high) / 2;
        int gasStations = calGasStations(arr, mid);
        if(gasStations <= k) high = mid;
        else low = mid;
    }
    return high;
}

int calGasStations(vector<int> arr, double mid)
{
    if(mid == 0) return 0;
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int stations = (arr[i + 1] - arr[i]) / mid;
        if(stations * mid == arr[i + 1] - arr[i])
            stations--;
        cnt += stations;
    }
    return cnt;
}
