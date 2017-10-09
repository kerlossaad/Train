#include <iostream>
#include <fstream>

using namespace std;

// declare the input file
  ifstream input_file("in.1",ios::in);
// declare the output file
  ofstream output_file("out.1",ios::out);


  class SIMPLER_TRAIN{

   public:      		// public methods for this class

        SIMPLER_TRAIN(int);	// example: e(a);
				// constructor to create an object;
                        	// with a elements and read the elements from the
				// input file;
                        	// returns nothing (void)
        void SIMPLER_TRAIN_PATH(int);
        			// example: e.SIMPLER_TRAIN_PATH(m);
        			// list departure stations with id m;
        			// returns no values;
		void SIMPLER_TRAIN_MILES(int);
				// example: e.SIMPLER_TRAIN_MILES(x);
				// list all train paths longer than x;
				// returns no values;
		void SIMPLER_MAX_MIN(int);
        			// example: e.SIMPLER_MAX_MIN(a);
        			// if a is -1,find the shortest distance;
        			// if a is 1,find the longest distance;
        			// returns int values
        void SIMPLER_DIRECT_CHECK(int,int);
        			// example: e.SIMPLER_DIRECT_CHECK(a,b);
        			// check if you can go from departure station a
        			// to arrival station b;
                        	// returns no values;

   private: // private var to be used by this class only (not from main)

        int n;  	// number of train paths;
        int departure[20];	// departure station no.
        int arrival[20];	// arrival station no.
	int miles[20];  // miles from departure station to arrival station;
	int price[20];  // ticket price;
   };




 SIMPLER_TRAIN::SIMPLER_TRAIN(int x)
 {
         // your constructor goes here:
n=x;
int j = 0;	
	
       	
		if( n > 1)		
		{
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       			cout<<"+++ OUTPUT FROM SIMPLER_TRAIN_CONSTRUCTOR:"<<endl;
       			cout<<"+++ SIMPLER_TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
       			cout<<"+++ THERE ARE "<< n <<" TRAIN PATHS IN THIS SIMPLER_TRAIN OBJECT."<<endl;
       			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       			output_file<<"+++ OUTPUT FROM SIMPLER_TRAIN_CONSTRUCTOR:"<<endl;
       			output_file<<"+++ SIMPLER_TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
       			output_file<<"+++ THERE ARE "<< n <<" TRAIN PATHS IN THIS SIMPLER_TRAIN OBJECT."<<endl;
       			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
 		}
		else {
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       			cout<<"+++ OUTPUT FROM SIMPLER_TRAIN_CONSTRUCTOR:"<<endl;
       			cout<<"+++ SIMPLER_TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
       			cout<<"+++ THERE ARE "<< n <<" TRAIN PATH IN THIS SIMPLER_TRAIN OBJECT."<<endl;
       			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       			output_file<<"+++ OUTPUT FROM SIMPLER_TRAIN_CONSTRUCTOR:"<<endl;
       			output_file<<"+++ SIMPLER_TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
       			output_file<<"+++ THERE ARE "<< n <<" TRAIN PATH IN THIS SIMPLER_TRAIN OBJECT."<<endl;
       			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		}	
		for (j=0; j<n; j++)
		{
			input_file >> departure[j]
			  	   >> arrival[j] 	
 			           >> miles[j]
			   	   >> price[j];
		}
}

 void SIMPLER_TRAIN::SIMPLER_TRAIN_PATH(int m)
 {
        // your code for SIMPLER_TRAIN_PATH goes here
int i =0;
int found = 0;
int found_pos = 0;
int j = 0;	

	if( m<0 ||  m>999)
	{
		
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                output_file<<"+++ OUTPUT FROM SIMPLER_TRAIN_PATH METHOD:"<<endl;
                output_file<<"+++ INPUT ERROR."<<endl;
                output_file<<"+++ HAVE A NICE DAY!"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	else{

		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_TRAIN_PATH METHOD:"<<endl;
       		for(i=0; i<n && found == 0; i++)
		{
			if(departure[i] == m)
			{

				output_file<<"+++ DEPART: "<<departure[i] <<" ARRIVE: "<< arrival[i] <<" MILES: "<< miles[i] <<" PRICE: "<< price[i] <<endl;
				found = 1;
				found_pos = i; 
			}
			else{}
		}		
		if(found == 1)
		{	

	
			for( j=(found_pos + 1); j<n; j++)
			{
				if( departure[j] == m)
				{
					output_file<<"+++ DEPART: "<<departure[j] <<" ARRIVE: "<< arrival[j] <<" MILES: "<< miles[j] <<" PRICE: "<< price[j] <<endl; 
				}
				else {}
			}		
		}
		else if( found != 1 && (m>= 0 || m <= 999))		
		{	
			
				output_file<<"+++ THE DEPARTURE STATION "<< m <<" IS: "<<endl;
        			output_file<<"+++ NOT FOUND."<<endl;
		}
		
		
	

        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
}
void SIMPLER_TRAIN::SIMPLER_TRAIN_MILES(int a)
{
		// your code for SIMPLER_TRAIN_MILES goes here
int i = 0;
int found = 0;
int found_pos = 0;


	if((a < 0 ||  a>999) )
	{
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       		cout<<"+++ OUTPUT FROM SIMPLER_TRAIN_MILES METHOD:"<<endl;
        	cout<<"+++ INPUT ERROR."<<endl;
        	cout<<"+++ HAVE A NICE DAY!"<<endl;
        	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_TRAIN_MILES METHOD:"<<endl;
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	else{
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	cout<<"+++ OUTPUT FROM SIMPLER_TRAIN_MILES METHOD:"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_TRAIN_MILES METHOD:"<<endl;
		cout<<"+++ THE TRAIN PATHS LONGER THAN "<< a <<" MILES ARE: "<<endl;
		output_file<<"+++ THE TRAIN PATHS LONGER THAN "<< a <<" MILES ARE: "<<endl;

		for( i = 0; i<n && found == 0; i++)	
		{
	           if( a < miles[i] && (a>=0 && a<= 999) )
		   {
			found = 1;
			found_pos = i;
			cout<<"+++ DEPART: "<<departure[found_pos] <<" ARRIVE: "<< arrival[found_pos] <<" MILES: "<< miles[found_pos]  <<endl; 
			output_file<<"+++ DEPART: "<<departure[found_pos] <<" ARRIVE: "<< arrival[found_pos] <<" MILES: "<< miles[found_pos]  <<endl; 
		   } 
		   else {}
	        }
	        if ( found == 1)
	        {
		   for(int j = (found_pos +1); j<n; j++)
		   {	 						
			if( miles[j] > a )
			{
				cout<<"+++ DEPART: "<<departure[j] <<" ARRIVE: "<< arrival[j] <<" MILES: "<< miles[j]  <<endl; 
				output_file<<"+++ DEPART: "<<departure[j] <<" ARRIVE: "<< arrival[j] <<" MILES: "<< miles[j]  <<endl; 
			}
			else {}
		
		   }
		}
	
		else {}
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
     	}
}

void SIMPLER_TRAIN::SIMPLER_MAX_MIN(int a)
{
	// your code for SIMPLER_MAX_MIN goes here
int i = 0;
int shortest_mileage = 0;
int longest_mileage = 0;
int shortest_mileage_pos = 0;
int longest_mileage_pos = 0;
	    
    if ( a != 1 )
    {	
	shortest_mileage= miles[0];
	shortest_mileage_pos = 0;
	for(i=0; i<n; i++)
	{
	 	if(  miles[i] < shortest_mileage )
		{ 
			shortest_mileage = miles[i];
			shortest_mileage_pos = i;
		}
		else{}
	}
	
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"+++ OUTPUT FROM SIMPLER_MAX_MIN METHOD:"<<endl;
        cout<<"+++ THE TRAIN PATH WITH SHORTEST DISTANCE:"<<endl;
        cout<<"+++ MILES:"<< miles[shortest_mileage_pos] <<""<<endl;
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        output_file<<"+++ OUTPUT FROM SIMPLER_MAX_MIN METHOD:"<<endl;
        output_file<<"+++ THE TRAIN PATH WITH SHORTEST DISTANCE:"<<endl;
        output_file<<"+++ MILES:"<< miles[shortest_mileage_pos] <<""<<endl;
        output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    }
    else {
	
	longest_mileage = miles[0];
	longest_mileage_pos = 0;
	for(i=0; i<n; i++)
	{
	 	if( longest_mileage < miles[i] )
		{ 
			longest_mileage = miles[i];
			longest_mileage_pos = i;
		}
		else{}
	}
		
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	cout<<"+++ OUTPUT FROM SIMPLER_MAX_MIN METHOD:"<<endl;
        	cout<<"+++ THE TRAIN PATH WITH LONGEST DISTANCE:"<<endl;
        	cout<<"+++ MILES:"<< miles[longest_mileage_pos ] <<""<<endl;
        	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_MAX_MIN METHOD:"<<endl;
        	output_file<<"+++ THE TRAIN PATH WITH LONGEST DISTANCE:"<<endl;
        	output_file<<"+++ MILES:"<< miles[longest_mileage_pos ] <<""<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	} 
	
}
void SIMPLER_TRAIN::SIMPLER_DIRECT_CHECK(int a, int b)
{
	// your code for SIMPLER_DIRECT_CHECK goes here
int i = 0;
int found = 0;
int found_pos = 0;
if ( a>= 0 && a <=999)
{   
   for( i = 0; i<n; i++)
   {		
	if( a == departure[i] && b == arrival[i] )
	{ 
		found = 1;
		found_pos = i;
	}
	else{}
   }	
   if(found == 1)
   {
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	cout<<"+++ OUTPUT FROM SIMPLER_DIRECT_CHECK METHOD:"<<endl;
        	cout<<"+++ TRAIN PATH IS FOUND."<<endl;
        	cout<<"+++ DEPART: "<< departure[found_pos] << endl;
        	cout<<"+++ ARRIVE: "<< arrival[found_pos] << endl;
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_DIRECT_CHECK METHOD:"<<endl;
        	output_file<<"+++ TRAIN PATH IS FOUND."<<endl;
        	output_file<<"+++ DEPART: "<< departure[found_pos] << endl;
        	output_file<<"+++ ARRIVE: "<<arrival[found_pos] << endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
   }
   else if( found != 1 && (0<=a<=999) && (0<=b<=999))
   {
	     	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	cout<<"+++ OUTPUT FROM SIMPLER_DIRECT_CHECK METHOD:"<<endl;
        	cout<<"+++ NO SUCH TRAIN PATH."<<endl;
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_DIRECT_CHECK METHOD:"<<endl;
        	output_file<<"+++ NO SUCH TRAIN PATH."<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	
   }
}
else if( (a<0||a>999)||  (b<0||b>999))
{
	     	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	cout<<"+++ OUTPUT FROM SIMPLER_DIRECT_CHECK METHOD:"<<endl;
        	cout<<"+++ INPUT ERROR."<<endl;
        	cout<<"+++ HAVE A NICE DAY!"<<endl;
	     	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLER_DIRECT_CHECK METHOD:"<<endl;
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
else{}
}

