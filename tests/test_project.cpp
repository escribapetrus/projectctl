#include <cassert>
#include "project.hpp"

void testProject1() {
  Project p = Project("1234", "testproject", "testlocation/");

  assert(p.get_id() == "1234");
  assert(p.get_name() == "testproject");
  assert(p.get_location() == "testlocation/");
}

int main() {
  testProject1();
  return 0;
}
