#include<iostream>
using namespace std;

struct queue
{
    int r;
    int f;
    int size;
    int* arr;
};

int isFull(queue *q)  
{
    if (q->r == q->size-1)
    {
        cout<<"Queue is Empty";
        return 1;
    }
    return 0;
    
}

int isEmpty(queue *q)
{
    if (q->r == q->f)
    {
        cout<<"Queue is Empty";
        return 1;
    }
    return 0;
    
}

void Enqueue(queue *q,int val)
{
   if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int Dequeue(queue *q)
{
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 10;
    q.r = 0;
    q.f = -1; 
    q.arr = (int*) malloc(q.size*sizeof(int));

    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

    cout<<" "<<i;
    visited[i] = 1;
    Enqueue(&q,i);
    while (!isEmpty(&q))
    {
        int node = Dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (A[node][j] == 1 && visited[j] == 0)
            {
                cout<<j;
                visited[j] = 1;
                Enqueue(&q,j);
            }
            
        }
        
    }
    
    return 0;
}
