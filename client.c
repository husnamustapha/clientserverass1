#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	
	int sock;
	struct sockaddr_in server_in;
	char message[1000],server_reply[1000];
	
	sock=socket(AF_INET,SOCK_STREAM,0);

	if(sock==-1){
		printf("could not create socket");
	}
	puts("Soket created");

	server_in.sin_addr.s_addr=inet_addr("192.168.80.130");
	server_in.sin_family=AF_INET;
	server_in.sin_port=htons(8080);

	if(connect(sock,(struct sockaddr*)&server_in,sizeof(server_in))<0){
		perror("connect failed.error");
		return 1;
	}
	puts("connected\n");
	
	while(1){
	printf("enter message:");
	scanf("%s",message);


	if(send(sock,server_reply,1000,0)<0){
	puts("recv failed");
	return 1;
	}
	if(recv(sock,server_reply,1000,0)<0){
	puts("recv failed");
	break;
}
	
	puts("server reply:");
	puts(server_reply);
}

return 0;
}
