
#include<iostream>
#include<vector>
#include<algorithm>

int MEXGame1(int& n, std::vector<int>& a) {
	int res = 0;
	std::sort(a.begin(), a.end());
	std::vector<int> c;
	int i = 0;
	while (!a.empty()) {
		
		//std::cout << ".." << std::endl;
	}
	for (int i = 0; i <= c.size(); i++) {
		bool check = false;
		for (int min : c) {
			if (min == i) {
				check = true;
				break;
			}
		}
		if (!check)
			return i;
	}	
	return -1;
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> res(t);
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int j = 0; j < n; j++) {
			std::cin >> a[j];
		}
		res[i] = MEXGame1(n, a);
	}
	for (int i = 0; i < t; i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}