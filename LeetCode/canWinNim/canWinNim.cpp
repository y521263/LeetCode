
#include<iostream>
bool canWinNim(int n)
{
	if (n % 4 == 0) return false;
	return true;
}
int main()
{
	if (canWinNim(5))
	{
		std::cout << "win" << std::endl;
	}
	else
	{
		std::cout << "lose" << std::endl;
	}
	return 0;
}