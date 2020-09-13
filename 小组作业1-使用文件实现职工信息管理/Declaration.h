//
// Created by 王子龙 on 2020/9/10.
//

#ifndef INC_1__DECLARATION_H
#define INC_1__DECLARATION_H
#include <bits/stdc++.h>
//Declaration of struct employee.

enum sex{M,F};

class sEmployee {
public:
    std::string sName;
    int iID;
    std::string sPosition;
    sex Sex;
    sEmployee(std::string name, const int& ID, std::string position, sex S) : sName(name), iID(ID), sPosition(position), Sex(S){}
};


#define EMPLOYEE_NUM 3
const std::string Positions[EMPLOYEE_NUM] = {"Manager",
                             "Boss",
                             "Developer"
};

#endif //INC_1__DECLARATION_H
