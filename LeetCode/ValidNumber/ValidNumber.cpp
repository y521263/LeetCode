
#include <iostream>
#include <string>

using namespace std;

bool isDigit(const char c)
{
	return ('0' <= c && c <= '9');
}

//optimization: using iterator 
bool isNumber(string s){
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	if (s.size() < 1) return false;
	string digit = "0123456789";
	std::size_t loc = 0;
	if (s.at(loc) == '-' || s.at(loc) == '+')
	{
		s = s.substr(loc + 1);
		if (s.size() < 1) return false;
	}
	if (!isDigit(s.at(0)) && s.at(0) != '.') return false;
	if (s.at(0) == '.')
	{
		if (s.size() >= 2 && !isDigit(s.at(1))) return false;
	}
	loc = s.find_first_not_of(digit);
	if (loc == string::npos) return true;
	if (s.at(loc) == '.' && s.size()>1)
	{
		s = s.substr(loc+1);
		if (s.size() < 1) return true;
		loc = s.find_first_not_of(digit);
		if (loc == string::npos) return true;
	}
	if (s.at(loc) == 'e' || s.at(loc) == 'E')
	{
		s = s.substr(loc+1);
		if (s.size() < 1) return false;
	}
	if (s.at(0) == '-' || s.at(0) == '+')
	{
		s = s.substr(1);
		if (s.size() < 1) return false;
	}
	loc = s.find_first_not_of(digit);
	if (loc == string::npos) return true;
	return false;
}
int main()
{
	string str = "-.1";// 5.e .1 0.1 
	if (isNumber(str))
	{
		cout << "is Number \n";
	}
	else
	{
		cout << "not Number \n";
	}
	return 0;
}