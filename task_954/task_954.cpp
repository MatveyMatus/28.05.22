#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    int N;
    std::ifstream inValue("input.txt");

    inValue >> N;
    inValue.close();

    std::vector<int> Ar(N + 1, 0);
    Ar[0] = 1;
    for (int i = 0; i < N + 1; ++i) {
        if (i + 1 > 10) {
            Ar[i] += Ar[i - 10];
        }
        if (i + 1 > 11) {
            Ar[i] += Ar[i - 11];
        }
        if (i + 1 > 12) {
            Ar[i] += Ar[i - 12];
        }
        Ar[i] %= 1000000;
    }

    std::ofstream result("output.txt");
    result << Ar[N] * 2 % 1000000;
    result.close();
    
}

