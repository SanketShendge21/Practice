#include<iostream>
#include<string.h>
using namespace std;

class HashFunction
{
    public:
    typedef struct hash
    {
        long key;
        char name[10];
    }hash;

    hash h[10];

    HashFunction()
    {
        for (int i = 0; i < 10; i++)
        {
            h[i].key = -1;
            strcpy(h[i].name,"NULL");
        }
        
    }

    void deleteKey(long k)
    {
        int index = find(k);
        if (index == -1)
        {
            cout<<"\n Key not found \n";
        }
        else
        {
            h[index].key = -1;
            strcpy(h[index].name,"NULL");
            cout<<endl<<"Key is deleted"<<endl;
            
        }
        
    }

    long find(long key)
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            if(h[i].key == key)
            {
                cout<<"Key Found At"<<i<<" Location With Name "<<h[i].name<<endl;
                return i;
            }
        }

        if(i==10)
        {
            cout<<"Key not found"<<endl;
            return -1;
        }

        return 0;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout<<endl<<"Key : "<<h[i].key<<"Value : "<<h[i].name<<endl;
        }
        
    }

    void insert()
    {
        int count=0,hash_ind,flag;
        long key;
        char c_name[10];
        int ktemp;
        char ntemp[10],ans;

        do
        {
            cout<<endl<<count;
            if (count>=10)
            {
                cout<<"Hash Table is FUll";
                break;
            }

            cout<<"Enter Number"<<endl;
            cin>>key;

            cout<<"Enter Name"<<endl;
            cin>>c_name;

            hash_ind = key%10;

            if (h[hash_ind].key == -1)
            {
                h[hash_ind].key = key;
                strcpy(h[hash_ind].name,c_name);
            }
                else if(h[hash_ind].key%10 != hash_ind)
                {
                    
                        ktemp = h[hash_ind].key;
                        strcpy(ntemp,h[hash_ind].name);
                        h[hash_ind].key = key;
                        strcpy(h[hash_ind].name,c_name);

                        for (int i = hash_ind+1; i < 10; i++)
                        {
                        if (h[i].key==-1)
                        {
                            h[i].key = ktemp;
                            strcpy(h[i].name,ntemp);
                            flag = 1;
                            break; 
                        }
                            
                        }
                        
                        for (int i = 0; i < hash_ind && flag==0; i++)
                        {
                            if (h[i].key==-1)
                        {
                            h[i].key = ktemp;
                            strcpy(h[i].name,ntemp);
                            break; 
                        }
                        }
                }    
                    
                else 
                {
                    for (int i = hash_ind+1; i < 10; i++)
                    {
                        if (h[i].key==-1)
                       {
                           h[i].key = ktemp;
                           strcpy(h[i].name,ntemp);
                           flag = 1;
                           break; 
                       }
                    }

                    for (int i = 0; i < hash_ind && flag==0; i++)
                    {
                        if (h[i].key==-1)
                       {
                           h[i].key = ktemp;
                           strcpy(h[i].name,ntemp);
                           break; 
                       }
                    }
                    
                }    

                flag = 0;
                count++;
                cout<<"Do you wish to enter more data? : y/n";
                cin>>ans; 
            
        } while (ans=='y' || ans=='Y');
        
    }
};

int main()
{
    int choice;
    long k;
    char ans;
    HashFunction obj;

    do
    {
        cout<<endl<<"1.Insert \n 2.Search \n 3.Display \n 4.Delete \n 5.Exit"<<endl;

        cout<<"Enter the operation to be performed";
        cin>>choice;

        switch (choice)
        {
            case 1:
                obj.insert();
                break;
            
            case 2:
                cout<<"Enter the key to be searched"<<endl;
                cin>>k;
                obj.find(k);
                break;

            case 3:
                obj.display();
                break;

            case 4:
                cout<<"Enter the key to be deleted"<<endl;
                cin>>k;
                obj.deleteKey(k);
                break;

            default:
                break;
        }
        cout<<"Do you wish to continue : y/n";
        cin>>ans;
    } while (ans=='y' || ans=='Y');
    
    return 0;
}