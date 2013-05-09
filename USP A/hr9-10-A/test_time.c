#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
   struct timespec ts;
   clock_gettime(CLOCK_REALTIME, &ts);
   printf("%ld:%ld\n", ts.tv_sec, ts.tv_nsec);
}
