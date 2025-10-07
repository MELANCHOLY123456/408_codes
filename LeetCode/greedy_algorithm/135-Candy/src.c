#include <stdio.h>

int candy(int* ratings, int ratingsSize) {
    int left[ratingsSize];
    for (int i = 0; i < ratingsSize; i++) {
        if (i > 0 && ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
        else {
            left[i] = 1;
        }
    }
    int right = 0;
    int res = 0;
    for (int i = ratingsSize - 1; i >= 0; i--) {
        if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1]) {
            right++;
        }
        else {
            right = 1;
        }
        res += (left[i] > right) ? left[i] : right;
    }
    return res;
}

int main() {
    int ratings1[] = { 1, 0, 2 };
    int ratingsSize1 = sizeof(ratings1) / sizeof(ratings1[0]);
    printf("示例1输出: %d\n", candy(ratings1, ratingsSize1));

    int ratings2[] = { 3, 2, 1, 1, 2 };
    int ratingsSize2 = sizeof(ratings2) / sizeof(ratings2[0]);
    printf("示例2输出: %d\n", candy(ratings2, ratingsSize2));

    return 0;
}