/*!
 * \file
 * \brief  MediaClient class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */
import java.io.*;
import java.net.*;


public class MediaClient {
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	private Socket sock;
	private BufferedReader input;
	private BufferedWriter output;
	
	public MediaClient(String host, int port) throws UnknownHostException, IOException {
		try {sock = new java.net.Socket(host, port);}
	    catch (java.net.UnknownHostException e) {
	        System.err.println("Client: Couldn't find host "+host+":"+port);
	        throw e;
	    } catch (java.io.IOException e) {
	        System.err.println("Client: Couldn't reach host "+host+":"+port);
	        throw e;
	    }
	    try {
	        input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
	        output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
	    } catch (java.io.IOException e) {
	        System.err.println("Client: Couldn't open input or output streams");
	        throw e;
	    }	
	}
	
	public String query(String request) {
	    try {
	      request += "\n";
	      output.write(request, 0, request.length());
	      output.flush();
	    } catch (java.io.IOException e) {
	      System.err.println("Client: Couldn't send message: " + e);
	      return null;
	    }
	    
	    try {return input.readLine();}
	    catch (java.io.IOException e) {
	      System.err.println("Client: Couldn't receive message: " + e);
	      return null;
	    }
	}
}
