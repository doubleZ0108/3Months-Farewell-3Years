//
//  copy.cpp
//  Farewell_C_Cpp
//  
//  Created by double Z on 2020/09/20 .
//  Copyright © 2020 double Z. All rights reserved.
//
#include <iostream>
using namespace std;

/**
 * Knowledge of Copy Constructor & Assign Operator
 */
class Student {
public:
    Student(){}
    Student(string name, int id): _name(name), _id(id) {}

    /**
     * Copy Constructor
     * - 参数必须为&，防止参数拷贝无限循环
     * - 必须是const，这样const的Student对象和non-const都可以被作为拷贝的模板
     * - 初始化和赋值是不一样的，即使 Student stu2 = stu1; 还是初始化，调用的构造函数
     */
    Student(const Student& stu){
        this->_name = stu._name;
        this->_id = stu._id;
    }

    /**
     * Assign Operator
     * - 返回值为&：防止返回时调用拷贝构造函数；可以实现连续赋值 stu1=stu2=stu3;
     * - 要判断是否为自我赋值
     * - 参数为const&，原因同上
     */
    Student& operator=(const Student& stu){
        if(this != &stu){
            this->_name = stu._name;
            this->_id = stu._id;
        }
        return *this;
    }
public:
    string _name;
    int _id;
};


/**
 * Knowledge of Deep & Shallow Copy
 * [浅拷贝]
 *      - 默认行为，memcpy
 *      - 如果指向其他数据的指针、动态分配内存就不能这样拷贝，要完整拷贝对象的所有数据
 * [深拷贝]
 *      - 如果一个类有指针类型的成员，只有深拷贝才能将指针指向的内容复制一份出来，让原对象和新对象互相独立，彼此不受影响
 */

int main(){

    return 0;
}