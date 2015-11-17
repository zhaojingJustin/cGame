//
//  userlogin.h
//  小组项目1
//
//  Created by 中软mini010 on 15/8/4.
//  Copyright (c) 2015年 中软mini010. All rights reserved.
//

#ifndef ______1__userlogin__
#define ______1__userlogin__
#define LENGTH 50
#include <stdio.h>
//这个结构体里面放会员信息
struct users
{
    int usersid;        //定义会员号
    char userspassword[9];  //定义用户密码
    int money;      //定义会员余额
    int sc;         //定义会员积分
    
};

#endif /* defined(______1__userlogin__) */
void userMenu();            //用户界面//完成
void userLogin();           //会员登陆
void inGame();              //进入游戏  //差点
void scoerUse();            //积分使用
void soChange();            //积分兑换
void soGoods();             //积分抽奖
long random1();              //猜数字随机数函数
long random2();             //猜拳随机数函数   //完成
void randomNum();           //随即数游戏
void caiQuan();             //猜拳游戏        //完成
void guess();               //猜数游戏2.0
void play(int n);           //开始玩游戏
void esc();                 //退出
void checkpsw();            //检查密码与账号
long random3();             //幸运777随机数函数
long random4();
long random5();
void reward();              //幸运777积分奖励
void login();               //幸运777
long random();              //抽奖随机数产生
void scList();              //积分排行
void twentyone();           //21点
void play1(int n);//开始游戏
void esc1();//退出
void checkpsw1();//检验密码与用户名
void pcShow();              //个人信息显示
void welcome();         //欢迎界面
void loading();         //声明登录方法
void LOGIN ();          //游戏登陆模块
void stargame();        //开始玩游戏
void rule();            //游戏规则
