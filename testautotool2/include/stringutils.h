#ifndef _STRING_UTILS_
#define _STRING_UTILS_

#include <cstring>  
  
#include <vector>

//using namespace std; 
using std::vector;
using std::string;

namespace stringutils{

 string& ltrim(string &str);
 string& rtrim(string &str);
 string& trim(string &str);

 string& str2upper(string &str);
 string& str2lower(string &str); 

 vector<string> split(const string& str, const string& delim);
 int charStartWith(char a[],char b[]);
 int isPathSuffix(char *a);
}


#endif // _STRING_UTILS_
