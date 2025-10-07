int cmp(int** a, int** b) {
    return ((*a)[1] - (*b)[1]);
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int*), (int (*)(const void*, const void*))cmp);
    int count = 1;
    int end = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
    }
    return intervalsSize - count;
}