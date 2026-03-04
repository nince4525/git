#include <iostream>
#include <string>

#include "array.h"
#include "algo.h"

//定义雇员信息类
struct employee_t {
    //重载的构造函数
    employee_t() {}
    employee_t(int _id, const std::string &_name) : id(_id), name(_name) {}

    //静态成员，用于排序等操作用到的比较操作
    //运算符 <=> 是C++20新增的，用于三向比较
    static auto compare_id(const employee_t &a, const employee_t &b) {
        return a.id <=> b.id;
    }
    static auto compare_name(const employee_t &a, const employee_t &b) {
        return a.name <=> b.name;
    }

    //声明友元函数。友元函数可以直接访问类的任意成员
    //这个友元函数是一个重载的输出运算符函数
    friend std::ostream &operator<<(std::ostream &os, const employee_t &e);

private:
    int id;
    std::string name;
};

//为employee_t类型重载的输出运算符函数
std::ostream &operator<<(std::ostream &os, const employee_t &e) {
    return os << e.id << '\t' << e.name;
}

int main() {
    using emp_array = array<employee_t, 5>;
    emp_array el{{1005, "xyz"},
        {1003, "abc"},
        {1004, "mno"},
        {1002, "def"},
        {1001, "rst"}};
    //定义一个用于遍历容器的泛型lambda表达式
    auto print_r = [](auto & l) {
        for (auto &e : l)
            std::cout << e << std::endl;
    };

    sort(el, employee_t::compare_id);
    print_r(el);

    std::cout << "---------------" << std::endl;

    sort(el, employee_t::compare_name);
    print_r(el);

    std::cout << "---------------" << std::endl;

    array<float, 6> fa{1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    print_r(fa);

    return 0;
}
