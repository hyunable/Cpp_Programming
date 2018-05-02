//
//  main.c
//  C_programming
//
//  Created by Hyunah on 2018. 4. 24..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include <stdio.h>
#include "HighFunctions.h"

/*
 * 구조체 & 포인터
 * Product : struct name
 * ProductInfo : type name ( 선언시 struct 생략 가능)
 */
typedef struct Product {
    int num;
    char name[100];
    int cost;
} ProductInfo;


int main() {
    // arr = &arr[0]
    // 즉, arr[i] = &arr[i]
    // *(arr + i) = arr[i]
    // +1 을 하면 자료형의 bite 만큼 옮겨간다
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int i=0; i<10; i++) {
        printf("&arr[%d] = %d\t", i, &arr[i]);
        printf("arr + %d = %d\n", i, arr+i);
    }
    
    
    // 배열 포인터
    
    int arr1[3] = {1,2,3};
    
    int (*arr1_ptr)[3]; // 길이가 3인 int형 배열을 가리키는 포인터를 선언
    arr1_ptr = &arr1;
    
    for (int i=0; i<3; i++) {
        printf("%d\n", (*arr1_ptr)[i]);
    }
    
    //2차원 배열과 배열 포인터
    int arr2[2][3] = {{1,2,3},{4,5,6}};
    
    /*
     &arr = &arr[0] = &arr[0][0] 이다.
     배열의 주솟값은 배열이 시작되는 주솟값이고. 따라서 위와 같은 결과가 나온다.
     */
    
    /*
     * 배열 포인터 : 배열을 가리키는 포인터  (*ptr)[4]
     * 포인터 배열 : 포인터들의 배열    *ptr[4]
     */
    
    for (int (*row)[3] = arr2; row < arr2 + 2; row++) {
        for (int (*col)= *row; col < *row + 3; col++) {
            //printf("%d", *col);
            printf("똥: %d\n", **row  +1);
        }
        printf("\n");
    }
    
    
    
    
    //구조체
    // (*a).b == a->b
    ProductInfo snack = {100, "과자", 2000};
    ProductInfo* ptr_snack = &snack;    //snack 구조체의 포인터
    
    printf("pointer: %i, just: %s\n", ptr_snack->cost, ptr_snack->name);
    
    printf("snack %s\n", ptr_snack->name);
    
    
    max(60, 20);
    
}
