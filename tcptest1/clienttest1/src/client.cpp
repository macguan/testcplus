#include<iostream>

#include<cstdlib>
#include<cstring>

#include<cerrno>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>

#include<propertispaser.h>
#include<map>

#define MAXLINE 4096

using properties_paser::getProperties;
using properties_paser::getValueFromPaser;

  
int main(int argc, char** argv){
     
     char serveriddr[20];
     char port[20];

     struct sockaddr_in  servaddr;

     int   sockfd, n;

     char  recvline[4096], sendline[4096];

    map<string,string> propaser;
  
    propaser = getProperties("system.properties"); 
    string serverip_frompaser = getValueFromPaser(propaser,string("serverip"));
    string serverlistenport_frompaser = getValueFromPaser(propaser,string("serverlistenport")); 
    
    std::strcpy(serveriddr,serverip_frompaser.c_str());   
    std::strcpy(port,serverlistenport_frompaser.c_str());
    
    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        std::cout<<"create socket error:"<< strerror(errno)<<"(errno:"<< errno <<")"<<std::endl; 
        return 0;
     }
 
     memset(&servaddr, 0, sizeof(servaddr));

     servaddr.sin_family = AF_INET;
     servaddr.sin_port = htons(atoi(port));

     if( inet_pton(AF_INET, serveriddr, &servaddr.sin_addr) <= 0){
         std::cout<<"inet_pton error for "<<serveriddr<<std::endl;
        return 0;
     }
 
     if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        std::cout<<"connect error:"<< strerror(errno)<<"(errno:"<< errno <<")"<<std::endl; 
        return 0;
     }
 
     std::cout<<"Now connected with server: "<<serveriddr<<",port:"<<port<<std::endl;
     std::cout<<"Now send msg to server "<<serveriddr<<std::endl;
     std::cout<<"input your msg here : ";

     
     //fgets(sendline, 4096, stdin);
     std::cin>>sendline;     

    if( send(sockfd, sendline, strlen(sendline), 0) < 0){
         std::cout<<"send error:"<< strerror(errno)<<"(errno:"<< errno <<")"<<std::endl; 
         return 0;
     }

     std::cout<<"Send successflly! "<<std::endl;

     close(sockfd);

     return 0;
 }
