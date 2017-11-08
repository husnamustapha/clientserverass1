import java.net.*;
import java.io.*;
public class client{
private static Socket socket;

public static void main(String args[]){
	try{
		String host="192.168.80.130";
		int port=8080;
		InetAddress addr=InetAddress.getByName(host);
		socket =new Socket(addr,port);

	OutputStream os = socket.getOutputStream();
	OutputStreamWriter osw=new OutputStreamWriter(os);
	BufferedWriter bw=new BufferedWriter(osw);
	String msg="hello husna";
	String sendMessage=msg+"\n";
	bw.write(sendMessage);
	bw.flush();
	System.out.println("Message sent to server:"+sendMessage);
	}
catch(Exception exception){
	exception.printStackTrace();}
finally{

try{
	socket.close();
}
catch (Exception e){
	e.printStackTrace();
}
}
}
}
