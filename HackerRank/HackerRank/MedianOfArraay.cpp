
#include <iostream>
#include <vector>
#include <algorithm>


int minOperationsToIncreaseMedian(int n, std::vector<int> a) {
    if (n == 1) {
        return 1;
    }
    std::sort(a.begin(), a.end());
    int medianIndex = (n + 1) / 2 -1 ;
    a[medianIndex]++;
    int operations = 1;
    for (int i = medianIndex; i < n-1; i++) {
        if (a[i]>a[i+1]) {
            operations++;
            a[i + 1]++;
        }
           
    }
    return operations;
}

int main() {
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
        //std::cout << a[0] << std::endl;
        res[i] = minOperationsToIncreaseMedian(n, a);
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
