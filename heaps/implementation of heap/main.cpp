#include <bits/stdc++.h>

using namespace std;

class minHeap{
    int* arr;
    int capacity;
    int count;
    public:
    minHeap(int cap){
        count = 0;
        capacity = cap;
        arr = new int[capacity];
    }
    //time: O(1)
    int parent(int i){
        if(i > 0) return (i - 1) / 2;
        return -1;
    }
    //time: O(1)
    int leftChild(int i){
        if(2 * i + 1 < count) return (2 * i + 1);
        return -1;
    }
    //time: O(1)
    int rightChild(int i){
        if(2 * i + 2 < count) return (2 * i + 2);
        return -1;
    }
    //time: O(1)
    int getMin(){
        if(count != 0)
            return arr[0];
        return INT_MIN;
    }
    //time: O(logn)
    void minHeapifyDown(int i){
        int l = leftChild(i);
        int r = rightChild(i);
        int smallest = i;
        if(l != -1 && arr[l] < arr[smallest])
            smallest = l;
        if(r != -1 && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapifyDown(smallest);
        }
    }
    //time: O(logn)
    void minHeapifyUp(int i){
        int p = parent(i);
        while(i != 0 && arr[p] > arr[i])
        {
            swap(arr[p], arr[i]);
            i = p;
            p = parent(p);
        }
    }
    //time: O(logn)
    int extractMin()
    {
        int min_ele;
        if(count == 0){
            cout << "heap is empty" << endl;
            return INT_MAX;
        }
        if(count == 1){
            count--;
            return arr[0];
        }
        min_ele = arr[0];
        arr[0] = arr[count - 1];
        count--;
        minHeapifyDown(0);
        return min_ele;
    }
    //time: O(logn)
    void decreaseKey(int i, int new_val)
    {
        arr[i] = new_val;
        minHeapifyUp(i);
    }
    //time: O(logn)
    void insertKey(int k)
    {
        if(count == capacity)
        {
            cout << "heap is full" << endl;
            return;
        }
        arr[count] = k;
        count++;
        minHeapifyUp(count);
    }
    //time: O(logn)
    void deleteKey(int i)
    {
        if(count == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[i] = arr[count - 1];
        count--;
        minHeapifyDown(i);
    }
};

int main()
{
}

