#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // 試行回数（必要に応じて変更してください）
    const int N = 10000;
    
    int i;
    int count_in = 0;   // 円の中に入った回数
    double x, y;        // 点の座標
    double pi_approx;   // 円周率の近似値

    // 乱数の種（シード）を現在時刻で初期化
    // これをしないと毎回同じ結果になってしまいます
    srand((unsigned int)time(NULL));

    printf("モンテカルロ法による円周率計算を開始します（試行回数: %d）\n", N);
    printf("----------------------------------------\n");
    printf(" 試行回数 |  円周率の近似値\n");
    printf("----------------------------------------\n");

    for (i = 1; i <= N; i++) {
        // 0.0 以上 1.0 以下の乱数を生成
        // rand() は 0～RAND_MAX の整数を返すので、RAND_MAXで割って正規化します
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        // 原点からの距離の2乗が1以下なら、円の内側
        if (x * x + y * y <= 1.0) {
            count_in++;
        }

        // 途中経過を表示 (例: 1000回ごとに表示)
        // ここが「途中経過も分かるように」のポイントです
        if (i % 1000 == 0) {
            pi_approx = (double)count_in / i * 4.0;
            printf(" %6d回 |  %.6f\n", i, pi_approx);
        }
    }

    printf("----------------------------------------\n");
    
    // 最終結果の計算
    pi_approx = (double)count_in / N * 4.0;
    printf("最終結果: %.6f\n", pi_approx);

    return 0;
}