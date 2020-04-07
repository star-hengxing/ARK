#include <fstream>
#include <iostream>
#include <string>
#include"ark.h"

using namespace std;

inline void CheckMistake(p_egg node)
{
    if (!node)
    {
        cout << "分配内存失败" << endl;
        system("pause");
        exit(3);
    }
}

inline string ReplaceTypeName(string str)
{
    int len = str.size() - 4;
    str.erase(len,4);
    return str;
}

void SearchDis(p_egg head)
{
    string _name;
    p_egg temp = head->next;
    cout << "恐龙名:";
    cin >> _name;
    printf("\n");
    while (temp)
    {
        if (temp->name == _name)
        {
            cout << temp->type<<endl;
            system("pause");
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "没有该恐龙信息" << endl;
    system("pause");
}

p_egg start()
{
    p_egg end, temp;
    //首先检查文件完整性

    //现需6个txt文件
    p_egg head = new egg;//头指针是一个坐标
    CheckMistake(head);
    end = head;//尾指针是一个搬运工

    //将文件数据导入链表
    temp = LoadEggData(end, "超小型蛋.txt");
    temp = LoadEggData(temp, "小型蛋.txt");        //赋值号优先级较低
    temp = LoadEggData(temp, "中型蛋.txt");        //可以无限套娃，但为了可读性，还是别了
    temp = LoadEggData(temp, "大型蛋.txt");
    temp = LoadEggData(temp, "超大型蛋.txt");
    temp = LoadEggData(temp, "特型蛋.txt");
    end = temp;//可读性
    end->next = NULL;
    //初始化完成
    return head;
}

p_egg LoadEggData(p_egg end, string _type)
{
    ifstream load;
    load.open(_type, ios::in);//以读入模式打开
    if (!load)
    {
        cout << "打开文件失败" << endl;
        exit(4);
    }
    _type = ReplaceTypeName(_type);
    while (load.peek() != EOF)
    {
        p_egg temp = new egg;
        CheckMistake(temp);
        load >> temp->name;
        temp->type = _type;
        end->next = temp;
        end = temp;
    }
    load.close();
    return end;
}

void show(p_egg head)
{
    p_egg temp = head->next;
    while (temp)
    {
        cout << temp->name<<"       "<<temp->type << endl;
        temp = temp->next;
    }
}