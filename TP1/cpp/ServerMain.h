/*!
 * \file
 * \brief  Server Main class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */

#ifndef SERVER_M
#define SERVER_M

#include <iostream>
#include <memory>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Store.h"


using namespace std;
const int PORT = 3331;


int serverMain(){
  int *chap2 = new int[3]{1, 2, 3};
  int *chap = new int[12]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Sst store(new Store());
  Smt p = store->createPhoto("IronMan", "photo/ironman.png", 1, 1 + 2.0);
  Smt p1 = store->createPhoto("Sea", "photo/sea.png", 1.02, 3.1+ 2.0);
  Smt v1 = store->createVideo("Promo1", "video/promo.mp4", 11);
  Smt f = store->createFilm("Harry", "video/harry.mp4", 20, 12, chap);
  Smt f2 = store->createFilm("Target", "video/video.mp4", 20, 3, chap2);

  p.reset();
  p1.reset();
  v1.reset();
  f.reset();
  f2.reset();


  // create a TCP server
    shared_ptr<TCPServer> server(new TCPServer());

    //create a non empty Store
    // Set sever callback as the dedicated function of the Store previouslt created.
    server->setCallback(*store, &Store::processRequest);

    // launch the server (loop)
    cout << "Starting Server on port " << PORT << endl;

    //possible server error:
    int status = server->run(PORT);
    if (status < 0) { cerr << "Could not start Server on port " << PORT << endl; return 1;}

    return 0;

}
#endif