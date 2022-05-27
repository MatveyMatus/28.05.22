#include <iostream>
#include <fstream>
#include <vector>


int main()
{
	int N;

	std::ifstream inValue("input.txt");
	inValue >> N;
	std::vector<std::vector<int>> price(N + 1, std::vector<int>(N + 1));

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			inValue >> price[i][j];
		}
	}
	inValue.close();

	std::vector<int> minPrice(N+1, INT_MAX);
	minPrice[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			minPrice[i] = std::min(minPrice[i], minPrice[j]+price[j][i]);
		}
	}

	std::ofstream result("output.txt");
	result << minPrice[N];
	result.close();
}


