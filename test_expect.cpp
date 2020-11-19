/*************************************************************************
	> File Name: test_expect.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 三  8/12 20:49:30 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <mytest.h>
using namespace std;

int add(int a, int b) {
    return a + b;  
}


int main() {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(3, 4), 8);
    return 0;
}
