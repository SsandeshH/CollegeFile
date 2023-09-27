using namespace std;
class PremiumCustomer:public Customer{
	double creditLimit;
	Date premiumDate;
	int premiumLimit;
public:
	PremiumCustomer(){
		Customer();
		creditLimit=0;
	}
	PremiumCustomer(int cid,string fn,string us,string pw,string em,double cd):Customer(cid,fn,us,pw,em),creditLimit(cd){
	}
	
	void askCustomerInfo(){
		double cdnum;
    	string un,pd;
    	fflush(stdin);
    	cout<<"Enter FullName: ";
    	getline(cin,un);
    	
    	fflush(stdin);
		cout<<"Enter Password: ";
    	getline(cin,pd);
    	
    	fflush(stdin);
    	cout<<"Enter Your CreditCard Number (Rs 100 will be reduced from your credit card): ";
    	cin>>cdnum;
    	
    	cout<<"Confirmed!! Enjoy your product surf"<<endl;
	}
/*
	void checkValidation(){
		string un,pd;
    	cout<<"What do you want to keep your temporary Username: ";
    	getline(cin,un);
    	
    	cout<<"Enter Password: ";
    	getline(cin,pd);
		if(username==un && password==pd){
			cout<<"Success";
		}
	}
*/
	void askdetails(){
		fflush(stdin);
    	cout<<"Enter Your username: ";
    	getline(cin,username);
    	
    	fflush(stdin);
		cout<<"Enter Email: ";
    	getline(cin,email);
    	
    	int mn,dy;
    	cout<<"Enter the Date you went premium last time: (MM DD)";
    	cin>>mn>>dy;
    	Date(mn,dy);
    	
    	fflush(stdin);
		cout<<"Enter Password: ";
    	getline(cin,password);
	}
	
	void displayCustomerInfo(){
		cout<<endl<<"Customer Name: "<<fullName;
		cout<<endl<<"Customer Type: Premium"<<endl;
		if(premiumLimit<0){
			cout<<"Premium Limit: None.Time to renew Monthly subscription."<<endl;
		}else{
			cout<<"Premium Limit: "<<premiumLimit<<"Days left"<<endl;
		}
		fflush(stdin);
		cout<<"UserName: "<<username<<endl;
		cout<<"Email: "<<email<<endl;
	}
	void calculatePremiumLimit(){
	 premiumLimit= 29-premiumDate.getDay();	
	}
};