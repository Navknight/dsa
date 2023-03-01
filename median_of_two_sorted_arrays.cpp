#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int t = nums1.size() + nums2.size();
    int h = t / 2;
    vector<int> a;
    int i = 0;
    int j = 0;
    while (t-- >= h)
    {
        if (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                a.push_back(nums1[i]);
                i++;
            }
            else
            {
                a.push_back(nums2[j]);
                j++;
            }
        }
        else if (i < nums1.size())
        {
            a.push_back(nums1[i]);
            i++;
        }
        else if (j < nums2.size())
        {
            a.push_back(nums2[j]);
            j++;
        }
    }
    int n = a.size();
    // for(int i = 0; i < n; i++)
    //     cout<<a[i]<<" ";
    if (n >= 2)
        return ((nums1.size() + nums2.size()) % 2 == 0) ? (float)(a[n - 1] + a[n - 2]) / 2.0 : (float)a[n - 2];
    else
        return a[0];
}

int main()
{
    vector<int> nums1;
    vector<int> nums2 = {3};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}