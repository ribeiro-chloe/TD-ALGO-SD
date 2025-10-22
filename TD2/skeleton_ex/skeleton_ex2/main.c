#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    int max=100;
    int sizeofarr=10;
    int array=malloc(sizeofarr*sizeof(int));
    for(int i=0; i<sizeofarr;i++){
        array[i]=rand()%max;
    }
    for (int i=0;i<sizeofarr;i++){
        printf("%d",array[i]);
    }

    int Sstart = clock();
    int s=selection_sort(array, sizeofarr);
    int Send=clock();
    double stime=(Send-Sstart)/CLOCK_PER_SEC;
    printf("Tri par selection: %f secondes\n",stime);
    int istart = clock();
    int i=insertion_sort(array, sizeofarr);
    int iend=clock();
    double itime=(iend-istart)/CLOCK_PER_SEC;
    printf("Tri par insertion: %f secondes\n",itime);
    int bstart = clock();
    int b=bubble_sort(array, sizeofarr);
    int bend=clock();
    double btime=(bend-bstart)/CLOCK_PER_SEC;
    printf("Tri à bulles: %f secondes\n",btime);
    int mstart = clock();
    int m=merge_sort(array, sizeofarr);
    int mend=clock();
    double mtime=(mend-mstart)/CLOCK_PER_SEC;
    printf("Tri fusion: %f secondes\n",mtime);
    int qstart = clock();
    int q=quick_sort(array, sizeofarr);
    int qend=clock();
    double qtime=(qend-qstart)/CLOCK_PER_SEC;
    printf("Tri rapide: %f secondes\n",qtime);

    return 0;
}
