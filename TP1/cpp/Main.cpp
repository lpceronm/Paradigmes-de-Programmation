/*!
 * \file
 * \brief  Main class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */
// #define TEST_VERSION
#define SERVER_VERSION

#include "TestMain.h"
#include "ServerMain.h"


#ifdef TEST_VERSION
int main(){
  testMain();
}
#endif //TEST_VERSION

#ifdef SERVER_VERSION
int main(){
  serverMain();
}
#endif