#include <sys/types.h>
#include <unistd.h>
main()
{
   printf("The current process ID is %d\n",getpid());
}
