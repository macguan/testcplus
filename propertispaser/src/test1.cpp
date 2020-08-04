#include <cstring>  
#include <iostream>
  
#include<map>

#include <propertispaser.h>
#include <stringutils.h>

//using namespace std;  
using std::cout;
using std::endl;
using std::map;
using std::string;

using properties_paser::getProperties;
using properties_paser::getValueFromPaser;


int main() {
    char c[]="/home/dwsoft/localdata/software/monitor/";
    char d[]="e";
    cout<<stringutils::isPathSuffix(c)<<endl;


    map<string,string> propaser;
  
    propaser = getProperties("system.properties");  
    cout<<"map size:"<<propaser.size()<<endl;
    string aaval = getValueFromPaser(propaser,string("dd"));

    cout<<"dd:"<<aaval<<endl;   
    
} 

