#include<stdio.h>
int main()
{
	int k,i;
	int a[8]={1,5,2,8,5,3,1,7};
	k=a[0];
	for(i=0;i<8;i++) {
		if(k<a[i])
		k=a[i];
	}
printf("largest elements=%d\n",k);
}
	
	
