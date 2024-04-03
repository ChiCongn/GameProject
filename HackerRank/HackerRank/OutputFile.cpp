
#include<iostream>
#include<fstream>

int main()
{
	std::ofstream file ("D:\\HighScore.txt");
	if (file.is_open()) {
		for (int i = 1; i <= 12; i++) {
			file << i+1 <<" ";
		}
		file << "Close";
		file.close();
	}
	return 0;
}