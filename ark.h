#ifndef _ARK_H
#define _ARK_H

#pragma warning(disable:4996)

#include<string>
//string是一个类

using namespace std;

typedef struct EGG
{
    string name;
    string type;//蛋的类型
    struct EGG* next;
}egg, * p_egg;

p_egg start();
//导入数据

void show(p_egg head);
//打印所有恐龙数据

void SearchDis(p_egg head);
//head是存放数据链表的头指针

p_egg LoadEggData(p_egg end, string _type);
//导入数据
//_type区分函数里的type

inline void CheckMistake(p_egg node);//检查分配内存的错误

inline string ReplaceTypeName(string str);//在导入恐龙类型时把.txt去掉

#endif
