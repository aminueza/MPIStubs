#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include "mpi.h"

/* lo-level function prototypes */

void mpi_copy_int(void *, void *, int);
void mpi_copy_float(void *, void *, int);
void mpi_copy_double(void *, void *, int);
void mpi_copy_char(void *, void *, int);
void mpi_copy_byte(void *, void *, int);

/* lo-level data structure */

struct _mpi_double_int {
  double value;
  int proc;
};
typedef struct _mpi_double_int double_int;

/* ---------------------------------------------------------------------- */
/* MPI Functions */
/* ---------------------------------------------------------------------- */

int MPI_Init(int *argc, char ***argv) {return MPI_SUCCESS;}

/* ---------------------------------------------------------------------- */

int MPI_Initialized(int *flag)
{
  *flag = 1;
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Finalize() {return MPI_SUCCESS;}

/* ---------------------------------------------------------------------- */

int MPI_Comm_rank(MPI_Comm comm, int *rank)
{
  *rank = 0;
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Comm_size(MPI_Comm comm, int *size)
{
  *size = 2;
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Abort(MPI_Comm comm, int errorcode)
{
  exit(1);
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Type_size(MPI_Datatype datatype, int *size)
{
  if (datatype == MPI_INT) *size = sizeof(int);
  else if (datatype == MPI_FLOAT) *size = sizeof(float);
  else if (datatype == MPI_DOUBLE) *size =sizeof(double);
  else if (datatype == MPI_CHAR) *size = sizeof(char);
  else if (datatype == MPI_BYTE) *size = sizeof(char);
  else if (datatype == MPI_UNSIGNED_LONG) *size = sizeof(uint64_t);
  else if (datatype == MPI_DOUBLE_INT) *size = sizeof(double_int);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Get_processor_name(char *name, int *resultlen)
{
  //strcpy(name,"Proc 0");
  //*len = strlen(name);
  const char host[] = "localhost";
  int len;

  if (!name || !resultlen) return MPI_FAILURE;

  len = strlen(host);
  memcpy(name,host,len+1);
  *resultlen = len;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

double MPI_Wtime()
{
  double time;
  struct timeval tv;

  gettimeofday(&tv,NULL);
  time = 1.0 * tv.tv_sec + 1.0e-6 * tv.tv_usec;
  return time;
}

/* ---------------------------------------------------------------------- */

int MPI_Send(void *buf, int count, MPI_Datatype datatype,
	      int dest, int tag, MPI_Comm comm)
{
  printf("MPI Stub WARNING: Should not send message to self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Rsend(void *buf, int count, MPI_Datatype datatype,
	       int dest, int tag, MPI_Comm comm)
{
  printf("MPI Stub WARNING: Should not rsend message to self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
	      int source, int tag, MPI_Comm comm, MPI_Status *status)
{
  printf("MPI Stub WARNING: Should not recv message from self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype,
	       int source, int tag, MPI_Comm comm, MPI_Request *request)
{
  printf("MPI Stub WARNING: Should not recv message from self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
  printf("MPI Stub WARNING: Should not wait on message from self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Waitall(int n, MPI_Request *request, MPI_Status *status)
{
  printf("MPI Stub WARNING: Should not wait on message from self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Waitany(int count, MPI_Request *request, int *index,
		 MPI_Status *status)
{
  printf("MPI Stub WARNING: Should not wait on message from self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Sendrecv(void *sbuf, int scount, MPI_Datatype sdatatype,
		  int dest, int stag, void *rbuf, int rcount,
		  MPI_Datatype rdatatype, int source, int rtag,
		  MPI_Comm comm, MPI_Status *status)
{
  printf("MPI Stub WARNING: Should not send message to self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count)
{
  printf("MPI Stub WARNING: Should not get count of message to self\n");
  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *comm_out)
{
  *comm_out = comm;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *comm_out)
{
  *comm_out = comm;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Comm_free(MPI_Comm *comm) { return MPI_SUCCESS; }

/* ---------------------------------------------------------------------- */

int MPI_Cart_create(MPI_Comm comm_old, int ndims, int *dims, int *periods,
		     int reorder, MPI_Comm *comm_cart)
{
  *comm_cart = comm_old;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Cart_get(MPI_Comm comm, int maxdims, int *dims, int *periods,
		  int *coords)
{
  dims[0] = dims[1] = dims[2] = 1;
  periods[0] = periods[1] = periods[2] = 1;
  coords[0] = coords[1] = coords[2] = 0;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
		    int *source, int *dest)
{
  *source = *dest = 0;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Cart_rank(MPI_Comm comm, int *coords, int *rank)
{
  *rank = 0;

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Barrier(MPI_Comm comm) { return MPI_SUCCESS; }

/* ---------------------------------------------------------------------- */

int MPI_Bcast(void *buf, int count, MPI_Datatype datatype,
	       int root, MPI_Comm comm) { return MPI_SUCCESS; }

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
		   MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  int n;
  if (datatype == MPI_INT) n = count*sizeof(int);
  else if (datatype == MPI_FLOAT) n = count*sizeof(float);
  else if (datatype == MPI_DOUBLE) n = count*sizeof(double);
  else if (datatype == MPI_CHAR) n = count*sizeof(char);
  else if (datatype == MPI_BYTE) n = count*sizeof(char);
  else if (datatype == MPI_UNSIGNED_LONG) n = count*sizeof(uint64_t);
  else if (datatype == MPI_DOUBLE_INT) n = count*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

int MPI_Scan(void *sendbuf, void *recvbuf, int count,
	      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  int n;
  if (datatype == MPI_INT) n = count*sizeof(int);
  else if (datatype == MPI_FLOAT) n = count*sizeof(float);
  else if (datatype == MPI_DOUBLE) n = count*sizeof(double);
  else if (datatype == MPI_CHAR) n = count*sizeof(char);
  else if (datatype == MPI_BYTE) n = count*sizeof(char);
  else if (datatype == MPI_UNSIGNED_LONG) n = count*sizeof(uint64_t);
  else if (datatype == MPI_DOUBLE_INT) n = count*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		   void *recvbuf, int recvcount, MPI_Datatype recvtype,
		   MPI_Comm comm)
{
  int n;
  if (sendtype == MPI_INT) n = sendcount*sizeof(int);
  else if (sendtype == MPI_FLOAT) n = sendcount*sizeof(float);
  else if (sendtype == MPI_DOUBLE) n = sendcount*sizeof(double);
  else if (sendtype == MPI_CHAR) n = sendcount*sizeof(char);
  else if (sendtype == MPI_BYTE) n = sendcount*sizeof(char);
  else if (sendtype == MPI_UNSIGNED_LONG) n = sendcount*sizeof(uint64_t);
  else if (sendtype == MPI_DOUBLE_INT) n = sendcount*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		    void *recvbuf, int *recvcounts, int *displs,
		    MPI_Datatype recvtype, MPI_Comm comm)
{
  int n;
  if (sendtype == MPI_INT) n = sendcount*sizeof(int);
  else if (sendtype == MPI_FLOAT) n = sendcount*sizeof(float);
  else if (sendtype == MPI_DOUBLE) n = sendcount*sizeof(double);
  else if (sendtype == MPI_CHAR) n = sendcount*sizeof(char);
  else if (sendtype == MPI_BYTE) n = sendcount*sizeof(char);
  else if (sendtype == MPI_UNSIGNED_LONG) n = sendcount*sizeof(uint64_t);
  else if (sendtype == MPI_DOUBLE_INT) n = sendcount*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
			MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  int n;
  if (datatype == MPI_INT) n = *recvcounts*sizeof(int);
  else if (datatype == MPI_FLOAT) n = *recvcounts*sizeof(float);
  else if (datatype == MPI_DOUBLE) n = *recvcounts*sizeof(double);
  else if (datatype == MPI_CHAR) n = *recvcounts*sizeof(char);
  else if (datatype == MPI_BYTE) n = *recvcounts*sizeof(char);
  else if (datatype == MPI_UNSIGNED_LONG) n = *recvcounts*sizeof(uint64_t);
  else if (datatype == MPI_DOUBLE_INT) n = *recvcounts*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		   void *recvbuf, int recvcount, MPI_Datatype recvtype,
		   int root, MPI_Comm comm)
{
  int n;
  if (sendtype == MPI_INT) n = sendcount*sizeof(int);
  else if (sendtype == MPI_FLOAT) n = sendcount*sizeof(float);
  else if (sendtype == MPI_DOUBLE) n = sendcount*sizeof(double);
  else if (sendtype == MPI_CHAR) n = sendcount*sizeof(char);
  else if (sendtype == MPI_BYTE) n = sendcount*sizeof(char);
  else if (sendtype == MPI_UNSIGNED_LONG) n = sendcount*sizeof(uint64_t);
  else if (sendtype == MPI_DOUBLE_INT) n = sendcount*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
		  void *recvbuf, int recvcount, MPI_Datatype recvtype,
		  MPI_Comm comm)
{
  int n;
  if (sendtype == MPI_INT) n = sendcount*sizeof(int);
  else if (sendtype == MPI_FLOAT) n = sendcount*sizeof(float);
  else if (sendtype == MPI_DOUBLE) n = sendcount*sizeof(double);
  else if (sendtype == MPI_CHAR) n = sendcount*sizeof(char);
  else if (sendtype == MPI_BYTE) n = sendcount*sizeof(char);
  else if (sendtype == MPI_UNSIGNED_LONG) n = sendcount*sizeof(uint64_t);
  else if (sendtype == MPI_DOUBLE_INT) n = sendcount*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* copy values from data1 to data2 */

int MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
		   MPI_Datatype sendtype,
		   void *recvbuf, int *recvcounts, int *rdispls,
		   MPI_Datatype recvtype,
		   MPI_Comm comm)
{
  int n;
  if (sendtype == MPI_INT) n = sendcounts[0]*sizeof(int);
  else if (sendtype == MPI_FLOAT) n = sendcounts[0]*sizeof(float);
  else if (sendtype == MPI_DOUBLE) n = sendcounts[0]*sizeof(double);
  else if (sendtype == MPI_CHAR) n = sendcounts[0]*sizeof(char);
  else if (sendtype == MPI_BYTE) n = sendcounts[0]*sizeof(char);
  else if (sendtype == MPI_UNSIGNED_LONG) n = sendcounts[0]*sizeof(uint64_t);
  else if (sendtype == MPI_DOUBLE_INT) n = sendcounts[0]*sizeof(double_int);

  memcpy(recvbuf,sendbuf,n);

  return MPI_SUCCESS;
}
