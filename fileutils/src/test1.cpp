#include <cstring>  
#include <iostream>

#include <fstream> 
  
#include <stringutils.h>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;


int main() {

   ifstream infile("NH04.TXT");
   ofstream outfile("wrNH04.TXT", ios::app);

   string linestr;

   if (!infile.is_open())  { 
        cout << "未成功打开文件" << endl; 
        return -1;
    } 

  while(getline(infile,linestr)){
  	//cout << linestr << endl;
  	outfile << linestr << endl;
  }
	
  infile.close();
    
    
} 

