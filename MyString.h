/*
 * c++练习-2
 * 字符串类
 * 练习管理资源
 * created by Yang Liu
 * 2016.02.15
 * version: 1.0
 */
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace MY_STRING 
{
    class MyString
    {
    public:
        typedef unsigned int size_type;

        MyString();
        MyString(const char *cp);
        MyString(const MyString& str);
        MyString(char ch, int n = 1);

        MyString& operator=(const MyString& str);
        MyString& operator=(const char *cp);

        const char& operator[](size_type pos) const;
        char& operator[](size_type pos);

        MyString& operator+=(const MyString &rhs);
        MyString& operator+=(const char *cp);
        const MyString operator+(const MyString &rhs) const;
        const MyString operator+(const char *cp) const;

        const MyString substr(int beg, int len) const;

        bool empty(void) const { return data_length == 0; };
        size_type size(void) const { return data_length; };

        ~MyString() { delete[] data; };

        friend std::istream& operator>>(std::istream& in, MyString& str);
        friend std::ostream& operator<<(std::ostream& out, const MyString& str);
        friend std::istream& getline(std::istream& in, MyString& str);
        friend bool operator<(const MyString &lhs, const MyString &rhs);
        friend bool operator<=(const MyString &lhs, const MyString &rhs);
        friend bool operator>(const MyString &lhs, const MyString &rhs);
        friend bool operator>=(const MyString &lhs, const MyString &rhs);
        friend bool operator==(const MyString &lhs, const MyString &rhs);
        friend bool operator!=(const MyString &lhs, const MyString &rhs);

    private:
        size_type data_length;
        char *data;
        //用于getline的字符数组长度
        static const size_type LINE_LIMIT = 1024;

        void init(size_type n, const char* beg = nullptr);
        bool check_range(size_type pos) const;
        void concat(size_type len_r, const char *cp);
    };
}
#endif