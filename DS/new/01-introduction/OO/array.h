#pragma once

#include <initializer_list>
#include <exception>

//类模板定义
//此模板定义一个了抽象容器，是一个数组包装类模板。此模板是最终类模板，不能被继承。
//模板的类型参数value_t给出了数组元素的基类型；非类型参数capacity给出容器的最大容量，这个参数可以是默认的。
template <typename value_t, size_t capacity = 128>
class array final {
    //声明类型别名
    using value_type = value_t;
    using pointer = value_type *;
    using reference = value_type &;

private:
    size_t length = 0; //容器实际存储的信息个数

    //容器的内部存储使用原生指针
    pointer storage = nullptr;

public:
    //默认构造函数，为内部指针分配最大容量
    array() noexcept : storage(capacity == 0 ? nullptr : new value_type[capacity]) {}

    //这个重载的构造函数使用了构造函数委托，即先执行默认构造函数，再执行自己
    array(const std::initializer_list<value_type> &l) noexcept : array() {
        for (auto &e : l)
            push_back(e);
    }

    //不整那么复杂，这里没有列出复制控制所需的成员函数
    //复制控制所需的成员函数包括：复制构造函数、转移复制构造函数、重载的赋值运算符函数、转移赋值运算符函数

    //析构函数，释放内存
    ~array() {
        delete[] storage;
    }

    //在尾部添加数据
    //如果超过容量，则抛出异常，退出程序
    void push_back(const value_type &e)
    try {
        if (length == capacity)
            throw std::out_of_range("array is full");

        storage[length++] = e;
    } catch (std::out_of_range &ex) {
        std::cout << ex.what() << std::endl;
        exit(-1);
    }

    //constexpr修饰符说明，函数的返回值是一个“常亮“，以便编译器做出优化
    //const修饰符说明，这个成员函数不修改内部数据
    constexpr size_t size() const {
        return length;
    }
    constexpr bool empty() const {
        return length == 0;
    }

    //定义迭代器类型。迭代器是一种用来模仿原生指针的机制，它的行为非常像是原生指针
    //此容器的迭代器是一种伪迭代器，实际上就是原生指针
    using iterator = pointer;
    //生成首迭代器，指向容器的首元素
    constexpr iterator begin() {
        return storage;
    }
    //生成哨兵迭代器，指向容器的尾元素的“后一个”元素
    constexpr iterator end() {
        return storage + length;
    }
};