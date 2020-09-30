#include<stdio.h>
#include<stdlib.h>
int get_parent_index(int cur_index)
{
    if(cur_index==0)
    {
        return 0;
    }
    if(cur_index%2==0)
    {
        return (cur_index/2)-1;
    }
    else
    {
        return (cur_index/2);
    }
    
}
void swap(int *heap,int i,int j)
{
    // printf("swapped");
    int temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
    return;
}

void insert(int no,int *heap,int insert_index)
{
    
    
    heap[insert_index]=no;
    
    
    int cur_index=insert_index;
    int parent_index;
    while(1)
    {
        parent_index=get_parent_index(cur_index);
        
        if(heap[cur_index]>heap[parent_index])
        {
            swap(heap,cur_index,parent_index);
            
            cur_index=parent_index;
        }
        else
        {
            
            return;
        }
        
    }
    
}
void sort(int *heap,int n)
{
    for(int i=n-1;i>=0;i--)
    {
        swap(heap,i,0);
        int cur=0;
        int key=heap[cur];
        int l_child=1;
        if(l_child+1<i)
        {
            if(heap[l_child+1]>heap[l_child])
            {
                l_child++;
            }
        }
        while(l_child<=i-1 && heap[l_child]>key)
        {
            swap(heap,cur,l_child);
            cur=l_child;
            l_child=2*cur;
            if(l_child+1<i)
            {
                if(heap[l_child+1]>heap[l_child])
                {
                    l_child++;
                }
            }
            else if(l_child>n)
            {
                l_child=n;
            }
            heap[cur]=key;
        }

    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *heap=(int *)malloc(n*sizeof(int));
    int temp;
    if(n==0)
    {
        printf("Size of array must be within [1,10000]");
        exit(0);
    }
    // int *final=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp<0)
        {
            printf("Number must be within [1,1000000]");
            exit(0);
        }
        insert(temp,heap,i);
    }
    sort(heap,n);
   for(int i=0;i<n;i++)
   {
       printf("%d ",heap[i]);
   }
    
}