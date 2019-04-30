#include<stdio.h>
#include<conio.h>2
#include<stdlib.h>
#include<time.h>
#define SIZE 100000

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int array1[5],arr[SIZE],n,x,y,i,j,fR,temp1=0,temp2=0;

    printf("Enter 5 Numbers for Sorting: \n");
    for(x=0;x<5;x++)
    {
        scanf("%d", &array1[x]);
    }

    //Generating 100000 random numbers as SIZE = 100000
    srand(time(0));
    for(fR=0;fR<SIZE;fR++)
        {
            arr[fR] = rand();
        }

    FILE *fp, *fw;
    fp = fopen("USERINPUT.txt", "w");
    for(x=0;x<5;x++)
        {
            fprintf(fp,"%d\n",array1[x]);
        }
    fclose(fp);
    printf("\nNumbers are Inputted in the USERINPUT_MERGE_SORT.TXT FILE\n\n");

    printf("Running MERGE Sort for 100000 Random Numbers\n");
    //Printing Inputs in a TXT File
    fp = fopen("100000_NUMBERS_MERGE_SORT_INPUT.txt", "w");

    for(fR=0;fR<SIZE;fR++)
        {
            fprintf(fp,"%d\n",arr[fR]);
        }
    fclose(fp);

    //SORTING NUMBERS
    clock_t t1;
    t1 = clock();
    mergeSort(arr,0,SIZE-1);
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    fw = fopen("100000_NUMBERS_MERGE_SORT_OUTPUT.txt", "w");
    //Printing Output in a Separate TXT File
    for(fR=0;fR<SIZE;fR++)
        {
            fprintf(fw,"%d\n",arr[fR]);
        }
    fclose(fw);

    clock_t t2;
    t2 = clock();
    mergeSort(arr,0,SIZE-1);
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    fp = fopen("USERINPUT_MERGE_SORTED_OUTPUT.txt", "w");

    for(x=0;x<5;x++)
        {
            fprintf(fp,"%d\n",array1[x]);
        }

    printf("\nUser Inputted Numbers are sorted using MERGE Sort \nand Output is in USERINPUT_MERGE_SORTED_OUTPUT.TXT FILE &\n");
    printf("100000 Random Numbers are generated and sorted using MERGE Sort\nand Output is in 100000_NUMBERS_MERGE_SORT_OUTPUT.TXT FILE\n");

    //Measuring The Time Required for MERGE Sort to Execute
    printf("\nThe Time Required for sorting Numbers using MERGE Sort\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|    >>%f Seconds Required for sorting UserInput Numbers<<     |\n", time_taken1);
    printf("|--------------------------------------------------------------------|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|  >>%f Seconds Required for sorting 100000 Random Number<<   |\n", time_taken2);
    printf("|--------------------------------------------------------------------|\n");

    double time_compare = time_taken2 - time_taken1;
    printf("\nCompare The Time Required for sorting UserInput Numbers and 100000 Random Number = %f\n\n", time_compare);
    return 0;
}
