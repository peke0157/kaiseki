#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265

// 正規乱数を生成する関数
double generate_normal_standard(){
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    if (u1 < 1e-9) u1 = 1e-9;
    return sqrt(-2.0 * log(u1)) *cos(2.0 * PI * u2);
}

int main(void){
    srand((unsigned int)time(NULL));

    int hp_1 = 6, hp_2 = 50;       // はぐれメタルのHP(hp_1)、あなたのHP(hp_2)
    int turn = 1;
    int p_damage = 0, m_damage = 0;
    double p_attack_roll, m_attack_roll;
    double run_prob;

    printf("はぐれメタルが現れた!!!");

    while (hp_1 > 0 && hp_2 > 0)
    {
        int command = 0;
        /* ターン事にダメージをリセット*/
        m_damage = 0;
        p_damage = 0;

        printf("--- 第%dターン ---\n", turn);
        printf("あなたのHP: %d\n", hp_2);

        while (command != 1 && command != 2){
            printf("どうする? 1:戦う 2:逃げる");
            scanf("%d", &command);
            printf("\n");

            // もし間違えたら警告する
            if (command != 1 && command != 2){
                printf("コマンドが間違えています\n");
            }

        }

        if (command == 1){
            printf("勇者は剣を構えた\n");

            // 敵が逃げるかの判定（一様乱数）
            run_prob = (double)rand() / RAND_MAX;
        
            if (run_prob < 0.2){
                printf("はぐれメタルは逃げ出した!!!!\n");
                return 0;
            }
            else {
                m_attack_roll = generate_normal_standard();
    
                if (m_attack_roll > 1.75){
                    m_damage = 10;
                    printf("「痛恨の一撃!!!」\n");
                    printf("あなたは%dのダメージを受けた!!!!\n", m_damage);
                }
            
                else if (m_attack_roll < -0.5){
                    m_damage = 7;
                    printf("はぐれメタルはギラを唱えた\n");
                    printf("あなたは%dのダメージを受けた\n", m_damage);
                }
            
                else {
                    m_damage = 5;
                    printf("はぐれメタルの攻撃\n");
                    printf("あなたは%dのダメージを受けた\n", m_damage);
                }
            }


            printf("あなたの攻撃!!!\n");
        
            p_attack_roll = generate_normal_standard();
        
            if (p_attack_roll > 1.5){
                p_damage = 10;
                printf("「会心の一撃!!!」\n");
                printf("はぐれメタルに%dのダメージ!!!!\n", p_damage);
            }
        
            else if (p_attack_roll < -1.0){
                p_damage = 0;
                printf("ミス！ はぐれメタルは攻撃をかわした\n");
            }
        
            else {
                p_damage = 1;
                printf("はぐれメタルに%dのダメージ\n", p_damage);
            }

        }

        else if (command == 2){
            printf("勇者は逃げ出した\n");
            printf("しかし回り込まれてしまった\n");

            // 敵が逃げるかの判定（一様乱数）
            run_prob = (double)rand() / RAND_MAX;
        
            if (run_prob < 0.2){
                printf("はぐれメタルは逃げ出した!!!!\n");
                return 0;
            }
        }
    
        hp_1 = hp_1 - p_damage;
        hp_2 = hp_2 - m_damage;
    
        if (hp_1 < 0) hp_1 = 0;
        if (hp_2 < 0) hp_2 = 0;
        turn++;
    }
    printf("------------------------------------------------------\n");

    if (hp_2 == 0){
        printf("あなたは力尽きた...........\n");
        printf("Game Over\n");
    }
    else if (hp_1 == 0){
        printf("はぐれメタルを倒した!\n");
        printf("経験値 10500 を手に入れた!!!\n");
        printf("クエストクリア!!!!\n");
    }
    return 0;
    }
    