import java.io.*;
import java.net.*;

public class server2
{
	private static Socket socket;
	public static void main(String[] args)
	{
		try
		{
			String host = "192.168.80.132";
			int port = 8080;
			InetAddress address = InetAddress.getByName(host);
			socket = new Socket(address,port);

			//Server is running always. This is done using this while(true) loop
			while(true)
			{
				//Reading the message from the client
				socket = serverSocket.accept();
				InputStream is = socket.getInputStream();
				InputStreamReader isr = new InputStreamReader(is);
				BufferedReader br = new BufferedReader(isr);
				String msg = br.readLine();
				System.out.println("Message received from client: " + msg );

				
			}	
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				socket.close();
			}
			catch(Exception e){}
		}
	}
}
