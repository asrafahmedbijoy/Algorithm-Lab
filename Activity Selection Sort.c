#include<stdio.h>

void activity_selection(int start[], int end[], int n)
{
   printf("SELECTED ACTIVITIES INDICES ARE: ");
   printf("0 "); //the first activity is always selected
   int j,i=0;
   for(j=1; j< n; j++)
      if(start[j] >= end[i])
          {
            printf("%d ",j); //the activity j is printed
            i=j;
          }
}


int main()
{
   int n,i;
   printf("Enter size of list: ");
   scanf("%d",&n);
   int start[n],end[n];
   printf("PLEASE ENTER ELEMENTS WITH THE SORTED END TIME MANNER \n");
   printf("Enter start time and end time simultaneously: \n");
   //here sorted input is taken for simplicity
   for(i=0;i< n;i++)
      scanf("%d %d",&start[i],&end[i]);
   activity_selection(start,end,n);
   return 0;
}

