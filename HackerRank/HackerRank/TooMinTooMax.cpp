
#include<iostream>
#include<vector>
#include<algorithm>

unsigned int maxVal(int n, std::vector<int> a) {
	unsigned int max = 0;
	std::sort(a.begin(), a.end());
	max = 2 * (a[n - 1] - a[0] + a[n - 2] - a[1]);
	return max;
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<unsigned int> res(t);
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int j = 0; j < n; j++) {
			std::cin >> a[j];
		}
		res[i] = maxVal(n, a);
	}
	for (int i = 0; i < t; i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}