
#include <optional>
#include <iostream>

std::optional<bool> &set(std::optional<bool> &val, bool v) {
  std::cout << "Address of val - " << &val << std::endl;
  val = v;
  return val;
}

int main(int argc, char *argv[]) {

  std::optional<bool> val = false;

  std::cout << "size of val - " << sizeof(val) << std::endl;
  std::cout << "Address of val - " << &val << std::endl;
  set(val, true);
  std::cout << "val - " << val.value() << std::endl;
}