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