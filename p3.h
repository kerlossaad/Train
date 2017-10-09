#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// declare the input file
  ifstream input_file("in.3",ios::in);
// declare the output file
  ofstream output_file("out.3",ios::out);

 class TRAIN{

   public:  

     	TRAIN(int );	// example: e(x);
			// constructor to create an object;
                  	// with x elements and read the elements from the
			// input file;      
        					
	void FIND_DIRECT_TRAIN_FARE(char *, char *);
			// example: e. FIND_DIRECT_TRAIN_FARE("NYP, "NBK");
			// find fare for the direct train path whose 
			// departure station is NYP and arrival station is NBK;
			// returns no values;

	void FIND_DIRECT_TRAIN_MILES(char *, int);
			// example: e.FIND_DIRECT_TRAIN_MILES ("NYP", x);
			// if x dollar is spent, find miles for the direct train
			// paths whose departure station is "NYP";
			// returns no values;

	void SORT_TRAIN_STATION(int);
			// example: e.SORT_TRAIN_STATION (x);
			// if x is 1, sort train destinations in alphbetical order;
			// if x is 0, list the train paths without sorting;
			// returns no values;
						
	void TRAIN_LIST(int, int);
			// example: e.TRAIN_LIST(x, m);
			// if x=1, list the train paths whose miles are 
			// more than m in alphabetical order based on 
			// their names of destinations;;
			// if x is -1, list the train paths whose miles are 
			// less than m in alphabetical order based on 
			// their names of destinations;
			// if x is 0, list the train paths whose miles are 
			// equal to m in alphabetical order based on their 
			// destinations;
			// returns no values;

   private: // private var to be used by this class only (not from main)

      	int n;  	  	// number of train paths;
      	int departure[20];	// departure station number
      	int arrival[20]; 	// arrival station number
	int miles[20];   	// miles from departure station to arrival station;
	int price[20];   	// ticket price;
	char depart_name[20][10]; // departure station names;
	char arrive_name[20][10]; // arrival station names;
 };
 
