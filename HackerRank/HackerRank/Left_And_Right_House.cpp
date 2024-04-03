
#include<iostream>
#include<vector>
#include<string>

int roundUp(int n) {
	if (n % 2 == 0) {
		return n / 2;
	}
	else
		return (n / 2) + 1;
}

int positionRoad(int n, std::string a) {
	std::vector<int> houseLeft(n+2);
	std::vector<int> houseRight(n+2);
	houseLeft[0] = 0, houseRight[0] = n;
	houseLeft[n + 1] = n, houseRight[n + 1] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0')
			houseLeft[i+1] = houseLeft[i] + 1;
		else
			houseLeft[i+1] = houseLeft[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == '1') {
			houseRight[i+1] = houseRight[i + 2] + 1;
		}
		else
			houseRight[i+1] = houseRight[i + 2];
	}
	int index = n / 2 + 1;
	int pos = n / 2;
	bool checkIndex = false, checkPos = false;
	while (index<=n) {
		if (houseLeft[index] >= roundUp(index) && houseRight[index] >= roundUp(n - index)) {			
			//std::cout << "break " << std::endl;
			checkIndex = true;
			break;
		}			
		index++;
		
	}
	while (pos >= 0) {
		if (houseLeft[pos] >= roundUp(pos) && houseRight[pos] >= roundUp(n - pos)) {	
			//std::cout << "breakPos" << std::endl;
			checkPos = true;
			break;
		}
		pos--;
	}
	//std::cout <<"houseLeft: "<< houseLeft[pos] << std::endl;
	//std::cout <<"pos: "<< pos <<"  checkPos: "<<checkPos <<" | checkIndex: " <<checkIndex<< "  index: " << index << std::endl;
	if (checkIndex && !checkPos)
		return index;
	else if (!checkIndex && checkPos)
		return pos;
	if (checkIndex && checkPos) 
	{
		if ((n / 2.0 - pos) <= (index - (n / 2.0)))
			return pos;
		
		else
			return index;
	}	
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> res(t);
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::cin.ignore();
		std::string a;
		std::cin >> a;
		res[i]=positionRoad(n, a);
	}
	for (int i = 0; i < t; i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}