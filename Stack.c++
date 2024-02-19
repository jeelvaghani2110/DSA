#include<iostream>
using namespace std ;

const int n = 3 ;
int arr[n];
int front = -1 ;

void push(int d)
{   
    if (front >= n-1)
    {
        cout << "Stack is Full" << endl ;
        return ;
    }
    
    if(front == -1)
    {
        front++ ;
        arr[front] = d ;
        cout << "Inserted this Elemnt :" << arr[front] << endl ;
        return;
    }

    front++ ;
    arr[front] = d ;
    cout << "Inserted this Element :" << arr[front] << endl ;
}

void pop()
{
    if (front == -1)
    {
        cout << "Stack is Empty" << endl ;
        return ;
    }

    cout << "Deleted this Element :" << arr[front] << endl ;
    front-- ;
}

void top()
{
    if (front == -1)
    {
        cout << "Stack is Empty" << endl ;
        return;
    }

    cout << "This is Top Element :" << arr[front] << endl ;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    top();
    pop();
    pop();
    pop();
    pop();
}