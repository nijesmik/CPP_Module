# Exception

## `what()`

예외 객체에서 호출되었을 때 해당 예외에 대한 설명을 반환한다.

```c++
virtual const char *what() const throw();
```

- `virtual`: Override하여 예외 객체가 어떤 상황에서 발생했는지 자세히 설명할 수 있다.
- `const char *`: 예외 메시지를 반환하므로 리턴 타입은 `const char *`이다.
- `throw()`: 함수가 어떤 예외도 던지지 않음을 나타낸다. C++11부터 `noexcept` 키워드로 대체되었다.