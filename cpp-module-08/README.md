# `std::stack`

- `std::stack`은 내부적으로 `std::vector`나 `std::deque` 같은 다른 컨테이너를 사용하여 요소를 저장한다.
- 내부 컨테이너의 실제 타입은 `std::stack<T>::container_type`을 통해 접근할 수 있다.
- `std::stack<T>::c`는 `std::stack` 클래스의 `protected`된 멤버로, 내부 컨테이너에 접근할 수 있게 한다.