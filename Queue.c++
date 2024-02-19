#include<iostream>
using namespace std;

const int n = 100 ;
int arr[n];
int front = -1 ;
int rear = -1 ;

void push(int d)
{
    if(rear >= n-1)
    {
        cout << "Queue is Full" << endl ;
        return ;
    }

    if(front==-1 && rear == -1)
    {
        front++ ;
        rear++ ;
        arr[rear] = d ;
        cout << "Inserted this Elemnt :" << arr[rear] << endl ;
        return ;
    }

    rear++ ;
    arr[rear] = d ;
    cout << "Inserted this Elemnt :" << arr[rear] << endl ;
}

void pop()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue is Empty" << endl ;
        return;
    }
    
    cout << "Deleted this Element :" << arr[front] << endl ;
    front++ ;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
}