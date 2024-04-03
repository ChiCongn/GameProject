
#include<iostream>
#include<string>
#include<vector>

std::string reverse(std::string s) {
	int len = s.length();
	std::string res = s;
	for (int i = 0; i < len; i++) {
		res[i] = s[len - i - 1];
	}
	return res;
}

std::string lexicographicallySmallestString(int& n, std::string& s) {
	int len = s.length();
	std::string res = reverse(s) + s;
	if (res < s)
		return res;
	else
		return s;
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<std::string> res(t);
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::cin.ignore();
		std::string s;
		std::getline(std::cin, s);
		res[i] = lexicographicallySmallestString(n, s);
	}
	for (int i = 0; i < t; i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}