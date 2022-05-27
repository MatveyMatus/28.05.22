#include <iostream>
#include <fstream>
#include <cassert>

int main()
{
    int N;
    std::ifstream inValue("input.txt");
    inValue >> N;
    inValue.close();

    int quant2, quant3;

    if (N % 3 == 0) {
        quant2 = 0;
        quant3 = N / 3;
    }
    else if (N % 3 == 1) {
        quant2 = 2;
        quant3 = (N - 4) / 3;
    }
    else {
        assert(N % 3 == 2);
        quant2 = 1;
        quant3 = (N - 2) / 3;
    }

    std::ofstream result("output.txt");

    if (quant2 > 0 && quant3 > 0) {
        result << "2 " << quant2 << " 3 " << quant3 << std::endl;
    }
    else if (quant2 > 0) {
        assert(quant3 == 0);
        result << "2 " << quant2 << std::endl;
    }
    else {
        assert(quant2 == 0 && quant3 > 0);
        result << "3 " << quant3 << std::endl;
    }
    result.close();
}
