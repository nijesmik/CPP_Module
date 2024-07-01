# Exception

## `what()`

예외 객체에서 호출되었을 때 해당 예외에 대한 설명을 반환한다.

```c++
virtual const char *what() const throw();
```

- `virtual`: Override하여 예외 객체가 어떤 상황에서 발생했는지 자세히 설명할 수 있다.
- `const char *`: 예외 메시지를 반환하므로 리턴 타입은 `const char *`이다.
- `throw()`: 함수가 어떤 예외도 던지지 않음을 나타낸다. C++11부터 `noexcept` 키워드로 대체되었다.

# Forward Declaration

클래스의 정의를 포함하지 않고, 클래스의 이름만 알려주는 방법이다. <br>
주로 헤더 파일 간의 순환 종속성을 피하기 위해 사용된다.

### Bureaucrat.hpp

```c++
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp" 

class Bureaucrat {
public:
    void signForm(Form &form); 
};

#endif
```

### Form.hpp

```c++
#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat; // Forward Declaration

class Form {
public:
    void beSigned(const Bureaucrat &bureaucrat);
};

#endif
```

## 주의사항

1. 포인터와 참조만 사용 가능하다.
2. 구현 파일에서 클래스 정의를 포함해야 한다.

### Form.cpp

```c++
#include "Form.hpp"
#include "Bureaucrat.hpp" // Bureaucrat 클래스 정의 포함

void Form::beSigned(const Bureaucrat &bureaucrat) {
    // ...
}
```

# `const_cast`

포인터(pointer) 또는 참조형(reference)의 상수성(constness)를 일시적으로 무시하기 위해 사용하는 타입 캐스트 연산자이다.

```c++
const_cast<type>(expression);
```

## 주의사항

`const_cast`를 사용하여 상수성을 제거한 후, 해당 객체를 수정하면 정의되지 않은 동작(undefined behavior)이 발생할 수 있다. <br>
컴파일러에 따라 프로그램이 충돌하거나 예기치 않은 결과를 초래할 수 있다.

```c++
int main() {
    const int a = 10;
    int &b = const_cast<int &>(a);
    b = 20; // undefined behavior, a는 원래 const로 선언됨

    std::cout << a << std::endl; // 결과는 컴파일러에 따라 다를 수 있음
    return 0;
}
```
