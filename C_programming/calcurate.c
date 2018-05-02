//
//  calcurate.c
//  C_programming
//
//  Created by Hyunah on 2018. 4. 29..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include "calcurate.h"


//비트연산
int main() {
    
    //8bit로 변환되어 각자리의 숫자들끼리 비교를 하게 된다.
    
    char a = 12, b = 10;
    
    printf("a & b = %d\n", a & b);  //8
    printf("a | b = %d\n", a | b);  //14
    printf("a ^ b = %d\n", a ^ b);  //6
    printf("~a = %d\n", ~a);    //-13
    
    
    //shift 연산
    char c = 22;
    printf("%i\n", c << 1);
    printf("%i\n", c >> 3);
    
    
}
