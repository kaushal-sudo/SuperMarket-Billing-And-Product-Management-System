#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
       int pcode;
       float price;
       float dis;
       string pname;

       public:
       void menu();
       void administrator();
       void buyer();
       void add();
       void edit();
       void rem();
       void list();
       void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;
    
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t     SuperMarket Main Menu     \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t| 1) Administrator    |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t| 2) Buyer            |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t| 3) Exit             |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t Please Select!";
    cin>>choice;

    switch (choice){
        case 1:
             cout<<"\t\t\t Please Login \n";
             cout<<"\t\t\t  Enter Email  \n";
             cin>>email;
             cout<<"\t\t\t  Password \n";
             cin>>password;

             if(email=="kaushal@gmail.com" && password=="kaushal@123"){
                administrator();
             }
             else{
                cout<<"Invalid Email/Password";
             }
             break;

        case 2:
             {
                buyer();
             }
        case 3:
             {
                exit(0);
             }

        default:
           {
            cout<<"Please select from the given options";
           }

    }
    goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\t\t\t\t Administrator Menu";
    cout<<"\t\t\t\n|___1) Add The Product____|";
    cout<<"\t\t\t\n|                         |";
    cout<<"\t\t\t\n|___2) Modify The Product_|";
    cout<<"\t\t\t\n|                         |";
    cout<<"\t\t\t\n|___3) Delete The Product_|";
    cout<<"\t\t\t\n|                         |";
    cout<<"\t\t\t\n|___4) Back to main menu__|";


    cout<<"\n\n\t  Please enter your choice";
    cin>>choice;

    switch (choice){
        case 1:
             add();
             break;

        case 2:
             edit();
             break;
        case 3:
             rem();
             break;
        case 4:
             menu();
             break;

        default:
           cout<<"Invalid choice !";

    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"\t\t\t_______________\n";
    cout<<"                     \n";
    cout<<"\t\t\t1) Buy Product \n";
    cout<<"                     \n";
    cout<<"\t\t\t1) Go Back     \n";
    cout<<"\t\t\t Enter Your Choice : ";

    cin>>choice;

    switch(choice)
    {
        case 1:
           receipt();
           break;
        case 2:
           menu();
        //    break;
        default:
          cout<<"Invalid choice";
    }
goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t  Add mew product";
    cout<<"\n\n\t Product code of product : ";
    cin>>pcode;
    cout<<"\n\n\t Product name : ";
    cin>>pname;
    cout<<"\n\n\t Price of the product : ";
    cin>>price;
    cout<<"\n\n\t Discount on product : ";
    cin>>dis;

    data.open("database.txt",ios::in);
   if(!data)
   {
    data.open("database.txt", ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
    data.close();
   }
   else{
    data>>c>>n>>p>>d;
    while (!data.eof())
    {
        if(c==pcode)
        {
            token++;
        }
        data>>c>>n>>p>>d;
    }
    data.close();
    
   if(token==1)
      goto m;
   else{
    data.open("database.txt", ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
    data.close();
   }
   }
   cout<<"\n\n\t\t Record inserted !";

}   

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't Exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code";
                cin>>c;
                cout<<"\n\t\t Name of Product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!"; 
        }
     }
}

void shopping :: rem()
{
     fstream data,data1;
    int pkey;
    int token=0;

    cout<<"\n\t\t\t Delete product";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't Exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!"; 
        }
     }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while (!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;        
    }
    data.close();

}

void shopping :: receipt()
{
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }
    else
    {
        data.close();
        
        list();
        cout<<"\n________________________________________\n";
        cout<<"\n                                        \n";
        cout<<"\n         Please Place the order         \n";
        cout<<"\n________________________________________\n";
        cout<<"\n                                        \n";
        do
        {
            m:
           cout<<"\n\n Enter Product code : ";
           cin>>arrc[c];
           cout<<"\n\n Enter the product Quantity :";
           cin>>arrq[c];
           for(int i=0;i<c;i++){
            if(arrc[c]==arrc[i])
            {
                cout<<"\n\n Duplicate product code. Please try again!";
                goto m;
            }
           }
           c++;
           cout<<"\n\n Do you wnat to buy another product? if yes then press y else no";
           cin>>choice;
        }
        while(choice == 'y');
        cout<<"\n\n\t\t\t___________________RECEIPT____________________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();

    }
    cout<<"\n\n________________________________________________________";
    cout<<"\n\n Total Amount : "<<total;
}


int main()
{
    shopping s;
    s.menu();
}





