//
//  main.cpp
//  C++_programming
//
//  Created by Hyunah on 2018. 4. 29..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include <iostream>

using namespace std;   //-> namespace 소속 생략 가능, 단 모호성이 생기는 경우 생략 불가 (ex, 두 네임스페이스간에 같은 이름의 함수 존재시)

/*
 * overload 지원
 * 디폴트 값은 오른쪽에서 부터 채워나가야 한다.
 */

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double &a, double &b) {   //참조값을 swappings
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(int* (&a), int* (&b)) {   //포인터의 값을 swapping
    int *tmp = a;
    a = b;
    b = tmp;
}


//접근제어

struct TV {
private:
    bool powerOn;
    int channel;
    int volume;
public:
    void on() {
        powerOn = true;
        cout << "turn on the TV" << endl;
    }
};




//this pointer
class changeValue {
private:
    int num;
public:
    void change(int num){
        this->num = 200;
        num = 105;
    }
};


int main() {
    int arr[] = { 1,2,3,4,5,6};
    
    for (int &n : arr) {
        cout << n << ' ';
        n++;
    }
    
    //범위 기반 for 문
    for (int n : arr) {
        //C++의 출력형태
        cout << n << endl;  //endl -> end+Line
    }
    
    
    /*
     * r-Value(휘발성 식), l-value(지속적 식)
     * 모든 C++ 식은 lvalue 또는 rvalue입니다. lvalue는 단일 식을 넘어 지속되는 개체를 참조합니다.
     * lvalue를 이름이 있는 개체로 생각할 수 있습니다. 수정할 수 없는(const) 변수를 비롯한 모든 변수가 lvalue입니다.
     * rvalue는 rvalue를 사용하는 식 외에서는 유지되지 않는 임시 값입니다.
     * lvalue와 rvalue 간의 차이를 더 자세히 알아보려면 다음 예제를 참조하십시오.
     * &&
     */


}
