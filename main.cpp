/*
 * c++练习-2
 * 字符串类
 * 练习管理资源
 * created by Yang Liu
 * 2016.02.15
 * version: 1.0
 */
#include <iostream>
#include "MyString.h"

int main()
{
    using MY_STRING::MyString;
    
    //初始化
    std::cout<<"1. Initialze:"<<std::endl;
    MyString str1;
    std::cout<<"str1 = "<<str1<<std::endl;
    MyString str2("hello");
    std::cout<<"str2 = "<<str2<<std::endl;   
    MyString str3(str2);
    std::cout<<"str3 = "<<str3<<std::endl;  
    MyString str4('x',10);
    std::cout<<"str4 = "<<str4<<std::endl;
    
    //赋值
    std::cout<<"2. Assignment:"<<std::endl;
    str3 = str4;
    std::cout<<"str3 = "<<str3<<std::endl;
    str3 = "world";
    std::cout<<"str3 = "<<str3<<std::endl;

    //[]
    std::cout<<"3. Access:"<<std::endl;
    std::cout<<"str2[1] = "<<str2[1]<<std::endl;
    
    //+
    std::cout<<"4. Concat:"<<std::endl;
    std::cout<<"str2+str3: "<<str2+str3<<std::endl;
    str2 += str3;
    std::cout<<"str2 += str3: "<<str2<<std::endl;
    
    //substr
    std::cout<<"5. Substr:"<<std::endl;
    std::cout<<"str2.substr(1,3): "<<str2.substr(1,3)<<std::endl;
    std::cout<<"str4.substr(5,-3): "<<str4.substr(5,-3)<<std::endl;
    
    //empty,size
    std::cout<<"6. Empty:"<<std::endl;
    std::cout<<"str1 is"<<(str1.empty()? "":" not")<<" empty."<<std::endl;
    std::cout<<"7. Size:"<<std::endl;
    std::cout<<"Length of str3 is "<<str3.size()<<std::endl;
    
    //逻辑
    std::cout<<"8. Logical Operations:"<<std::endl;
    str1 = "abc";
    str2 = "ABC";
    str3 = "abc";
    str4 = "abcde";
    std::cout<<"str1 "<<(str1<str2? "<":">=")<<" str2"<<std::endl;
    std::cout<<"str1 "<<(str1==str2? "=":"<>")<<" str2"<<std::endl;
    std::cout<<"str1 "<<(str1==str3? "=":"<>")<<" str3"<<std::endl;
    std::cout<<"str1 "<<(str1<str4? "<":">=")<<" str4"<<std::endl; 
    
    //输入
    std::cout<<"9. Input:"<<std::endl;
    std::cout << "Plz input a line: ";
    getline(std::cin, str1);
    std::cout << "Your line is: " << str1 << std::endl;
    std::cout << "Plz input a word: ";
    std::cin>>str1;
    std::cout<<"Your word is: "<<str1<<std::endl;

    return 0;
}