#include <stdio.h>

void Reverse(int R[], int start, int end) {
    int i, temp;
    for (i = 0; i < (end - start + 1) / 2; i++) {
        temp = R[start + i];
        R[start + i] = R[end - i];
        R[end - i] = temp;
    }
}

void Converse(int R[], int n, int p) {
    Reverse(R, 0, p - 1);
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testConverse() {
    printf("=== 测试 Converse 函数 ===\n");

    // 测试用例1
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int p1 = 3;

    printf("测试用例1:\n");
    printf("原数组: ");
    printArray(arr1, n1);
    printf("p = %d\n", p1);

    Converse(arr1, n1, p1);
    printf("结果: ");
    printArray(arr1, n1);
    printf("期望: 4 5 6 7 1 2 3\n\n");

    // 测试用例2
    int arr2[] = { 10, 20, 30, 40, 50 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int p2 = 2;

    printf("测试用例2:\n");
    printf("原数组: ");
    printArray(arr2, n2);
    printf("p = %d\n", p2);

    Converse(arr2, n2, p2);
    printf("结果: ");
    printArray(arr2, n2);
    printf("期望: 30 40 50 10 20\n\n");

    // 测试用例3: p = 0
    int arr3[] = { 1, 2, 3 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int p3 = 0;

    printf("测试用例3 (p = 0):\n");
    printf("原数组: ");
    printArray(arr3, n3);
    printf("p = %d\n", p3);

    Converse(arr3, n3, p3);
    printf("结果: ");
    printArray(arr3, n3);
    printf("期望: 1 2 3\n\n");

    // 测试用例4: p = n (数组长度)
    int arr4[] = { 1, 2, 3, 4 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int p4 = 4;

    printf("测试用例4 (p = n):\n");
    printf("原数组: ");
    printArray(arr4, n4);
    printf("p = %d\n", p4);

    Converse(arr4, n4, p4);
    printf("结果: ");
    printArray(arr4, n4);
    printf("期望: 1 2 3 4\n\n");

    // 测试用例5: 单个元素
    int arr5[] = { 99 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int p5 = 1;

    printf("测试用例5 (单个元素):\n");
    printf("原数组: ");
    printArray(arr5, n5);
    printf("p = %d\n", p5);

    Converse(arr5, n5, p5);
    printf("结果: ");
    printArray(arr5, n5);
    printf("期望: 99\n\n");
}

int main(int argc, char const* argv[]) {
    testConverse();
    return 0;
}
