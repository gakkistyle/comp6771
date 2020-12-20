#include<iostream>
#include<vector>
void sort_for_three(std::vector<int>& obj);
void sort_for_three(std::vector<std::string>& obj);

int main()
{
  auto arr = std::vector<std::string>{"hi","ab","egg"};
  sort_for_three(arr);
  std::cout<<"now sorted: "<<std::endl;
  for(auto const i:arr)
      std::cout<<i<<std::endl;
  return 0;
}
