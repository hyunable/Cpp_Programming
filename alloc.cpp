//
//  alloc.cpp
//  C++_programming
//
//  Created by Hyunah on 2018. 5. 1..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include "alloc.hpp"
#include <iostream>

using namespace std;

int main() {
    int *arr;
    int len;
    
    cout << "동적 할당할 배열 길이 입력: ";
    cin >> len; //입력한 값을 len에 담는다
    
    arr = new int[len];
    
    for (int i = 0; i < len; i++) {
        arr[i] = len - i;
        
        cout << i << "번째" << arr[i] << endl;
    }
    
    delete[] arr;
}
