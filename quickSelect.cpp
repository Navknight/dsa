#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int quickLargest(vector<int> &arr, int l, int r, int k)
{
}

int quickSmallest(vector<int> &arr, int l, int r, int k)
{
}

int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};
    int n = arr.size();
    int k = 3;
    cout << quickLargest(arr, 0, n - 1, k) << endl;
    cout << quickSmallest(arr, 0, n - 1, k) << endl;
    return 0;
}