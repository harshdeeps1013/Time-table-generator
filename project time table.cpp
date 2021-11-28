#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<limits>
using namespace std;

	struct ai{
	     string teac[30][3];
		 string subject;
		 int no_teach;
		 int no_of_lec;
		 int priority;
	}arr[20];
	
	struct{string m_sec[20][20];
		}sec__[10];
	int just_the_count=0;
	
	
	
	
class stor_inf{
	public:
	static int no__;
	int lab_count;
	 
	 
		void store_subjects()
		{cout<<"enter the subject"<<endl;
		cin>>arr[no__].subject;
		cout<<endl;
		cout<<"enter the no. of lec in a week----";
		cin>>arr[no__].no_of_lec;
		while(1)
		{
		if(cin.fail())
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"You have entered wrong input"<<endl;
		cin>>arr[no__].no_of_lec;
		cin.sync();
		}if(!cin.fail())
			break;
		}

		cout<<endl;
		just_the_count=just_the_count+arr[no__].no_of_lec;
		cout<<"Total lectures assigned"<<just_the_count<<endl<<endl;
		no__++;
		 } 
		 
	

		 void store_labs()
		{string lo;
			cout<<"enter the lab----";
			  cin>>lo;
			arr[no__].subject="LAB"+lo;
			cout<<"enter the no. of labs in a week---";
			  cin>>arr[no__].no_of_lec;
			  	while(1)
					{
					if(cin.fail())
					{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"You have entered wrong input"<<endl;
					cin>>arr[no__].no_of_lec;
					cin.sync();
					}if(!cin.fail())
						break;
					}
			  cout<<endl;
			arr[no__].priority=1;
			just_the_count=just_the_count+2*arr[no__].no_of_lec;
			cout<<"Total lectures assigned"<<just_the_count<<endl<<endl;
		no__++;
		 } 

		 
		stor_inf()
		{int i,j,k;
		
		for(i=0;i<20;i++)
			{for(j=0;j<30;j++)
				{arr[i].teac[j][0]="no teach"+to_string(i)+to_string(j);
				 arr[i].teac[j][1]="0";}
			}}
		
		void assign_teachers()
		{int i,j,k;
		cout<<"Enter The Teachers For Each Subject "<<endl;
		for(i=0;i<no__;i++)
		{
		    cout<<endl<<"__"<<arr[i].subject<<"__"<<endl;
		    cout<<"enter no of teachers ----";
			cin>>arr[i].no_teach;
			for(j=0;j<arr[i].no_teach;j++)
				{cout<<"enter teachers name"<<endl;
				cin>>arr[i].teac[j][0];}
		}
		}};
		
	

class make_sec:public stor_inf{
    public:
		
		int x,y,sec;
		
		 void assign_sec(int y)
		{sec=y;
		}
        
	void intable(int in1,int in2)
    {int i,j,k;
	x=in1;
    y=in2;
    for(k=0;k<sec;k++)
	for(i=0;i<x;i++)
    {for(j=0;j<y;j++)
		{sec__[k].m_sec[i][j]="NULL";}
		}}


   int chk_table(string strl,int a,int b )
   {int flag=0,i,j;
   
   		for(i=0;i<sec;i++)
   		{if(sec__[i].m_sec[a][b]==strl)
    		{flag=1;
	  		break;}
	  	if(i==7)
		{break;}
		}
		
	if(flag==1)
		return 0;
	else
	  	return 1;}
	  	
	
	
	int insert_lab(string str,int k)
    {int i,j;
      for(j=0;j<y;j++)
	   {for(i=0;i<x;i++)
		 {if(chk_table(str,i,j) && chk_table(str,i,j+1) && sec__[k].m_sec[i][j+1]=="NULL" && sec__[k].m_sec[i][j]=="NULL")	
     		{sec__[k].m_sec[i][j]=str;
			 sec__[k].m_sec[i][j+1]=str;
			 return 1;
			 
			 }}}	
			 
	return 0;}
	
	
	
	int insert_(string str,int k)
    {int i,j,l;
     for(j=0;j<y;j++)
		{for(i=0;i<x;i++)
			{
			if(chk_table(str,i,j) && sec__[k].m_sec[i][j]=="NULL")	
     			{
				 sec__[k].m_sec[i][j]=str;
			     return 1;
			 	 }
			 }
		 }	
	return 0;
	 }
   
