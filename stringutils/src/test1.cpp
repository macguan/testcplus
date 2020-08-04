#include <cstring>  
#include <iostream>
  
#include <stringutils.h>

using std::cout;
using std::endl;
using std::string;
using std::isspace;

int test1();
int test2();
int test3();
int test4();


int main() {

 test4();
    
} 

int test1() {
    char c[]="/home/dwsoft/localdata/software/monitor/";
    char d[]="e";
    cout<<stringutils::isPathSuffix(c)<<endl;


}

int test2() {

  //string line="hello world!    I am mac";
  //string dim = " ";

  string line="hello	world !	I	am	mac";
  //string dim = "\t";
  string dim = "\t| ";
  
  
  vector<string> tempvector;
  
  cout<<line<<endl;
  tempvector = stringutils::split(line,dim);
  for(int i=0;i<tempvector.size();i++){
    cout<<tempvector[i]<<"|";
  }
  cout<<endl;  

}

int test3(){

        string str = "\t\r\n ACB%&*KU234 \r\n";
        string str1 = str;
        string str2 = str;
 
        cout << "str: |" << str << "|" << endl << endl;
 
        cout << "trim(str): |" << stringutils::trim(str1) << "|" << endl;


}

int test4(){
  string str = "Hello World!";
  
  cout << "str: " << str << endl << endl;
  string str1 = stringutils::str2upper(str);
  cout << "str1: " << str1 << endl << endl;
  
  cout << "str: " << str << endl << endl;
  string str2 = stringutils::str2lower(str);
  cout << "str2: " << str2 << endl << endl;

  

}
