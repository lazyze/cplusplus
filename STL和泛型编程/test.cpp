#include <iostream>
#include <list>
using namespace std;



const long ASIZE  =   500000L;

//-----------------
long get_a_target_long()
{
long target=0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
long target=0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
  return ( *(long*)a - *(long*)b );
}

int compareStrings(const void* a, const void* b)
{
  if ( *(string*)a > *(string*)b )
     	return 1;
  else if ( *(string*)a < *(string*)b )
     	return -1;  
  else      	
        return 0;  
}

//-----------------
#include <array>
#include <iostream>
#include <ctime> 
#include <cstdlib> //qsort, bsearch, NULL
namespace jj01
{
void test_array()
{
	cout << "\ntest_array().......... \n";
     
array<long,ASIZE> c;  	
			
clock_t timeStart = clock();									
    for(long i=0; i< ASIZE; ++i) {
        c[i] = rand(); 
    }
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	//
	cout << "array.size()= " << c.size() << endl;		
	cout << "array.front()= " << c.front() << endl;	
	cout << "array.back()= " << c.back() << endl;	
	cout << "array.data()= " << c.data() << endl;	
    cout << *c.data() << "," << c[0] << endl;
   
	
long target = get_a_target_long();

	timeStart = clock();
    ::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
long* pItem = (long*)::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs); 
	cout << "qsort()+bsearch(), milli-seconds : " << (clock()-timeStart) << endl;	//    
  	if (pItem != NULL)
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
}
}

//---------------------------------------------------
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm> 	//sort()
namespace jj02
{
void test_vector(long& value)
{
	cout << "\ntest_vector().......... \n";
     
vector<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));     		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			     //曾經最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "vector.max_size()= " << c.max_size() << endl;	//1073747823
	cout << "vector.size()= " << c.size() << endl;		
	cout << "vector.front()= " << c.front() << endl;	
	cout << "vector.back()= " << c.back() << endl;	
	cout << "vector.data()= " << c.data() << endl;
	cout << "vector.capacity()= " << c.capacity() << endl << endl;		

																				
// string target = get_a_target_string();
//     {
// 	timeStart = clock();
// auto pItem = find(c.begin(), c.end(), target);
// 	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;  
	 
//   	if (pItem != c.end())
//     	cout << "found, " << *pItem << endl << endl;
//   	else
//     	cout << "not found! " << endl << endl;
//     }

// 	{
// 	timeStart = clock();
//     sort(c.begin(), c.end());
// 	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl; 
	
// 	timeStart = clock();	    
// string* pItem = (string*)::bsearch(&target, (c.data()), 
//                                    c.size(), sizeof(string), compareStrings); 
// 	cout << "bsearch(), milli-seconds : " << (clock()-timeStart) << endl; 
	   
//   	if (pItem != NULL)
//     	cout << "found, " << *pItem << endl << endl;
//   	else
//     	cout << "not found! " << endl << endl;	
// 	}
	
// 	c.clear();
// 	test_moveable(vector<MyString>(),vector<MyStrNoMove>(), value);	
}	
}



int main ()
{
    // char buffer [100];
    // int cx = 1545;

    // cx = snprintf(buffer, 10, "%d", cx);

    // cout << buffer << "," << cx << endl << strlen(buffer) << endl;


    //jj01::test_array();
	list<long long> a;
	cout << sizeof(a); 

    return 0;
}