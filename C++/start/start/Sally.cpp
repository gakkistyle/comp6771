//
//  Sally.cpp
//  start
//
//  Created by 郑淇文 on 2020/6/1.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "Sally.hpp"
#include <iostream>
using namespace std;

Sally::Sally(int a,int b)
: regVar(a),constVar(b)
{
    cout << "I am the constructor"<<endl;
}

Sally::~Sally(){
    cout<<"I am the deconstructor"<<endl;
}

void Sally::printShiz(){
    cout<< "I am a regular function"<<endl;
}

void Sally::printShiz2() const{
    cout << "I am the constant function."<<endl;
}


void Sally::printCrap(){
    cout << "did someone say steak?"<<endl;
}


void Sally::print(){
    cout << "regular var is: "<<regVar<<endl;
    cout << "const var is : "<<constVar<<endl;
}
