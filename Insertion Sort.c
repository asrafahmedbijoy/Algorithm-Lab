#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000

int main()
{
    int array1[5],array2[SIZE],n,x,y,i,j,fR,temp1=0,temp2=0;

    printf("Enter 5 Numbers for Sorting: \n");
    for(x=0;x<5;x++)
    {
        scanf("%d", &array1[x]);
    }

    //Generating 100000 random numbers as SIZE = 100000
    srand(time(0));
    for(fR=0;fR<SIZE;fR++)
        {
            array2[fR] = rand();
        }

    FILE *fp, *fw;
    fp = fopen("USERINPUT.txt", "w");
    for(x=0;x<5;x++)
        {
            fprintf(fp,"%d\n",array1[x]);
        }
    fclose(fp);
    printf("\nNumbers are Inputted in the USERINPUT_INSERTION_SORT.TXT FILE\n\n");

    printf("Running Insertion Sort for 100000 Random Numbers\n");
    //Printing Inputs in a TXT File
    fp = fopen("100000_NUMBERS_INSERTION_SORT_INPUT.txt", "w");

    for(fR=0;fR<SIZE;fR++)
        {
            fprintf(fp,"%d\n",array2[fR]);
        }
    fclose(fp);

    //SORTING NUMBERS
    clock_t t1;
    t1 = clock();
    for(fR=1;fR<SIZE;fR++)
        {
        temp2 = array2[fR];
        i = fR - 1;

        while(temp2 < array2[i] && i >=0)
            {
                array2[i+1] = array2 [i];
                i--;
            }
        array2 [i+1] = temp2 ;
        }
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;

    fw = fopen("100000_NUMBERS_INSERTION_SORT_OUTPUT.txt", "w");
    //Printing Output in a Separate TXT File
    for(fR=0;fR<SIZE;fR++)
        {
            fprintf(fw,"%d\n",array2[fR]);
        }
    fclose(fw);

    clock_t t2;
    t2 = clock();

    for(y=1;y<5;y++)
        {
        temp1 = array1[y];
        x = y - 1;

        while(temp1 < array1[x] && x >=0)
            {
                array1[x+1] = array1 [x];
                x--;
            }
        array1 [x+1] = temp1 ;
        }
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;

    fp = fopen("USERINPUT_INSERTION_SORTED_OUTPUT.txt", "w");

    for(x=0;x<5;x++)
        {
            fprintf(fp,"%d\n",array1[x]);
        }

    printf("\nUser Inputted Numbers are sorted using Insertion Sort \nand Output is in USERINPUT_INSERTION_SORTED_OUTPUT.TXT FILE &\n");
    printf("100000 Random Numbers are generated and sorted using Insertion Sort\nand Output is in 100000_NUMBERS_INSERTION_SORT_OUTPUT.TXT FILE\n");

    //Measuring The Time Required for Insertion Sort to Execute
    printf("\nThe Time Required for sorting Numbers using Insertion Sort\n");
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
