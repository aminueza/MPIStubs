#include "mpi.h"
#include <stdio.h>


int main(int argc, char **argv)
{
  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  printf("it works!\n");
  MPI_Finalize();
}
