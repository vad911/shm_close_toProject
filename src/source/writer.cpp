
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>


#include <iostream>
#include "Data.h"
#include "myTypes.h"







int main ()
{

  std::cout << "\n start programm ...";

   //Remove shared memory on construction and destruction
   struct shm_remove
   {
      shm_remove() { bi::shared_memory_object::remove("MySharedMemory"); }
     ~shm_remove() { bi::shared_memory_object::remove("MySharedMemory"); }
   } remover;

   //Create shared memory
   bi::managed_shared_memory shm(bi::create_only,"MySharedMemory", 65536);






//============== Ver: ==========================================================
//  Ver:    ipc_string -> class Data -> vec<Data> -> map <int, Data>
/*
def_alloc      alloc_inst      (shm.get_segment_manager());
vecAllocator   vector_allocator (shm.get_segment_manager());

MyMap* mymap = shm.construct<MyMap>("MyMap")(std::less<int>(),alloc_inst);
vec*   myvec = shm.construct<vec>("myvec")(vector_allocator);
// vec *myvec   = segment.construct<vec>("myvec")(std::less<int>(), vectorallocator);


Data dat00(alloc_inst);
dat00.Label = "first----";
dat00.X = 125;
dat00.Y = 205;

Data dat01(alloc_inst);
dat01.Label = "second";
dat01.X = 52;
dat01.Y = 68;

Data dat02(alloc_inst);
dat02.Label = "third - string sadasdasdssssssssssss";
dat02.X = 14;
dat02.Y = 5;


myvec->push_back(dat00);
myvec->push_back(dat01);
myvec->push_back(dat02);


std::pair<const int, vec> my_pair = std::make_pair(5, (*myvec));
mymap->insert(my_pair);
 */
//==============================================================================
//==============================================================================
// Ver:    ipc_string -> class Data -> map <int, Data>

void_alloc  alloc_inst (shm.get_segment_manager());

MyMap* mymap = shm.construct<MyMap>("MyMap")(std::less<int>(),alloc_inst);

/*
Data* pData00   = shm.construct<Data>("data01")(alloc_inst);
Data* pData01   = shm.construct<Data>("data02")(alloc_inst);
Data* pData02   = shm.construct<Data>("data03")(alloc_inst);
*/

Data dat00(alloc_inst);
dat00.Label = "first----";
dat00.X = 125;
dat00.Y = 205;



Defect def00(alloc_inst);
def00.URL_address = "/mnt/source00";
def00.size = 152;
def00.width = 501;

Defect def01(alloc_inst);
def01.URL_address = "/mnt/source00_454";
def01.size = 18;
def01.width = 512;

Defect def02(alloc_inst);
def02.URL_address = "/mnt/source00_sdcard588";
def02.size = 7;
def02.width = 154;



dat00.defects.push_back(def00);
dat00.defects.push_back(def01);
dat00.defects.push_back(def02);
// положим в вектор
/*
dat00.defects.push_back(def00);
dat00.defects.push_back(def01);
dat00.defects.push_back(def02);
*/

Data dat01(alloc_inst);
dat01.Label = "second";
dat01.X = 52;
dat01.Y = 68;

// положим в вектор
Defect def11(alloc_inst);
def11.URL_address = "Program Files/scan";
def11.size = 882;
def11.width = 777;
dat01.defects.push_back(def11);




Data dat02(alloc_inst);
dat02.Label = "third - string sadasdasdssssssssssss";
dat02.X = 14;
dat02.Y = 5;

// положим в вектор
Defect def21(alloc_inst);
def21.URL_address = "shared folder ...";
def21.size  = 555;
def21.width = 888;
dat02.defects.push_back(def21);


std::pair<const int, Data> my_pair00 = std::make_pair(101, dat00);
std::pair<const int, Data> my_pair01 = std::make_pair(102, dat01);
std::pair<const int, Data> my_pair02 = std::make_pair(103, dat02);


mymap->insert(my_pair00);
mymap->insert(my_pair01);
mymap->insert(my_pair02);





   //==========================================================================

  std::cout << "\n server in RAM ...";
  std::cout << "\n press any key to unload server ...";
  int wait_val;
  std::cin >> wait_val;


  std::cout << "\n end programm ..." << std::endl;
   return 0;
}