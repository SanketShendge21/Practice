#include<iostream>
#include<string.h>
using namespace std;


class Flight
{
    public:
    int amount[10][10];
    char city_index[10][10];

    Flight()
    {
        int i,j;
        for (i = 0; i < 10; i++)
        {
            strcpy(city_index[i],"xx");
        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                amount[i][j] = 0;
            }
            
        }
        
        
    }

    int create()
    {
        int city_count=0,si,di,j,wt;
        char s[10],d[10],c;
        do
        {
            cout<<"Enter source city"<<endl;
            cin>>s;

            cout<<"Enter destination city"<<endl;
            cin>>d;

            for(j=0;j<10;j++)
            {
                if (strcmp(city_index[j],s)==0)
                {
                    cout<<"\n City is already present";
                    break;
                }
                
            }
            if (j==10)
            {
                strcpy(city_index[city_count],s);
                city_count++;
            }
            for(j=0;j<10;j++)
            {
                if (strcmp(city_index[j],d)==0)
                {
                    cout<<"\n City is already present";
                    break;
                }
                
            }
            if (j==10)
            {
                strcpy(city_index[city_count],d);
                city_count++;
            }

            cout<<"\n\t Enter Distance From "<<s<<" And "<<d<<": ";
		    cin>>wt;
            
            for (j = 0; j < 10; j++)
            {
                if (strcmp(city_index[j],s)==0)
                    si=j;
                if (strcmp(city_index[j],d)==0)
                    di=j;
                
            }

            amount[si][di] = wt;
            cout<<"\n\t Do you want to add more cities.....(y/n) : ";
		    cin>>c;	
        } while (c=='y'||c=='Y');
        return (city_count);
        
    }

    void display(int city_count)
    {
        int i,j;
        cout<<"\n\t Adjacency Matrix : \n\t";
        for (i = 0; i < city_count; i++)
        {
            cout<<"\t "<<city_index[i];
        }
        cout<<"\n";

        for (i = 0; i < city_count; i++)
        {
            cout<<"\t"<<city_index[i];
            for (j = 0; j < city_count; j++)
            {
                cout<<"\t"<<amount[i][j];
            }
            cout<<"\n";
            
        }
        
        
    }
};

int main()
{
    Flight f;
    int choice,city_count;
    char c;

    do
    {
        cout<<"******* Flight Main Menu ********"<<endl;
        cout<<"\n\t 1.Create \n\t 2.Adjacency Matrix \n\t3.Exit";
        cout<<"\n\t Enter your choice ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            city_count = f.create();
            break;
        
        case 2:
            f.display(city_count);
            break;

        case 3:
            return 0;
        }

        cout<<"\n\t Do you want to continue with main menu.....(y/n) : ";
		    cin>>c;	
        } while (c=='y'||c=='Y');

    return 0;
}