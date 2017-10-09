#include <iostream>
#include <fstream>

using namespace std;

// declare the input file
  ifstream input_file("in.2",ios::in);
// declare the output file
  ofstream output_file("out.2",ios::out);

  class SIMPLE_TRAIN{

   public:  

        SIMPLE_TRAIN(int);	// example: e(x);
			// constructor to create an object;
                       	// with x elements and read the elements from the
			// input file;      
        			
	void SIMPLE_TRAIN_LIST_PRICE(int, int);
			// example: e.SIMPLE_TRAIN_LIST_PRICE(x, y);
			// if x is 1, find train paths whose fares are 
			// more than y;
			// if x is -1, find train paths whose fares are 
			// less than y;
			// if x is 0, find train paths whose fares are 
			// equal y;
			// returns no values;

	void SIMPLE_TRAIN_SORT_MILES(int);
			// example: e.SIMPLE_TRAIN_SORT_MILES(x);
			// if x is 1, sort train paths in ascending order 
			// based on their distance to the destinations;
			// if x is -1, sort train paths in descending order 
			// based on their distance to the destinations;
			// if x is 0, list the train paths without sorting
			// in the order they are stored in miles[] array;
			// returns no values;
	
   private: // private var to be used by this class only (not from main)

        int n;  	  // number of train paths;
        int departure[20];// departure station number
        int arrival[20]; // arrival station number
	int miles[20];   // miles from departure station to arrival station;
	int price[20];   // ticket price;
   };

