//
//  main.cpp
//  start
//
//  Created by 郑淇文 on 2020/5/7.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool f(int x,int y)
{
    return x>y;
}

void vectorDemo(){
    vector<int> A = {11,2,3,14};
    cout<<A[1]<<endl;
    sort(A.begin(),A.end()); //O(NlogN)
    
    bool present = binary_search(A.begin(),A.end(),3);
    present = binary_search(A.begin(),A.end(),4);
    
    A.push_back(100);
    present = binary_search(A.begin(),A.end(),100);
    cout<<"The present is now: "<<present<<endl;
    
    //2,3,11,14,100
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    
    vector<int>::iterator it = lower_bound(A.begin(),A.end(), 100); //same as auto it = ...
    vector<int>::iterator it2 = upper_bound(A.begin(),A.end(), 100);//same as auto it2 = ...
    
    cout<<*it<<"   "<<*it2<<endl;
    cout<<it2-it<<endl;
    
    sort(A.begin(),A.end(),f);
    vector<int>::iterator it3;
    for(it3 = A.begin(); it3!=A.end();it3++)
    {
        cout<<*it3<<" ";
    }
    cout<<endl;
    

    for(auto x:A)
    {
        x++;
        cout<<x<<" ";
    }
    cout<<endl;
    
    for (auto &x:A) //reference
    {
        x++;
    }
    
    for(it3 = A.begin(); it3!=A.end();it3++)
    {
        cout<<*it3<<" ";
    }
    cout<<endl;
}

void setDemo()
{
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);
    
    for(int x:S)
        cout<<x<<" ";
    cout<<endl;
    
    //-10 -1 1 2
    auto it = S.find(2);
    if(it == S.end())
        cout<<"not present\n";
    else{
        cout<<"present\n";
        cout<<*it<<endl;
        cout<<"distance is : "<<distance(S.begin(),it)<<endl;
    }
    
    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);
    cout<<*it2<<" "<<*it3<<endl;
    
    auto it4 = S.upper_bound(2);
    if(it4 == S.end()){
        cout<<"oops! sorry cant find something like that\n";
    }
}


void mapDemo()
{
    map<int,int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[10016] = 1;
    
    map<char,int> cnt;
    string x = "zard love pis";
    
    for(char c : x)
    {
        cnt[c]++;
    }
    
    cout<<cnt['d']<<" "<<cnt['z']<<endl;
}

void PowerofStl()
{
    //logN
    set<pair<int,int>> S;
    
    
    S.insert({2,3});
    S.insert({10,20});
    S.insert({30,400});
    S.insert({401,450});
    
    int point = 11;
    auto it = S.upper_bound({point,INT_MAX});
    if(it==S.begin())
    {
        cout<<"the given point is not lying in any interval..\n";
        return;
    }
    
    it--;
    pair<int,int> current = *it;
    if(current.first <= point && point <= current.second){
        cout<<"yes its present: "<<current.first<<" "<<current.second<<endl;
    }
    else{
        cout<<"the given point is not lying in any interval..\n";
    }
    
}

//int main(int argc, const char * argv[]) {
//    //C++ STL
//    //setDemo();
//    //mapDemo();
//    PowerofStl();
//    return 0;
//}

