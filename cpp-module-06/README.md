# `reinterpret_cast`

`reinterpret_cast`는 실제로 데이터의 형식을 변경하지 않고 단지 메모리 상에서의 해석 방식을 변경한다.

일반적으로 다음과 같은 상황에서 사용될 수 있다:

- 서로 관련 없는 포인터 타입 간의 변환 (예: 포인터를 정수로 변환하거나 그 반대)
- 객체의 주소를 `void` 포인터로 변환하거나 `void` 포인터를 다른 포인터 타입으로 변환하는 경우
- 비트 단위로 메모리 블록을 해석해야 할 때 (예: 네트워크 패킷 처리)

# `dynamic_cast`

`dynamic_cast`는 런타임에 타입을 확인하고, 타입이 맞으면 다운캐스팅(downcasting)을 수행하고,
타입이 틀리면 `nullptr`를 반환하거나 예외(std::bad_cast)를 발생시킨다.

```c++
dynamic_cast<Derived *>(base_ptr); // nullptr if failed
// or
dynamic_cast<Derived &>(base_ref); // std::bad_cast if failed
```

# `static_cast`

`static_cast`는 컴파일 타임에 타입 변환을 수행한다. <br>
주로 명시적인 타입 변환이 필요할 때 사용되며, 아래와 같은 다양한 상황에서 유용하게 사용된다:

1. 기본 자료형 간의 변환
    - 예: `int`를 `double`로, `float`를 `int`로 변환하는 경우

2. 상속 계층 구조에서의 변환
    - 자식 클래스 객체를 부모 클래스 포인터나 참조자로 변환
    - 반대로 부모 클래스 포인터를 자식 클래스 포인터로 변환할 때도 사용 가능하지만, 이 경우 자식 클래스의 실제 타입을 확신할 수 있을 때만 사용해야 한다.

3. `void` 포인터와 다른 포인터 타입 간의 변환
    - 예: `void *`를 특정 타입의 포인터로 변환

4. 열거형과 정수형 간의 변환
    - 예: 열거형 값을 정수형으로 변환하거나 그 반대의 경우

```c++
// 기본 자료형 변환
int a = 10;
double b = static_cast<double>(a);

// 상속 계층 구조에서의 변환
Derived derived;
Base *basePtr = static_cast<Base *>(&derived);

// void 포인터와 다른 포인터 타입 간의 변환
void *voidPtr = basePtr;
Base *basePtr2 = static_cast<Base *>(voidPtr);

// 열거형과 정수형 간의 변환
enum Color { RED, GREEN, BLUE };
Color color = GREEN;
int colorInt = static_cast<int>(color);
```

### 주의사항

- static_cast는 타입 변환의 안전성을 보장하지 않는다. 즉, 잘못된 타입으로 캐스팅을 시도하면 예상치 못한 동작이나 런타임 오류가 발생할 수 있다.
- 상속 관계에서 부모 클래스 포인터를 자식 클래스 포인터로 캐스팅할 때는 타입 안전성을 항상 염두에 두어야 한다. 잘못된 캐스팅은 정의되지 않은 동작을 초래할 수 있다.
