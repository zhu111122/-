#include <stdio.h>
void main()
{
    //进制转换函数的声明
    int transfer(int x);
    int x;
    printf("请输入一个十进制数:");
    scanf("%d",&x);
    printf("转换成二进制数是:%d\n",transfer(x));
}
int transfer(int x)
{
    int p=1,y=0,yushu;
    while(1)
    {
        yushu=x%2;
        x/=2;
        y+=yushu*p;
        p*=10;
        if(x<2)
        {
            y+=x*p;
            break;
        }
    }
    return y;
}
