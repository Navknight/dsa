#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int left = l;
    int right = r;
    while (left < right)
    {
        while (arr[left] < pivot)
        {
            left++;
        }
        while (arr[right] >= pivot)
        {
            right--;
        }
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[left], &arr[r]);
    return left;
}

void quickSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int pivot = partition(arr, l, r);
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
}

int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}