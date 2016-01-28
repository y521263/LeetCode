/*

p1 p2 p3
p4 *  p5
p6 p7 p8

*/

#include<iostream>
#include<vector>
#include<map>
#include<sstream>

using namespace std;
struct Point{
	int x;
	int y;
	Point() :x(0), y(0){}
	Point(int a, int b) :x(a), y(b){}
};
//algo 1 超时 失败了

//string IntToStr(int i)
//{
//	std::stringstream stream;
//	string strresult;
//	stream << i;
//	stream >> strresult;
//	return strresult;
//}
//void UpdatePointState(Point& leftDownedge, Point& rightUpedge, const string& pointkey, map<string, int>& tmpmap)
//{
//	size_t i = 1;
//	bool p1, p2, p3, p4, p5, p6, p7, p8;
//	p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8= true;
//	int x, y;
//	int pos = pointkey.find("#");
//	x = stoi(pointkey.substr(0, pos));
//	y = stoi(pointkey.substr(pos+1));
//	string key = IntToStr(x) + "#" + IntToStr(y);
//	int value = tmpmap[key];
//	int tmpvalue = value;
//	string tmpkey;
//	while(p1){
//		tmpkey = IntToStr(x - i) + "#" + IntToStr(y + i);
//		//利用C++ map的有序性,判断是否已经遍历了 或者单独建立一个map保存已经遍历的
//		if (tmpkey < key)
//		{
//			p8 = false;
//			break;
//		}
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (x - i <= leftDownedge.x || y + i >= rightUpedge.y)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//
//	while (p2){
//		tmpkey = IntToStr(x) + "#" + IntToStr(y + i);
//		if (tmpkey < key)
//		{
//			p7 = false;
//			break;
//		}
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (y + i >= rightUpedge.y)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//
//	while (p3){
//		tmpkey = IntToStr(x + i) + "#" + IntToStr(y + i);
//		if (tmpkey < key) 
//		{
//			p6 = false;
//			break;
//		}
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (x + i >= rightUpedge.x || y + i >= rightUpedge.y)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//
//	while (p4){
//		tmpkey = IntToStr(x - i) + "#" + IntToStr(y);
//		if (tmpkey < key)
//		{
//			p5 = false;
//			break;
//		}
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (x - i <= leftDownedge.x)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//
//	while (p5){
//		tmpkey = IntToStr(x + i) + "#" + IntToStr(y);
//		if (tmpkey < key) break;
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (x + i >= rightUpedge.x)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//	while (p6){
//		tmpkey = IntToStr(x - i) + "#" + IntToStr(y - i);
//		if (tmpkey < key) break;
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (x - i <= leftDownedge.x || y - i >= leftDownedge.y)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//	while (p7){
//		tmpkey = IntToStr(x) + "#" + IntToStr(y - i);
//		if (tmpkey < key) break;
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (y - i <= leftDownedge.y)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//	i = 1;
//	tmpvalue = value;
//	while (p8){
//		tmpkey = IntToStr(x + i) + "#" + IntToStr(y - i);
//		if (tmpkey < key) break;
//		auto ite = tmpmap.find(tmpkey);
//		if (ite != tmpmap.end())
//		{
//			tmpvalue += ite->second;
//		}
//		else if (x + i >= rightUpedge.x || y - i <= leftDownedge.y)
//		{
//			if (tmpvalue > tmpmap[key]) tmpmap[key] = tmpvalue;
//			break;
//		}
//		i++;
//	}
//}
//int GetMax(map<string, int>& points)
//{
//	int max = 0;
//	for (auto ite = points.begin(); ite != points.end(); ++ite)
//	{
//		if (ite->second > max)
//			max = ite->second;
//	}
//	return max;
//}
//int maxPoints(vector<Point>& points) {
//	map<string, int> tmpmap;
//	Point leftDownedge;
//	Point rightUpedge;
//	for (auto ite = points.begin(); ite != points.end(); ++ite)
//	{
//		if (ite->x < leftDownedge.x)
//			leftDownedge.x = ite->x;
//		if (ite->y < leftDownedge.y)
//			leftDownedge.y = ite->y;
//
//		if (ite->x > rightUpedge.x)
//			rightUpedge.x = ite->x;
//		if (ite->y > rightUpedge.y)
//			rightUpedge.y = ite->y;
//
//		string key = IntToStr(ite->x) + "#" + IntToStr(ite->y);
//		if (tmpmap.find(key) != tmpmap.end())
//			tmpmap[key] += 1;
//		else
//			tmpmap[key] = 1;
//	}
//	for (auto ite = tmpmap.begin(); ite != tmpmap.end(); ++ite)
//	{
//		UpdatePointState(leftDownedge, rightUpedge, ite->first, tmpmap);
//	}
//	return GetMax(tmpmap);
//}
//algo 2
int maxPoints(vector<Point> &points) {
	map<double, int> tmpmap;
	int maxnum = 0;
	if (points.size() <= 2) return points.size();

	for (int i = 0; i < points.size(); i++)
	{
		tmpmap.clear();
		tmpmap[INT_MIN] = 0;//确保[ [1,1] [1,1] [1,1] ] 情况下 tmpmap不是空的
		int samepoints = 1;//这里 1 看似多了其实不多
		for (int j = i+1; j < points.size();j++)
		{
			int delta_x = points[i].x - points[j].x;
			int delta_y = points[i].y - points[j].y;
			if (delta_x == 0 && delta_y == 0)
			{
				samepoints++;
				continue;
			}
			double inx = INT_MAX;
			if (delta_y != 0)
			{
				inx = 1.0*delta_x / delta_y;
			}
			tmpmap[inx]++;
		}
		for (auto ite = tmpmap.begin(); ite != tmpmap.end(); ++ite)
		{
			if (maxnum < ite->second + samepoints)
				maxnum = ite->second + samepoints;
		}
	}
	return maxnum;
}
int main()
{
	vector<Point> points;
	/*points.push_back(Point(1, 0));
	points.push_back(Point(1, 1));
	points.push_back(Point(3, 3));
	points.push_back(Point(4, 5));*/
	points.push_back(Point(0, 0));
	points.push_back(Point(-1, -1));
	points.push_back(Point(2, 2));

	maxPoints(points);
	return 0;
}