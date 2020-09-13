//
// Created by 王子龙 on 2020/9/10.
//

#ifndef INC_1__EMPLOYEETABLE_H
#define INC_1__EMPLOYEETABLE_H
#include "Declaration.h"
using namespace std;
class EmployeeTable
{
public:
    vector<sEmployee> Employees;
    fstream file;
    bool readFile();
    bool addEmployee(sEmployee e);
    void print();
    int search(const int &id);
    bool changeInfo(const int &id, string position);
    bool deleteEmployee(const int &id);
    void writeFile();
    // void add
};

#endif //INC_1__EMPLOYEETABLE_H
