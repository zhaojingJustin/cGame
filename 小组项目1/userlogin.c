//
//  userlogin.c
//  game
//
//  Created by 中软mini003 on 15/8/12.
//  Copyright (c) 2015年 中软mini003. All rights reserved.
//

#include "userlogin.h"
#include <time.h>
#include <stdlib.h>
#define N 4
//定义3个初始用户"
struct users userArr[]={{1111,"aaaa",0,500},{2222,"bbbb",100,1000},{3333,"cccc",10,0}};
int q=0;
void userMenu()
{
    char a;          //选择控制变量!
    printf("\t\t\t\t\t\t\t\t\t欢迎使用一点都不好玩游戏合集v1.0版");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t1:个人信息查询\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t2:游戏入口\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t3:积分排行\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t4:积分商城\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t5:退出\n");
    
    do{
        printf("请输入数字:输入5返回上级菜单\n");
        scanf("%s",&a);
        if ((a<49||a>53)) {
            printf("输入数据非法！请重新输入。\n");
        }
    }while (a<49||a>53);
    switch (a) {
        case '1':pcShow();break;
        case '2':inGame();break;
        case '3':scList();break;
        case '4':scoerUse();break;
        case '5':main();break;
    }
}
//游戏菜单
void inGame()
{
    printf("\t\t\t\t\t\t\t\t\t欢迎使用一点都不好玩游戏合集v1.0版");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t1:猜数字v1.0\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t2:猜拳游戏\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t3:幸运777\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t4:猜数字v2.0\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t5:21点\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t6:退出\n");
    printf("请选择,输入6返回上一级\n");
    char e;
    do{
        scanf("%s",&e);
        //                getchar();
        if(e<'1' || e>'6'){
            printf("输入数据非法！请重新输入。\n");
        }
    }while (e<'1' || e>'6');
    switch (e) {
        case '1':welcome();break;
        case '2':caiQuan();break;
        case '3':login();break;
        case '4':guess();break;
        case '5':twentyone();break;
        case '6':userMenu();break;
    }
    
    
}
//猜拳游戏随机数产生
long random2()
{
    int num;
    srand((unsigned)time(NULL));
    num=rand()%3;
    return num;
}

