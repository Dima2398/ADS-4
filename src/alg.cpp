// Copyright 2021 NNTU-CS
#include <stdio.h> 
#include <stdlib.h>
int comparator(const void* p, const void* q) {
return (*(int*)p - *(int*)q);
}
int countPairs1(int *arr, int len, int value) {
    qsort((void*)arr, len, sizeof(arr[0]), comparator);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value)
                count++;
    }
    if (count)
        return count;
return 0;
}
int countPairs2(int *arr, int len, int value) {
    qsort((void*)arr, len, sizeof(arr[0]), comparator);
    int count = 0;
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            if (arr[i] + arr[j] == value)
                count++;
    }
    if (count)
        return count;
return 0;
}
int countPairs3(int *arr, int len, int value) {
    qsort((void*)arr, len, sizeof(arr[0]), comparator);
    int count = 0;
    int x, left, right, mid;
    for (int i = 0; i < len; i++) {
        left = i + 1;
        right = len - 1;
        x = value - arr[i];
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] < x)
                left = mid + 1;
            else if (arr[mid] > x)
                right = mid - 1;
            else {
                count++;
                int next = mid + 1;
                int prev = mid - 1;
                while (arr[mid] == arr[next]) {
                    count++;
                    next += 1;
                }
                while (arr[mid] == arr[prev]) {
                    count++;
                    prev -= 1;
                 }
                break;
            }
        }
    }
    if (count)
        return count;
return 0;
}
