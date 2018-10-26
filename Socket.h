#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <vector>
#include <sys/un.h>
#include <errno.h>

using namespace std;

class Socket
{
public:
    Socket();
    Socket(int domain,int type,int protocol);
    int Bind(string ip, string port);
    int Connect(string ip, string port);
    int Listen(int max_queue);
    Socket* Accept();
    int Write(string msg);
    int Read(string &buf,int len);
    int SafeRead(string &buf,int len,int seconds);
    int WriteTo(string msg, string ip, string port);
    int ReadFrom(string &buf, int len, string ip, string port);
    int SetOpt(int level, int optname, void* optval);
    int GetOpt(int level, int optname, void* optval);
    int SetBlocking();
    int SetNonBlocking();
    int ShutDown(int how);
    void Close();
    static int Select(vector<Socket> *reads, vector<Socket> *writes, vector<Socket> *exceptions,int seconds);
    static string IpFromHostName(string hostname);
private:
    int m_nSock;
    string m_strAddress;
    string m_strPort;
    struct AddrInfo m_addressInfo;
};
#endif
