# cpp-smallutils

Collection of miscellaneous C++ utilities too small to justify their own library.

## Examples

- [lengthof](#lengthof)
- [on_scope_exit](#on_scope_exit)
- [scoped_timer](#scoped_timer)

### lengthof
```cpp
int arr[] { 1, 2, 3, 4, 5 };
std::cout << lengthof(arr); // 5
```

### on_scope_exit
```cpp
int counter = 0;
{
  auto obj = make_on_scope_exit([&]() { counter = 2; });
  counter = 10;
}
std::cout << counter; // 2
```

### scoped_timer
```cpp
{
  scoped_timer<scoped_timer_unit::MILLISECONDS> timer("sleep", std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
// sleep took 200ms
```
