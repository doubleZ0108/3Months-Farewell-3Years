//
//  template.cpp
//  Farewell_C_Cpp
//  
//  Created by double Z on 2020/09/20 .
//  Copyright © 2020 double Z. All rights reserved.
//

/* Generic Programming */

/**
 * Knowledge of Function Template
 * - 值的参数化：函数定义的时候数据的值是未知的，通过实参确定
 * - 数据类型也可以推迟到实参传递时推导
 */
#include <iostream>
using namespace std;

template<typename Type> void Swap(Type&, Type&);

void testFunctionTemplate(){
    int a = 3, b = 4;
    Swap(a, b);
    cout << a << " " << b << endl;

    string zz("zz"), yoyo("yoyo");
    Swap(zz, yoyo);
    cout << zz << " " << yoyo << endl;
}


/**
 * Knowledge of Class Template
 * - 类模板在实例化时必须显示指明数据类型
 */
template<typename T1, typename T2>
class Point {
public:
    Point() {}
    Point(T1 x, T2 y): _x(x), _y(y) {}

    T1 getX();
    T2 getY();
private:
    T1 _x;
    T2 _y;
};

template<typename T1, typename T2>
T1 Point<T1, T2>::getX(){
    return this->_x;
}

template<typename t1, typename t2>
t2 Point<t1, t2>::getY() {
    return this->_y;
}

void testClassTemplate(){
    Point<int, string>* point = new Point<int, string>(1, "zz");
    cout << point->getX() << " " << point->getY() << endl;

    delete point;
}

int main(){
//    testFunctionTemplate();
    testClassTemplate();
    return 0;
}

template<typename Type>
void Swap(Type& a, Type& b){
    Type tmp = a;
    a = b;
    b = tmp;
}