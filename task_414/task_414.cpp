#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int n, a, b, k;

    std::ifstream inValue("input.txt");
    inValue >> n >> a >> b;

    std::vector <int> v;
    std::vector <int> v1;
    std::vector <int> v2;
    v.push_back(1);
    v.push_back(1);

    for (int i = 1; i < n; ++i) {
        inValue >> k;
        v.push_back(k);
    }

    inValue.close();

    int x = a;
    v1.push_back(x);
    int y = b;
    v2.push_back(y);

    while (x != 1) {
        x = v[x];
        v1.push_back(x);
    }

    while (y != 1) {
        y = v[y];
        v2.push_back(y);
    }

    x = a;
    y = b;

    while (x != y) {
        if (v2.size() > v1.size())
        {
            v2.erase(v2.begin());
        }

        else
            v1.erase(v1.begin());

        x = v1[0];
        y = v2[0];
    }

    std::ofstream result("output.txt");

    result << x;

    result.close();
}