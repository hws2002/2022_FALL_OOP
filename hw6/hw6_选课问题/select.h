#pragma once
#include "Student.h"
using namespace std;

template<class Student>
vector<int> select(vector<int> credit, int left, int right, Student student)
{
    student->l = left;
    student->r = right;
    return student->select_class(credit);
}
