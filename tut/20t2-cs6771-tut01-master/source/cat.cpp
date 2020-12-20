#include <iostream>

auto main()->int{
    //c-style
//    char buffer[100];
//    fgets(buffer,100,stdin);
//    printf("%s",buffer);
//
    //c++ style
    auto a = std::string(""); //do not care about size
    std::cin>>a;
    std::cout<<a<<"\n";
    return 0;
}
