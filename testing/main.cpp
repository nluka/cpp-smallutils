#include <thread>
#include <iostream>

#include "../scoped_timer.hpp"
#include "../on_scope_exit.hpp"
#include "../lengthof.hpp"
#include "ntest.hpp"

int main() {
  ntest::init();

  {
    size_t counter = 0;
    {
      auto const obj = make_on_scope_exit([&counter]() { ++counter; });
      ntest::assert_int64(0, counter);
    }
    ntest::assert_int64(1, counter);
  }

  {
    scoped_timer<scoped_timer_unit::MILLISECONDS> timer("200ms sleep", std::cout);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  {
    int arr[3] {};
    ntest::assert_uint64(3, lengthof(arr));
  }

  auto const res = ntest::generate_report("smallutils");
  std::cout << res.num_passes << " passed, " << res.num_fails << " failed\n";
}
