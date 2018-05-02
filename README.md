#  C++ Programming

C에서 OOP개념이 추가된 부분을 위주로 설명했습니다.


<br>



### Class vs Struct
---
- **클래스** (자료형) : 특수한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀
- **객체**(오브젝트) : 그 틀을 이용하여 찍어낸 개체 (변수, 메모리 상의 공간) 



<br>



### 접근제어

---

<u>OOP (*Object-Oriented* Programming) 의 기본 특성</u>

1. 추상화 (Abstraction)
   - 공통의 속성이나 기능을 묶어 이름을 붙이는 것
   - 예를 들어 토끼, 사자 ,강아지를 큰 범위의 객체로 동물이라고 묶는것을 추상화라고 한다.
2. 캡슐화 (Encapsulation)
   - 실제로 구현되는 부분을 외부에 드러나지 않도록 캡슐로 감싸 이용방법만을 알려주는 것.
   - 변수와 함수를 하나로 묶는 것. *객체가 맡은 역할을 수행하기 위한 하나의 목적을 한데 묶는다*
   - 데이터를 외부에서 직접 접근하는 것을 막고 , 메서드를 통해서 접근하게 해주는 것
3. 은닉화
   - 은닉이란 내부 데이터, 내부 연산을 외부에서 접근하지 못하도록 은닉(hiding) 혹은 격리(isolation)시키는 것
   - 변수에 접근지정자를 private 로 지정한다
   - setter , getter 를 사용해 변수의 접근, 제어한다
   - 은닉화는 캡슐화의 한 개념으로 객체 외부에서 객체내의 자료로의 접근을 제한하고 데이터를 수정,조작하는 동작은 내부에 두고 접근(getter),설정(setter)하는 메소드로 결과만 받는것
   - UI 나 인터페이스 설계에서 핵심적인 부분
4. **상속성,재사용**
   - 상위 개념의 특징을 하위 개념이 물려받는 것
   - 재사용으로 인해 코드량이 줄어든다. 
   - 하위 클래스는 상위 클래스가 가지고 있는 모든 자료와 메소드를 물려받아 자유롭게 사용할 수 있지만, 또한 자신만의 자료와 메소드를 추가적으로 덧붙임으로써 새로운 형태의 클래스로 발전하게 된다
5. 다형성
   - Overriding
   - Overloading



<br>



- private : `class`의 기본 접근제어자
- protected
- Public : `struct`의 기본 접근제어자



```c++
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
```



<br>



### this 포인터

---

자기 자신이 속해있는 주솟값을 뜻하며, swift 나 python 의 `self`와 같다.



```c++
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
```



위와 같은 경우 인자 변수의 `num`과 멤버변수 `num`과 구별이 가지 않는다. 이때 직관성을 위해서 this 를 써준다.



<br>



### 생성자

---

멤버 변수 초기화. 처음 선언되었을 때 생성된다. 

```c++
class Complex {
public:
    Complex(double real_, double image_) {	//생성자 
        real = real_;
        image = image_;
    }
    
    Complex() {
        cout << this << ": ~Vector()" << endl;	//소멸자 deinit
    }
    
    double getReal() {	//getter
        return real;
    }
    void setReal(double real_){	//setter
        real = real_
    }
private:
    double real;
    double image;
}


//생성자 호출
int main() {
    Complex c1;	//할당 없이 디폴트 생성자로 인해서 인스턴스 생성
    
    Complex c2 = Complex(2,3);
    Complex c3(2,3);
    Complex c4 = {2,3};
    Complex c5 = Complex{2,3};
    Complex c6{2,3};
}


//생성자 예제 2

int a = 5;
int a(5);

//위 두 수식은 같은 의미이다. 보면 a(5)는 생성자와 같은 로직이다.
//따라서 단순히 값을 대입할 때는 괄호를 사용하여 대입할 수 없다.

//생성자 예제3
Complex() : real(0), image(0) { }
Complex(double real_, double image_) : real(real_), image(image_) { }	//콜론뒤에는 기본적으로 멤버 변수만 올 수 있다.
```



<br>



### 정적멤버(static)

---

인스턴스를 생성하지 않아도 독자적으로 사용 할 수 있는 프로퍼티. 메모리상에 항상 올라와 있다. 

@ 전역 변수/함수는 OOP에서는 최대한 지양한다.

```c++
class ColorList {
    
public:
    //initalizer
    ColorList() : r(0),g(0),b(0) { }
    ColorList(float r,float g, float b) : r(r),g(g),b(b) { }
    
    float getR() { return r; }
    float getG() { return g; }
    float getB() { return b; }
    
    ColorList mixColor(ColorList a, ColorList b){
        return ColorList( a.getR()+b.getR() /2 ,a.getG()+b.getG() /2, a.getB()+b.getB() /2);
    }
    
private:
    float r;
    float g;
    float b;

};



int main() {
    ColorList blue(0,0,1);
    ColorList red(1,0,0);
    //static을 쓸 때는 namespace 처럼 명시를 해준다. # dot(.)으로도 접근가능. ex, red.mixColor(blue, red);
    ColorList mixedColor = ColorList::mixColor(blue, red);
    
    cout << "r = " << mixedColor.getR() << endl;
}
```



<br>



### 상수형 매개변수 & 상수형 메서드

---

매개변수가 들어왔을 때 어떤 코드로 인해서 값이 변경되는 것을 방지하기 위해서 상수형 매개변수를 쓴다.

```c++
void deposit(const int money) const {	//<- 상수 메서드
    //...code
}
```



<br>



### 연산자 오버라이드

---

특정 `행렬+행렬` 과 같은 연산을 진행하고 싶을 때, 연산자 오버라이드를 통해서 구현할 수 있다.



```c++
class Vector {
    Vector operator+(Vector &ref)	//operator+ 라고 명시해준다.
    {
        return Vector(num1+ref.num1, num2+ref.num2);
    }
}
```





<br>



## 동적할당

---

- 정적 할당 : `int a;`
- 동적 할당 : 프로그램 실행 중에 변수를 메모리에 할당하는 것.



```c++
int *a = new int(5);//a에 int형 5를 할당한다.

	*a = 10;	//a라는 변수에 10을 할당한다
	delete a;	//a를 메모리에서 해제한다.

```



<br>



```c++
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
    
    delete[] arr;		//배열 해제!! []를 빼먹지 않도록 주의하자. 하지않으면 arr[0] 값만 해제가됨.
}
```



<br>



### 얕은복사 VS 깊은 복사

---

1. 단순복제는 완전히 동일한 객체,
2. 얉은복사(shallow copy)는 복합객체(껍데기)만 복사, 그 내용은 동일한 객체
3. 깊은복사(deep copy)는 복합객체 복사 + 그 내용도 재귀적으로 복사



```c++
int *a = new int(5);
int *b = new int(3);

a = b;	//얕은 복사(참조만 복사)
*a = *b;	//깊은 복사(값을 복사)


```

