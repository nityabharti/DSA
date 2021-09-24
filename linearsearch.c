//program to search an element in a 2-D array using linear search
#include <stdio.h>
int main()
{
     int x,y,check=0;
     printf("enter number of rows in array\n");
     scanf("%d",&x);
     printf("enter number of columns in array\n");
     scanf("%d",&y);
     int arr[x][y];
     printf("enter one by one elements\n");
     for (int i = 0; i < x; i++)
     {
         for (int j = 0; j < y; j++)
         {
            printf("enter the element of row %d column %d\n",i+1,j+1);
            scanf("%d",&arr[i][j]);
         } 
     }
     printf("enter the element we want to find\n");
     int element;
     scanf("%d",&element);
     for (int i = 0; i < x; i++)
     {
         for(int j = 0; j < y; j++)
         {
             if(arr[i][j] == element)
             {
                 check=1;
                 printf("element found at row %d column %d\n",i+1,j+1);
                 break;
             }
         }
     }
     if (check==0)
     printf("element not found in array");


   return 0;
}
