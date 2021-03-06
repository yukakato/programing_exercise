#include <iostream>
#include <string>
using namespace std;

int d[5][5] = {
    {10000, 10000, 10000, 10000, 10000},
    {10000, 10000, 10000, 10000, 10000},
    {10000, 10000, 10000, 10000, 10000},
    {10000, 10000, 10000, 10000, 10000},
    {10000, 10000, 10000, 10000, 10000}
};

void edit_distance(string& str1, string& str2) {
    for (int i = 0; i < str1.size() + 1; ++i) d[i][0] = i;
    for (int i = 0; i < str2.size() + 1; ++i) d[0][i] = i;
    for (int i = 1; i < str1.size() + 1; ++i) {
        for (int j = 1; j < str2.size() + 1; j++) {
            int n1 = d[i-1][j-1] + 1;
            if (str1[i-1] == str2[j-1]) n1 = d[i-1][j-1];
            int n2 = min(d[i-1][j], d[i][j-1]) + 1;
            d[i][j] = min(n1, n2);
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << d[i][j] << " ";
        cout << endl;
    }
}

int main() {
    string str1 = "abcd";
    string str2 = "aebc";
    edit_distance(str1, str2);
}
