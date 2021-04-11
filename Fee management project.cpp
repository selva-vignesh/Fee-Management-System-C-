/* **************************************************************** COLLEGE FEE MANAGEMENT *****************************************************************************************
Types of Student Registration:
       1. Counselling Regular
       2. Management Regular
       3. Counselling Lateral
       4. Management Lateral
Fee Classification:
       1. Academic Fees (for all students)
       2. Hostel Fees  (for hostellers)
       3. Bus Fees (for daysscholars)
Fee waivers:
       1. Scholarships
       2. Sports
       3. KVITT trust
       4. Private Organization Scholar
       5. Top 5 Academic Excellance (for each department)
 $$$$$$$$$$$$$$$$$$$  Academic Fees  $$$$$$$$$$$$$$$$$$$$$$$$$$
  Fees included for Couns.Reg
       1. Tution fee
       2. Book fee
       3. Exam fee
       4. Other missellanious fee (Only for 1st year)
       5. Placement Training fee (Only for 3rd and 4th years)
 Fees included for Mang.Reg
       1. Donation
       2. Tution Fee
       3. Book Fee
       4. Other Misellanious fees (Only for 1st years)
       5. Placement Training Fee(Only for 3rd and 4th years) 
*/
#include<iostream>
#include<fstream>
using namespace std;

class stud
{
	protected:
		int year;
	public:
		stud()
		{ 
		   cout<<"\t \t FEE MANAGEMENT DATABASE COLLECTION \t \t \n";
		   cout<<"Enter Your details carefully ! \n";
		}
		~stud()
		 {
			cout<<"Your Response has been recorded. \n";
			cout<<"Thank you :)\n";
		 }
		virtual void set()
		{
			cout<<"Enter the Year of study: \n";
			cin>>year;
		}
};
class reg:public stud
{
	protected:
		int bk_fee, ex_fee, tut_fee,om_fee,pl_fee,aca_fee;
	public:
		void set1()
		{
			bk_fee=5000;
			ex_fee=5000;
			tut_fee=75000;
			if (year=1)
				{
					om_fee=25000;
					pl_fee=0;
				}
			if (year=3||4)
			{
				om_fee=0;
				pl_fee=30000;
			}
			if (year=2)
			{
				om_fee=0;
				pl_fee=0;
			}
			
		}
		int display1()
		{
			aca_fee=bk_fee+ex_fee+tut_fee+om_fee+pl_fee;
			return aca_fee;
		}
};

class lat :public reg
{
	protected:
		int bk_fee, ex_fee, tut_fee,pl_fee,aca_fee;
	public:
		void set()
		{
			bk_fee=5000;
			ex_fee=5000;
			tut_fee=65000;
			if (year=3||4)
			{
				pl_fee=30000;
			}
			if (year=2)
			{
				pl_fee=0;
			}
		
			
		}
	int display2()
		{
			cout<<bk_fee<<"  "<<ex_fee<<"  "<<tut_fee<<"   "<<pl_fee<<endl;
		    aca_fee=bk_fee+ex_fee+tut_fee+pl_fee;
			return aca_fee;
		}
};
class waiver
{
	int scholar,dec;
	public:
		void setwaiver()
		{
			cout<<"Enter the scholarship that you got : \n";
			cout<<"1.CSSR Scholar\n 2.BC/MBC Scholar \n 3.Top 5% Academic excellance\n 4.KVIIT Trust Scholar \n 5.Sports Scholar\n 6.None\n";
            cin>>scholar;
        }
        int decduce(){
			if(scholar==1)
			{
				dec=10000;
			}
			else if(scholar==2)
			{
				dec=9000;
			}
			else if(scholar==3)
			{
				dec=35000;
			}
			else if(scholar==4)
			{
				dec=75000;
			}
			else if(scholar=5)
			{
				dec=12000;
			}
			else
			{
				dec=0;
			}
			return dec;
		}
};
int main()
{
	int type_of_mode,a,fine,ac,b,age,c,i;
	string name, roll_no,dept;
	string z;
	int paid;
    stud *p;
    waiver w;
	lat l;
		fstream fs("FEE DETAIL.txt",std::fstream::in|std::fstream::out|std::fstream::app);
	for(int i=0; i<5; i++)
	{
	 	cout<<"Enter your choice : \n";
	    cout<<"1.Entry \n2. Check status \n3.Exit \n";
	    cin>>c;
	 switch(c)
	 {
	    case 1:
	{
	    	cout<<"Enter the mode of admission: \n";
         	cout<<"1. Regular Counselling\n2. Regular Management \n3.Lateral Counselling \n4.Lateral Management \n";
            cin>>type_of_mode;
        	cout<<"Enter your name: \n";
			cin>>name;
			cout<<"Enter your roll number: \n";
			cin>>roll_no;	
			cout<<"Enter your age: \n";
			cin>>age;
			cout<<"Enter your department name :\n";
			cin>>dept;
	if (type_of_mode==1||2)
	{
		    
			l.set1();
			w.setwaiver();
			b=w.decduce();
	        a=l.display1();
    }
    else
	{
    	    p=&l;
            p->set();
            w.setwaiver();
			b=w.decduce();
	        a=l.display2();
  	}
  	        
     	      cout<<"Enter the fine of the Student: \n ";
			  cin>>fine;
		      cout<<"The fee for this Academic year is : " <<a<<endl;
			  cout<<"The Fine amount to be paid is : "<<fine<<endl;
			  ac=a+fine-b;
		      cout<<"The total fee to be paid is : "<<ac<<endl;
		      cout<<"Enter wheater paid or not : \n";
		      cin>>paid;
		      fs<<name<<" "<<roll_no<<" "<<age<<" "<<dept<<" "<<a<<" "<<fine<<" "<<b<<" "<<ac<<" "<<paid<<endl;
			  break;
		  }
		
		case 2:
	         {
			cout<<"Those who are not paid the Fees \n";
			fstream fs("FEE DETAIL.txt",std::fstream::in|std::fstream::out|std::fstream::app);
			 fs>>name>>roll_no>>age>>dept>>a>>fine>>b>>ac>>paid;
			 if(paid==1)
			 {
			 cout<<"Name :"<<name<<"  Roll no :"<<roll_no<<" Age :"<<age<<"   Dept :"<<dept<<" a :"<<a<<"  fine :"<<fine<<"  B ;"<<b<<"  ac :"<<ac<<"   Paid :"<<paid<<endl;}
			 fs>>name>>roll_no>>age>>dept>>a>>fine>>b>>ac>>paid;
			 if (paid==1) cout<<"Name :"<<name<<"  Roll no :"<<roll_no<<" Age :"<<age<<"   Dept :"<<dept<<" a :"<<a<<"  fine :"<<fine<<"  B ;"<<b<<"  ac :"<<ac<<"   Paid :"<<paid<<endl;
			  fs>>name>>roll_no>>age>>dept>>a>>fine>>b>>ac>>paid;
			 if(paid==1) cout<<"Name :"<<name<<"  Roll no :"<<roll_no<<" Age :"<<age<<"   Dept :"<<dept<<" a :"<<a<<"  fine :"<<fine<<"  B ;"<<b<<"  ac :"<<ac<<"   Paid :"<<paid<<endl;
			}
		case 3:
		{
			return 0;
		}
	}
}
}




