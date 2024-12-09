#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main()
{
    char paper[40][70];
    int i,j;        //遍历数组的变量i为横j为竖
    srand(time(0));
    int a = rand();
    int b = rand();
    a= (a% 51) + 10;
    b = (b % 51) + 10;              //a,b为球初始点的坐标,随机生成
    int x = 0;
    int y = 0;          //x为左边挡板的纵坐标值，y为右边挡板的纵坐标值

    while(1){
        for (j = 0; j < 40; j++){
            for (i = 0; i < 70; i++){
                paper[j][i] = ' ';
            }
            paper[j][69] = '\0'; // 确保每行都是一个正确的字符串
        }

        for (i = x; i < x + 10; i++){
            paper[i][0] = '|';
        }
        for (i = y; i < y + 10; i++){
            paper[i][69] = '|';
        }
        paper[a][b] = '*';

        system("cls"); // 清屏
        printf("----------------------------------------------------------------------\n");
        for (j = 0; j < 70; j++)
        {
            printf("%s\n", paper[j]);
        }
        printf("----------------------------------------------------------------------\n");

        int ch = _getch();
        switch (ch)
        {
        case 'W':
        case 'w':
            if (x > 0)
                x--;
            break;
        case 'S':
        case 's':
            if(x<30)
                x++;
            break;
        case 72:
            if (y > 0)
                y--;
            break;
        case 80:
            if (y < 30)
                y++;
            break; // 监听按键，W和S控制左边，小键盘方向键控制右边
        }
    Sleep(100);
    }
    return 0;
}