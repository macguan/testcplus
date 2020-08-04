#include <cstring>  
#include <iostream> 
#include <vector>

#include <cctype>
#include <algorithm>

#include <stringutils.h>

using std::ptr_fun;
using std::isspace;
using std::not1;
using std::vector;
using std::string;
using std::cout;
using std::endl;


string& stringutils::ltrim(string &str) {
    string::iterator p = find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace)));
    str.erase(str.begin(), p);
    return str;
}
 
string& stringutils::rtrim(string &str) {
    string::reverse_iterator p = find_if(str.rbegin(), str.rend(), not1(ptr_fun<int , int>(isspace)));
    str.erase(p.base(), str.end());
    return str;
}
 
string& stringutils::trim(string &str) {
    ltrim(rtrim(str));
    return str;
}

string& stringutils::str2upper(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

string& stringutils::str2lower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


int stringutils::charStartWith(char a[],char b[]){
    if(strlen(a) < strlen(b)){
        return 0;
    }

    for(int i=0;i<strlen(b);i++){
        if(a[i] != b[i]){
            return 0;
        }else{
	}
    }

    return 1;

}

int stringutils::isPathSuffix(char *a){    
    char up1;
    char *path;
    for(path=a;*path!=0;path++){
        up1=*path;
        
    }
    
    if(up1=='/'){
        return 1;
    }
    if(up1=='\\'){
        return 1;
    }
}	





vector<string> stringutils::split(const string& str, const string& delim) {
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

