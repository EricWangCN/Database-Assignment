//
// Created by 王子龙 on 2020/9/10.
//

#include "EmployeeTable.h"

bool EmployeeTable::readFile()
{
    string sName, sPos, sTmp;
    sex sSex;
    int iID;
    file.open("EmployeeInfo.txt", ios::in);
    while (!file.eof())
    {
        file >> sName >> iID >> sPos >> sTmp;
        // cout << sName << iID << sPos << sTmp;
        if (sName == "")
            break;
        if (sTmp == "F")
            sSex = F;
        else
            sSex = M;
        sEmployee tmp = sEmployee(sName, iID, sPos, sSex);
        Employees.push_back(tmp);
    }
    file.close();

    return true;
}

int EmployeeTable::search(const int &id)
{
    int iLen = Employees.size();
    for (int i = 0; i < iLen; ++i)
    {
        if (Employees[i].iID == id)
            return i;
    }
    return -1;
}

bool EmployeeTable::addEmployee(sEmployee e)
{
    if (search(e.iID) == -1)
    {
        Employees.push_back(e);
        return true;
    }
    else
    {
        return false;
    }
}

void EmployeeTable::print()
{
    int iLen = Employees.size();
    cout << "Name\tID\tPosition\n";
    for (int i = 0; i < iLen; ++i)
        cout << Employees[i].sName << '\t' << Employees[i].iID << '\t' << Employees[i].sPosition << '\n';
}

bool EmployeeTable::changeInfo(const int &id, string position)
{
    int iPos = search(id);
    if (iPos >= 0)
    {
        Employees[iPos].sPosition = position;
        return true;
    }
    else // Cannot find him/her
        return false;
}

bool EmployeeTable::deleteEmployee(const int &id)
{
    int iPos = search(id), iLen = Employees.size();
    if (iPos >= 0)
    {
        for (int i = iPos; i < iLen - 1; ++i)
        {
            Employees[i].sPosition = Employees[i + 1].sPosition;
            Employees[i].iID = Employees[i + 1].iID;
            Employees[i].sName = Employees[i + 1].sName;
        }
        Employees.pop_back();
        return true;
    }
    else
        return false;
}

void EmployeeTable::writeFile()
{
    fstream ile;
    int iLen = Employees.size();
    string sTmp;
    ile.open("EmployeeInfo.txt", ios::out);
    if (!ile.is_open())
        cout << "error\n";
    for (int i = 0; i < iLen; ++i)
    {
        if (Employees[i].Sex == F)
            sTmp = "F";
        else
            sTmp = "M";
        ile << Employees[i].sName << ' ' << Employees[i].iID << ' ' << Employees[i].sPosition << ' ' << sTmp;
        if (i != iLen - 1)
        {
            ile << '\n';
        }
    }
    ile.close();
}
