#include <iostream>

int main() {
    auto i = 0;
    auto j = 0;
    if(not(std::cin>>i>>j)){
        std::cerr<<"Something went wrong while reading an integer, bailing...\n";
        return 1;
    }
    std::cout<<"Sum: "<<i+j<<std::endl;
	return 0;
}
