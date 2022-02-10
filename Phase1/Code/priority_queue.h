#include "headers.h"

struct node
{
	struct processData data;
    int p;
	struct node* next;
};

    struct node* readyQueue = NULL;
    struct node* runningProcess = NULL;

    void enqueue(struct processData d,int pr) //Insert the element and priority in Queue
    { 	
        struct node* temp;
        struct node* new_n;
        new_n = (struct node*)malloc(sizeof(struct node));
        new_n->data = d;
        new_n->p = pr;
        //printf("\n\nAdding Data = %d\tPriority = %d ",new_n->data.id,new_n->p);
        if((readyQueue==NULL) || (pr < readyQueue->p)) 
        {
            new_n->next = readyQueue;
            readyQueue = new_n;
        }
        else
        {
            temp = readyQueue;           
            while( (temp->next != NULL) && ((temp->next->p) <= pr) ){
                temp = temp->next;
            }        
            new_n->next = temp->next;
            temp->next = new_n;

        }
    }

    void print() //Print the data of Queue
    {
        struct node* temp = readyQueue;
        while(temp != NULL) 
        { 
            printf("\nAdded ID = %d",temp->data.id);	 
            temp = temp->next; 
        } 

    }

    void dequeue() //Deletion of highest priority element from the Queue
    {
        if(readyQueue==NULL) //Check for Underflow condition
            printf("\nQueue is Empty");
        else
        {
            runningProcess = readyQueue;
            readyQueue = readyQueue->next;
            //printf("\nRemoved ID %d \n",runningProcess->data.id);
        }
    }

    void processFinished()
    {    
        printf("finished process with id: %d\n", runningProcess->data.id);
        runningProcess = NULL;
    }
