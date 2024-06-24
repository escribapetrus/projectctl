#include <cassert>
#include "db.hpp"

void testDatabase1() {
  Database db = Database("test.db");

  assert(true);
}

int main() {
  testDatabase1();
  return 0;
}
