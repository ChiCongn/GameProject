
#include<iostream>
#include<vector>

void printCombination(int n) {
	std::cout << 0 << " ";
	long long k = 1, multy = n;
	for (int i = 1; i <= n; i++) {
		k *= i;
		multy *= n - i;
		if ((multy / k) > 1e9) {
			std::cout << (multy / k) % 1000000000 << " ";
		}
		else
			std::cout << multy / k << " ";
	}
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> input(t);
	for (int i = 0; i < t; i++) {
		std::cin >> input[i];
	}
	for (int i = 0; i < t; i++) {
		printCombination(input[i]);
		std::cout << std::endl;
	}
	return 0;
}