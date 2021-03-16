 /* The question description is as follows followed by it's code */
 
 /* Assume we have one input queue, one output queue and a stack with its associated basic operations
such as push and pop. No element from the output queue can be pushed into the stack.  Also, 
once input from the input queue is pushed into stack it cannot be put back into the input queue.
We can take elements from the input queue and push into the stack. At any time we can pop an 
element from the stack.  However, if there is no element available in the input queue, 
then only pop operations are possible. A popped element should be always be placed into the 
output queue and cannot be pushed back on to the stack. The act of producing an output
sequence from a given input sequence as explained is known as stack permutation.    
Suppose we have a sequence of k elements 1, 2, 3, ..., k available from the input queue. 
Generate all stack permutation of k elements. Clearly explain the nature of stack permutations
and find out an expression for the number of stack permutations. */

/* Request you to follow the instructions of read the instructions of readMe file and then 
execute */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAXSIZE 20

int input_queue[MAXSIZE];
int output_queue[MAXSIZE];

int front = -1;
int rear = -1;
int size = -1;
int mark = 0;

int isempty()
{
    return size<0;
}

int isfull()
{
    return size == MAXSIZE;
}

void enqueue_input(int value)
{
    if(size<MAXSIZE)
    {
        if(size<0)
        {
            input_queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE-1)
        {
            input_queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            input_queue[rear+1] = value;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

void enqueue_output(int value)
{
    if(size<MAXSIZE)
    {
        if(size<0)
        {
            output_queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE-1)
        {
            output_queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            output_queue[rear+1] = value;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

int dequeue()
{
    if(size<0)
    {
        mark=1;
    }
    else
    {
        size--;
        front++;
    }
}

void display_output()
{
    int i;
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",output_queue[i]);
        }
    }
    else
    {
        for(i=front;i<MAXSIZE;i++)
        {
            printf("%d ",output_queue[i]);
        }
        
        for(i=0;i<=rear;i++)
        {
            printf("%d ",output_queue[i]);
        }
    }
}

// A structure to represent a stack 
struct StackNode
{ 
    int data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode* root) 
{ 
    return !root; 
} 
  
void PUSH(struct StackNode** root, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%d pushed to stack\n", data); 
} 
  
int POP(struct StackNode** root) 
{ 
    if (isEmpty(*root)) 
    {
         return INT_MIN;        
    }

    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
    
    return popped; 
} 
  
int peek(struct StackNode* root) 
{ 
    if (isEmpty(root))
    {
        return INT_MIN;         
    }

    return root->data; 
} 

/* function written to compute the factorial of the number this is used 
in the next part of the program */
long long int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

// function written to compute the catalan value of the number
long long int com(int n)
{
    long long int p,q,r;
    p=pow(2,n);
    for(q=3;q<=((2*n)-1);q+=2)
    {
        p*=q;
    }
    r=fact(n);
    p/=r;
    p/=(n+1);
    return p;
}
int pop(int a[],int s[],int q[],int ,int ,int);
int push(int a[],int s[],int q[],int ,int ,int);
int operate(int a[],int s[],int q[],int ,int ,int);
int n;
long long int count=0;
int main()
{
    int i,a1,s1,q1;
    printf("        PROGRAM TO GENERATE ALL POSSIBLE STACK PERMUTATIONS OF A GIVEN INPUT    \n\n");
    printf("Make sure your input is less than 15 otherwise this program will not run due to the\nenormous number of outputs series");
    printf("\nEnter the value of k as mentioned in the question: ");
    scanf("%d",&n);
    printf("\nEnter your array of %d integers: ",n);
    int a[n],s[n],q[n];
    // Taking the complete input in the form of an array
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nPrinting all sets of outputs:\n");
    // Converting the entire input array into the input queue
    for(i=0;i<n;i++)
    {
        enqueue_input(a[i]);
    }
    // defining extra variables to be used further in the stack permutaton
    a1=n;
    s1=0;
    q1=0;
    // This is the final function call after which the entire stack permutation is generated
    // Written as operate function
    operate(a,s,q,a1,s1,q1);
    // This operation algorithm is using stack ADT operations
    // The printing is completed and compilation is terminated
    // At the end is 
    return 0;
    // Hopefully the output matches we get our answer
}
int operate(int a[],int s[],int q[],int a1,int s1,int q1)
{
    int i;
    if(s1==0)
    {
        if(a1==0)
        {
            int i=0,m;
            for(i=0;i<q1;i++)
            {
                dequeue();
            }
            for(i=0;i<q1;i++)
            {
                m=q[i];
                enqueue_output(m);
            }
            display_output();
            for(i=0;i<q1;i++)
            {
                dequeue();
            }
            printf("\n");
            count++;
            if(count==com(n))
            {
                printf("The total number of stack permutations as printed above are: %lld\n",count);                
            }

            return 0;
        }
        else
        {
            int a2[n],s2[n],q2[n],i;
            for(i=0;i<n;i++)
            {
                a2[i]=a[i];
                s2[i]=s[i];
                q2[i]=q[i];
            }
            push(a2,s2,q2,a1,s1,q1);
        }
    }
    else if(a1==0)
    {
         int a2[n],s2[n],q2[n],i;
            for(i=0;i<n;i++)
            {
                a2[i]=a[i];
                s2[i]=s[i];
                q2[i]=q[i];
            }
        pop(a2,s2,q2,a1,s1,q1);
    }
    else
    {    int a2[n],s2[n],q2[n],i;
            for(i=0;i<n;i++)
            {
                a2[i]=a[i];
                s2[i]=s[i];
                q2[i]=q[i];
            }
         push(a2,s2,q2,a1,s1,q1);
         int a3[n],s3[n],q3[n];
            for(i=0;i<n;i++)
            {
                a3[i]=a[i];
                s3[i]=s[i];
                q3[i]=q[i];
            }
        pop(a3,s3,q3,a1,s1,q1);
    }
    return 0;
}
int push(int a[],int s[],int q[],int a1,int s1,int q1)
  {
    s[s1]=a[0];
    s1++;
    int i;
    for(i=0;i<a1-1;i++)
    {
        a[i]=a[i+1];
    }
    a1--;
    int a3[n],s3[n],q3[n];
            for(i=0;i<n;i++)
            {
                a3[i]=a[i];
                s3[i]=s[i];
                q3[i]=q[i];
            }
    operate(a3,s3,q3,a1,s1,q1);
    return 0;
  }

int pop(int a[],int s[],int q[],int a1,int s1,int q1)
{
    q[q1]=s[s1-1];
    s1--;
    q1++;
    int a3[n],s3[n],q3[n],i;
            for(i=0;i<n;i++)
            {
                a3[i]=a[i];
                s3[i]=s[i];
                q3[i]=q[i];
            }
    operate(a3,s3,q3,a1,s1,q1);
    return 0;
}

	
