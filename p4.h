
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// declare the output file
  ofstream output_file("out.4",ios::out);

 class LOADED_TRAIN{

   public:

        LOADED_TRAIN(int, char *);
        		// example: LOADED_TRAIN e(x, "in_name");
			// constructor to create an object with x elements
			// and read the elements from the file called in_name;

        LOADED_TRAIN();
        		// example: LOADED_TRAIN e2();
        		// second constructor;
                        // create an object with 0 elements;

	void LOADED_PRINT();
			// example: e.LOADED_PRINT();
			// print the train paths information as they appear
			// in the private data members;
			// return no values;

	void LOADED_SORT_STATION();
                        // example: e.TRAIN_SORT_STATION();
			// sort train paths in reverse alphbetical
			// order based on their arrival station names;
                        // returns no values;

	int operator == (int);
			// example: if (e == m)
                        // returns 1 if the number of train paths in e is m;
                        // returns 0 otherwise;

	int operator < (LOADED_TRAIN &);
			// example: if (e2 < e1)
                        // returns 1 if the number of train paths in e2 is
                        // less than those of e1;
                        // returns 0 otherwise;

	void operator -= (int);
			// example: e -= 5000;
			// remove all information of the train paths with
			// arrival station number 5000 and update the
			// private data members;
			// return no values;

	void operator += (int);
			// example: e += 2;
			// increment fare for each train path by 2 dollars;
			// price[] will be modified;
			// return no values;

	void operator = (LOADED_TRAIN );
			// example: e2 = e1;
                        // assign the elements of e1 to e2;
                        // elements of e2 is overwritten;
                        // e1 remains unchanged;
                        // returns no values;

	LOADED_TRAIN operator + (LOADED_TRAIN &);
			// example: e1+e2;
                        // Merge the data in e1 and e2
                        // into a temporary LOADED_TRAIN object;
                        // return this temporary object;



   private: // private var to be used by this class only (not from main)

        int n;  	  // number of train paths;
        int departure[20];// departure station number
        int arrival[20]; // arrival station number
	int miles[20];   // miles from departure station to arrival station;
	int price[20];   // ticket price;
	char depart_name[20][10]; // departure station names;
	char arrive_name[20][10]; // arrival station names;
	char in_file[10]; 	  // hold the input file name
 };

