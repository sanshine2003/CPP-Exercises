#include "iface.h"

int main(int argc, char *argv[]) {

  iface &ifs = iface::Instance();
  ifs.method(1);
}