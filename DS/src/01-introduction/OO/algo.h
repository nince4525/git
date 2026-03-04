#pragma once

//与类型无关的泛型算法，适用于任意类型容器（但不能是原生数组）的排序。排序算法是冒泡排序法
//第一个类型参数是容器类型，第二类型参数是比较函数类型
template <typename range, typename compare_t>
void sort(range &r, compare_t compare) {
    //对象first、last、i、j都是容器r关联的迭代器。如果迭代器是伪的，那么它们就是原生指针
    typename range::iterator first = r.begin(), last = r.end(), i, j;
    for (i = first; i < last - 1; ++i)
        //注意：last和i都是迭代器（也许就是原生指针），因此last - i计算的结果是整数！
        //因此，j必须是和一个指针进行比较，该指针是在first的基础上加上一个整数，等到一个新的迭代器（指针）
        for (j = first; j < first + (last - i - 1); ++j)
            if (compare(*j, *(j + 1)) > 0)
                std::swap(*j, *(j + 1));
}