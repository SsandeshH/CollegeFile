class Product{
    string productCode;
    string description;
    int quantityInStock;
    double unitSalesPrice;
    double unitCostPrice;
public:
		Product():productCode("  "),description(" "),quantityInStock(0),unitSalesPrice(0.0),unitCostPrice(0.0){
		}
		
		Product(string pcc,string disc,int qs,double us,double up):productCode(pcc),description(disc),quantityInStock(qs),unitSalesPrice(us),unitCostPrice(up){
		}
		
	//forBuyer
		Product(string pcc,string disc,int qk){
			productCode=pcc;
			description=disc;
			quantityInStock=qk;
			unitSalesPrice=0.0;
			unitCostPrice=0.0;
		}
       

void listAllProducts(Product *pl,int N){
        int i;
        for(i=0;i<N;i++){

                cout<<endl<<"Product Code: "<<pl->productCode;
                cout<<endl<<"Product Description: "<<pl->description;
            //    cout<<endl<<"Product Stock: "<<stock;
                
        }
    }
       //unused
       /*
       bool changePrice(string Pc,double newPrice){


       }
       
       bool deleteproduct(string pc){


       }
       */
       
       void displayProductsAvailable(){
		cout<<"|"<<productCode<<"\t\t\t"<<"|"<<description<<"\t\t\t"<<"|"<<quantityInStock<<"\t\t\t"<<"|"
			<<unitSalesPrice<<"\t\t\t"<<"|"<<unitCostPrice
			<<endl;
		   
       	
	   }

};