TRAIN::TRAIN(int x)
{
int i = 0;
n = x;

	for( i = 0; i<n; i++)
	{
		input_file >> departure[i]
			   >> arrival[i]
			   >> depart_name[i]
			   >> arrive_name[i]
			   >> miles[i]
			   >> price[i];
	}
	if( n > 1)
	{
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM TRAIN_CONSTRUCTOR:"<<endl;
        	output_file<<"+++ TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
        	output_file<<"+++ THERE ARE "<< n <<" TRAIN PATHS IN THIS TRAIN OBJECT."<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	else{	
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM TRAIN_CONSTRUCTOR:"<<endl;
        	output_file<<"+++ TRAIN CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT."<<endl;
        	output_file<<"+++ THERE IS " << n << " TRAIN PATH IN THIS TRAIN OBJECT."<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
}
void 
TRAIN::FIND_DIRECT_TRAIN_FARE(char * s1, char * s2)
{
int i = 0;
int found = 0;
int found_pos = 0;

	if( (strlen(s1) > 9 || strlen(s2) >9 ) )
	{
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM FIND_DIRECT_TRAIN_FARE:"<<endl;
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
	else{
		for( i = 0; i<n; i++)
		{
			if( (strcmp(depart_name[i], s1) == 0) && (strcmp(arrive_name[i], s2) == 0))
			{
				found = 1;
				found_pos = i;
			}
			else{}
		}
		if( found == 0)
		{
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
   		        output_file<<"+++ OUTPUT FROM FIND_DIRECT_TRAIN_FARE:"<<endl;
   		        output_file<<"+++ NO TRAIN PATHS WITH MATCHING STATIONS ARE FOUND."<<endl;
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		}
		else if( found == 1)
		{
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        		output_file<<"+++ OUTPUT FROM FIND_DIRECT_TRAIN_FARE:"<<endl;
        		output_file<<"+++ FROM STATION "<<depart_name[found_pos] <<" (NO."<< departure[found_pos] <<")"<<endl;
        		output_file<<"+++ TO STATION "<< arrive_name[found_pos] <<" (NO."<< arrival[found_pos] <<")"<<endl;
        		output_file<<"+++ FARE IS "<< price[found_pos] <<"."<<endl;
			output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		}
	}
}
void 
TRAIN::FIND_DIRECT_TRAIN_MILES(char * s, int x)
{
int i = 0;
int found = 0; 
	if( (strlen(s) > 9) || x > 9999 ) 
	{
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM FIND_DIRECT_TRAIN_MILES:"<<endl;
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

	}

	else{
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        	output_file<<"+++ OUTPUT FROM FIND_DIRECT_TRAIN_MILES:"<<endl;
		for( i = 0; i<n; i++)
		{
			if( (strcmp(depart_name[i], s) == 0) && x == price[i])
			{
		
				if( found == 0)
				{
					output_file<<"+++ FARE: "<< x <<endl;
				}
				else{}
				
				output_file<<"+++ TRAVEL "<< miles[i] <<" MILES FROM DEPARTURE STATION "<< depart_name[i] <<endl;
				found++;
			}
			else{}
		}
		if( found == 0)
		{
			output_file<<"+++ DEPARTURE STATION "<< s <<" WITH FARE "<< x << endl;
        		output_file<<"+++ NO SUCH TRAIN PATHS ARE FOUND. "<<endl;
		}
		else{}
        	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}

}
void TRAIN::SORT_TRAIN_STATION(int x)
{
int i = 0;
int j = 0;
int k = 0;
char min_name[11];
char max_name[11];
char equal_name[11];
char temp_name[11];
int min_pos = 0;
int max_pos = 0;
int equal_pos = 0;
int temp= 0;	
	
	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        output_file<<"+++ OUTPUT FROM SORT_TRAIN_STATION:"<<endl;
	if( x != 0 && x!= 1)
	{
        	output_file<<"+++ INPUT ERROR."<<endl;
        	output_file<<"+++ HAVE A NICE DAY!"<<endl;
	}
	else{

		if( x == 0 )
		{
			for( k = 0; k<n; k++)
			{
				if( k == 0)
				{
					output_file<<"+++ TRAIN PATHS LISTED:"<<endl;
				}
				else{}
			
				output_file<<"+++ DEPART: "<< depart_name[k] <<"(NO."<< departure[k] <<") ARRIVE: "<< arrive_name[k] <<"(NO."<< arrival[k] <<")"<<endl;
			}
		}		
		else if( x == 1)
		{
			for( i = 0; i<n; i++)
			{
				strcpy(min_name, arrive_name[i]);
				min_pos = i;
				
			
				for( j = i; j<n; j++)
				{
					if( (strcmp(arrive_name[j], min_name)<0))
					{
						strcpy(min_name, arrive_name[j]);
						min_pos = j;
					}
					else{}
				}	
			
				//swapping of the input file alphabetically 		
				strcpy( temp_name, depart_name[i] );
				strcpy( depart_name[i], depart_name[min_pos] );
				strcpy( depart_name[min_pos], temp_name );
			
				strcpy( temp_name, arrive_name[i] );
				strcpy( arrive_name[i], arrive_name[min_pos] );
				strcpy( arrive_name[min_pos], temp_name );
	
				temp = departure[i];
				departure[i] = departure[min_pos];
				departure[min_pos] = temp;

				temp = arrival[i];
				arrival[i] = arrival[min_pos];
				arrival[min_pos] = temp;

				
				temp = miles[i];
				miles[i] = miles[min_pos];
				miles[min_pos] = temp;
			
				temp = price[i];
				price[i] = price[min_pos];
				price[min_pos] = temp;
			}	
			for( k = 0; k<n; k++ )
			{
				if( k == 0)
				{
					output_file<<"+++ TRAIN PATHS SORTED IN ALPHABETICAL ORDER:"<<endl;
				}
				else{}
			
				output_file<<"+++ DEPART: "<< depart_name[k] <<" (NO."<< departure[k] <<") ARRIVE: "<< arrive_name[k] <<" (NO."<< arrival[k] <<")"<<endl;
			}
		}
		else{}
	}	
	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void 
TRAIN::TRAIN_LIST(int x, int m)
{
int i = 0;
int j = 0;
int k = 0;
char min_name[11];
char max_name[11];
char equal_name[11];
char temp_name[11];
int min_pos = 0;
int max_pos = 0;
int equal_pos = 0;
int temp= 0;
int found = 0;	
if( (x != 0 && x!= -1 && x!= 1) || ( m < 0 || m > 999))
{	
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	        output_file<<"+++ OUTPUT FROM TRAIN_LIST_PRICE:"<<endl;
	        output_file<<"+++ INPUT ERROR."<<endl;
	        output_file<<"+++ HAVE A NICE DAY!"<<endl;
	        output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
else{
	for( i = 0; i<n; i++)
	{
		strcpy(min_name, arrive_name[i]);
		min_pos = i;
			
			
		for( j = i; j<n; j++)
		{
			if( (strcmp(arrive_name[j], min_name)<0))	
			{
				strcpy(min_name, arrive_name[j]);
				min_pos = j;
			}
			else{}
		}	
			
		//swapping of the input file alphabetically 		
		strcpy( temp_name, depart_name[i] );
		strcpy( depart_name[i], depart_name[min_pos] );
		strcpy( depart_name[min_pos], temp_name );
			
		strcpy( temp_name, arrive_name[i] );
		strcpy( arrive_name[i], arrive_name[min_pos] );
		strcpy( arrive_name[min_pos], temp_name );
	
		temp = departure[i];
		departure[i] = departure[min_pos];
		departure[min_pos] = temp;

		temp = arrival[i];
		arrival[i] = arrival[min_pos];
		arrival[min_pos] = temp;

				
		temp = miles[i];
		miles[i] = miles[min_pos];
		miles[min_pos] = temp;
			
		temp = price[i];
		price[i] = price[min_pos];
		price[min_pos] = temp;
	}
	
	output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        output_file<<"+++ OUTPUT FROM TRAIN_LIST:"<<endl;
        output_file<<"+++ TRAIN PATHS SORTED IN ALPHABETICAL ORDER:"<<endl;
		
		for( k= 0; k<n; k++)
		{
			if( x == 1)
			{
				if( miles[k] > m )
				{	
					if( found  == 0)
					{
						output_file<<"+++ THE TRAIN PATHS WITH MILES MORE THAN "<< m <<" ARE "<<endl;
					}
					else{}
        				output_file<<"+++ DEPART: "<< depart_name[k] <<"(NO:"<< departure[k] <<") ARRIVE: "<< arrive_name[k] <<"(NO:" <<arrival[k] <<")"<<endl;
					found++;
				}	
				else{}
			}	
			else if( x == -1)
			{
				if( miles[k] < m )
				{	
					if( found == 0)
					{
						output_file<<"+++ THE TRAIN PATHS WITH MILES LESS THAN "<< m <<" ARE "<<endl;
					}
					else{}
        				output_file<<"+++ DEPART: "<< depart_name[k] <<"(NO:"<< departure[k] <<") ARRIVE: "<< arrive_name[k] <<"(NO:" <<arrival[k] <<")"<<endl;
					found++;
				}
				else{}
			}	
			else if( x == 0)
			{
				if( miles[k] == m )
				{	
					if( found == 0)
					{
						output_file<<"+++ THE TRAIN PATHS WITH MILES EQUAL TO "<< m <<" ARE "<<endl;
					}
					else{}
					found++;
        				output_file<<"+++ DEPART: "<< depart_name[k] <<"(NO:"<< departure[k] <<") ARRIVE: "<< arrive_name[k] <<" (NO:" <<arrival[k] <<")"<<endl;
				}
				else{}
			}	
		}
		output_file<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}	
}

