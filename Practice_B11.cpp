#include<iostream>
#include<string.h>
using namespace std;


struct node
{
    char k[20];
    char m[20];
    node *left;
    node *right;
};

struct node* root = NULL;

class Dict
{
    public:
 

    void create()
    {
        int ch;
        do
        {
            node *temp = new node;
            cout<<"\n Enter keyword ";
            cin>>temp->k;

            cout<<"\n Enter meaning ";
            cin>>temp->m;

            temp->left = NULL;
            temp->right = NULL;

            if (root==NULL)
            {
                root = temp;
            }
            else
            {
                insert(root,temp);
            }

            cout<<"\n Do you wish to continue : y=1/n=0";
            cin>>ch;
            
        }while(ch==1);
    }

    void insert(node *root,node *temp)
    {
        if (strcmp(temp->k,root->k)<0)
        {
            if(root->left == NULL)
            {
                root->left = temp;
            }
            else
            {
                insert(root->left,temp);
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = temp;
            }
            else
            {
                insert(root->right,temp);
            }
            
        }
        
    }

    void displayAsc(node *root)
    {
        node *temp = root;
        if (temp !=NULL)
        {
            displayAsc(temp->left);
            cout<<"\nKeyword : "<<temp->k;
            cout<<"\t Meaning : "<<temp->m;
            displayAsc(temp->right);
        }
        
    }

    int search(node *root,char k[20])
    {
        int comp = 0;
        node *temp = root;
        while(temp!=NULL)
        {
            comp++;
            if (strcmp(k,temp->k) == 0)
            {
                cout<<"\n Number of comparisons :"<<comp;
                return 1;
            }

            else if (strcmp(k,temp->k) < 0)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            
            
        }
        return -1;
        
    }

    int update(node *root,char k[20])
    {

        node *temp = root;
        while (temp!=NULL)
        {
            if(strcmp(k,temp->k) == 0)
            {
                cout<<"Enter New Meaning For Keyword : "<<temp->k;
                cin>>temp->m;
                return 1;
            }

            else if (strcmp(k,temp->k)<0)
            {
               temp = temp->left; 
            }
            else
            {
                temp = temp->right;
            }
            
        }
        
        return -1;
    }

    node *deleteKey(node *root,char k[20])
    {
        node *temp;
        if (root == NULL)
        {
            cout<<"Element not found";
            return root;
        }
        else if (strcmp(k,temp->k)<0)
        {
            root->left = deleteKey(root->left,k);
            return root;
        }
        else
        {
            root->right = deleteKey(root->right,k);
            return root;
        }
        if (root->left == NULL && root->right == NULL)
        {
            temp = root;
            delete temp;
            return NULL;
        }

        if (root->right == NULL)
        {
            temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        if (root->left == NULL)
        {
            temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        temp = minimum(root->right);
        strcpy(root->k,temp->k);
        root->right = deleteKey(root->right,temp->k);
        return root;
        
    }

    node *minimum(node *q)
    {
        while (q->left!=NULL)
        {
            q = q->left;
        }
        return q;
    }

};

    int main()
    {
        char k[20];
        char ans;
        int choice;
        Dict d;
        
        do
        {
            cout<<"\nMenu\n1.Create\n2.Display\n3.Search\n4.Update\n5.Delete\nEnter Your Choice:";
            cin>>choice;
            switch (choice)
            {
            case 1:
                d.create();
                break;
            
            case 2:
                if (root == NULL)
                {
                    cout<<"\nNo element found";
                }
                else
                {
                    d.displayAsc(root);
                }
                break;

            case 3:
                if (root == NULL)
                {
                    cout<<"\n The disctionary is empty";
                }
                else
                {
                    cout<<"\n Enter the keyword which you want to search";
                    
                    cin>>k;
                    d.search(root,k);
                }

                if (d.search(root,k)==1)   
                {
                    cout<<"Keyword Found"<<endl;
                }
                else
                {
                    cout<<"Keyword Not Found"<<endl;
                }
                
                break;

            case 4:
                if (root == NULL)
                {
                    cout<<"\n The disctionary is empty";
                }
                else
                {
                    cout<<"\n Enter the keyword which you want to update its meaning";
                    cin>>k;
                    d.update(root,k);
                }

                 if (d.update(root,k)==1)   
                {
                    cout<<"Meaning Updated"<<endl;
                }
                else
                {
                    cout<<"Meaning Not Found"<<endl;
                }
                break;

            case 5:
                if (root == NULL)
                {
                    cout<<"\n The dictionary is empty";
                }
                else
                {
                    cout<<"\n Enter the keyword which you want to delete";
                    cin>>k;
                    node *temp = d.deleteKey(root,k);
                    cout<<"\n The keyword"<<temp->k<<" deleted";
                }
  
            default:
                break;
            }
                          
            cout<<"\n Do you wish to continue in the main menu";
            cin>>ans;
        } while (ans=='y'||ans=='Y');
        

        return 0;
    }
