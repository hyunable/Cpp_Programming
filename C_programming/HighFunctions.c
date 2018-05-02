//
//  HighFunctions.c
//  C_programming
//
//  Created by Hyunah on 2018. 4. 29..
//  Copyright © 2018년 hyunable. All rights reserved.
//

#include <stdio.h>
#include "HighFunctions.h"


//macro 라고 부른다.
#define PI 3.141592     //별칭 붙여주기
#define SQUATE(X) X * X     //메서드와 매우 비슷, 왼쪽 매크로는 오른쪽으로 대체된다고 생각하면 된다.
#define MAX(A,B) (((A) > (B)) ? (A) : (B))

//for문을 매크로로 쓰기
#define FOR(I,S,E) for (int I = S; I <= E, I++)


/* 상수만들기
 * swift :
 * let PI = 3.14
 * C :
 * const float PI = 3.14;
 * # 상수는 대문자를 쓴다는 네이밍 룰이 있다.
 */


// 변수는 아래와 같이 대문자로 표기하며, 변경불가능한 상수이다.
// 넘버로 state를 나타내기보다 훨씬 가독성이 좋고 직관적인 코드를 작성 가능하다.

const int GAMESTATE_GAMEOVER = 3;


/* 열거형
 * 1. 타입선언을 하지 않는다.
 * 2. 0,1,2,3...으로 시작하는 값은 할당하지 않아도 자동으로 카운팅되어 할당된다. (= 스위프트와 동일)
 */

enum EGateState {
    GAMESTATE_MAINMEN = 1,
    GAMESTATE_PLAYING = 2,
    GAMESTATE_PAUSED = 3,
    GAMESTATE_GAMEOVERON = 4
};

//enum EGateState1 {
//    GAMESTATE_MAINMEN,
//    GAMESTATE_PLAYING,
//    GAMESTATE_PAUSED,
//    GAMESTATE_GAMEOVER
//};
//
//
//enum EGateState2 {
//    GAMESTATE_MAINMEN = 1,
//    GAMESTATE_PLAYING,
//    GAMESTATE_PAUSED,
//    GAMESTATE_GAMEOVER
//};





/*
 ** 삼항연산자
 */

int max(int a, int b){
//    if (a>b) return a;
//    return b;
    
    //매크로로 나타낸다면..?
    printf("최댓값 : %d\n", MAX(a, b));
    
    return (a>b) ? a : b;
}

