//
//  adminlogin.c
//  小组项目1
//
//  Created by 中软mini010 on 15/8/4.
//  Copyright (c) 2015年 中软mini010. All rights reserved.
//

#include "adminlogin.h"
extern struct users userArr[];
struct ADMIN adminArr[]={9999,9999};
//管理员登陆函数
void adminLogin()
{
    //输入管理员账户密码
    printf("请输入管理员号");
    int id;             //定义输入的会员号
    scanf("%d",&id);
    printf("\n请输入密码");
    int password;       //定义输入的密码
    scanf("%d",&password);
    //循环判断管理员账户是否匹配
    int flag=0;
    for (int i=0; i<LENGTH; i++) {
        if (adminArr[i].adminid==id&&adminArr[i].password==password) {
            flag=1;
            adminMenu();
        }
    }if (!flag) {
        printf("管理员账户错误,请重新输入:\n");
        adminLogin();
    }
    
}
//管理员界面
void adminMenu()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t管理员界面");
    putchar('\n');
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t1:余额充值\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t2:积分充值\n");
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t3:会员信息显示\n");
    putchar('\n');
    printf("请输入数字:输入n返回上级菜单\n");
    char a;
    scanf("%s",&a);
    switch (a) {
        case '1':topup();break;
        case '2':scAdd();break;
        case '3':showUsers();break;
        case 'n':main();break;
        default:printf("输入不识别，请重新输入:");
            inGame();
            break;
    }
}
void addUser()
{
    //loadfromfile_arr("/Users/zhongruanmini002/Desktop/hh", userArr);
    int userid;
    char word[9];
    
    printf("\t\t\t\t\t\t\t\t\t\t\t新会员注册");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t\t\t\t\t\t\t会员注册\n");
    printf("\t\t\t请输入会员号:");
    scanf("%d",&userid);
    printf("\t\t\t请输入会员密码:");
    scanf("%s",word);
    //循环判断当前位置是否可用
    for (int i=0; i<LENGTH; i++) {
        //如果可用，继续输入会员密码
        if (userArr[i].usersid==0) {
            
            userArr[i].usersid=userid;
            strcpy(userArr[i].userspassword,word);
            //
            //
            
            printf("注册成功!");
            //savetofile_arr("/Users/zhongruanmini002/Desktop/hh", userArr, 3);
            break;
        }
        //如果不可用，提示会员号已存在，
        if (userArr[i].usersid==userid)
        {
            printf("会员已存在，请重新输入\n");
            addUser();
        }
    }
    printf("输入n返回上级菜单\n");
    char e;
    scanf("%s",&e);
    switch (e) {
        case 110:main();break;
        default:printf("请重新输入\n");addUser();break;
    }
}
void topup()
{
    int pid;
    int pid1;
    int money;
    int j;
    printf("\t\t\t\t\t\t\t\t\t\t\t管理员界面");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t会员余额充值\n");
    printf("\t\t\t请输入要充值的会员号:");
    scanf("%d",&pid);
    putchar('\n');
    //循环判断输入会员号是否存在
    int flag=0;
    for (int i=0; i<LENGTH; i++) {
        if (userArr[i].usersid==pid)
        {
            j=i;
            flag=1;
            putchar('\n');
            //确认充值号码无误
            printf("\t\t\t请再次输入要充值的会员号:");
            scanf("%d",&pid1);
            //会员号不匹配，跳出
            if (pid1!=pid)
            {
                printf("输入会员号不匹配，请重新输入\n");
                scAdd();
                
            }
            printf("请输入充值金额:");
            scanf("%d",&money);
            //再次缺认充值帐号和金额
            printf("\n确定给%d号会员充值%d元?(y/n)",userArr[i].usersid,money);
            char c;
            scanf("%s",&c);
            switch (c) {
                case 'y':
                    userArr[j].money+=money;
                    //savetofile_arr("/Users/zhongruanmini002/Desktop/hh", userArr, 3);
                    //loadfromfile_arr("/Users/zhongruanmini002/Desktop/hh", userArr);
                    
                    printf("充值成功!");
                    break;
                case 'n':
                    topup();
                    break;
                default:printf("输入错误，请重新输入:\n");topup();
                    break;
            }break;
            
        }
    }
    if(!flag)
    {
        printf("会员号错误,请重新输入:\n");
        topup();
    }
    printf("输入n返回上级菜单\n");
    char e;
    scanf("%s",&e);
    switch (e) {
        case 110:adminMenu();break;
        default:printf("请重新输入\n");topup();break;
    }
}
void scAdd()
{
    int pid;
    int pid1;
    int sc;
    int j;
    printf("\t\t\t\t\t\t\t\t\t\t\t管理员界面");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t会员积分充值\n");
    printf("\t\t\t请输入要充值的会员号:");
    scanf("%d",&pid);
    putchar('\n');
    //循环判断输入会员号是否存在
    int flag=0;
    for (int i=0; i<LENGTH; i++) {
        if (userArr[i].usersid==pid)
        {
            j=i;
            flag=1;
            putchar('\n');
            //确认充值号码无误
            printf("\t\t\t请再次输入要充值的会员号:");
            scanf("%d",&pid1);
            //会员号不匹配，跳出
            if (pid1!=pid)
            {
                printf("输入会员号不匹配，请重新输入\n");
                scAdd();
                
            }
            printf("请输入充值积分:");
            scanf("%d",&sc);
            //再次缺认充值帐号和金额
            printf("\n确定给%d号会员充值%d积分?(y/n)",userArr[i].usersid,sc);
            char c;
            scanf("%s",&c);
            switch (c) {
                case 'y':
                    userArr[j].sc+=sc;
                    //savetofile_arr("/Users/zhongruanmini002/Desktop/hh", userArr, 3);
                    //loadfromfile_arr("/Users/zhongruanmini002/Desktop/hh", userArr);
                    
                    printf("充值成功!");
                    break;
                case 'n':
                    scAdd();
                    break;
                default:printf("输入错误，请重新输入:\n");return;
                    break;
            }break;
            
        }
    }
    if(!flag)
    {
        printf("会员号错误,请重新输入:\n");
        scAdd();
    }
    printf("输入n返回上级菜单\n");
    char e;
    scanf("%s",&e);
    switch (e) {
        case 110:adminMenu();break;
        default:printf("请重新输入\n");return;
    }
}
//查询用户信息
void showUsers()
{
    loadfromfile_arr("/Users/zhongruanmini002/Desktop/hh", userArr);
    printf("\t\t\t\t\t\t\t\t\t欢迎使用一点都不好玩游戏合集v1.0版");
    for (int i=0; i<99; i++)
    {
        putchar('*');
    }
    printf("用户信息显示:\n");
    for (int i=0; i<LENGTH; i++) {
        
        if(userArr[i].usersid!=0)
        {
            printf("用户名\t\t用户余额\t\t用户积分\n");
            printf("%5d\t\t%5d\t\t%5d\n",userArr[i].usersid,userArr[i].money,userArr[i].sc);
        }
        
    }
    printf("输入n返回上级菜单\n");
    char e;
    scanf("%s",&e);
    switch (e) {
        case 'n':adminMenu();break;
        default:printf("请重新输入\n");return;
    }
    
}

