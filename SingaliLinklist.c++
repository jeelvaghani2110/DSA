#include<iostream>
using namespace std;

class node
{
    int data;
    node* next;

    friend class implement;

    public:
        node(int d)
        {
            this -> data = d ;
            this -> next = NULL ;
        }
};

class implement
{
    node* first ;

    public:
        implement()
        {
            first = NULL ;
        }

        void insertTail(int d)
        {
            node* nn = new node(d);

            if(first==NULL)
            {
                first = nn ;
            }

            else
            {
                node* temp = first ;

                while(temp->next != NULL)
                {
                    temp = temp->next ;
                }

                temp->next = nn ;
            }
        }

        void insertHead(int d)
        {
            node* nn = new node(d);

            if(first==NULL)
            {
                first = nn ;
            }

            else
            {
                node* temp = first ;

                nn->next = temp ;
                first = nn ;
            }
        }

        void insertAfter(int x , int d)
        {
            node* temp = first ;
            node* nn = new node(d);

            while(temp->data != x)
            {
                temp = temp->next ;
            }

            nn->next = temp->next ;
            temp->next = nn ;
        }

        void insertBefore(int x , int d)
        {
            node* temp = first ;
            node* nn = new node(d);

            if(temp->data==x)
            {
                nn->next = temp ;
                first = nn ;
            }

            else
            {
                while(temp->next->data != x)
                {
                    temp = temp->next ;
                }

                nn->next = temp->next ;
                temp->next = nn ;
            }
        }

        // void del(int d)
        // {
        //     node* temp = first ;

        //     while(temp->next->data != d)
        //     {
        //         temp = temp->next ;
        //     }

        //     temp->next = temp->next->next ;
        // }

        // void deleteAfter(int d)
        // {
        //     node* temp = first ;

        //     while(temp->data != d)
        //     {
        //         temp = temp->next ;
        //     }

        //     temp->next = temp->next->next ;
        // }

        // void deleteBefore(int d)
        // {
        //     node* temp = first ;

        //     while(temp->next->next->data != d)
        //     {
        //         temp = temp->next ;
        //     }

        //     temp->next = temp->next->next ;
        // }

        // void append(implement* i1 , implement* i2)
        // {
        //     first = i1->first ;
        //     node* temp = i1->first ;

        //     while(temp->next != NULL)
        //     {
        //         temp = temp->next ;
        //     }

        //     temp->next = i2->first ;
        // }

        // void reverse()
        // {
        //     node* pre = NULL ;
        //     node* curr = first ;
        //     node* forwad = NULL ;

        //     if(first == NULL || first->next == NULL)
        //     {
        //         return ;
        //     }

        //     while(curr != NULL)
        //     {
        //         forwad = curr->next ;
        //         curr->next = pre ;
        //         pre = curr ;
        //         curr = forwad ;
        //     }
            
        //     first = pre ;
        // }

        void print()
        {
            node* temp = first ;

            while(temp != NULL)
            {
                cout << temp->data << "  " ;
                temp = temp->next ; 
            }

            cout << endl ;
        }
};

int main()
{
    implement i1 , i2 , i3 ;
    // i1.insertTail(10); 
    // i1.insertTail(20);
    // i1.insertTail(30); 
    // i1.insertTail(40);
  /*i1.insertAfter(30,35);
    i1.insertHead(40);
    i1.del(10);
    i1.deleteAfter(20);
    i1.deleteBefore(20);*/

  /*i2.insertTail(50);
    i2.insertTail(60);
    i2.insertTail(70);
    i2.insertTail(80);

    i3.append(&i1 , &i2);*/
    
    //i1.reverse();

    i1.insertTail(10);
    i1.insertBefore(10,20);
    i1.print();
}