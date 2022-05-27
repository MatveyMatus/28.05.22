#include <iostream>
#include <fstream>

int main()
{
	int N;
	std::ifstream inValue("input.txt");
	inValue >> N;
	inValue.close();

	int num1 = 0, num2 = 0;

	for (int i = N; i > 0; --i) {
		for (int j = 1; j < N; ++j) {
			if (i + j == N && i % j == 0) {
				num1 = i;
				num2 = j;
			}
		}
	}

	std::ofstream result("output.txt");
	result << num2 << " " << num1;
	result.close();
}

