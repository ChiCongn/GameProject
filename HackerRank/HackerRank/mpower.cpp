
#include<iostream>
#include<cmath>
#include<algorithm>

int mpower(int b, int n, int m) {
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		int x = mpower(b, n / 2, m);
		std::cout << "Chan:\tb: " << b << " \tn= " << n << " \tm= " << m << " \t=> " << (x * x) % m << std::endl;
		return (x*x) % m;
	}
	else {
		int x = mpower(b, n / 2, m);
		std::cout << "Le:\tb: " << b << " \tn= " << n << " \tm= " << m << " \t=> " << (x * x) % m << std::endl;
		return ((x * x % m)*b%m) % m;
	}
}

int binpow(int x, int n, int m) {
	int res = 1;
	while (n) {
		if (n & 1) (res *= x) %= m;
		(x *= x) %= m;
		n >>= 1;
	}
	return res;
}
int main()
{
	int b, n, m;
	std::cout << "Nhap vao lan luot b, n, m: " << std::endl;
	std::cin >> b>> n>> m;
	std::cout << binpow(b, n, m) << std::endl
		<< mpower(b, n, m);
	return 0;
}