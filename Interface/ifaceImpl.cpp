#include "iface.h"
#include <iostream>
#include <string>

class ifaceImpl : public iface {
public:
  ifaceImpl() = default;
  ~ifaceImpl() override = default;

  void method(int param) override {
    std::cout << " Method Called" << std::endl;
  }
};

iface &iface::Instance() {
  static ifaceImpl *instance = new ifaceImpl();
  return reinterpret_cast<iface &>(*instance);
}