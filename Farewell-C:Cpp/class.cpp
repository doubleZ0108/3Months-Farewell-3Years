//
//  class.cpp
//  Farewell_C_Cpp
//  
//  Created by double Z on 2020/09/17 .
//  Copyright © 2020 double Z. All rights reserved.
//
#include <iostream>
using namespace std;


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

Array::Array(int len): _len(len) {  // initialization list
    if(this->_len > 0){
        _parr = new int[_len];
        s_counter++;
    }
}

int Array::s_counter = 0;   // static variable need to be initialize outside the class definition body

int main(){
    Array array(3);
    array.display();

    Array* parr = new Array();

    cout << Array::getCounter() << endl;

    delete parr;

    cout << Array::getCounter() << endl;

    return 0;
}
