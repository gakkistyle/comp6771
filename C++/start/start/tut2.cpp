//
//  tut2.cpp
//  start
//
//  Created by 郑淇文 on 2020/6/8.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
auto second(std::vector<int>& v, std::vector<int>::iterator new_first) -> std::vector<int>::const_iterator {
  auto copy = std::vector<int>(v.begin(), new_first);
  v.erase(v.begin(), new_first);
  return v.insert(v.end(), copy.begin(), copy.end());
}

auto all_unique(std::string const& word) -> bool{
    auto s_set = std::set<char>{};
//    for(auto i = word.begin();i!=word.end();i++){
//        s_set.insert(*i);
//    }
    for(char c:word){
        s_set.insert(c);
    }
    //s_set.insert(word.begin(),word.end());
    return s_set.size() == word.size()?true:false;

}

auto all_unique_in_place(std::string const& word) -> bool
{
    for(size_t i = 0;i<word.size()-1;i++){
        for(size_t j = i+1;j<word.size();j++)
            if (word[i] == word[j])
                return false;
    }
    return true;
}


//
//int main(){
////    auto nums = std::vector<int>{1,5,3};
////    auto i = nums.end();
////    auto new1 = second(nums, i);
////    std::cout<<*(new1+1)<<std::endl;
////    auto test = std::string {"acdop"};
////    auto re = all_unique(test);
////    std::cout<<re<<std::endl;
//    auto test2 = std::string{"abcdd"};
//    auto re2 = all_unique_in_place(test2);
//    std::cout<<re2<<std::endl;
//    return 0;
//}