SIMPLE_TRAIN::SIMPLE_TRAIN(int x)
{
n = x;
int i = 0;
	
	for( i = 0; i<n; i++)
	{
		input_file >>departure[i];
		input_file >>arrival[i];	
		input_file >>miles[i];
		input_file >>price[i];
	}
	cout<< departure[2] << " heyyyyyyyyyy "<<endl;	
 	if(n>1)
	{
	       output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
 	       output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_CONSTRUCTOR:"<<endl;
 	       output_file<<"+++ SIMPLE_TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
 	       output_file<<"+++ THERE ARE "<< n <<" TRAIN PATHS IN THIS SIMPLE_TRAIN OBJECT."<<endl;
 	       output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	else{

	       output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
 	       output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_CONSTRUCTOR:"<<endl;
 	       output_file<<"+++ SIMPLE_TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
 	       output_file<<"+++ THERE IS "<< n <<" TRAIN PATH IN THIS SIMPLE_TRAIN OBJECT."<<endl;
 	       output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
}	
void
SIMPLE_TRAIN::SIMPLE_TRAIN_LIST_PRICE(int x, int y)
{
int i = 0;
int  j = 0;  
int z = 0; 
int found = 0;

	if(( x!= 1 && x!= -1 && x!= 0) ||( y<0 || y>999))
	{
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_LIST_PRICE:"<<endl;
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	
	else{
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_LIST_PRICE:"<<endl;
		if ( x == 1)
		{
					
			for( i = 0; i<n; i++)
			{
				if ( price[i]>y)
				{
					if(i==0)
					{
					
						output_file<<"+++ THE TRAIN PATHS WITH FARES MORE THAN "<< y <<" ARE:"<<endl;
					}
					output_file<<"+++ FARE:"<< price[i]<<" STATION "<< departure[i] <<" STATION "<< arrival[i] <<endl;
					found++;
				}
				else{}
			}
			if( found == 0)
			{
        			output_file<<"+++ NO TRAIN PATHS WITH MATCHING FARES ARE FOUND."<<endl;
			}
			else{}
		}
		else if( x == -1)
		{
			for( j = 0; j< n; j++)
			{
				if ( price[j]<y)
				{
					if(j==0)
					{
					
						output_file<<"+++ THE TRAIN PATHS WITH FARES LESS THAN "<< y <<" ARE:"<<endl;
					}
					output_file<<"+++ FARE:"<< price[j]<<" STATION "<< departure[j] <<" STATION "<< arrival[j] <<endl;
					found++;
				}
				else{}
			}
			if( found == 0)
			{
        			output_file<<"+++ NO TRAIN PATHS WITH MATCHING FARES ARE FOUND."<<endl;
			}
			else{}
		}
		else if( x == 0)	
		{
			for( z = 0; z<n; z++)
			{
				if( price[z] == y)
				{
					if(z==0)
					{
					
						output_file<<"+++ THE TRAIN PATHS WITH FARES EQUAL TO"<< y <<" ARE:"<<endl;
					}
					output_file<<"+++ FARE:"<< price[z]<<" STATION "<< departure[z] <<" STATION "<< arrival[z] <<endl;
					found++;
				}
				else{}
			}
			if( found == 0)
			{
        			output_file<<"+++ NO TRAIN PATHS WITH MATCHING FARES ARE FOUND."<<endl;
			}
			else{}
		
		}
		
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}


}

void
SIMPLE_TRAIN::SIMPLE_TRAIN_SORT_MILES(int x)
{
int max = 0;
int max_pos = 0;
int min = 0;
int min_pos = 0;
int temp = 0;
int i = 0; int j= 0; int k = 0; 

	
	if((x!=0 && x!= -1 && x!= 1))
	{
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_SORT_MILES: "<<endl;
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	else{
		if( x==1 ) 
		{
			for( i = 0; i<n; i++)
			{
				min = miles[i];
				min_pos = i;
				for( j=i; j<n; j++)
				{
					if( miles[j] < min)
					{
						min = miles[j];
						min_pos = j;
					}
					else{}
				}
				
				// swapping the input file
				temp = miles[i];
				miles[i] = miles[min_pos];
				miles[min_pos] = temp;
		 
				// swapping the input file
				temp = departure[i];
				departure[i] = departure[min_pos];
				departure[min_pos] = temp;

				// swapping the input file
				temp = arrival[i];
				arrival[i] = arrival[min_pos];
				arrival[min_pos] = temp;
			}
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_SORT_MILES:"<<endl;
        		output_file<<"+++ THE TRAIN PATHS LISTED:"<<endl;
			for( k = 0; k<n; k++)
			{
				output_file<<"+++ MILES: "<< miles[k] <<" STATION "<< departure[k] <<" STATION "<< arrival[k] <<endl;
			}
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		}
		else if( x==-1 ) 
		{
			for( i = 0; i<n; i++)
			{
				max_pos = i;
				max = miles[i];
				for( j=i; j<n; j++)
				{
					if( miles[j] >  max)
					{
						max = miles[j];
						max_pos = j;
					}
					else{}
				}
				
				// swapping the input file
				temp = miles[i];
				miles[i] = miles[max_pos];
				miles[max_pos] = temp;
		 
				// swapping the input file
				temp = departure[i];
				departure[i] = departure[max_pos];
				departure[max_pos] = temp;

				// swapping the input file
				temp = arrival[i];
				arrival[i] = arrival[max_pos];
				arrival[max_pos] = temp;
			}
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_SORT_MILES:"<<endl;
        		output_file<<"+++ THE TRAIN PATHS LISTED:"<<endl;
			for( k = 0; k<n; k++)
			{
				output_file<<"+++ MILES: "<< miles[k] <<" STATION "<< departure[k] <<" STATION "<< arrival[k] <<endl;
			}
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		}
		else if( x == 0)
		{
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			output_file<<"+++ OUTPUT FROM SIMPLE_TRAIN_SORT_MILES:"<<endl;
			output_file<<"+++ THE TRAIN PATHS LISTED:"<<endl;
			for( i = 0; i<n; i++)
			{
				output_file<<"+++ MILES: "<< miles[i] <<" STATION "<< departure[i] <<" STATION "<< arrival[i] <<endl;
			}		
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		}
		else{}
	

	}

}
