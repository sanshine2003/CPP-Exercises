#pragma once

struct iface {
  virtual ~iface() = default;

  static iface &Instance();

  virtual void method(int param) = 0;
};
