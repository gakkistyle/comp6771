//
//  Sally.hpp
//  start
//
//  Created by 郑淇文 on 2020/6/1.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#ifndef Sally_hpp
#define Sally_hpp

class Sally
{
public:
    Sally(int a,int b);
    void printCrap();
    void printShiz();
    void printShiz2() const;
    void print();
    ~Sally();
protected:
private:
    int regVar;
    const int constVar;
};

#endif /* Sally_hpp */
