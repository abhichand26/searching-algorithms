#include<stdio.h>
#include<malloc.h>

void LinearSearch(int A[],int n,int search)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(A[i]==search)
		{
			printf("%d is present at location %d\n",search,i+1);
			count++;
		}
	}
	if(count==0)
		printf("%d is not present in array\n",search);
	else
		printf("%d is present %d times in array\n",search,count);
}

void BinarySearch(int A[],int n,int search)
{
	int i,j,mid;
	i=0;
	j=n-1;
	mid=(i+j)/2;
	while(i<=j)
	{
		if(A[mid]<search)
			i=mid+1;
		else if(A[mid]==search)
		{
			printf("%d is present at location %d\n",search,mid+1);
			break;
		}
		else
			j=mid-1;
		
		mid=(i+j)/2;
	}
	if(i>j)
    	printf("%d is not present in the array\n",search);
}

int main()
{
	int i,n,*A,search,sel;
	char ch;

	do
	{
		printf("Enter the size of Array : ");
		scanf("%d",&n);
		A=(int *)malloc(n*sizeof(int));
		printf("Enter the elements of Array:\n");
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
	
		printf("Enter the element to search : ");
		scanf("%d",&search);
		
		printf("Select the type of searching:\n");
		printf("1-Linear Search\n");
		printf("2-Binary Search\n");
		printf("3-Exit\n");
		printf("Enter your choice:");
		scanf("%d",&sel);
		
		switch(sel)
 		{
			case 1:
  				LinearSearch(A,n,search);
  				break;
  				
			case 2:
  				BinarySearch(A,n,search);
  				break;
				
			case 3:
				return 0;

			default:
  				printf("That is not a valid selection!\n");
  		}
  		
  		printf("\nTo continue enter (Y/y):");
  		fflush(stdin);
  		scanf("%c",&ch);	
	}while(ch=='Y'||ch=='y');
	
	return 0;
}
