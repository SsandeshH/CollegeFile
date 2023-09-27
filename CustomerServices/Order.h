class Order{
    string orderId;
    Date orderDate;
    Date deliveryDate;
    string deliveryAddress;
public:
	Order(string oid,int y,int m,int d,string dA){
		orderDate=Date(y,m,d);
		deliveryAddress=dA;

	}
    Order():orderId(" "),orderDate(0,0,0),deliveryDate(0,0,0),deliveryAddress(" "){}
    Order(string od,int y,int m,int d,int yy,int mm,int dd,string ad):orderId(od),orderDate(y,m,d),deliveryDate(yy,mm,dd),deliveryAddress(ad){}


    string generateCart(){
    	int a;
    	srand(time(nullptr));
		a=rand();
		
    	return (to_string(a));

    }
 /*
    void emptyCart(){


    }
    bool addProductToCart(Product p,int qty){


    }
*/
	void displayOrder(Order* o,int choice){
		
	}

};