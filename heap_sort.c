#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX1 10000
#define MAX2 1000000
#define MIN 1


void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void create_heap(int a[],int n) {
    int child,key,parent,i;
    
    for(i=2;i<=n;i++) {
        child = i;
        key = a[i];
        parent = floor(child / 2);
        while(child > 1 && key > a[parent]) {
            swap(&a[child],&a[parent]);
            //a[child] = a[child] + a[parent];
            //a[parent] = a[child] - a[parent];
            //a[child] = a[child] - a[parent];
            
            child = parent;
            parent = floor(child / 2);
            if(parent < 1)
                parent = 1;
        }
        a[child] = key;
    }
    return;
}

void heap_sort(int a[],int n) {
    int parent,child,key,count;
    for(count=n;count>=2;count--) {
        swap(&a[1],&a[count]);
        //a[1] = a[1] + a[count];
        //a[count] = a[1] - a[count];
        //a[1] = a[1] - a[count];
        
        parent = 1;
        key = a[1];
        child = 2;
        
        if(child + 1 < count) {
            if(a[child+1] > a[child])
                child++;
        }
        while(child < count && a[child] > key) {
            swap(&a[child],&a[parent]);
            //a[child] = a[child] + a[parent];
            //a[parent] = a[child] - a[parent];
            //a[child] = a[child] - a[parent];
            parent = child;
            child = 2 * parent;
            if(child + 1 < count) {
                if(a[child+1] > a[child])
                    child++;
            }
            else if(child > n)
                child = n;
            a[parent] = key;
        }
    }
}

int main() {
    int i,n;
    scanf("%d",&n);
    if(n < 1) {
        printf("Size of array must be within [%d,%d]\n",MIN,MAX1);
        exit(0);
    }
    int a[n+1];
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i] < 1) {
            printf("Number must be within [%d,%d]\n",MIN,MAX2);
            exit(0);
        }
    }
    create_heap(a,n);
    heap_sort(a,n);
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
