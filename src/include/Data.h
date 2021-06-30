#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

#include "myTypes.h"  // определяю свои типы


class Defect{

   public:
   int size;
   int width;
   
   ipc_string URL_address;

   Defect(void_alloc alloc) : URL_address(alloc) {}
};



class Data {
   public:
   int X;
   int Y;
   
   ipc_string Label;
   
   //Defect def;

   ipc_vector_Defect defects;   // vector with class Defect

   Data(void_alloc alloc) : Label(alloc),  defects(alloc) {}
    
};



#endif // DATA_H