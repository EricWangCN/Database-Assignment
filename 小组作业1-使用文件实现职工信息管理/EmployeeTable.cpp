//
// Created by 王子龙 on 2020/9/10.
//

#include "EmployeeTable.h"

bool EmployeeTable::readFile() {
    string sTmp;
    file.open("EmployeeInfo.csv", ios::out | ios::in);
    while (!file.eof()) {
        file >> sTmp;
        int iPos1, iPos2, iLen = sTmp.length();
        bool flag = false;
        for (int i = 0; i < iLen; ++i) {
            if (sTmp[i] == ',') {
                if (!flag) {
                    iPos1 = i;
                    flag = true;
                } else {
                    iPos2 = i;
                }
            }
        }
        Employees.emplace_back(sTmp.substr(0, iPos1), stoi(sTmp.substr(iPos1, iPos2)), sTmp.substr(iPos2, iLen));
    }
    file.close();

    return true;
}

int EmployeeTable::search(const int &id) {
    int iLen = Employees.size();
    for (int i = 0; i < iLen; ++i) {
        if (Employees[i].iID == id) return i;
    }
    return -1;
}

bool EmployeeTable::addEmployee(const sEmployee e) {
    if (!search(e.iID)) {
        Employees.push_back(e);
        return true;
    } else {
        return false;
    }
}

void EmployeeTable::print() {
    int iLen = Employees.size();
    cout << "Name\tID\tPosition\n";
    for (int i = 0; i < iLen; ++i)
        cout << Employees[i].sName << '\t' << Employees[i].iID << '\t' << Employees[i].sPosition << '\n';
}

bool EmployeeTable::changeInfo(const int &id, string position) {
    int iPos = search(id);
    if (iPos >= 0) {
        Employees[iPos].sPosition = std::move(position);
        return true;
    } else // Cannot find him/her
        return false;
}

bool EmployeeTable::deleteEmployee(const int &id) {
    int iPos = search(id), iLen = Employees.size();
    if (iPos >= 0) {
        for (int i = iPos; i < iLen - 1; ++i) {
            Employees[i].sPosition = Employees[i + 1].sPosition;
            Employees[i].iID = Employees[i + 1].iID;
            Employees[i].sName = Employees[i + 1].sName;

        }
        Employees.pop_back();
        return true;
    } else
        return false;
}
