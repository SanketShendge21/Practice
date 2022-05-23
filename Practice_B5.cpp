#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node
{
    char name[20];
    node *next;
    node *down;
    int flag;

};

class Book
{
    public:
    node * head = NULL; 
    node * temp = NULL; 
    node * t1 = NULL; 
    node * t2 = NULL; 

    char ch[20];
    int n,i;

    node* createNode()
    {
        node *temp = new node;
        temp->next = NULL;
        temp->down = NULL;
        temp->flag = 0;
        // temp->name[] = NULL;
        cout<<"\n Enter Name : "<<endl;
        cin>>temp->name;

        return temp;
    }

    void insertBook()
    {
        if (head == NULL)
        {
            t1 = createNode();
            head = t1;
        }

        else
        {
            cout<<"\n Book already exist"<<endl;
        }
        
    }

    void insertChapter()
    {
        if (head == NULL)       
        {
            cout<<"\n Book does not exist"<<endl;
        }

        else
        {
            cout<<"\nHow many chapters do you wish to enter"<<endl;
            cin>>n;

            for (int j = 0; j < n; j++)
            {
                t1 = createNode();
                if (head->flag == 0)
                {
                    head->down = t1;
                    head->flag = 1;
                }

                else
                {
                    temp = head;

                    temp = temp->down;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = t1;
                    
                }
                
            }
            
        }
        
    }

    void insertSection()
    {

        if (head == NULL)
        {
            cout<<"\n Book does not exist"<<endl;
        }

        else
        {
            cout<<"Enter the name of chapter in which you want to enter section";
            cin>>ch;

            temp = head;
            if (temp->flag == 0)
            {
                cout<<"\n There are no chapters in the book"<<endl;
            }

            else
            {
                temp = temp->down;
                while (temp!=NULL)
                {
                    if(!strcmp(temp->name,ch))
                    {
                        cout<<"\nEnter the number of sections"<<endl;
                        cin>>n;

                        for (int i = 0; i < n; i++)
                        {
                            t1 = createNode();
                            if (temp->flag == 0)
                            {
                                temp->down = t1;
                                temp->flag = 1;
                                t2 = temp->down;
                            }
                            else
                            {
                                while (t2->next !=NULL)
                                {
                                    t2 = t2->next;
                                }
                                t2->next = t1;
                            }
                            
                        }

                    break; 
                    }

                    temp = temp->next;
                }
                
            }
            
        }
        
    }

    void insertSubSection()
    {
         if (head == NULL)
        {
            cout<<"\n Book does not exist"<<endl;
        }
        else
        {
            cout<<"\n Enter the chapter name in which you want to enter the sub section "<<endl;
            cin>>ch;

            temp = head;
            if (temp->flag == 0)
            {
                cout<<"\n Chapter does not exist"<<endl;
            }
            else
            {
                temp = temp->down;
                while (temp->next!=NULL)
                {
                    if (!strcmp(ch,temp->name))
                    {
                        cout<<"\n Enter the section name in which you wish to enter the sub section"<<endl;
                        cin>>ch;

                        if (temp->flag == 0)
                        {
                            cout<<"\n No section exist"<<endl;
                        }
                        else
                        {
                            temp=temp->down;
                            while (temp->next!=NULL)
                            {
                                if (!strcmp(ch,temp->name))
                                {
                                    cout<<"\n Enter the number of sub sections"<<endl;
                                    cin>>n;

                                    for (i = 0; i < n; i++)
                                    {
                                        t1=createNode();
                                        if (temp->flag ==0)
                                        {
                                            temp->down = t1;
                                            temp->flag = 1;
                                            t2=temp->down;
                                        }

                                        else
                                        {
                                            while (t2->next!=NULL)
                                            {
                                                t2 = t2->next;
                                            }
                                            t2->next = t1;
                                        }
                                        
                                    }
                                    
                                break;
                                }
                                temp=temp->next;
                            }
                            
                        }
                        
                    }
                    temp= temp->next;
                }
                
            }
            
        }
    }

    void displayBook()
    {
        if (head == NULL)
        {
            cout<<"\n Book does not exist"<<endl;
        }
        else
        {
            temp = head;
            cout<<"\n Name of the Book : \t"<<temp->name<<endl;
            if (temp->flag == 1)
            {
                temp = temp->down;
                while (temp!=NULL)
                {
                    cout<<"\n Name of Chapter : \t"<<temp->name<<endl;
                    t1=temp;
                    if (t1->flag==1)
                    {
                        t1=t1->down;
                        while (t1!=NULL)
                        {
                            cout<<"\n Name of Section : \t"<<t1->name<<endl;
                            t2=t1;

                            if (t2->flag == 1)
                            {
                                t2=t2->down;
                                while (t2!=NULL)
                                {
                                    cout<<"\n Name of Sub Section : \t"<<t2->name<<endl;
                                    t2=t2->next;
                                }
                                
                            }

                            t1=t1->next;
                            
                        }
                        
                    }
                    temp=temp->next;
                    

                }
                
            }
            
        }
    }
};



int main()
{

    int choice;
    Book b;
    while (1)
    {
    
    cout<<endl<<"1.Insert Book \n 2.Insert Chapter 3.Insert Section  \n 4.Insert Sub Section \n 5.Display Book \n 6.Exit"<<endl;
    cin>>choice;
    
        switch (choice)
        {
            case 1:
                b.insertBook();
                break;
            
            case 2:
                b.insertChapter();
                break;

            case 3:
                b.insertSection();
                break;

            case 4:
                b.insertSubSection();
                break;

            case 5:
                b.displayBook();
                break;
            case 6:
                exit(0);
            default:
                break;
        }
    }
      
    return 0;
}