   void main_system()
   {int ins_count=0,l=0,i,j,k=0,trverse=0;
    string temp_store,cmp="";
    
	for(i=0;i<no__;i++)
	{	if(arr[i].priority==0 && trverse==1)
	   			{continue;}
	
		for(k=0;k<sec;k++)
   			{for(j=0;j<arr[i].no_of_lec;j++) 
   			
   				{
				arr[i].priority=0;
   				cout<<arr[i].subject<<endl;
  		 		temp_store=arr[i].subject;
        		cmp=temp_store.substr(0,3);
        		
        		if(cmp=="LAB")
         			{ins_count=insert_lab(temp_store+"  "+ teac_assignn(i),k);}
		 		else
	    			{ins_count=insert_(temp_store+"  "+ teac_assignn(i),k);}
	    
	    		if(!ins_count)
	    			{j--;}
	    		}
		    }
	
		if(i==no__-1 && trverse==0)
		{i=0;
		trverse=1;
		}
	}
	}   
   
  string teac_assignn(int a)
   	{int tec_count,l=0;
   		for(tec_count=0;tec_count<10;tec_count++)
   		{
   		l=atoi(arr[a].teac[tec_count][1].c_str());
   
   		if(l<20)
    		{
    		l++;
    		arr[a].teac[tec_count][1]=to_string(l);
    		return arr[a].teac[tec_count][0];}
		}
   }
   
   
   
   void shw_table()
    {int i,j,k;
    for(k=0;k<sec;k++)
    {cout<<endl<<"---------------------------------sec_no_"<<k<<"----------------------------------------"<<endl;
	for(i=0;i<x;i++)
    {for(j=0;j<y;j++)
	{cout<<sec__[k].m_sec[i][j]<<"|";}
	cout<<endl<<"_________________________________________"<<endl;
	}
}
   }
   
   
   
   void make_excel_file()
{ofstream ptr{"time_table.csv"};
    int i,j,k;
    string days[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    
	for(k=0;k<sec;k++)
    {ptr<<endl<<endl<<endl<<","<<"SEC-"<<k+1;
    	ptr<<endl;
		for(j=0;j<y;j++)
     	{ptr<<","<<j+1;
			 }
    for(i=0;i<x;i++)
    {ptr<<endl;
	ptr<<days[i]+",";
	for(j=0;j<y;j++)
	{ptr<<sec__[k].m_sec[i][j]<<",";}
	}
	}
   ptr.close();}
}; 

int stor_inf::no__=0 ;



int main()

{int input[20],i,j=0,num_days,num_lec,num_labs,num_sub,as;
string sd;

make_sec ob;
stor_inf ob1;

cout<<"enter no. of work days a week---";
cin>>num_days;
cout<<"enter total no. of lectures-----";
cin>>num_lec;
cout<<"enter no. of sec"<<endl;
cin>>as;
ob.assign_sec(as);
ob.intable(num_days,num_lec);
cout<<endl<<endl;

l:
cout<<"enter 1 to enter subjects "<<endl;
cout<<"enter 2 to enter lab "<<endl;
cout<<"enter 3 to assign teachers"<<endl;
cout<<"enter 4 to process and make time table "<<endl;
cout<<"enter 5 to excel file "<<endl;
cout<<"enter 6 to exit "<<endl;
cin>>i; 
cin.sync();

while(1)
		{
		if(cin.fail())
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"You have entered wrong input"<<endl;
		cin>>i;
		}if(!cin.fail())
			break;
		}
		
if(!(i>0 && i<=6))
{cout<<"enter a option from 1 to 6"<<endl<<endl;;
i=0;
}

cin.sync();
switch(i)
{case 1:
		cout<<"enter no of subjects----";
		cin>>num_sub;
		
		while(1)
		{
		if(cin.fail())
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"You have entered wrong input"<<endl;
		cin>>num_sub;
		cin.sync();
		}if(!cin.fail())
			break;
		}
		
		cin.sync();
        j=0;
		while(j<num_sub)
		{
		ob1.store_subjects();
		j++;
		}
        break;
        
case 2:cout<<"enter no of labs----";
		cin>>num_labs;
			while(1)
		{
		if(cin.fail())
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"You have entered wrong input"<<endl;
		cin>>num_labs;
		cin.sync();
		}if(!cin.fail())
			break;
		}
	
		j=0;
		cin.sync();
        while(j<num_labs)
		{	ob1.store_labs();
		j++;
		} 
        break;

case 3:ob.assign_teachers();
		break;
        
        
case 4: ob.main_system();
        ob.shw_table();
		break;  
		 
case 5:/*ob.make_text_file()*/;
		ob.make_excel_file();
		break;
		
case 6:
	exit(0);

}
goto l;
return 0;
}

