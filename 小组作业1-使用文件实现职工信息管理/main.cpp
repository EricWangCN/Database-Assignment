/***************************************
 * @author Zilong Wang                 *
 * @email wangzilong@bjtu.edu.cn       *
 * @date Sep.10th, 2020                *
 *                                     *
 * This program is coded by Zilong.    *
 * Only for database course.           *
 * Please use UTF-8 to view this file! *
 ***************************************/
#include "EmployeeTable.h"
#include <bits/stdc++.h>
#include <utility>

using namespace std;

int printMenu(int options = 7)
{
    int cmd;
    cout << "\n\n\n===================================\n请输入需要进行操作的序号：" << endl;
    cout << "1. 从文件中读入员工信息" << endl;
    cout << "2. 添加员工入职信息" << endl;
    cout << "3. 查找指定员工是否在职" << endl;
    cout << "4. 修改员工信息" << endl;
    cout << "5. 办理员工离职" << endl;
    cout << "6. 查看全部员工名单" << endl;
    cout << "7. 查找某个员工担任销售角色的项目名" << endl;
    cout << "8. 退出" << endl;

    cin >> cmd;
    while (cmd < 1 || cmd > options)
    {
        cout << "输入有误，请输入 (1-" << options << ") 的整数序号：";
        cin >> cmd;
    }
    return cmd;
}

int main()
{
    int options = 8;
    int cmd = printMenu(options);
    EmployeeTable table;

    int iID, iPos;
    string sName, sPos, sProject, sTmp;
    //table.readFile();
    while (cmd != options)
    {
        switch (cmd)
        {
        case 1:
            table.readFile();
            break;
        case 2:
        {
            sex sSex;
            cout << "请输入员工姓名 工号 职位 性别：";
            cin >> sName >> iID >> sPos >> sTmp;
            if (sTmp == "F")
                sSex = F;
            else
                sSex = M;
            sEmployee tmp = sEmployee(sName, iID, sPos, sSex);
            table.addEmployee(tmp);
            break;
        }
        case 3:
            cout << "请输入工号：";
            cin >> iID;
            iPos = table.search(iID);
            if (iPos >= 0)
                cout << "找到！\n";
            else
                cout << "没找到！\n";
            break;
        case 4:
            cout << "请输入工号";
            cin >> iID;
            iPos = table.search(iID);
            if (iPos >= 0)
            {
                cout << "请输入要变更的职位：";
                cin >> sTmp;
                table.changeInfo(iID, sTmp);
            }
            else
            {
                cout << "没找到！\n";
            }
            break;
        case 5:
            cout << "请输入工号：";
            cin >> iID;
            iPos = table.search(iID);
            if (iPos >= 0)
            {
                table.deleteEmployee(iID);
                cout << "已删除！\n";
            }
            else
            {
                cout << "没找到！\n";
            }
            break;
        case 6:
            table.print();
            break;
        case 7:
            cout << "请输入查找员工工号：";
            cin >> iID;
            int id;
            int flag = 0;
            fstream file;
            file.open("EmployeeInfo2.txt", ios::out | ios::in);
            while (!file.eof())
            {
                file >> id >> sProject >> sPos;
                if (id == iID && sPos == "sale")
                {
                    cout << "担任销售的项目是：" << sProject << endl;
                    file.close();
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "没找到这个员工\n";
            }
            break;
        }
        cmd = printMenu(options);
    }
    table.writeFile();
    return 0;
}
