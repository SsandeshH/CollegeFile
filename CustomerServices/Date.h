class Date{
    int year,month,day;
public:
	Date(int m,int d){
		year=0;
		month=m;
		day=d;
	}
    Date():year(0),month(0),day(0){}
    Date(int y,int m,int d):year(y),month(m),day(d){}
    
    //getters&setters
    int getYear(){
    	return year;
	}
	int getMonth(){
		return month;
	}
	int getDay(){
		return day;
	}
	void setYear(int y){
		year=y;
	}
	void setMonth(int m){
		month=m;
	}
	void setDay(int d){
		day=d;
	}

};