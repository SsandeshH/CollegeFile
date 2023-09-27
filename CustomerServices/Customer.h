class Customer{
protected:
    int customerId;
    string fullName;
    string username;
    string password;
    string email;
public:
	Customer(){
	}
    Customer(int cid,string fn,string us,string pw,string em):customerId(cid),fullName(fn),username(us),password(pw),email(em){}

/*
    bool registerCustomer(){

    }
    
    bool unsubscribe(){

    }
*/    
    void askCustomerInfo(){
    	fflush(stdin);
    	cout<<"Enter Your FullName: ";
    	getline(cin,fullName);
    	
    	fflush(stdin);
		cout<<"What do you want to keep your temporary Username: ";
    	getline(cin,username);
    	
    	fflush(stdin);
		cout<<"Enter Email: ";
    	getline(cin,email);
    	
    	fflush(stdin);
		cout<<"Enter Password: ";
    	getline(cin,password);
    	
    	cout<<endl;
	}


    
};