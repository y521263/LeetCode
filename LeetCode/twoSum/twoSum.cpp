#include<iostream>
#include<vector>
#include<map>
using namespace std;
// algo 1 简单粗暴
//vector<int> twoSum(vector<int>& nums, int target)
//{
//	map<int, int> tmpmap;
//	vector<int> ret;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		for (int j = i + 1; j< nums.size(); j++)
//		{
//			if (target != nums[i] + nums[j])
//			{
//				continue;
//			}
//			if (i < j)
//			{
//				ret.push_back(i + 1);
//				ret.push_back(j + 1);
//			}
//			else
//			{
//				ret.push_back(j + 1);
//				ret.push_back(i + 1);
//			}
//			return ret;
//		}
//	}
//	return ret;
//}
// algo 2 稍微优化一点
vector<int> twoSum(vector<int>& nums, int target)
{
	multimap<int, int> tmpmap;
	vector<int> vecret;
	for (int i = 0; i < nums.size();i++)
	{
		tmpmap.insert(pair<int, int>(nums[i], i));
	}
	for (auto ite = tmpmap.begin(); ite != tmpmap.end(); ite++)
	{
		if (ite->first == target - ite->first && tmpmap.count(ite->first) < 2) continue;
		if (ite->first == target - ite->first && tmpmap.count(ite->first) >= 2)
		{
			auto ret = tmpmap.equal_range(ite->first);
			int pos1 = INT_MAX;
			int pos2 = INT_MAX - 1;
			for (auto tt = ret.first; tt != ret.second; tt++)
			{
				if (pos1 > pos2 && tt->second < pos1)
				{
					pos1 = tt->second;
					continue;
				}
				else if (tt->second<pos2)
				{
					pos2 = tt->second;
					continue;
				}
			}
			vecret.push_back(pos1 + 1);
			vecret.push_back(pos2 + 1);
			return vecret;
		}
		else if (tmpmap.find(ite->first) != tmpmap.end() && tmpmap.find(target - ite->first) != tmpmap.end())
		{
			auto ret = tmpmap.equal_range(ite->first);
			int pos = INT_MAX;
			auto tmpite = ret.first;
			for (auto tt = ret.first; tt != ret.second; tt++)
			{
				if (tt->second < pos)
				{
					tmpite = tt;
					pos = tt->second;
				}
			}
			int val1 = tmpite->second;

			ret = tmpmap.equal_range(target - ite->first);
			pos = INT_MAX;
			tmpite = ret.first;
			for (auto tt = ret.first; tt != ret.second; tt++)
			{
				if (tt->second < pos)
				{
					tmpite = tt;
					pos = tt->second;
				}
			}
			int val2 = tmpite->second;
			if (val1 < val2)
			{
				vecret.push_back(val1 + 1);
				vecret.push_back(val2 + 1);
			}
			else
			{
				vecret.push_back(val2 + 1);
				vecret.push_back(val1 + 1);
			}
			return vecret;
		}
	}
	return vecret;
}
int main()
{
	vector<int> vec;
	vec.push_back(-3);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(90);
	twoSum(vec,0);
	return 0;
}