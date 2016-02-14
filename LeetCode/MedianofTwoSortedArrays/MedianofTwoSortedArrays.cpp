//https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double findkth(vector<int>& nums1, int np1, vector<int>& nums2, int np2,int k)
{
    if (nums1.size()-np1 > nums2.size()-np2)
        return findkth(nums2,np2,nums1,np1,k);
    if (nums1.size() - np1 == 0)
        return nums2[np2+k - 1];
    if (k == 1)
        return min(nums1[np1],nums2[np2]);
    int pa = min(k/2,int(nums1.size()-np1));
    int pb = k - pa;
    if (nums1[np1 + pa - 1] < nums2[np2 + pb - 1])
        return findkth(nums1, np1 + pa, nums2, np2, k - pa);
    else if (nums1[np1 + pa - 1] > nums2[np2 + pb - 1])
        return findkth(nums1, np1, nums2, np2 + pb, k - pb);
    else
        return nums1[np1 + pa - 1];
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if (total % 2)
    {
        return findkth(nums1, 0, nums2, 0, total / 2 + 1);
    }
    else
    {
        return (findkth(nums1, 0, nums2, 0, total / 2) + findkth(nums1, 0, nums2, 0, total / 2 + 1)) /2.0;
    }
}
int main()
{
    vector<int> vec1 = { 1, 2, 3, 4, 34 };
    vector<int> vec2 = { 6, 7, 8, 9, 20 };
    double a = findMedianSortedArrays(vec1,vec2);
    return 0;
}