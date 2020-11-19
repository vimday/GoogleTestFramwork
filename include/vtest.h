/*
 * @Author      :vimday
 * @Desc        :a toy gtest named vtest
 * @Url         :
 * @File Name   :vtest.h
 * @Created Time:2020-11-19 15:42:55
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <cstdio>
#include <vector>
#ifndef _VTEST_H
#define _VTEST_H

#define COLOR(msg, code) "\033[1;" #code "m" msg "\033[0m"
#define RED(msg) COLOR(msg, 31)
#define GREEN(msg) COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg) COLOR(msg, 34)

#define EXPECT(a, comp, b)                                                             \
    {                                                                                  \
        if (!((a)comp(b))) {                                                           \
            printf(RED("%s:%s.%d: error\n"), __FILE__, __PRETTY_FUNCTION__, __LINE__); \
        }                                                                              \
    }
#define EXPECT_EQ(a, b) EXPECT(a, ==, b)
#define EXPECT_NE(a, b) EXPECT(a, !=, b)
#define EXPECT_LT(a, b) EXPECT(a, <, b)
#define EXPECT_LE(a, b) EXPECT(a, <=, b)
#define EXPECT_GT(a, b) EXPECT(a, >, b)
#define EXPECT_GE(a, b) EXPECT(a, >=, b)
struct _vTest {
    void (*func)();
    const char *name;
};
std::vector<_vTest> func_arr;
void add_test(void (*func)(), const char *name) {
    func_arr.push_back({func, name});
}
#define TEST(a, b)                                      \
    void a##_##b();                                     \
    __attribute__((constructor)) void reg_##a##_##b() { \
        add_test(a##_##b, #a "." #b);                   \
    }                                                   \
    void a##_##b()

int RUN_ALL_TESTS() {
    for (_vTest &t : func_arr) {
        printf(GREEN("[ RUN ]") " %s\n", t.name);
        t.func();
    }
    return 0;
}

#endif