//猜拳游戏
void caiQuan()
{
    printf("\t\t\t\t\t\t\t\t\t欢迎进入猜拳游戏v1.0版");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    
    int flag=0; //判断能进入游戏
    int userIndex = -1;
    //通过这个循环得到合法的会员号
    do{
        //这个循环验证会员号是否可用
        printf("请输入会员号");
        int id;             //定义输入的会员号
        scanf("%d",&id);
        printf("\n请输入密码");
        char password[9];       //定义输入的密码
        scanf("%s",password);
        
        //验证用户名密码是否合法
        for (int i=0; i<LENGTH; i++)
        {
            if (userArr[i].usersid==id&&strcmp(userArr[i].userspassword,password)==0)
            {
                flag=1;         //修改标志位
                userIndex = i;  //保存当前用户索引
                break;
            }
        }
        if (!flag) {
            printf("\n会员帐户或密码错误，请重新输入！\n");
        }
        
    }while(!flag);
    
    //合法时进入游戏
    //先判断用户帐户余额
    if (userArr[userIndex].money<5)
    {
        printf("会员余额不足,请找管理员充值\n");
        //函数调用结束
        return;
    }else{
        //进入到游戏
        char e = 'n';     //继续变量
        do{
            //进入游戏先减5元
            userArr[userIndex].money=userArr[userIndex].money-5;
            
            //显示游戏界面
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t1:石头");
            putchar('\n');
            printf("\t\t\t\t\t\t\t\t\t\t\t2:剪刀");
            putchar('\n');
            printf("\t\t\t\t\t\t\t\t\t\t\t3:布");
            putchar('\n');
            printf("\t\t\t\t\t\t\t\t\t\t\t4:退出游戏");
            putchar('\n');
            printf("请做出你的选择:");
            
            int u;      //用户选择
            do{
                scanf("%d",&u);
                //                getchar();
                if(u<1 || u>4){
                    printf("输入数据非法！请重❤️输入。\n");
                }
            }while (u<1 || u>4);
            
            //显示你出的是什么
            if (u==1)
            {
                printf("你出的是石头!\n");
            }else if(u==2)
            {
                printf("你出的是剪刀!\n");
            }else if (u==3) {
                printf("你出的是布!\n");
            }else if(u==4)//4:退出游戏
            {
                inGame();
            }
            
            //电脑选择
            long a;             //电脑产生的随机数
            a=random2();         //电脑产生的随机数
            //输出电脑出的数字
            if (a==1) {
                printf("电脑出的是石头!");
            }if (a==2)
            {
                printf("电脑出的是剪刀!");
            }if (a==0)
            {
                printf("电脑出的是布!");
            }
            //这个判断显示游戏结果
            switch (u-a)
            {
                case -1:
                case 2:
                    printf("\t\t你赢了!获得50积分!\n");
                    userArr[userIndex].sc+=50;
                    break;
                case 1:
                case -2:
                    printf("\t\t你输了!请再接再厉!\n");
                    userArr[userIndex].sc-=50;
                    break;
                case 0:
                case 3:
                    printf("\t\t真巧,平了!\n");
                    userArr[userIndex].sc+=20;
                    break;
                default:
                    printf("请重新输入:");
                    break;
                    
            }
            
            //让用户选择是否继续
            printf("是否继续?继续请输入y\n");
            scanf("%s",&e);
            getchar();
            
        }while(e=='y'||e=='Y');
    }
    
}
void scoerUse()
{
    printf("\t\t\t\t\t\t\t\t\t会员积分兑奖");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t1:积分兑换");
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t2:积分抽奖");
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t3:退出");
    putchar('\n');
    char e;
    do{
        scanf("%s",&e);
        //                getchar();
        if(e<'1' || e>'3'){
            printf("输入数据非法！请重新输入。\n");
        }
    }while (e<'1' || e>'3');
    switch (e) {
        case '1':soChange();break;
        case '2':soGoods();break;
        case '3':userMenu();break;
    }
}
void soChange()
{
    int id;
    char word[9];
    int sc;
    printf("\t\t\t\t\t\t\t\t\t积分兑换\n");
    int flag=0; //判断能进入
    int userIndex = -1;
    //通过这个循环得到合法的会员号
    do{
        printf("\t\t\t\t请输入会员号:");
        scanf("%d",&id);
        printf("\t\t\t\t请输入密码:");
        scanf("%s",word);
        
        //验证用户名密码是否合法
        for (int i=0; i<LENGTH; i++)
        {
            if (userArr[i].usersid==id&&strcmp(userArr[i].userspassword, word)==0)
            {
                flag=1;         //修改标志位
                userIndex = i;  //保存当前用户索引
                break;
            }
        }
        if (!flag) {
            printf("\n管理员帐户或密码错误，请重新输入！\n");
        }
        
    }while(!flag);
    printf("\n\t\t请输入需要兑换的积分(10的倍数):(10分->1元)");
    scanf("%d",&sc);
    //判断输入积分是否大于会员积分;
    if (sc>userArr[userIndex].sc)
    {
        printf("会员积分不足");
        soChange();
    }else
    {   //判断输入积分是否为10的倍数
        if (sc%10!=0) {
            printf("\t\t\t\t请输入10的倍数:");
            soChange();
        }
        else
        {
            userArr[userIndex].sc=userArr[userIndex].sc-sc;
            int mo;     //积分兑换中介
            mo=sc/10;
            userArr[userIndex].money=userArr[userIndex].money+mo;
            printf("\t\t\t\t\n会员积分兑换成功!\n");
            scoerUse();
        }
    }
}
long random()
{
    int num;
    srand((unsigned)time(NULL));
    num=rand()%100;
    return num;
}
void soGoods()
{
    int id;
    char word[9];
    long a;
    int k;
    printf("\t\t\t\t\t\t\t\t\t积分抽奖\n");
    int flag=0; //判断能进入
    int userIndex = -1;
    //通过这个循环得到合法的会员号
    do{
        //这个循环验证管理员号是否可用
        printf("\t\t\t\t请输入会员号:");
        scanf("%d",&id);
        printf("\t\t\t\t请输入密码:");
        scanf("%s",word);
        
        
        //验证用户名密码是否合法
        for (int i=0; i<LENGTH; i++)
        {
            if (userArr[i].usersid==id&&strcmp(userArr[i].userspassword, word)==0)
            {
                flag=1;         //修改标志位
                userIndex = i;  //保存当前用户索引
                break;
            }
        }
        if (!flag) {
            printf("\n管理员帐户或密码错误，请重新输入！\n");
        }
        
    }while(!flag);
    if (userArr[userIndex].sc-50>=0)
    {
        
        printf("是否开始(y/n)输入n返回上一层\n");
        char o;
        scanf("%s",&o);
        switch (o) {
            case 'y':
                a=random();
                userArr[userIndex].sc=userArr[userIndex].sc-50;
                k=userIndex;
                printf("抽奖号码为:%ld\n",a);
                switch (a) {
                    case 1:
                    case 11:
                    case 0:
                        printf("幸运客户获赠500积分!\n");
                        userArr[k].sc=userArr[k].sc+500;
                        soGoods();
                        break;
                    case 3:
                    case 9:
                    case 15:
                    case 97:
                    case 64:
                        printf("幸运客户获赠100积分!\n");soGoods();
                        userArr[k].sc=userArr[k].sc+100;
                        break;
                    case 5:
                    case 10:
                    case 35:
                    case 65:
                    case 77:
                    case 32:
                    case 23:
                    case 66:
                    case 87:
                    case 63:
                        printf("幸运客户获赠50积分!\n");
                        userArr[k].sc=userArr[k].sc+50;
                        soGoods();
                        break;
                        
                    default:printf("您没有中奖");
                        soGoods();
                        break;
                }
            case 'n':scoerUse();
                
        }
    }if (userArr[userIndex].sc<50) {
        printf("积分不足，请充值或进行游戏！\n");
        scoerUse();
    }
}
//冒泡函数
void swap(struct users *x,struct users *y)
{
    struct users temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//冒泡排序查看积分，从大到小
void scList()
{
    printf("用户名\t\t用户积分\n");
    int m=0;
    for (int i = 0; i<20; i++)
    {
        if (userArr[i].usersid==0)
        {
            m=i-1;
            break;
        }
    }
    for (int i=0; i<=m; i++)
    {
        for (int j=i+1; j<=m;j++ )
        {
            if(userArr[i].sc<userArr[j].sc)
                swap(&userArr[i], &userArr[j]);
        }
    }
    for (int i=0; i<=m; i++) {
        
        printf("%5d\t\t%5d\n",userArr[i].usersid,userArr[i].sc);
    }
    printf("输入n返回上级菜单\n");
    char e;
    do{
        scanf("%s",&e);
        if(e!='n'){
            printf("输入数据非法！请重新输入。\n");
        }
    }while (e!='n');
    switch (e) {
        case 'n':userMenu();break;
    }
}
void guess()
{
    printf("\t\t\t\t\t\t\t\t\t欢迎进入猜数字游戏v2.0版");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    
    int flag=0; //判断能进入游戏
    int userIndex = -1;
    //通过这个循环得到合法的会员号
    do{
        //这个循环验证会员号是否可用
        printf("请输入会员号");
        int id;             //定义输入的会员号
        scanf("%d",&id);
        printf("\n请输入密码");
        char password[9];       //定义输入的密码
        scanf("%s",password);
        
        //验证用户名密码是否合法
        for (int i=0; i<LENGTH; i++)
        {
            if (userArr[i].usersid==id&&strcmp(userArr[i].userspassword,password)==0)
            {
                flag=1;         //修改标志位
                userIndex = i;  //保存当前用户索引
                break;
            }
        }
        if (!flag) {
            printf("\n会员帐户或密码错误，请重新输入！\n");
        }
        
    }while(!flag);
    
    //合法时进入游戏
    //先判断用户帐户余额
    if (userArr[userIndex].money<5)
    {
        printf("会员余额不足,请找管理员充值\n");
        //函数调用结束
        return;
    }else{
        //进入到游戏
        char e = 'n';     //继续变量
        do{
            //进入游戏先减5元
            userArr[userIndex].money=userArr[userIndex].money-5;
            
            //显示游戏界面
            printf("\n                       猜数字小游戏v2.0             \n");
            for (int i=0; i<99; i++)
            {
                putchar('*');
            }
            printf("\n\t\t\t\t\t\t\t1.游戏规则🎮       \n");
            printf("\n\t\t\t\t\t\t\t2.开始游戏       \n");
            printf("\n\t\t\t\t\t\t\t3.退出       \n");
            for (int i=0; i<99; i++)
            {
                putchar('*');
            }
            printf("请做出你的选择:");
            
            int u;      //用户选择
            do{
                scanf("%d",&u);
                //                getchar();
                if(u<1 || u>3){
                    printf("输入数据非法！请重新输入。\n");
                }
            }while (u<1 || u>3);
            
            //显示你出的是什么
            if (u==1)
            {
                printf("\n\n*********************************猜数字游戏规则*********************************\n\n本游戏是您与电脑各出一四位数均不重复之数字（第一个数字不为0），游戏开始时，由您先猜电脑所出之题目为何数，电脑会告知您所猜测之数字与电脑之题目是否相同，若不相同，电脑以A，B标示来提示您，例如：\n\n电脑的题目：1 2 3 4\n\n您猜的数字：5 2 8 3 结果为：1 A 1 B\n\n表示您共猜对了两位数，其中有一个字位置对，另一个字位置不对，此例中，您猜对了2及3，但是3的位置猜错了，故电脑给的提示为1A1B，其中，1A表示猜对一個字且位置也对，1B表示猜对一个字但是位置不对。\n\n另例：\n\n电脑的题目：1 2 3 4\n\n您猜的数字：3 2 6 1 结果为：1 A 2 B\n\n电脑的题目：1 2 3 4\n\n您猜的数字：8 7 6 5 结果为：0 A 0 B\n\n\n*********************************开始猜数字游戏*********************************\n生成数据有一定延时，请耐心等待……\n\n");//规则
                printf("按任意键返回主菜单");
                getchar();
                break;
                
            }else if(u==2)
            {
                printf("随机数已产生，输入的数字用空格隔开\n");
                play(userIndex);
                
            }else if (u==3) {
                
                inGame();
            }
            
            //让用户选择是否继续
            printf("是否继续?继续请输入y\n");
            scanf("%s",&e);
            getchar();
            
        }while(e=='y'||e=='Y');
    }
    
    
}
void play(int n)
{
    int a,b,i,j,k=0,flag1,arr1[N],arr2[N];
    do
    {
        
        
        flag1=0;
        srand((unsigned)time(NULL));//产生四个互不相同的随机数且第一位不为零
        for(i=0;i<N;i++)
            arr1[i]=rand()%10;
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
                if(arr1[i]==arr1[j]||arr1[0]==0)
                {
                    flag1=1;
                    break;
                }
        }
    }while(flag1==1);
    do
    {
        char c;
        int flag2=0;
        k++;
        a=b=0;
        if (k==5||k==10||k==15)//中途看答案的提示
        {
            printf("要不要看看答案，^_^（y/n）");
            getchar();
            scanf("%c",&c);
            switch (c)
            {
                case 'y'://输出答案
                    flag2=1;
                    for (int i=0; i<N; i++)
                    {
                        printf("%d ",arr1[i]);
                    }
                    break;
                case 'n'://继续游戏
                    break;
                default:
                    break;
            }
            
        }
        
        printf("猜猜看：");//用户输入的数字与答案比较
        for(i=0;i<N;i++)
            scanf("%d",&arr2[i]);
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
            {
                if(arr1[i]==arr2[i])
                {
                    a++;
                    break;
                }
                if(arr1[i]==arr2[j]&&i!=j)
                {
                    b++;
                    break;
                }
            }
        printf("提示：%d A %d B\n\n",a,b);
        if(a==4)                    //根据猜数字所用次数输出评语
        {
            if(flag2==0)
            {
                printf("\n\n*********************************猜数字游戏评语*********************************\n\n");
                if(k==1)
                {
                    printf(" 哇哦！火星撞地球的几率！\n\n");
                    printf("恭喜你得五百分～");
                    userArr[n].sc+=500;         //对应加上所得积分
                    break;
                }
                else if(k<=5)
                {
                    printf(" 666！我对你佩服的真是五体投地！\n\n");
                    printf("恭喜你得一百分～");
                    userArr[n].sc+=100;
                    break;
                }
                else if(k<=10)
                {
                    printf("  不错不错，多玩几次，你一定会成为高手\n\n");
                    printf("恭喜你得五十分～");
                    userArr[n].sc+=50;
                    break;
                }
                else if(k<=15)
                {
                    printf(" 多动动脑再猜！你会找到正确的方法的！\n\n");
                    printf("恭喜你得三十分～");
                    userArr[n].sc+=30;
                    break;
                }
                else
                {
                    printf(" →_→ ！你确定你认识阿拉伯数字吗！\n\n");
                    printf("恭喜你得二十分～");
                    userArr[n].sc+=20;
                    break;
                }
                break;
            }
            else
            {
                printf("恭喜你得十分～");
                printf("试试下次不看答案会不会猜对\n");
                userArr[n].sc+=10;
                //printf("%d",userArr[n].sc);
                break;
            }
        }
        
    }while(1);
    
    
}
void twentyone()
{
    printf("\t\t\t\t\t\t\t\t\t欢迎进入21点游戏");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    
    int flag=0; //判断能进入游戏
    int userIndex = -1;
    //通过这个循环得到合法的会员号
    do{
        //这个循环验证会员号是否可用
        printf("请输入会员号");
        int id;             //定义输入的会员号
        scanf("%d",&id);
        printf("\n请输入密码");
        char password[9];       //定义输入的密码
        scanf("%s",password);
        
        //验证用户名密码是否合法
        for (int i=0; i<LENGTH; i++)
        {
            if (userArr[i].usersid==id&&strcmp(userArr[i].userspassword,password)==0)
            {
                flag=1;         //修改标志位
                userIndex = i;  //保存当前用户索引
                break;
            }
        }
        if (!flag) {
            printf("\n会员帐户或密码错误，请重新输入！\n");
        }
        
    }while(!flag);
    
    //合法时进入游戏
    //先判断用户帐户余额
    if (userArr[userIndex].money<5)
    {
        printf("会员余额不足,请找管理员充值\n");
        //函数调用结束
        return;
    }else{
        //进入到游戏
        char e = 'n';     //继续变量
        do{
            //进入游戏先减5元
            userArr[userIndex].money=userArr[userIndex].money-5;
            
            //显示游戏界面
            printf("\n                       21点小游戏v2.0             \n");
            for (int i=0; i<99; i++)
            {
                putchar('*');
            }
            printf("\n\t\t\t\t\t\t\t1.游戏规则🎮       \n");
            printf("\n\t\t\t\t\t\t\t2.开始游戏       \n");
            printf("\n\t\t\t\t\t\t\t3.退出       \n");
            for (int i=0; i<99; i++)
            {
                putchar('*');
            }
            printf("请做出你的选择:");
            
            int u;      //用户选择
            do{
                scanf("%d",&u);
                //                getchar();
                if(u<1 || u>3){
                    printf("输入数据非法！请重❤️输入。\n");
                }
            }while (u<1 || u>3);
            
            //显示你出的是什么
            if (u==1)
            {
                printf("\n\n*********************************21点游戏规则*********************************\n\n本游戏是您根据所得随机数来判断还要不要继续加牌，若您和电脑最后所得数字之和都不超过21点，则越接近21点者赢得游戏；若有一方超过则另一方胜利；若都超过或点数相同，则为平局\n\n\n*********************************开始21点游戏*********************************\n生成数据有一定延时，请耐心等待……\n\n");//规则
                printf("按任意键返回主菜单");
                getchar();
                break;
                
            }else if(u==2)
            {
                
                play(userIndex);
                
            }else if (u==3) {
                
                inGame();
            }
            
            //让用户选择是否继续
            printf("是否继续?继续请输入y\n");
            scanf("%s",&e);
            getchar();
            
        }while(e=='y'||e=='Y');
    }
    
    
}
void play1(int n)
{
    int b=0,j=1,computer=0,sum=0,x,y,z,arr1[25]={};
    int i=0;
    char a;
    if (userArr[n].money>=5) {
        userArr[n].money-=5;
        
    }
    else
    {
        printf("余额不足请充值～");
        q=1;
        return;
    }
    if (userArr[n].sc<=0) {
        printf("积分不足请尝试其他游戏获得积分～");
        q=1;
        return;
    }
    srand((unsigned)time(NULL));
    do{
        
        
        printf("随机数已产生，是否开始累加(y/n)\n");
        getchar();
        scanf("%c",&a);
        switch (a) {
            case 'y':
                
                arr1[b]=rand()%10;
                printf("%d\n",arr1[b]);
                for (i=0; i<=b; i++)
                {
                    sum=sum+arr1[i]-arr1[i-1];
                }
                printf("当前您的点数为%d\n",sum+i);
                if (sum+i>21)
                {
                    printf("点数爆了，您输了，电脑赢了");
                    return;
                }
                else
                {
                    b++;
                    break;
                }
            case 'n':
                j=0;
                break;
            default:
                break;
        }
    }while(j);
    
    x=rand()%10;
    y=rand()%10;
    z=rand()%10;
    computer=x+y+z;
    if (sum+i<=21&&computer<=21)
    {
        if (sum+i<computer)
        {
            printf("您输了，电脑赢了");
            userArr[n].sc-=100;
        }
        else if(sum+i>computer)
        {
            printf("您赢了，电脑输了");
            userArr[n].sc+=80;
        }
        else
        {
            printf("您与电脑打成平局");
            userArr[n].sc+=20;
        }
        
    }else if(computer>21)
    {
        printf("电脑点数爆了，你赢了");
        userArr[n].sc+=50;
    }
    
    printf("您的点数为%d\n",sum+i);
    
    printf("电脑的点数为%d,%d,%d,共%d点\n",x,y,z,computer);
    
    
}
//登录
void login()
{
    //定义会员号
    int usersid1;
    //定义用户密码
    char userspassword1[LENGTH];
    int i;
    printf("请输入会员号：");
    scanf("%d",&usersid1);
    printf("请输入会员密码：");
    scanf("%s",userspassword1);
    //输入三次
    for(i=0;i<=2;i++)
    {
        //登录初始化数组中任意一位
        for(int j=0;j<=LENGTH;j++)
        {
            //判断账号和密码是否相等
            if(userArr[j].usersid==usersid1&&strcmp(userArr[j].userspassword,userspassword1)==0)
            {
                printf("🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 🍒 \n");
                printf("恭喜登陆成功，欢迎来到幸运7⃣️7⃣️7⃣️环节，这里会有惊喜呦－.－!\n");
                //进入积分奖励
                reward(j);
                return;
            }
            
        }
        printf("请重新输入会员号：");
        scanf("%d",&usersid1);
        printf("请重新输入会员密码：");
        scanf("%s",userspassword1);
        
    }
    printf("您的输入已经超过三次，自动退出程序，欢迎下次的参与。");
}


