#include <stdio.h>
#include <pthread.h>

static void * experiment ( void * a )
{
   pthread_attr_t tattr;
   size_t size;
   int ret = pthread_attr_getstacksize(&tattr, &size);
   printf ( " ret = %d,size=%u\n" ,ret , size ) ;
}

int main( int argc , char * argv[] )
{
   pthread_t thr;
   int arg = 123 ;
   pthread_create(&thr, NULL, experiment, (void*)arg );
   pthread_exit(0);
   return 0;
}
