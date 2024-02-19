#include<iostream>
using namespace std ;

const int n = 5 ;
int queue[n] ;
int front=-1 , rear=-1 ;

void push(int d)
{
    if(front == (rear+1)%n)
    {
        cout << "Queue is Full." << endl ;
        return ;
    }

    else if(front==-1)
    {
        rear = 0 ;
        front = 0 ;
        queue[rear] = d ;
        cout << "This Element Is Inserted : " << queue[rear] << endl ;
    }

    else
    {
        rear = (rear+1)%n ;
        queue[rear] = d ;
        cout << "This Element Is Inserted : " << queue[rear] << endl ;
    }
}

void pop()
{
    if(front == -1)
    {
        cout << "Queue is Empty." << endl ;
        return ;
    }

    if(front == rear)
    {
        cout << "This Element Is Deleted : " << queue[front] << endl ;
        front = rear = -1 ;
        return ;
    }

    else
    {
        cout << "This Element Is Deleted : " << queue[front] << endl ;
        front = (front+1)%n ;
        return ;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(40);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    return 0 ;
}
