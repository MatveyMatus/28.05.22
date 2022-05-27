#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    int N;

    std::ifstream inValue("input.txt");
    inValue >> N;
    const int MAX = 100;

    std::vector<std::vector<int>> Matr(N, std::vector<int>(N));
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inValue >> Matr[i][j];
            if (Matr[i][j] == 0 && i != j) {
                Matr[i][j] = MAX;
            }
        }
    }
    

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int q = 0; q < N; ++q) {
                Matr[j][q] = std::min(Matr[j][q], Matr[j][i] + Matr[i][q]);
            }
        }
    }

    int v1, v2;
    inValue >> v1 >> v2;
    v1--;
    v2--;

    std::ofstream result("output.txt");
    if (Matr[v1][v2] == MAX) {
        result << -1;
    }
    else {
        result << Matr[v1][v2];
    }

    inValue.close();
    result.close();
}

