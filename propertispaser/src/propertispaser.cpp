

#include <fstream>  
#include <cstring>  

#include <iostream>

  
#include <vector>
#include <list>
#include <map>


#include <propertispaser.h>
#include <stringutils.h>

//using namespace std;

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::list;
using std::ifstream;


map<string,string>  properties_paser::getProperties(string filename){
    
    list<string> linelist;
    list<string>::iterator lineiter;
    map<string,string> strMap;

    char filename1[200]; 
    
    string line;
    vector<string> tempStr;

    strcpy(filename1,filename.c_str());    
    
    ifstream in(filename1);
   
   
    if(in) // 有该文件  
    {
        while (getline (in, line)) // line中不包括每行的换行符  
        {
            //cout << line << endl;
            linelist.push_back(line); 
        }
    }
    else // 没有该文件  
    {
        cout <<"no such file" << endl;
    }

   for (lineiter = linelist.begin(); lineiter != linelist.end(); ++lineiter){  
        line = *lineiter;
        //cout << line << endl;
        tempStr = stringutils::split(line,"=");
        if(tempStr.size()==2){
          //cout<<tempStr[0]<<"<=>"<<tempStr[1]<<endl;
          strMap[string(tempStr[0])] =tempStr[1];
	}
   }
   
    return strMap;
}

string properties_paser::getValueFromPaser(map<string,string> strMap,string key){
  
  string retval;
  map<string,string>::iterator iter1;
  
  iter1 = strMap.find(string(key));
  if(iter1 != strMap.end()){
   retval = iter1->second;
  }else {
    retval="";
  }
  return retval;
}

/*
vector<string> properties_paser::split(const string& str, const string& delim) {  
	vector<string> res;  
	if("" == str) return res;  

	char * strs = new char[str.length() + 1] ; //不要忘了  
	strcpy(strs, str.c_str());   
 
	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  
 
	char *p = strtok(strs, d);  
	while(p) {  
		string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);  
	}  
 
	return res;  
}
*/

