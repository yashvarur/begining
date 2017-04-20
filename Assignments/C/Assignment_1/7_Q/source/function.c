int fun(int n)	/*function to reverse the number*/
{
	int rev;
	while(n!=0)
        { 

           rev=rev*10+n%10;
           n=n/10;
        }
return rev;
}
