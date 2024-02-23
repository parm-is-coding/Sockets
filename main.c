#include <stdio.h> //main() ->printf()
#include <stdlib.h>// initializeAddressInfo() -> exit()
#include <string.h> // initializeAddressInfo() -> memset
#include <netdb.h> // initializeAddressInfo() -> struct addrinfo, getaddrinfo(),freeaddrinfo()

void initializeAddressInfo(const char* hostName,const char* portNumber,struct addrinfo* pAddrInfo){
    memset(pAddrInfo,0,sizeof *(pAddrInfo));
    pAddrInfo->ai_flags = AI_PASSIVE;
    pAddrInfo->ai_family = AF_INET;
    pAddrInfo->ai_socktype = SOCK_DGRAM;
    struct addrinfo * pServerInfo;
    int status;
    status = getaddrinfo(hostName,portNumber,pAddrInfo,&pServerInfo);
    if(status != 0){
        printf("Error initializeAddressInfo():  getaddrinfo() failed");
        exit(1);
    }
    pAddrInfo->ai_protocol = pServerInfo->ai_protocol;
    pAddrInfo->ai_addrlen = pServerInfo->ai_addrlen;
    pAddrInfo->ai_addr = pServerInfo->ai_addr;
    pAddrInfo->ai_canonname = pServerInfo->ai_canonname;
    pAddrInfo->ai_next = pServerInfo->ai_next;
    freeaddrinfo(pServerInfo);
}

int main(){
    const char* hostName = "129.0.0.1";
    const char* portNumber = "4455";
    struct addrinfo addrInfo;

    initializeAddressInfo(hostName,portNumber,&addrInfo);
    printf("helloWorld");
    
    return 0;
}