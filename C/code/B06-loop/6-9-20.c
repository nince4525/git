/*
 * Copyright (c) 白忠建 电子科技大学信息与软件工程学院
 * C语言程序示例 is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

/*
 * 有一家奇怪的点心店，只出售6只、9只、20只三种包装的点心，不拆零。
 * 请问这三种包装不能组合的最大数是多少？
 *
 */

/**
 * @file 6-9-20.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 这个程序演示了“穷举法”的算法设计思路
 * @version 1.0
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * @brief   测试一个整数n能否被6、9、20组合
 * @param   n：待测试的证书
 * @return  bool：如果能，返回true；否则返回false
 */

/**
 * @brief 测试一个整数n能否被6、9、20组合
 *
 * @param n 待测试的整数
 * @return true 能被组合
 * @return false 不能被组合
 */
bool test(int n) {
    int _20, _9, _6; // _20：20只包装的数量，_9：9只包装的数量，_6：6只包装的数量
    for (_20 = 0; _20 <= n / 20; ++_20)
        for (_9 = 0; _9 <= n / 9; ++_9) {
            _6 = n - _20 * 20 - _9 * 9; // 剩下的就是6只包装的总数量
            if (_6 >= 0 && _6 % 6 == 0) // 如果_6不是负数且能够被6整除，那么n一定能被组合
                return true;
        }

    // 都试过了，n不能被组合
    return false;
}

int main(int argc, char *argv[]) {
    int n = 6;

    if (argc == 2) { // 带一个命令行参数，这个参数是上限
        int limit = atoi(argv[1]);
        if (limit < 100) limit = 100;
        printf("not rigorously: \n");

        /*
         * 根据题意，这个不能组合的最大数应该不大，并且不超过100
         * 因此，对6~100以内的每一个数，去测试它是否能被组合
         * 如果不能，则打印这个数。打印结果的最后一个数就应该是最大值了
         */
        for (; n < limit; ++n)
            if (!test(n)) printf(" %d", n);
    } else {
        printf("rigorously: \n");

        /*
         * 前面的思路并不科学，它建立在一个没有被证明的基础上
         * 因此，我们换一个思路
         * 我们还是从6开始，对每一个数进行测试
         * 假设从m起，以后连续6个数都能被组合，那么可以断言：以后的每一个数都可以被组合（这个可以被证明是正确的）
         * 那么，m-1就是不能组合的最大数
         */
        while (true) {
            if (!test(n++)) continue; // 如果n不能被组合，则马上进行下一次循环，测试n+1。注意后缀++的作用
            if (!test(n++)) continue; // 如果n能被组合，那么这行测试n+1是否能被组合。以下四行同理。
            if (!test(n++)) continue;
            if (!test(n++)) continue;
            if (!test(n++)) continue;
            if (!test(n)) continue;

            break; // 这条语句能被执行，则一定是连续6个数都能被组合
        }

        printf("%d", n - 6);  // 因为n已经自加的5次，所以结果就是n-6
    }
    
    putchar('\n'); // 最后输出一个换行

    return 0;
}