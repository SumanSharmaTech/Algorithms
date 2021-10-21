#include<stdio.h>
int a[20];
void main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements in the array");
    for(int x=0;x<n;x++)
    {
        scanf("%d",&a[x]);
    }
    int ele;
    printf("Enter the element to be searched");
    scanf("%d",&ele);
    int first=0;int last=n-1;int mid=0;int pos=-1;
    while(first<=last)
    {

        mid=(first+last)/2;
        if(ele<a[mid])
            last=mid-1;
        else if(ele>a[mid])
            first=mid+1;
        else
        {
            pos=mid;
            break;
        }
    }
    if(pos!=-1)
        printf("Element %d found at position %d",ele,pos);
    else
        printf("Element not found!");

}
