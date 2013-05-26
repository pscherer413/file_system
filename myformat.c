#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "file_system.h"
#include "mydisk.h"

int main(int argc, char** argv){
   if(argc != 2) {
      printf("Usage: myformat <diskname>\n");
      return 1;
   }
   char *disk_name = argv[1];
   assert(disk_name);
   disk_t disk = opendisk(disk_name);
   write_super_block(disk);
   write_root_dir(disk);
   write_block_map(disk);
   return 0;
}