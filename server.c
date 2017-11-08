#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	
	int socket_desc,client_sock,c,read_size;
	struct sockaddr_in server,client;
	char client_message[1000],*begin,*end,temp;
	int i, j=0;
	
	socket_desc=socket(AF_INET,SOCK_STREAM,0);
		if(socket_desc==-1)
		{
		printf("could not create socket");
		}
	puts("socket created");

server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(8080);

if(bind(socket_desc,(struct sockaddr *)&server,sizeof(server))<0)
{
perror("bind failed .error");
return 1;
}
puts("bind fone");
listen(socket_desc,5);

puts("waiting for incoming conection...");
c=sizeof(struct sockaddr_in);

client_sock=accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&c);
if(client_sock<0){
perror("accept failed");
return 1;
}
puts("connection acepted");

while((read_size=recv(client_sock,client_message,1000,0))>0)
{
begin=client_message;
end=begin+strlen(client_message)-1;

	while(end>begin)
	{
	temp=*begin;
	*begin=*end;
	*end=temp;

	++begin;
	}


	write(client_sock,client_message,strlen(client_message));
}

if(read_size==0){
puts("client disconnected");
fflush(stdout);
}
else if(read_size== -1){
perror("recv failed");
}
return 0;
}

