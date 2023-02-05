#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *a = new int[n1];
    int *b = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[l + k] = a[i];
            k++;
            i++;
        }
        if (b[j] <= a[i])
        {
            arr[l + k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[l + k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[l + k] = b[j];
        k++;
        j++;
    }

    // Your code here
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
    // code here
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}