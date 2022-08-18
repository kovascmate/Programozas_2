
#include <iostream>
#include "monocikli.h"
#define _(x)  std::cout << #x << std::endl; x

int main() {
_(    Monocikli m1_obj;          )
_(    Monocikli m2_obj = m1_obj; )
_(    return 0;                  )
}
