#include <stdio.h>

int M_search(int A[], int B[], int n) {
    int s1 = 0, d1 = n - 1, m1;
    int s2 = 0, d2 = n - 1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2]) {
            return A[m1];
        }
        if (A[m1] < B[m2]) {
            // 若元素个数为奇数
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;        // 舍弃A中间点以前的部分且保留中间点
                d2 = m2;        // 舍弃B中间点以后的部分且保留中间点
            }
            // 若元素个数为偶数
            else {
                s1 = m1 + 1;    // 舍弃A中间点及中间点以前的部分
                d2 = m2;        // 舍弃B中间点以后的部分且保留中间点
            }
        }
        else {
            // 若元素个数为奇数
            if ((s1 + d1) % 2 == 0) {
                d1 = m1;        // 舍弃A中间点以后的部分且保留中间点
                s2 = m2;        // 舍弃B中间点以前的部分且保留中间点
            }
            // 若元素个数为偶数
            else {
                d1 = m1;        // 舍弃A中间点以后的部分且保留中间点
                s2 = m2 + 1;    // 舍弃B中间点及中间点以前的部分
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

// 打印数组
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

// 合并数组并排序（用于验证结果）
void mergeAndSort(int A[], int B[], int n, int merged[]) {
    // 简单合并两个数组
    for (int i = 0; i < n; i++) {
        merged[i] = A[i];
        merged[i + n] = B[i];
    }

    // 简单冒泡排序
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }
}

// 测试函数
void test_M_search() {
    printf("=== 测试 M_search 函数 ===\n\n");

    // 测试用例1：题目中的例子
    int A1[] = { 11, 13, 15, 17, 19 };
    int B1[] = { 2, 4, 6, 8, 20 };
    int n1 = 5;
    int merged1[10];

    printf("测试用例1:\n");
    printf("A = "); printArray(A1, n1); printf("\n");
    printf("B = "); printArray(B1, n1); printf("\n");

    int result1 = M_search(A1, B1, n1);
    mergeAndSort(A1, B1, n1, merged1);

    printf("算法结果: %d\n", result1);
    printf("合并后数组: "); printArray(merged1, 2 * n1); printf("\n");
    printf("实际中位数: %d\n", merged1[n1 - 1]); // 第n个元素（0-based）
    printf("期望结果: 11\n");
    printf("测试结果: %s\n\n", result1 == 11 ? "PASS" : "FAIL");

    // 测试用例2：中位数在A中
    int A2[] = { 1, 3, 5, 7, 9 };
    int B2[] = { 2, 4, 6, 8, 10 };
    int n2 = 5;
    int merged2[10];

    printf("测试用例2:\n");
    printf("A = "); printArray(A2, n2); printf("\n");
    printf("B = "); printArray(B2, n2); printf("\n");

    int result2 = M_search(A2, B2, n2);
    mergeAndSort(A2, B2, n2, merged2);

    printf("算法结果: %d\n", result2);
    printf("合并后数组: "); printArray(merged2, 2 * n2); printf("\n");
    printf("实际中位数: %d\n", merged2[n2 - 1]);
    printf("期望结果: 5\n");
    printf("测试结果: %s\n\n", result2 == 5 ? "PASS" : "FAIL");

    // 测试用例3：中位数在B中
    int A3[] = { 1, 2, 3, 4, 5 };
    int B3[] = { 6, 7, 8, 9, 10 };
    int n3 = 5;
    int merged3[10];

    printf("测试用例3:\n");
    printf("A = "); printArray(A3, n3); printf("\n");
    printf("B = "); printArray(B3, n3); printf("\n");

    int result3 = M_search(A3, B3, n3);
    mergeAndSort(A3, B3, n3, merged3);

    printf("算法结果: %d\n", result3);
    printf("合并后数组: "); printArray(merged3, 2 * n3); printf("\n");
    printf("实际中位数: %d\n", merged3[n3 - 1]);
    printf("期望结果: 5\n");
    printf("测试结果: %s\n\n", result3 == 5 ? "PASS" : "FAIL");

    // 测试用例4：有重复元素
    int A4[] = { 1, 1, 3, 3, 5 };
    int B4[] = { 1, 2, 4, 4, 6 };
    int n4 = 5;
    int merged4[10];

    printf("测试用例4:\n");
    printf("A = "); printArray(A4, n4); printf("\n");
    printf("B = "); printArray(B4, n4); printf("\n");

    int result4 = M_search(A4, B4, n4);
    mergeAndSort(A4, B4, n4, merged4);

    printf("算法结果: %d\n", result4);
    printf("合并后数组: "); printArray(merged4, 2 * n4); printf("\n");
    printf("实际中位数: %d\n", merged4[n4 - 1]);
    printf("期望结果: 3\n");
    printf("测试结果: %s\n\n", result4 == 3 ? "PASS" : "FAIL");

    // 测试用例5：偶数长度序列
    int A5[] = { 1, 2, 3, 4 };
    int B5[] = { 5, 6, 7, 8 };
    int n5 = 4;
    int merged5[8];

    printf("测试用例5 (偶数长度):\n");
    printf("A = "); printArray(A5, n5); printf("\n");
    printf("B = "); printArray(B5, n5); printf("\n");

    int result5 = M_search(A5, B5, n5);
    mergeAndSort(A5, B5, n5, merged5);

    printf("算法结果: %d\n", result5);
    printf("合并后数组: "); printArray(merged5, 2 * n5); printf("\n");
    printf("实际中位数: %d\n", merged5[n5 - 1]);
    printf("期望结果: 4\n");
    printf("测试结果: %s\n\n", result5 == 4 ? "PASS" : "FAIL");

    // 测试用例6：单个元素
    int A6[] = { 5 };
    int B6[] = { 3 };
    int n6 = 1;
    int merged6[2];

    printf("测试用例6 (单个元素):\n");
    printf("A = "); printArray(A6, n6); printf("\n");
    printf("B = "); printArray(B6, n6); printf("\n");

    int result6 = M_search(A6, B6, n6);
    mergeAndSort(A6, B6, n6, merged6);

    printf("算法结果: %d\n", result6);
    printf("合并后数组: "); printArray(merged6, 2 * n6); printf("\n");
    printf("实际中位数: %d\n", merged6[n6 - 1]);
    printf("期望结果: 3\n");
    printf("测试结果: %s\n\n", result6 == 3 ? "PASS" : "FAIL");
}

int main() {
    test_M_search();
    return 0;
}