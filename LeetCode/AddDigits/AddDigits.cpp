//https://leetcode.com/problems/add-digits/
#include<iostream>

int addDigits(int num) {
	int a[10] = { 9, 1, 2, 3, 4, 5, 6, 7, 8 };
	if (num) return a[num % 9];
	return num;
}
int main()
{
	int aa = addDigits(38);
	return 0;
}