LOADED_TRAIN::LOADED_TRAIN(int x, char * in_name)
{
n = x;
int i = 0;
        
	strcpy (in_file, in_name);
        ifstream input_file( in_file, ios::in);
	      
	for( i = 0; i<n; i++)
	{
		input_file >> departure[i];
		input_file >> arrival[i];
		input_file >> depart_name[i];
		input_file >> arrive_name[i];
		input_file >> miles[i];
		input_file >> price[i];
	}
	
       	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
       	output_file << " +++ OUTPUT FROM LOADED_TRAIN CONSTRUCTOR: " << endl;
       	output_file << " +++ " << n << " TRAIN PATHS ARE CREATED SUCCESSFULLY FROM INPUT FILE " << in_name << "." << endl;
       	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;


}
LOADED_TRAIN::LOADED_TRAIN()
{
n = 0;
}
void 
LOADED_TRAIN::LOADED_PRINT()
{   
int i = 0;
	
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
  	output_file << " +++ OUTPUT FROM LOADED_PRINT METHOD: " << endl;
	for( i = 0; i< n; i++)
	{
		output_file << " +++ DEPARTS: " << depart_name[i] << " ARRIVES: " << arrive_name[i] << " MILES: " << miles[i] << " FARE: " << price[i] << endl;
	}
    	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;


}
void 
LOADED_TRAIN::LOADED_SORT_STATION()
{
int i = 0;
int j = 0;
int max_pos = 0;
char max[11];
char temp_string[11];
int temp;
	for(i = 0; i<n; i++)
	{
		strcpy(max, arrive_name[i]);
		max_pos = i;
		for( j = i; j<n; j++)
		{
			if( strcmp(arrive_name[j], max) > 0)
			{
				strcpy(max, arrive_name[j]);
				max_pos = j;
			}
			else{}
		}
		strcpy(temp_string, arrive_name[i]);
		strcpy(arrive_name[i], arrive_name[max_pos]);
		strcpy(arrive_name[max_pos], temp_string);

		strcpy(temp_string, depart_name[i]);
		strcpy(depart_name[i], depart_name[max_pos]);
		strcpy(depart_name[max_pos], temp_string);
		
		temp = arrival[i];
		arrival[i] = arrival[max_pos];
		arrival[max_pos] = temp;
	
		temp = departure[i];
		departure[i] = departure[max_pos];
		departure[max_pos] = temp;
		
		temp = miles[i];
		miles[i] = miles[max_pos];
		miles[max_pos] = temp;

		temp = price[i];
		price[i] = price[max_pos];
		price[max_pos] = temp;
	}
 	
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
        output_file << " +++ OUTPUT FROM SORT_TRAIN_STATION METHOD: " << endl;
        output_file << " +++ TRAIN PATHS SORTED IN REVERSED ALPHABETICAL ORDER: " << endl;
	
	for( i = 0; i<n; i++)
	{
	        output_file << " +++ DEPARTS: " << depart_name[i] << " ARRIVES: " << arrive_name[i] << " FARE: " << price[i] << endl;
	}
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;	
}		
int 			
LOADED_TRAIN::operator == (int m)
{
	if( n == m)
	{
		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
    		output_file << " +++ OUTPUT OVERLOADED OPERATOR == METHOD: " << endl;
    		output_file << " +++ RETURNS TRUE: THERE ARE  " << m << " TRAIN PATHS. " << endl;
    		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
 		return 1;
	}
	else{	
		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
    		output_file << " +++ OUTPUT OVERLOADED OPERATOR == METHOD: " << endl;
    		output_file << " +++ RETURNS FALSE: THERE ARE NOT " << m << " TRAIN PATHS. " << endl;
    		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
		return 0;

	}
}
int 
LOADED_TRAIN::operator < (LOADED_TRAIN & g)
{
	if( g.n < n )
	{
		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
    		output_file << " +++ OUTPUT OVERLOADED OPERATOR < METHOD: " << endl;
    		output_file << " +++ RETURNS TRUE. " << endl;
    		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
		return 1;
 	}	
	else{
		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
   		output_file << " +++ OUTPUT OVERLOADED OPERATOR < METHOD: " << endl;
    		output_file << " +++ RETURNS FALSE. " << endl;
    		output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
		return 0;
	}	
}
void 
LOADED_TRAIN::operator -= (int m)
{
int i = 0;
int j = 0;
int found = 0;
int found_pos = 0;
	
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	output_file << " +++ OUTPUT OVERLOADED OPERATOR -= METHOD: " << endl;
	for( i = 0; i<n; i++)
	{
		if( arrival[i] == m)
		{
			found_pos = i;
			if(found == 0)
			{	
				output_file << " +++ ARRIVAL STATIONS " << arrive_name[i] << " WITH NUMBER " << arrival[i] << " ARE REMOVED. " << endl;
			}
			found++;
			for( j = i; j<n; j++)
			{
				departure[j] = departure[j+1];
				arrival[j] = arrival[j+1];
				miles[j] = miles[j+1];
				price[j] = price[j+1];
				strcpy(arrive_name[j], arrive_name[j+1]);
				strcpy(depart_name[j], depart_name[j+1]);
			}
			n = n-1;
		}
		else{}
	}
	if( found > 0)
	{
		output_file << " +++ NOW THERE ARE " << n << " TRAIN PATHS. " << endl;
	}
	else{
		output_file << " +++ ARRIVAL STATION WITH NUMBER " << m << " DOES NOT EXIST. " << endl;
		output_file << " +++ UNABLE TO REMOVE ARRIVAL STATION WITH NUMBER " << m <<". " << endl;
	}
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
}
void 
LOADED_TRAIN::operator += (int m)
{
int i = 0;
	for( i = 0; i<n; i++)
	{
		price[i] = price[i] + m;
	}
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	output_file << " +++ OUTPUT OVERLOADED OPERATOR += METHOD: " << endl;
	output_file << " +++ INCREMENT FARE " << m << " FOR ALL TRAIN PATHS. " << endl; 
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;

}
void 
LOADED_TRAIN::operator = (LOADED_TRAIN g)
{
int i = 0;
	n = g.n;
	for( i = 0; i<g.n; i++)
	{
		departure[i] = g.departure[i] ;
		arrival[i] = g.arrival[i];
		miles[i] = g.miles[i]; 
		price[i] = g.price[i];
		strcpy(arrive_name[i], g.arrive_name[i]);
		strcpy(depart_name[i], g.depart_name[i]);
	}


	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	output_file << " +++ OUTPUT OVERLOADED OPERATOR = METHOD: " << endl;
	output_file << " +++ " << n << " TRAIN PATHS ARE COPIED SUCCESSFULLY. " << endl;
        output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;

}
LOADED_TRAIN LOADED_TRAIN::operator + (LOADED_TRAIN & g)
{
int i =0;
	LOADED_TRAIN temp_obj;
	temp_obj.n = g.n + n;
	for( i = 0; i<n; i++)
	{
		temp_obj.departure[i] = departure[i];
		temp_obj.arrival[i] = arrival[i];
		temp_obj.miles[i] = miles[i];
		temp_obj.price[i] = price[i];
		strcpy(temp_obj.arrive_name[i], arrive_name[i]);
		strcpy(temp_obj.depart_name[i], depart_name[i]);
	}
	for( i = 0; i<g.n; i++)
	{
		temp_obj.departure[n+i] = g.departure[i];
		temp_obj.arrival[n+i] = g.arrival[i];
		temp_obj.miles[n+i] = g.miles[i];
		temp_obj.price[n+i] = g.price[i];
		strcpy(temp_obj.arrive_name[n+i], g.arrive_name[i]);
		strcpy(temp_obj.depart_name[n+i], g.depart_name[i]);
	}
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	output_file << " +++ OUTPUT OVERLOADED OPERATOR + METHOD: " << endl;
 	output_file << " +++ " << n << " TRAIN PATHS ARE IN FIRST LOADED_TRAIN. " << endl;
        output_file << " +++ " << g.n << " TRAIN PATHS ARE IN SECOND LOADED_TRAIN. " << endl;
	output_file << " +++ TRAIN PATHS ARE MERGED. TOTAL NUMBER OF TRAIN PATHS IS " << temp_obj.n<< ". " << endl;
	output_file << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;




	return temp_obj;

}
