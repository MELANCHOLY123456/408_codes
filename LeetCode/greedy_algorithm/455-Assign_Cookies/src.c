#include <stdio.h>
#include <stdlib.h>

// 贪心策略: 给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int i = 0;
    for (int j = 0; j < sSize; j++) {
        if (i < gSize && g[i] <= s[j]) {
            i++;
        }
    }
    return i;
}

int main() {
    int g1[] = { 1, 2, 3 };
    int s1[] = { 1, 1 };
    int gSize1 = sizeof(g1) / sizeof(g1[0]);
    int sSize1 = sizeof(s1) / sizeof(s1[0]);
    printf("示例1输出: %d\n", findContentChildren(g1, gSize1, s1, sSize1));

    int g2[] = { 1, 2 };
    int s2[] = { 1, 2, 3 };
    int gSize2 = sizeof(g2) / sizeof(g2[0]);
    int sSize2 = sizeof(s2) / sizeof(s2[0]);
    printf("示例2输出: %d\n", findContentChildren(g2, gSize2, s2, sSize2));
    return 0;
}