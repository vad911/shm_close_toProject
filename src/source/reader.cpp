

#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#include "Data.h"
#include <iomanip> // for put_time()




int main(int argc, char *argv[])
{
 


  // удалитель shared memory
  struct shm_remove
  {
       // we turn off this struct  for while
       //  shm_remove() {/* shared_memory_object::remove("MySharedMemory"); }
       // ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
  };

  // made object for auto removing shared memory
  shm_remove  remover;

  
  //Open already created shared memory object.
  bi::managed_shared_memory shm (bi::open_only, "MySharedMemory");



// ====================== Читаем структуру map<int, vec<int>> из памяти ========
      // имя объекта которое ищется

      std::string nameMap_data = "MyMap"; 
      
      

      MyMap* pMap;
         
      
      size_t isExist_map = 0;
    

      std::pair< MyMap* ,std::size_t> ret_Data = shm.find<MyMap>(nameMap_data.c_str());
            

      // pVec = ret_Data.first;
      isExist_map = ret_Data.second;
      // =======================================================================
      std::cout << "\n We start to check data class ...";

      if (isExist_map == 1) { 
      std::cout <<"\n!!!Map is found: ";
      MyMap* pMap = ret_Data.first;



      
      for (auto it = (*pMap).begin(); it!=(*pMap).end(); ++it )
      {
           std::cout << "\n Map key:" << (*it).first;
           std::cout << "\n val:" <<(*it).second.Label;
           std::cout << "\n val:" <<(*it).second.X;
           std::cout << "\n val:" <<(*it).second.Y;


           std::cout << "\n now read vector Defects:";
           int count = 0;
           auto it_vec = (*it).second.defects;
          
           for (auto item : it_vec){
             std::cout << "\nvec item url: " << item.URL_address;
             std::cout << "\nvec item size: " << item.size;
             std::cout << "\nvec item width: " << item.width;

           }
        std::cout << "\n\n";
         
      }
        
      

      }
      else{
        std::cout << "\nI can't find string in shared memory";
        std::cout <<"\nRead string size from shared memory: " << isExist_map << std::endl;
      }


      
      
      // закончили проверку

      // =======================================================================

    
  
  return 0;
}



