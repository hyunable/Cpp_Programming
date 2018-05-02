//
//  stream.c
//  C_programming
//
//  Created by Hyunah on 2018. 4. 29..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include <stdio.h>
#include "stream.h"

int main(){
    FILE *input, *output;   //파일(스트림) 포인터변수
    int n;
    
    input = fopen("input.txt", "r");    //r : read only, w : write only, a: append - 기존에 입력한 값을 덮어쓰지않고 쓸수있다.
    output = fopen("output.txt", "a");  // 기존에 입력한 값이 전부 출력된다.
    
    if (input != NULL) {
        fscanf(input, "%d", &n);
        fprintf(output, "%d\n", n);
    }
    
    fclose(input);
    fclose(output);
}
