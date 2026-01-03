#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int main (void){
    double x, y;    // ランダムなxとyの座標
    double z;       // x^2 + y^2 の結果を格納する変数
    double pi;      // 円周率の近似値を格納する変数
    int count = 0;      // 円の中に入った回数

    // 乱数のシードを設定
    srand(time(NULL));     

    for (int i = 0; i < MAX; i++){

        x = (double)rand() / RAND_MAX;  /* rand()は~RAND_MAXの範囲で出力する関数で、xを正規化している */
        y = (double)rand() / RAND_MAX;

        z = (x * x) + (y * y);

        if (z < 1){
            count++;       // 円内にあればカウント 
        }

        // 途中結果の表示
        if ((i + 1) % 1000 == 0){
            pi = (double)count / (i + 1) * 4.0;
            printf("%6d回 | %.6f\n", i + 1, pi);
        }
    }

    printf("--------------------------------\n");

    // 最終的な円周率の近似
    pi = (double)count / MAX * 4.0;
    printf("最終結果: %.6f\n", pi);
    return 0;

}