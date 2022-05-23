#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *HashTable[10];

class hashing
{
    public:
    hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
        
    }

    int HashFunction(int value)
    {
        return (value%10);
    }

    node *create_node(int val)
    {
        node* temp = new node;
        temp->next = NULL;
        temp->value = val;
        return temp;
    }

    void display()
    {
        node *temp = new node;
        for (int i = 0; i < 10; i++)
        {
        temp = HashTable[i];
        cout<<"Index : ["<<i<<"]";
        while (temp!=NULL)
        {
            cout<<"Value : "<<temp->value;
            temp=temp->next;
        }
        cout<<"\n";
        }
        
    }

    int searchElement(int value)
    {
        node *temp = new node;
        for (int i = 0; i < 10; i++)
        {
            temp = HashTable[i];
        
            while (temp!=NULL)
            {   
                if (temp->value == value)
                    {
                        cout<<"Element Found : "<<temp->value;  
                    }
                temp=temp->next;
            }
  
        }
        cout<<"Element Not Found";
            if (!temp)
            return -1;
            
        return 0;
    }

    int deleteElement(int value)
    {  
        node *temp = new node;        
        int hash_val = HashFunction(value);
        temp = HashTable[hash_val];

        if(temp==NULL)
        {
            cout<<"Element Not Found";
        }

        if (temp->value==value)
        {
            HashTable[hash_val] = temp->next;
            return 0;
        }

        while ((temp->next)->value!=value)
        {
            temp = temp->next;
        }
        
        temp->next = (temp->next)->next;
        return 0;
    }

    void insertElement(int value)
    {
        int hash_val = HashFunction(value);
        node *temp = new node;
        node *head = new node;
        head = create_node(value);
        temp = HashTable[hash_val];

        if(temp == NULL)
        {
            HashTable[hash_val] = head;
        }

        else
        {
            while (temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next=head;    
        }
    }

};

int main()
{
    // cout<<"Working";
  
    int choice,data;
    hashing h;


    do
    {
    cout<<endl<<"1.Insert \n 2.Search \n 3.Display \n 4.Delete \n 5.Exit"<<endl;

    cout<<"Enter the operation to be performed";
    cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter the value to be inserted";
            cin>>data;
            h.insertElement(data);
            break;

        case 2:
            cout<<"Enter the value ";
            cin>>data;
            h.searchElement(data);
            break;

        case 3:
            h.display();
            break;

        case 4:
            cout<<"Enter the value to be deleted";
            cin>>data;
            h.deleteElement(data);
        
        default:
            cout<<"Enter valid choice";
            break;
        }
    }while(choice!=5);
  
    return 0;
}