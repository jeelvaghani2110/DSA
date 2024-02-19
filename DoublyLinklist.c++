#include<iostream>
using namespace std ;

class node
{
        int data;
        node* next;
        node* pre;
        friend class implement;

    public:
        node(int d)
        {
            this -> data = d ;
            this -> next = NULL ;
            this -> pre = NULL ;
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
            node* temp = first ;
            node* nn = new node(d);

            if(first == NULL)
            {
                first = nn ;
            }

            else
            {
                while(temp->next != NULL)
                {
                    temp = temp->next ;
                }

                nn->pre = temp ;
                temp->next = nn ;
            }
        }

        void insertHead(int d)
        {
            node* temp = first ;
            node* nn = new node(d);

            if(first == NULL)
            {
                first = nn ;
            }

            else
            {
                nn->pre = NULL ;
                nn->next = temp ;
                first = nn ;
            }
        }

        void insert(int x , int d)
        {
            node* temp = first ;
            node* nn = new node(d);

            while(temp->data != x)
            {
                temp = temp->next ;
            }

            nn->next = temp->next;
            nn->pre = temp ;
            temp->next = nn ;
        } 

        void del(int d)
        {
            node* temp = first ;

            while(temp->next->data != d)
            {
                temp = temp->next ;
            }

            temp->next->next->pre = temp ;
            temp->next = temp->next->next ;
        }

        void deleteAfter(int d)
        {
            node* temp = first ;

            while(temp->data != d)
            {
                temp = temp->next ;
            }

            temp->next->next->pre = temp ;
            temp->next = temp->next->next ;
        }

        void deleteBefore(int d)
        {
            node* temp = first ;
        
            if(temp->next->data != d)
            {
                first = first->next ;
                first->pre = NULL ;
            }

            else
            {
                while(temp->next->next->data != d)
                {
                    temp = temp->next ;
                }

                temp->next->next->pre = temp ;
                temp->next = temp->next->next ;
            }

        }

        void append(implement* m , implement* n)
        {
            first = m->first ;
            node* temp = m->first ;

            while(temp->next != NULL)
            {
                temp = temp->next ;
            }
            
            temp->next = n->first ;
        }

        void reverse()
        {
            node* prev = NULL ;
            node* curr = first ;
            node* forwad = NULL ;

            if(first == NULL || first->next == NULL)
            {
                return ;
            }

            while(curr != NULL)
            {
                forwad = curr->next ;
                curr->next = prev ;
                curr->pre = prev ;
                prev = curr ;
                curr = forwad ;
            }
            
            first = prev ;
        }

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
    i1.insertTail(10);
    i1.insertTail(20);
   
  /*i1.insertHead(60);
    i1.insert(30,31);
    i1.del(31);
    i1.deleteAfter(20);
    i1.deleteBefore(20);*/

    // i2.insertTail(10);
    // i2.insertTail(20);
    // i2.insertTail(30);
    // i2.insertTail(40);
    // i2.insertTail(50);

    // i3.append(&i1,&i2);
    // i3.reverse();

    i2.deleteBefore(20);
    i2.print();
}