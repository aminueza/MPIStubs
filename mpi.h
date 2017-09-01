#ifndef MPI_STUBS
#define MPI_STUBS

typedef int MPI_Comm;
typedef int MPI_Request;

typedef int MPI_Datatype;
typedef int MPI_Op;

typedef int MPI_Fint;
typedef int MPI_Aint;

typedef int MPI_Group;

/* defs for MPI stubs */

#define MPI_COMM_WORLD (1)
#define MPI_COMM_NULL (0)

/* MPI_GROUP_EMPTY and MPI_GROUP_NULL must not conflict with MPI_GROUP_ONE */
#define MPI_GROUP_EMPTY (-1)
#define MPI_GROUP_NULL (0)

#define MPI_FAILURE 1
#define MPI_COUNT 3

/* The type's value is its size in bytes */

#define MPI_BYTE            (sizeof(char))
#define MPI_CHAR            (sizeof(char))
#define MPI_UNSIGNED_CHAR   (sizeof(unsigned char))
#define MPI_SHORT           (sizeof(short))
#define MPI_UNSIGNED_SHORT  (sizeof(unsigned short))
#define MPI_INT             (sizeof(int))
#define MPI_UNSIGNED        (sizeof(unsigned))
#define MPI_LONG            (sizeof(long))
#define MPI_UNSIGNED_LONG   (sizeof(unsigned long))
#define MPI_FLOAT           (sizeof(float))
#define MPI_DOUBLE          (sizeof(double))
#define MPI_LONG_DOUBLE     (sizeof(long double))
#define MPI_UNSIGNED_LONG_LONG  (sizeof(unsigned long long))

/* types for MINLOC and MAXLOC */
#define MPI_FLOAT_INT         (sizeof(struct{float a; int b;}))
#define MPI_DOUBLE_INT        ((MPI_Datatype)18)
#define MPI_LONG_INT          (sizeof(struct{long a; int b;}))
#define MPI_2INT              (sizeof(struct{int a; int b;}))
#define MPI_SHORT_INT         (sizeof (struct{short a; int b;}))
#define MPI_LONG_DOUBLE_INT   (sizeof (struct{long double a; int b;}))

#define MPI_SUM 1
#define MPI_MAX 2
#define MPI_MIN 3
#define MPI_MAXLOC 4
#define MPI_MINLOC 5
#define MPI_PRODUCT 4

/* Results of the compare operations */
#define MPI_IDENT     0
#define MPI_CONGRUENT 1
#define MPI_SIMILAR   2
#define MPI_UNEQUAL   3

#define MPI_UNDEFINED (-1)

#define MPI_ANY_SOURCE (-1)
#define MPI_ANY_TAG (-1)

#define MPI_Comm int
#define MPI_Request int
#define MPI_Datatype int
#define MPI_Op int

#define MPI_MAX_PROCESSOR_NAME (128)
#define MPI_MAX_ERROR_STRING (128)

/* use C bindings for MPI interface */

#ifdef __cplusplus
extern "C" {
#endif

/* MPI data structs */
struct _MPI_Status {
  int count;
  int MPI_SOURCE, MPI_ERROR, MPI_TAG;
  int private_count;
};
typedef struct _MPI_Status MPI_Status;

#define MPI_STATUS_IGNORE (MPI_Status *)0
#define MPI_STATUSES_IGNORE (MPI_Status *)0

/* These are provided for Fortran... */
#define MPI_COMPLEX        ((MPI_Datatype)23)
#define MPI_DOUBLE_COMPLEX ((MPI_Datatype)24)
#define MPI_LOGICAL        ((MPI_Datatype)25)
#define MPI_REAL           ((MPI_Datatype)26)
#define MPI_DOUBLE_PRECISION ((MPI_Datatype)27)
#define MPI_INTEGER        ((MPI_Datatype)28)
#define MPI_2INTEGER       ((MPI_Datatype)29)
#define MPI_2COMPLEX       ((MPI_Datatype)30)
#define MPI_2DOUBLE_COMPLEX   ((MPI_Datatype)31)
#define MPI_2REAL             ((MPI_Datatype)32)
#define MPI_2DOUBLE_PRECISION ((MPI_Datatype)33)
#define MPI_CHARACTER         ((MPI_Datatype)1)

#define MPI_STATUS_SIZE (sizeof(MPI_Status) / sizeof(int))

/* Function prototypes for MPI stubs */

int MPI_Init(int *argc, char ***argv);
int MPI_Initialized(int *flag);
int MPI_Finalize();

int MPI_Comm_rank(MPI_Comm comm, int *rank);
int MPI_Comm_size(MPI_Comm comm, int *size);
int MPI_Abort(MPI_Comm comm, int errorcode);
int MPI_Type_size(MPI_Datatype datatype, int *size);
int MPI_Get_processor_name(char *name, int *resultlen);
double MPI_Wtime();

int MPI_Send(void *buf, int count, MPI_Datatype datatype,
	      int dest, int tag, MPI_Comm comm);
int MPI_Rsend(void *buf, int count, MPI_Datatype datatype, int dest,
        int tag, MPI_Comm comm);
int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
        int source, int tag, MPI_Comm comm, MPI_Status *status);
int MPI_Irecv(void *buf, int count, MPI_Datatype datatype,
        int source, int tag, MPI_Comm comm, MPI_Request *request);
int MPI_Wait(MPI_Request *request, MPI_Status *status);
int MPI_Waitall(int n, MPI_Request *request, MPI_Status *status);
int MPI_Waitany(int count, MPI_Request *request, int *index,
		 MPI_Status *status);
int MPI_Sendrecv(void *sbuf, int scount, MPI_Datatype sdatatype,
		  int dest, int stag, void *rbuf, int rcount,
		  MPI_Datatype rdatatype, int source, int rtag,
		  MPI_Comm comm, MPI_Status *status);
int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count);

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *comm_out);
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *comm_out);
int MPI_Comm_free(MPI_Comm *comm);

int MPI_Cart_create(MPI_Comm comm_old, int ndims, int *dims, int *periods,
		     int reorder, MPI_Comm *comm_cart);
int MPI_Cart_get(MPI_Comm comm, int maxdims, int *dims, int *periods,
		  int *coords);
int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
		  int *source, int *dest);
int MPI_Cart_rank(MPI_Comm comm, int *coords, int *rank);

int MPI_Barrier(MPI_Comm comm);
int MPI_Bcast(void *buf, int count, MPI_Datatype datatype,
        int root, MPI_Comm comm);
int MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
		   MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
int MPI_Scan(void *sendbuf, void *recvbuf, int count,
	      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		   void *recvbuf, int recvcount, MPI_Datatype recvtype,
		   MPI_Comm comm);
int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		    void *recvbuf, int *recvcounts, int *displs,
		    MPI_Datatype recvtype, MPI_Comm comm);
int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
			MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
int MPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		void *recvbuf, int recvcount, MPI_Datatype recvtype,
		int root, MPI_Comm comm);
int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		  void *recvbuf, int recvcount, MPI_Datatype recvtype,
		  MPI_Comm comm);
int MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
		   MPI_Datatype sendtype,
		   void *recvbuf, int *recvcounts, int *rdispls,
		   MPI_Datatype recvtype,
		   MPI_Comm comm);


/* MPI's error classes */
#include "mpi_errno.h"

#ifdef __cplusplus
}
#endif

#endif
