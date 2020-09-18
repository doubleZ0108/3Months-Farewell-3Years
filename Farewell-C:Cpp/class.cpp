//
//  class.cpp
//  Farewell_C_Cpp
//  
//  Created by double Z on 2020/09/17 .
//  Copyright © 2020 double Z. All rights reserved.
//
#include <iostream>
using namespace std;

/**
 * Knowledge of Basic Class Concept
 */
class Array {
public:
    /* Constructor */
    Array(): _len(0){
        s_counter++;
    }
    Array(int len);

    /* Destructor */
    ~Array() {
        delete[] this->_parr;
        Array::s_counter--;
    }

    /* Const Function */
    void display() const {
        for(int i=0;i<_len;++i){
            cout << *(_parr+i) << " ";
        }
        cout << endl;
    }

    /* Static Function */
    static int getCounter() {
        return Array::s_counter;
    }
private:
    int* _parr;
    const int _len;
    static int s_counter;   // Static Variable
};

// initialization list
Array::Array(int len): _len(len) {      // const variable can only be initialized by this way
    if(this->_len > 0){
        _parr = new int[_len];
        s_counter++;
    }
}

int Array::s_counter = 0;   // static variable need to be initialize outside the class definition body

void testBasicClassConcept(){
    Array array(3);
    array.display();
    Array* parr = new Array();
    cout << Array::getCounter() << endl;
    delete parr;
    cout << Array::getCounter() << endl;
}

/**
 * Knowledge of Inheritance & Derive
 */
class Base {
public:
    void func() { cout << "Base::func()" << endl; }
    void func(int) { cout << "Base::func(int)" << endl; }

    void getPrivateVar() {
        cout << this->_privateVar << endl;
    }

    Base() {}
    Base(int baseVar): _baseVar(baseVar) {}
private:
    int _privateVar;     // 这个在子类里是占内存的，但是无法访问
    int _baseVar;
};

class Derived : public Base {
public:
    void func() { cout << "Derived::func()" << endl; }
    void func(char) { cout << "Derived::func(char)" << endl; }

    Derived() {}    // 也会默认调用基类的构造函数
    Derived(int baseVar, int derivedVar): Base(baseVar), _derivedVar(derivedVar) {}     // 通过调用基类的构造函数初始化基类的private属性

    ~Derived() {}   // 析构函数只有一个，编译器之道怎么选择，不需要调用基类的
private:
    int _derivedVar;
};

void testInheritanceDerived(){
    Base base;
    Derived derived;

    derived.func();
    derived.func('z');
//    derived.func(1);      // 编译错误：名字遮盖，子类只要重名直接覆盖，不会重载
    derived.Base::func();
    derived.Base::func(1);

    derived.getPrivateVar();    // 但是可以通过这种方法访问基类中的private属性
}


/**
 * Knowledge of Upper Casting
 * 1. 赋值的本质是内存的写入，只有属性占据真实内存，因此函数不会进行赋值
 * 2. 向上转型是安全的(数据多出来了好办，直接丢掉就好)
 */
class Father{
public:
    int fatherData;

    void display(){
        cout << "Father: " << fatherData << endl;
    }

    Father() {}
    Father(int data): fatherData(data) {}
};

class Son : public Father {
public:
    int sonData;

    void display(){
        cout << "Son: " << sonData << endl;
    }

    Son() {}
    Son(int fatherData, int data): Father(fatherData), sonData(data) {}
};

void testUpCast(){
    Father* pfather = new Father(1);
    Son* pson = new Son(999, 998);

    /**
     * pfather的类型是Father* 但是指向的Son类型的数据
     * 使用的Son的数据 + Father的方法
     *
     * 指针指向哪个对象就使用谁的数据，指针的类型是什么就使用谁的方法
     */
    pfather = pson;
    pfather->display();     // Father: 999
}

int main(){
//    testBasicClassConcept();
//    testInheritanceDerived();

    testUpCast();

    return 0;
}
