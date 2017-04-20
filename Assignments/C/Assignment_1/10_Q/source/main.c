// program to find largest elements in an array
#include <header.h>
int main()
{
	int a[100],i,n;
  	printf("enter the number of elements\n");
	scanf("%d",&n);			/*read the number of elements in an array*/ 
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);		/*read the array elements */
	fun(a,n);
return 0;
}
