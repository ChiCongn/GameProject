#include <iostream>
#include <string>
#include<vector>

std::string arrayFix(int n, std::vector<int> a) {
	std::vector<int> check;
	check.push_back(0);
	for (int i = 0; i <n; i++) {
		if (check[check.size() - 1] <= a[i]) {
			int digit = a[i] % 10, chuc = a[i] / 10;
			if (digit >= chuc && chuc >= check[check.size() - 1]) {
				check.push_back(chuc);
				check.push_back(digit);
			}
			else {
				check.push_back(a[i]);
			}
		}
		else
			return "NO";
	}
	return "YES";
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<std::string> res(t);
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int j = 0; j < n; j++) {
			std::cin >> a[j];
		}
		res[i] = arrayFix(n, a);
	}
	for (int i = 0; i < t; i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}