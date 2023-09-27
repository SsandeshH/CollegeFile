class GuestCustomer:public Customer{
    string couponCode;

public:
	GuestCustomer(){
		Customer();
		couponCode="0000";
	}
    GuestCustomer(int cid,string fn,string us,string pw,string em,string cc):Customer(cid,fn,us,pw,em),couponCode(cc){}

		void displayCustomerInfo(){
		cout<<endl<<"Customer Name: "<<fullName;
		cout<<endl<<"Customer Type: Guest"<<endl;
		cout<<"UserName: "<<username<<endl;
		cout<<"Email: "<<email<<endl;
	}
	
	string generateCouponCode(){
		int a;
		srand(time(nullptr));
		a=rand();
		couponCode=a;
    	return (to_string(a));
	}
};