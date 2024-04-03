
#include<iostream>
#include<vector>
#include<algorithm>

//1  3  6  10  and  15

int minNumOfCoins(int n) {
	 int amount = 0;
	 while (n >= 15 && n%20!=0) {
		 n -= 15;
		 amount++;
	 }
	 while (n >= 10 && n%12!=0) {
		 n -= 10;
		 amount++;
	 }
	 while (n >= 6) {
		 n -= 6;
		 amount++;
	 }
	 while (n >= 3) {
		 n -= 3;
		 amount++;
	 }
	 while (n >= 1) {
		 n -= 1;
		 amount++;
	 }

	 return amount;
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> res(t);
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		res[i] = minNumOfCoins(n);
	}
	for (int i = 0; i < t; i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}