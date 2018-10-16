
// #define TEST_VERSION
#define SERVER_VERSION

#include <iostream>
#include <memory>

#include "TestMain.h"
#include "ServerMain.h"


#ifdef TEST_VERSION
int main(){
  testMain();
  return 0;
}
#endif //TEST_VERSION

#ifdef SERVER_VERSION
int main(){
  serverMain();
  return 0;
}
#endif