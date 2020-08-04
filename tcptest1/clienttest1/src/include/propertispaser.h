#ifndef _PROPERTIES_PASER_
#define _PROPERTIES_PASER_

#include <cstring>  
#include <iostream>

  
#include <vector>
#include <map>

//using namespace std; 
using std::map;
using std::vector;
using std::string;

namespace properties_paser{
	map<string,string>  getProperties(string filename);
	string getValueFromPaser(map<string,string> strMap,string key);
}

#endif //_PROPERTIES_PASER_ 
