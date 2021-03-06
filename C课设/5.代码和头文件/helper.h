#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>



// 日期
typedef struct Date {
	int year;	// 年
	int month;	// 月
	int day;	// 日
}Date;

// 账号
typedef struct Account {
	char user[20];  // 用户名
	char psw[20];   // 密码
	char type[20];	// 普通用户或管理员
}Account;

typedef struct AccountNode {
	Account* account;
	struct AccountNode* next;
}AccountNode;


// 新闻
typedef struct News {
	int id;					// 编号
	char *title;			// 标题
	char *content;			// 内容 
	char publisher[20];		// 发布者
	char type[10];   		// 新闻分类
	Date date;				// 发布日期
	int verified;	        // 是否被审核
	int deleted;           // 是否被删除
}News;

typedef struct NewsNode {
	News* news;
	struct NewsNode* next;
}NewsNode;


// 评论
typedef struct Comment {
	int newsId;		// 新闻编号
	char user[20];  // 用户名
	char* content;  // 评论的内容
}Comment;

typedef struct CommentNode {
	Comment* comment;
	struct CommentNode* next;
}CommentNode;


// 比较两个日期
int CompareDate(struct Date date1, struct Date date2);

// 从文件读取数据
void ReadDataFromFile(AccountNode** accounts, NewsNode** news, CommentNode** comments);

// 保存数据到文件
void WriteDataFromFile(AccountNode* accounts, NewsNode* news, CommentNode* comments);

// 添加新闻
void AddNews(NewsNode* news, Account* account);

// 输入整数
int InputInteger(char* msg, int low, int high);

// 输入字符串
char* InputString(char* msg);

// 按Enter键继续
void WaitForEnterKey();

// 清空输入缓存
void ClearInputBuffer();

// 查找新闻
NewsNode* CopyNews(NewsNode* news, int needVerified, int excluedDeleted, char* type,
	int* year, int* month, int* day, struct Date* startDate, struct Date* endDate, 
	char* titleKeyword, Account* account);

// 登录系统
Account* Login(AccountNode* accounts);

#endif // HELPER_H
