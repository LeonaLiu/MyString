/*
 * c++练习-2
 * 字符串类
 * 练习管理资源
 * created by Yang Liu
 * 2016.02.15
 * version: 1.0
 */
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string.h>
#include "MyString.h"

namespace MY_STRING
{
    //默认构造
    MyString::MyString()
    {
        init(0);
    }

    //字符数组构造
    MyString::MyString(const char *cp)
    {
        init(strlen(cp), cp);
    }

    //拷贝构造
    MyString::MyString(const MyString& str)
    {
        init(str.size(), str.data);
    }

    //初始化，用于默认和拷贝构造,赋值
    void MyString::init(size_type n, const char* beg)
    {
        data_length = n;
        data = new char[data_length + 1];
        if (data_length > 0)
        {
            std::copy_n(beg, data_length, data);
        }
        data[data_length] = '\0';
    }

    //重复字符构造
    MyString::MyString(char ch, int n)
    {
        try {
            if (n <= 0)
            {
                //不能对n<=0的情况初始化
                throw std::runtime_error
                    ("MyString: Initialization requires positive number of characters.");
            }

            data_length = n;
            data = new char[data_length + 1];
            std::fill_n(data, data_length, ch);
            data[data_length] = '\0';
        }
        catch (std::runtime_error &err)
        {
            std::cout << err.what() << std::endl << "Plz try again." << std::endl;
            exit(1);
        }
    }

    //拷贝赋值
    MyString& MyString::operator=(const MyString& str)
    {
        if (*this == str)
        {
            return *this;
        }
        char* old_data = data;//防止new发生异常导致的内存泄露
        init(str.size(), str.data);
        delete[] old_data;
        return *this;
    }

    //字符串赋值
    MyString& MyString::operator=(const char *cp)
    {
        char* old_data = data;
        init(strlen(cp), cp);
        delete[] old_data;
        return *this;
    }

    //访问字符数组 const
    const char& MyString::operator[](size_type pos) const
    {
        try
        {
            if (!check_range(pos)) //检查pos是否合法
            {
                throw std::runtime_error("MyString[]: out of range.");
            }
            return data[pos];
        }
        catch (std::runtime_error &err)
        {
            std::cout << err.what() << std::endl << "Plz try again." << std::endl;
            exit(1);
        }
    }

    //访问字符数组 non-const
    char& MyString::operator[](size_type pos)
    {
        return const_cast<char&>(
            static_cast<const MyString&>(*this)
            [pos]
        );
    }

    //检查访问范围
    bool MyString::check_range(size_type pos) const
    {
        return pos < data_length;
    }

    //加等
    MyString& MyString::operator+=(const MyString &rhs)
    {
        concat(rhs.size(), rhs.data);
        return *this;
    }

    //加等
    MyString& MyString::operator+=(const char *cp)
    {
        concat(strlen(cp), cp);
        return *this;
    }

    //连接两个MyString
    void MyString::concat(size_type len_cp, const char *cp)
    {
        size_type new_len = data_length + len_cp;
        char *new_data = new char[new_len + 1];

        std::copy_n(data, data_length, new_data);
        std::copy_n(cp, len_cp, new_data+data_length);
        new_data[new_len] = '\0';

        delete[] data;
        data = new_data;
        data_length = new_len;
    }

    //加法
    const MyString MyString::operator+(const MyString &rhs) const
    {
        MyString re_str(*this);
        re_str += rhs;
        return re_str;
    }

    //加法
    const MyString MyString::operator+(const char *cp) const
    {
        MyString re_str(*this);
        re_str += cp;
        return re_str;
    }

    //提取子字符串
    const MyString MyString::substr(int beg, int len) const
    {
        if (len < 0) //重新定位起始位置beg
        {
            beg += len;
            len = -len;
        }

        try
        {
            if (!check_range(beg)) //检查beg是否合法
            {
                throw std::runtime_error("MyString.substr: out of range.");
            }
            //beg+len可能超过字符串长度
            len = (beg + len <= data_length) ? len : data_length - beg;

            MyString re_str;
            re_str.init(len, data + beg);

            return re_str;
        }
        catch (std::runtime_error &err)
        {
            std::cout << err.what() << std::endl << "Plz try again." << std::endl;
            exit(1);
        }
    }

    //输入
    std::istream& operator>>(std::istream& in, MyString& str)
    {
        char temp[MyString::LINE_LIMIT];
        char ch;
        //去除多余的空格和换行
        while (in.get(ch) && (ch == ' ' || ch == '\n'));

        int i = 0;
        do
        {
            //遇到空格/换行，结束输入
            if (ch == ' ' || ch == '\n')
            {
                break;
            }
            //输入超过字符数组范围
            if (i >= MyString::LINE_LIMIT - 1)
            {
                //放回多余的字符
                in.putback(ch);
                break;
            }
            temp[i++] = ch;
        } while (in.get(ch));

        temp[i] = '\0';
        str = temp;
        return in;
    }

    //输入一行
    std::istream& getline(std::istream& in, MyString& str)
    {
        char temp[MyString::LINE_LIMIT];
        in.getline(temp, MyString::LINE_LIMIT, '\n');
        if (in)
        {
            str = temp;
        }

        return in;
    }

    //输出
    std::ostream& operator<<(std::ostream& out, const MyString& str)
    {
        out << str.data;
        return out;
    }

    //小于
    bool operator<(const MyString &lhs, const MyString &rhs)
    {
        return (strcmp(lhs.data, rhs.data) < 0);
    }

    //小于等于
    bool operator<=(const MyString &lhs, const MyString &rhs)
    {
        return lhs < rhs || lhs == rhs;
    }

    //大于
    bool operator>(const MyString &lhs, const MyString &rhs)
    {
        return rhs < lhs;
    }

    //大于等于
    bool operator>=(const MyString &lhs, const MyString &rhs)
    {
        return rhs < lhs || lhs == rhs;
    }

    //相等
    bool operator==(const MyString &lhs, const MyString &rhs)
    {
        return (strcmp(lhs.data, rhs.data) == 0);
    }

    //不等
    bool operator!=(const MyString &lhs, const MyString &rhs)
    {
        return !(lhs == rhs);
    }
}
