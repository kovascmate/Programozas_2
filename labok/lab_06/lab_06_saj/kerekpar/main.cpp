



#include <iostream>
#include "monocikli.h"
#define _(x)  std::cout << #x << std::endl; x

int main() {
_(    Monocikli m1_obj;          )
_(    m1_obj.kiir();             )
_(    Monocikli m2_obj = m1_obj; )
_(    m2_obj.kiir();             )
_(    return 0;                  )
}
