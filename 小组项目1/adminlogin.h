//
//  adminlogin.h
//  小组项目1
//
//  Created by 中软mini010 on 15/8/4.
//  Copyright (c) 2015年 中软mini010. All rights reserved.
//

#ifndef ______1__adminlogin__
#define ______1__adminlogin__

#include <stdio.h>
#include "userlogin.h"
#endif /* defined(______1__adminlogin__) */
//这个结构体放管理员信息
struct ADMIN
{
    int adminid;            //定义管理员帐号
    int password;           //定义管理员密码
};
void adminLogin();          //管理员登陆
void addUser();             //添加会员的函数
void scAdd();             //积分充值函数
void topup();               //帐号充值函数
void adminMenu();           //管理员
void showUsers();           //会员信息显示//完成