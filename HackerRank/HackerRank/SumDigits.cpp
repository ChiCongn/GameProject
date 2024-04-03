
#include<iostream>
#include<string>

int main()
{
	std::string num;
	int k;
	std::cin >> num;
	std::cin >> k;
	unsigned int sum = 0;
	for (char c : num) {
		sum += c - '0';
		if (sum > 9)
			sum -= 9;
		std::cout << sum << std::endl;
	}
	sum =(sum* k) % 9;
	if (sum == 0)
		sum = 9;
	std::cout << sum;
	return 0;
}