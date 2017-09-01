#include "mpi.h"
#include <stdio.h>


int main(int argc, char **argv)
{
    // Testing MPI_INIT
    if(MPI_Init(NULL, NULL) !=  MPI_SUCCESS){
        printf("[INIT] it does not work!\n");
    }
    printf("[INIT] it works!\n");

    // Testing MPI_RANK
    int world_rank;
    if(MPI_Comm_rank(MPI_COMM_WORLD, &world_rank) !=  MPI_SUCCESS){
        printf("[RANK] it does not work!\n");
    }
    printf("[RANK] it works! Rank: %d\n", world_rank);

    // Testing MPI_SIZE
    int size;
    if(MPI_Comm_size(MPI_COMM_WORLD, &size) !=  MPI_SUCCESS){
        printf("[SIZE] it does not work!\n");
    }
    printf("[SIZE] it works! Size: %d\n", size);


    MPI_Finalize();
}
