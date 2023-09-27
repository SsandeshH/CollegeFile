#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#include "Date.h"
#include "Product.h"
#include "Order.h"
#include "Customer.h"
#include "GuestCustomer.h"
#include "PremiumCustomer.h"



int main(){
	GuestCustomer g1;
	PremiumCustomer p1;
		
	int choice=0,porg=0;
	char ch;
	//Menu
	cout<<"\t\t\t\t\t\tWelcome To Our Store "<<endl
		<<"Are you\n"
		<<"1. Guest/New Customer\n"
		<<"2. Premium Customer\n"
		<<"Choose (1/2): ";
	cin>>choice;
	
	//Customertype
	switch(choice){
		case 1:
			cout<<endl<<"Hello Guest Customer,Lets get you ready for the Product Purchase: "<<endl;
			g1.askCustomerInfo();
			cout<<"Do you Want to go premium?(Y/N) ";
			cin>>ch;
			if(ch=='Y'||ch=='y'){
				p1.askCustomerInfo();

			}
			break;
		case 2:
			porg=1;
			cout<<endl<<"Hello Premium User, Please Enter your details "<<endl;
			p1.askdetails();
			p1.calculatePremiumLimit();
			break;

		default:
			cout<<endl<<"Please choose (1/2) from the option";
			exit(-1);
			break;		
	}
	cout<<endl<<"Everything is Processed.Please have a fun Experience Shopping at our store.\nPress any key to Continue.";
	getch();
	system("CLS");
	
	//Showing What products we have
	cout<<endl<<"Product Lists: "<<endl;
	Product defaultProduct[5]={Product("1a","Shoes",3,100,120),
								Product("1b","Tshirt",2,100,120),
								Product("1c","Tie",5,50,55),
								Product("1d","Watch",2,200,220),
								Product("1e","Lenses",1,1000,1200)};
	//Instantiating the product array
	
	string pcc, disc;
	int qs,i;
	double us,up;
	
	//Available Stuff
	       	cout<<endl<<"| Product Code \t"
       		<<"| Product Description \t"
       		<<"| Quantity in stock \t"
       		<<"| Unit Sales Price \t"
       		<<"| Total Costprice \t"
       		<<endl;
       		
	for(i=0;i<5;++i){
	defaultProduct[i].displayProductsAvailable();
	}
	
	cout<<endl<<"How many Order do you have? :";
	cin>>choice;
	
	Order o1[choice];		
	Product P1[20];

cout<<endl;

int yr,mn,dy,j=0;
ch='Y';
string dA;
	cout<<endl<<"Enter Order date:(YY MM DD): ";
	cin>>yr,mn,dy;
	
	fflush(stdin);
	cout<<"Enter Delivery Address: ";
	getline(cin,dA);
	
string oid;	
for(i=0;i<choice;i++){
cout<<endl<<"orderId: "<<i+2002;
oid=to_string(i+2002);	
		while(ch=='Y'||ch=='y'){
		fflush(stdin);
		cout<<endl<<"Your "<<j+1<<"th productName: ";
		getline(cin,disc);
		
		fflush(stdin);
		cout<<"Your "<<j+1<<"th ProductCode: ";
		getline(cin,pcc);
		
		cout<<"Total amount of Product You want to order: ";
		cin>>qs;
		
		j++;
		cout<<endl<<"Do you want more product?: (Y/N)";
		cin>>ch;
		P1[j]=Product(disc,pcc,qs);
		}
		cout<<endl<<"Confirm "<<i+1<<"th Order?(Y/N)";
		cin>>ch;
		
		if(ch=='Y'||ch=='y'){
		
		o1[i]=Order(oid,yr,mn,dy,dA);
		cout<<"Your Cart Number: "<<o1[i].generateCart()<<endl;	
		}
		else{
			cout<<endl<<"Orders Not Registered.Plese retry"<<endl;
		}

		}
		
		cout<<endl<<"All your products and Order got registered."
			<<"Here's your Final Order Slip.Press Any Key"<<endl;
			getch();
			system("CLS");
			
		cout<<"\t\t\t***Ordered Product List.***"<<endl;
		
		//Sending a productList and Printing it
		if(porg==1){ //PremiumUser
			p1.displayCustomerInfo();
		}else{		//guestUser
			g1.displayCustomerInfo();
			cout<<"Your Coupon code is: "<<g1.generateCouponCode()<<endl;
		}
		//Displaying
		Product *pptr;
		pptr->listAllProducts(&P1[0],choice);
		
		
	
	return 0;
}