//积分奖励
void reward(int i)
{
    srand((unsigned int)time(NULL));
    char j;
    long a1,a2,a3;
    
    
    //判断用户的余额是否大于等于5
    if(userArr[i].money>=5)
    {
        a1=rand() % 8;
        a2=rand() % 8;
        a3=rand() % 8;
        printf("三个数字分别为%ld\t%ld\t%ld\n",a1,a2,a3);
        //判断三个随机数对7取余是否相等
        if(a1==a2&&a2==a3)
        {
            //判断三个随机数对7取余是否都等于7
            if(a3==7)
            {
                printf("哇哦！您获得的幸运数字是7⃣️7⃣️7⃣️，恭喜您获得我们的最高积分500分，真是匪夷所思，您真厉害...\n");
                userArr[i].sc=userArr[i].sc+500;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            
            //判断三个随机数对7取余是否都等于6
            if(a3==6)
            {
                printf("哇哦！您获得的幸运数字是6⃣️6⃣️6⃣️，恭喜您获得了400积分，真是匪夷所思，还差一步你就是幸运之王了耶⛽️！\n");
                userArr[i].sc=userArr[i].sc+400;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            //判断三个随机数对7取余是否等于5
            else if(a3==5)
            {
                printf("哇哦！您获得的幸运数字是5⃣️5⃣️5⃣️，恭喜您获得300积分，您真的很幸运，棒棒的呦...\n");
                userArr[i].sc=userArr[i].sc+300;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            //判断三个随机数对7取余是否等于4
            else if(a3==4)
            {
                printf("哇哦！您获得的幸运数字是4⃣️4⃣️4⃣️恭喜您获得200积分，很不错呦...\n");
                userArr[i].sc=userArr[i].sc+200;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //判断三个随机数对7取余是否等于3
            else if(a3==3)
            {
                printf("哇哦！您获得的幸运数字是3⃣️3⃣️3⃣️，恭喜您获得100积分，棒棒的哒...\n");
                userArr[i].sc=userArr[i].sc+100;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            
            //判断三个随机数对7取余是否等于2
            else if(a3==2)
            {
                
                printf("哇哦！您获得的幸运数字是2⃣️2⃣️2⃣️，恭喜您获得50积分，继续再接再厉，❤️-.-\n");
                userArr[i].sc=userArr[i].sc+50;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            
            //判断三个随机数对7取余是否等于1
            else if(a3==1)
            {
                printf("哇哦！您获得的幸运数字是1⃣️1⃣️1⃣️，恭喜您获得50积分，相信您还可以得到更高的分数，不要气馁呦...");
                userArr[i].sc=userArr[i].sc+50;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            //判断三个随机数对7取余是否等于0
            else
            {
                printf("哇哦！您获得的幸运数字是0⃣️0⃣️0⃣️，恭喜您获得400积分，继续加油。。。\n");
                userArr[i].sc=userArr[i].sc+400;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            userArr[i].money=userArr[i].money-5;
            printf("您的余额为%d\n",userArr[i].money);
            printf("是否(y/n)要继续游戏呢?下一次可能会有大大的惊喜呦-.-:");getchar();
            scanf("%c",&j);
            switch(j)
            {
                    //继续游戏
                    //进入积分奖励
                case 'y':
                    reward(i);
                    return;
                    //不继续游戏
                    //跳转到登陆页面
                case 'n':
                    inGame();
                    return;
                    
            }
            
            
        }
        
        //判断三个数中有两个相同
        if ((a1==a2)||(a1==a3)||(a2==a3))
        {
            //判断三个数中有两个数为7
            if ((a1==a2&&a2==7)||(a1==a3&&a3==7)||(a2==a3&&a3==7))
            {
                printf("哇哦！您获得的幸运数字中含有2个7⃣️，恭喜您获得50积分，再来一局，相信你可以的！\n");
                userArr[i].sc=userArr[i].sc+50;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //判断三个数中有两个数为6
            else if ((a1==a2&&a2==6)||(a1==a3&&a3==6)||(a2==a3&&a3==6))
            {
                printf("哇哦！您获得的幸运数字中含有2个6⃣️，恭喜您获得40分，真是匪夷所思，您真厉害...\n");
                userArr[i].sc=userArr[i].sc+40;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            //判断三个数中有两个数为5
            else if ((a1==a2&&a2==5)||(a1==a3&&a3==5)||(a2==a3&&a3==5))
            {
                printf("哇哦！您获得的幸运数字中含有2个5⃣️，恭喜您获得30积分，您真的很幸运，棒棒的呦...\n");
                userArr[i].sc=userArr[i].sc+30;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //判断三个数中有两个数为4
            else if ((a1==a2&&a2==4)||(a1==a3&&a3==4)||(a2==a3&&a3==4))
            {
                printf("哇哦！您获得的幸运数字中含有2个4⃣️恭喜您获得30积分，很不错呦...\n");
                userArr[i].sc=userArr[i].sc+30;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //判断三个数中有两个数为3
            else if ((a1==a2&&a2==3)||(a1==a3&&a3==3)||(a2==a3&&a3==3))
            {
                printf("哇哦！您获得的幸运数字中含有2个3⃣️，恭喜您获得30积分，棒棒的哒...\n");
                userArr[i].sc=userArr[i].sc+30;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
                
            }
            //判断三个数中有两个数为2
            else if ((a1==a2&&a2==2)||(a1==a3&&a3==2)||(a2==a3&&a3==2))
            {
                printf("哇哦！您获得的幸运数字中含有2个2⃣️，恭喜您获得20积分，继续再接再厉，❤️-.-\n");
                userArr[i].sc=userArr[i].sc+20;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //判断三个数中有两个数为1
            else if ((a1==a2&&a2==1)||(a1==a3&&a3==1)||(a2==a3&&a3==1))
            {
                printf("哇哦！您获得的幸运数字中含有2个1⃣️，恭喜您获得10积分，相信您还可以得到更高的分数...");
                userArr[i].sc=userArr[i].sc+10;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //判断三个数中有两个数为0
            else if ((a1==a2&&a2==0)||(a1==a3&&a3==0)||(a2==a3&&a3==0))
            {
                printf("哇哦！您获得的幸运数字中含有2个0⃣️，恭喜您获得20积分，距离最高积分只有一步之遥了哦...\n");
                userArr[i].sc=userArr[i].sc+20;
                printf("您目前的积分是%d，好棒哦！\n",userArr[i].sc);
            }
            //每玩一次花费5元钱
            userArr[i].money=userArr[i].money-5;
            printf("您的余额为%d\n",userArr[i].money);
            printf("是否(y/n)要继续游戏呢?下一次可能会有大大的惊喜呦-.-:");getchar();
            scanf("%c",&j);
            switch(j)
            {
                    //继续游戏
                    //进入积分奖励
                case 'y':
                    reward(i);
                    return;
                    //不继续游戏
                    //跳转到登陆页面
                case 'n':
                    inGame();
                    return;
                    
            }
            
        }
        
        else
        {
            printf("🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹 🌹\n");
            printf("产生的3个数不相等！\n");
            userArr[i].money=userArr[i].money-5;
            printf("您的余额为%d\n",userArr[i].money);
            printf("是否(y/n)要继续游戏呢?下一次可能会有大大的惊喜呦-.-:");getchar();
            scanf("%c",&j);
            switch(j)
            {
                    //继续游戏
                    //进入积分奖励
                case 'y':
                    reward(i);
                    return;
                    //不继续游戏
                    //跳转到登陆页面
                case 'n':
                    inGame();
                    return;
                    
            }
            
        }
        
    }
    
    else
        printf("您的余额已不足，请找管理员充值，谢谢-.-\n");
    inGame();
}
//个人信息显示界面
void pcShow()
{
    
    printf("\t\t\t\t\t\t\t个人信息显示!");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    putchar('\n');
    int flag=0; //判断能进入
    int userIndex = -1;
    //通过这个循环得到合法的会员号
    do{
        //这个循环验证会员号是否可用
        printf("请输入会员号");
        int id;             //定义输入的会员号
        scanf("%d",&id);
        printf("\n请输入密码");
        char password[9];       //定义输入的密码
        scanf("%s",password);
        
        //验证用户名密码是否合法
        for (int i=0; i<LENGTH; i++)
        {
            if (userArr[i].usersid==id&&strcmp(userArr[i].userspassword,password)==0)
            {
                flag=1;         //修改标志位
                userIndex = i;  //保存当前用户索引
                break;
            }
        }
        if (!flag) {
            printf("\n会员帐户或密码错误，请重新输入！\n");
        }
        
    }while(!flag);
    printf("用户名\t\t用户余额\t\t用户积分\n");
    printf("%5d\t\t%5d\t\t%5d\n",userArr[userIndex].usersid,userArr[userIndex].money,userArr[userIndex].sc);
    printf("\t\t\t\t\t输入n返回上一层菜单\n");
    
    char e;
    do{
        scanf("%s",&e);
        if(e!='n'){
            printf("输入数据非法！请重新输入。\n");
        }
    }while (e!='n');
    switch (e)
    {
        case 'n':userMenu();
            
    }
}

//欢迎界面
void welcome()
{
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    printf("\n");
    printf("\t\t🍀🍀🍀欢迎来玩猜数字小游戏🍀🍀🍀\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t  1、游戏规则 👙\n");
    printf("\n");
    printf("\t\t\t  2、登陆游戏 💋\n");
    printf("\n");
    printf("\t\t\t  3、退出登录 👀\n");
    printf("\n");
    printf("\n");
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    printf("请选择:\n");
    char a;
    scanf("%s",&a);
    switch (a)
    {
            //选择1，进入游戏规则
        case '1':
            rule();
            break;
            //选择2，登录系统
        case '2':
            loading();
            break;
            //选择3，退出登录
        case '3':
            inGame();
            break;
            
        default:printf("\n输入错误，请重新输入\n");
            welcome();break;
    }
    
}

//游戏规则
void rule()
{
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    printf("\n");
    printf("第一步：进入游戏系统会产生一个1000以内的随机整数；\n第二步：根据提示输入一个小于1000的任意整数；\n第三步：判断您输入的数和随机数是否相等，如果相等，恭喜你猜对了，将获得500积分。\n温情提示：每轮游戏有六次机会，每玩一次扣5元现金\n");
    printf("按n退出,欢迎您多提宝贵意见🌝🌝🌝:");
    getchar();
    char n;
    scanf("%c",&n);
    switch (n) {
        case 'n':
            welcome();
            break;
        default:printf("\n输入错误，请重新输入\n");
            rule();break;
            
    }
    printf("\n");
    printf("\n");
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
}

//用户登录
void loading()
{
    int id;                  //定义一个整形的id
    char password[LENGTH];   //定义一个字符型的password数组
    printf("请输入会员号:\n");
    scanf("%d",&id);         //输入一个整形的会员号
    printf("请输入密码:\n");
    scanf("%s",password);    //输入一个字符型的密码
    
    //进入第一层循环，循环判断是否输入超过3次
    for (int a=0; a<2; a++)
    {
        //进入第二层循环，循环判断输入的会员号是否存在，密码是否正确
        for (int i=0; i<LENGTH; i++)
        {
            if((userArr[i].usersid==id)&&strcmp(userArr[i].userspassword,password)==0)
            {
                //如果输入的会员号和密码都正确，登陆成功
                LOGIN (i);
                
            }
        }
        printf("输入的用户名和密码不匹配请重新输入:\n");
        printf("重新输入会员号:\n");
        scanf("%d",&id);
        printf("重新输入密码:\n");
        scanf("%s",password);
        
    }
    printf("您的输入已经超过3次,退出游戏\n");//退出系统
    inGame();
}

//游戏登陆模块
void LOGIN (int x)
{
    int i=1;
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t1、猜数字 💋\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t2、退出游戏 👀\n");
    printf("\n");
    printf("\n");
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    printf("\n");
    while (i==1)
    {
        
        printf("请选择:\n");
        char a;
        scanf("%s",&a);
        switch (a)
        {
            case '1':
                //如果余额大于等于5，可以开始游戏
                if (userArr[x].money>=5)
                {
                    stargame(x);//会员登陆账号开始玩游戏
                    break;
                }
                //余额小于5，余额不足
                else
                {
                    printf("您的余额不足，请充值💰💰💰\n");
                    i=1;
                    LOGIN(x);    //余额不足，跳出.
                    break;
                }
                break;
            case '2':
                welcome();            //返回欢迎界面
            default:printf("\n输入错误，请重新输入\n");
                LOGIN(x);break;
        }
        
    }
    
    
    
}

//开始玩游戏
void stargame(int x)
{
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    printf("\n");
    
    //产生一个随机数
    srand((unsigned)time(NULL));
    int b,i;
    //对产生的随机数对1000取余
    b=rand()%1000;
    printf("系统已经产生一个随机数，请开始游戏\n");
    printf("\n");
    //进入循环，一轮游戏只有6次机会
    for (i=0; i<8; i++)
    {
        //每轮游戏需要5元钱，每玩一次，判断一次余额是否充足
        if (userArr[x].money>4)
        {
            printf("请输入一个1000以下的整数:");
            int a;
            scanf("%d",&a);
            
            //输入的数小于随机数
            if (a<b)
            {
                printf("小于产生的随机数,请重新输入:\n");
                
            }
            //输入的数大于随机数
            else
                if(a>b)
                {
                    printf("大于产生的随机数,请重新输入:\n");
                    
                }
            //输入的数和随机数相同，猜对
                else
                {
                    printf("恭喜你!!猜对了👏👏👏\n");
                    //猜对奖励积分500
                    userArr[x].sc=userArr[x].sc+500;
                    //显示你当前的积分
                    printf("你当前的积分为:%d\n",userArr[x].sc);
                    break;
                    
                }
            //每玩一次，扣5块钱
            userArr[x].money=userArr[x].money-5;
            //显示当前余额
            printf("你当前的余额为💰:%d\n",userArr[x].money);
        }else
        {
            //余额不足
            printf("您的余额不足，请充值💰💰💰\n");
            LOGIN (x);   //余额不足，返回充值
        }
        
    }
    if(i==8)
    {printf("你的八次机会已用完，本轮游戏结束\n");}
    //输入y开始一局新的游戏，输入n退出账号
    printf("是否开始新一局的游戏(y/n):");getchar();
    char m;
    scanf("%c",&m);
    switch (m)
    {
        case 'y':
            LOGIN (x);
            break;
        case 'n':
            welcome();
            break;
        default:printf("\n输入错误，请重新输入\n");
            welcome();break;
    }
    printf("🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄🎃🎄🎄🎄🎄\n");
    printf("\n");
    
}
