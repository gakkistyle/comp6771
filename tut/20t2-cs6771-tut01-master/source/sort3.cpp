//#include "range/v3/utility.hpp" // for ranges::swap
#include <iostream>
#include <vector>
#include <utility>

void sort_for_three(std::vector<int>& obj){
    const int num = 3;
    if(obj.size() != 3){
        std::cout<<"wrong size"<<std::endl;
        exit(1);
    }
    for(auto i=0;i<num-1;i++){
        for(auto j=0;j<num-1-i;j++){
            if(obj[j]>obj[j+1]){
//                auto temp = obj[j];
//                obj[j] = obj[j+1];
//                obj[j+1] = temp;
                std::swap(obj[j],obj[j+1]);
            }
        }
    }
}

void sort_for_three(std::vector<std::string>& obj){
    const int num = 3;
    if(obj.size() != 3){
        std::cout<<"wrong size"<<std::endl;
        exit(1);
    }
    for(auto i=0;i<num-1;i++){
        for(auto j=0;j<num-1-i;j++){
            if(obj[j].compare(obj[j+1])>0){
    //                auto temp = obj[j];
    //                obj[j] = obj[j+1];
    //                obj[j+1] = temp;
                std::swap(obj[j],obj[j+1]);
            }
        }
    }
}
