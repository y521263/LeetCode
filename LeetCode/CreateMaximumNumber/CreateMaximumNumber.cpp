#include<iostream>
#include<vector>

using namespace std;


//最大数组的意思是 把一个数组当作一个数字 这个数字最大
vector<int> findsubarray(vector<int>& n1,int pos)
{
    int l1 = n1.size();
    if (pos >= l1) return n1;
    vector<int> ret(pos, 0);
    int idx = 0;
    for (int i = 0; i < l1; i++)
    {
        while (idx>0 && pos - idx < l1 - i && ret[idx - 1] < n1[i])
            idx--;
        if (idx < pos)
        {
            ret[idx++] = n1[i];
        }
    }
    return ret;
}
bool compareTwoArray(vector<int>& n1,int s1, vector<int>& n2,int s2)
{
    for (; s1 < n1.size() && s2 < n2.size(); s1++, s2++)
    {
        if (n1[s1]> n2[s2]) return true;
        if (n1[s1] < n2[s2]) return false;
    }
    return s1 < n1.size();
}
vector<int> mergeTwoArray(vector<int>& n1, vector<int>& n2)
{
    vector<int> result;
    int l1 = n1.size();
    int l2 = n2.size();
    int pos1 = 0;
    int pos2 = 0;
    while (pos1<l1 && pos2< l2)
    {
        if (n1[pos1] == n2[pos2])
            result.push_back(compareTwoArray(n1, pos1 + 1, n2, pos2 + 1) ? n1[pos1++] : n2[pos2++]);
        else
        {
            result.push_back(n1[pos1] > n2[pos2] ? n1[pos1++] : n2[pos2++]);
        }
    }
    if (pos1 < l1)
        result.insert(result.end(), n1.begin() + pos1, n1.end());
    if (pos2<l2)
        result.insert(result.end(), n2.begin() + pos2, n2.end());

    return result;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int l1 = nums1.size();
    int l2 = nums2.size();
    vector<int> result;

    if (k == l1 + l2)
    {
        auto ret = mergeTwoArray(nums1, nums2);
        return ret;
    }
    for (int i =  k> l2 ? k-l2:0; i <= nums1.size() && k - i <= nums2.size(); i++)
    {
        vector<int> s1 = findsubarray(nums1, i);
        vector<int> s2 = findsubarray(nums2, k-i);
        auto ret = mergeTwoArray(s1,s2);
        if (compareTwoArray(ret, 0, result, 0))
        {
            result = ret;
        }
    }
    return result;
}
int main()
{
    //vector<int> num1 = { 3, 4, 6, 5 };
    //vector<int> num2 = { 9, 1, 2, 5, 8, 3 };
    vector<int> num1 = { 8,6,9 };
    vector<int> num2 = { 1,7,5 };
    maxNumber(num1, num2, 3);
    return 0;
}