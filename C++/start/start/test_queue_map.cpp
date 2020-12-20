//
//  test_queue_map.cpp
//  start
//
//  Created by 郑淇文 on 2020/6/10.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include<iostream>
#include<unordered_map>
#include<deque>
#include<vector>
#include<map>
#include<string>
int main(){
//    auto words = std::vector<std::vector<std::string>>{{"one","two"},{"one","three"},{"one","abb"}};
////    std::sort(words.begin(),words.end());
////    for(int i = 0;i<words.size();i++){
////        for(int j = 0;j<words[i].size();j++){
////            std::cout<<words[i][j]<<" ";
////        }
////        std::cout<<"\n";
////    }
//    auto iter = words.begin();
//    std::cout<<"fir st pointer: "<<(*iter).back()<<std::endl;
//    words.insert(words.end(),{"oo","gg"});
//    iter ++;
//    std::cout<<"first pointer: "<<(*words.begin()).back()<<std::endl;
//    std::cout<<"last pointer: "<<(*iter).back()<<std::endl;

    
//    auto map1 = std::unordered_map<std::string,std::string>{{"one","two"},{"three","four"}};
//    map1.emplace("five","six");
//    std::cout<<"five: "<<map1.at("five")<<std::endl;
//
//    if(map1.find("six")==map1.end()){
//        std::cout<<"good thing!"<<std::endl;
//    }
//
//    auto que1 = std::queue<std::string>{};
//    que1.push("hi");
//    que1.push("shit");
//    auto breakpoint = que1.back();
//    que1.pop();
//    if(breakpoint == que1.front())
//        std::cout<<"is it equall? ";
//    if(que1.empty())
//        std::cout<<"hei";
//    que1.push("dota");
//    que1.pop();
//
//    std::cout<<"now breakpoint is: "<<breakpoint<<std::endl;
//    std::cout<<"the content of queue is"<<que1.front()<<std::endl;
//
//    auto map1 = std::multimap<std::string,std::string>{{"an","apple"},{"a","banana"}};
//    map1.emplace("a","pipi");
//    map1.emplace("a","pipi");
//    auto iter = map1.equal_range("a");
//    if(iter.first != std::end(map1)) {
//       for(auto iter2 = iter.first;iter2!=iter.second;++iter2)
//             std::cout<<iter2->first<<" "<<iter2->second<<"\n";
//    }
//
//    auto v1 = std::vector<std::string>{};
//    std::sort(v1.begin(), v1.end());
    
//    std::queue<int> s1 = {};
//    s1.push();
//
//    auto ex = std::vector<std::vector<int>>{};
//    ex.insert(ex.begin(), std::vector<int>{1});
//    ex.push_back(std::vector<int>{1});
//    ex[0].push_back(2);
//    std::cout<<ex.size()<<std::endl;
//    size_t i = 0;
//    std::cout<<(i==ex.size());
//    std::cout<<ex[i][0];

//    auto map1 = std::multimap<int, int>{{1,1}};
//    map1.emplace(1,2);
//    int r=2;
//    map1.emplace(3,4);
// //   std::cout<<(map1.count(1)==r);
//    int start = 3;
//    start = map1.find(start)->second;
//    std::cout<<start;
//    auto str1 = std::string{"123"};
//    size_t i = 0;
//    std::cout<<str1.size();
    
//    auto que2 = std::deque<int>{};
//    que2.push_back(3);
//    que2.push_back(5);
//    auto ii = std::find(que2.begin(),que2.end(),7);
//    std::cout<<(ii==que2.end());
    
//    auto m3 = std::map<std::string,std::vector<std::string>>{};
//    auto v1 = std::vector<std::string>{"w","t"};
//    m3.emplace("hi",v1);
//    auto place = m3.at("hi");
//    std::cout<<place[0];
    
//    std::vector<int> v3 = {};
//    std::cout<<(v3==std::vector<int>{});
//    char s[40];
//    //auto s = std::string{};
//    std::cin.getline(s,1024);
//    std::cout<<strlen(s)<<std::endl;
//    char in[1024];
//    strncpy(in, s+2, strlen(s)-2);
//    int i = atoi(in);
//    std::cout<<i;
//    if(s[1]==' ')
//        std::cout<<"xixi";
    
    auto ss = std::string{"dfefe"};
//    auto sa = std::string{ss.begin(),ss.end()-1};
//    std::cout<<sa;
    ss += "b";
    std::cout<<ss;
}
