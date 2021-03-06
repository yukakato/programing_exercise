#include <iostream>
#include <time.h>
using namespace std;

// Q値が入力される行列，経路のない項目は-1
int q[12][12] = {
    {-1,  0, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1},
    { 0, -1,  0, -1, -1,  0, -1, -1, -1, -1, -1, -1},
    {-1,  0, -1,  0, -1, -1,  0, -1, -1, -1, -1, -1},
    {-1, -1,  0, -1, -1, -1, -1,  0, -1, -1, -1, -1},
    { 0, -1, -1, -1, -1,  0, -1, -1,  0, -1, -1, -1},
    {-1,  0, -1, -1,  0, -1,  0, -1, -1,  0, -1, -1},
    {-1, -1,  0, -1, -1,  0, -1,  0, -1, -1,  0, -1},
    {-1, -1, -1,  0, -1, -1,  0, -1, -1, -1, -1,  0},
    {-1, -1, -1, -1,  0, -1, -1, -1, -1,  0, -1, -1},
    {-1, -1, -1, -1, -1,  0, -1, -1,  0, -1,  0, -1},
    {-1, -1, -1, -1, -1, -1,  0, -1, -1,  0, -1,  0},
    {-1, -1, -1, -1, -1, -1, -1,  0, -1, -1,  0, -1}
};

// Q値を初期化する
void initialize() {
    srand((unsigned int)time(NULL));
    // [0,99]の範囲の乱数を生成し，-1でない項目の初期値にする
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            if (q[i][j] != -1) q[i][j] = rand() % 100;
}

// ここに遷移処理，Q値の更新処理などを書く
void action() {
}

// 結果を出力する
void print_q(void) {
    cout << endl;
    cout << "       --" << (int)q[8][9] << "--> " 
         << "      --" << (int)q[9][10] << "--> " 
         << "      --" << (int)q[10][11] << "-->" << endl;
    cout << "       <--" << (int)q[9][8] << "-- " 
         << "      <--" << (int)q[10][9] << "-- "
         << "      <--" << (int)q[11][10] << "-- " << endl << endl;
    cout << (int)q[4][8] << "|" << (int)q[8][4] << "        " 
         << (int)q[5][9] << "|" << (int)q[9][5] << "        " 
         << (int)q[6][10] << "|" << (int)q[10][6] << "         " 
         << (int)q[7][11] << "|" << (int)q[11][7] << endl << endl;
    cout << "       --" << (int)q[4][5] << "--> " 
         << "      --" << (int)q[5][6] << "--> " 
         << "      --" << (int)q[6][7] << "-->" << endl;
    cout << "       <--" << (int)q[5][4] << "-- " 
         << "      <--" << (int)q[6][5] << "-- "
         << "      <--" << (int)q[7][6] << "-- " << endl << endl;
    cout << (int)q[0][4] << "|" << (int)q[4][0] << "        " 
         << (int)q[1][5] << "|" << (int)q[5][1] << "        " 
         << (int)q[2][6] << "|" << (int)q[6][2] << "         " 
         << (int)q[3][7] << "|" << (int)q[7][3] << endl << endl;
    cout << "       --" << (int)q[0][1] << "--> " 
         << "      --" << (int)q[1][2] << "--> " 
         << "      --" << (int)q[2][3] << "-->" << endl;
    cout << "       <--" << (int)q[1][0] << "-- " 
         << "      <--" << (int)q[2][1] << "-- "
         << "      <--" << (int)q[3][2] << "-- " << endl << endl;
    cout << "-------------------------------------------------" << endl;
}

// main関数
int main() {
    initialize();
    action();
    print_q();
}
