//
//  operator_overloading.cpp
//  Farewell_C_Cpp
//  
//  Created by double Z on 2020/09/20 .
//  Copyright © 2020 double Z. All rights reserved.
//
/**
 * Knowledge of Operator Loading
 * - 重载不能改变运算符优先级、结合性、几元运算符
 * - 不能有默认参数
 * - 可以作为成员函数也可以是全局函数
 * - 至少有一个类型要是对象，防止篡改默认运算性质
 * - 箭头运算符->、下标运算符[ ]、函数调用运算符( )、赋值运算符=只能以成员函数的形式重载。
 */
#include <iostream>>
using namespace std;

class Complex {
    // 以全局函数的形式重载
    friend Complex operator+(const Complex& comp1, const Complex& comp2);
    friend istream& operator>>(istream& is, Complex& complex);
public:
    Complex() {}
    Complex(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }

    // 以成员函数的形式重载
    Complex& operator-=(const Complex& rhv);
private:
    int real;
    int imaginary;
};

Complex operator+(const Complex& comp1, const Complex& comp2){
    return Complex(comp1.real+comp2.real, comp1.imaginary+comp2.imaginary);
}

istream& operator>>(istream& is, Complex& complex) {
    is >> complex.real >> complex.imaginary;
    return is;  // 连续输入
}

Complex& Complex::operator-=(const Complex& rhv){
    this->real -= rhv.real;
    this->imaginary -= rhv.imaginary;
    return *this;
}


class Array {
public:
    Array() {}
    Array(int length){
        this->length = length;
        if(this->length > 0){
            arr = new int[this->length];
        }
    }
    ~Array(){
        if(arr) { delete[] arr; }
    }

    // 不仅可以访问 还可以修改元素
    int& operator[](int index){
        return arr[index];
    }
    // 只能访问 支持const对象
    const int& operator[](int index) const {
        return arr[index];
    }
private:
    int length;
    int* arr;
};
