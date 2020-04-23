import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;



import Download.Client;

public class DemoClient extends Thread{
	static String host=null;
	int port = 8888;
	Socket socket=null;
	
	
	
     public static void main(String[] args) {
		System.out.println("请输入服务端IP地址（输入 1 使用本地IP地址）：");
		Scanner scanner = new Scanner(System.in);
		host = scanner.next();
		String localAddress = null;
		if(host.equals("1")) {
			try {
				InetAddress address = InetAddress.getLocalHost();
				String ip = address.toString();
				char [] ip2 = ip.toCharArray();
				int i=0;
				for(i=0;;i++) {
					if(ip2[i]=='/') {
						break;
					}
				}
				localAddress = ip.substring(i+1);
				System.out.println("本地ip地址： "+localAddress);
			} catch (UnknownHostException e) {
				
				e.printStackTrace();
			}
			
		}
		host = localAddress;
		DemoClient client = new DemoClient();
		client.start();
      }
     
     
     public void run(){
    	 OutputStream os = null;
 		InputStream is = null;
 		FileOutputStream fos = null;
 		Scanner scanner =null;
 		String message ="服务端没有该文件!";
 		try {
			socket = new Socket(host,port);
			System.out.println("请输入要下载文件的绝对地址");
			scanner = new Scanner(System.in);
			String s2 = scanner.next();
			os = socket.getOutputStream();	
			os.write(s2.getBytes());
			socket.close();
			socket = new Socket(host,port);
			
			is = socket.getInputStream();
			byte[] respond = new byte[1024];
			is.read(respond);
			message = new String(respond,0,respond.length);
			System.out.println(message);
			
//			socket.close();
//			socket = new Socket(host,port);
//			is = socket.getInputStream();
			byte[] filebytes = is.readAllBytes();
			System.out.println("文件大小: "+(filebytes.length-1)+" B");
			String ret = null;
			System.out.println("请为下载的文件命名 :");
			String s3 = scanner.next();
			scanner.close();
			File file2 = new File(s3);
			file2.createNewFile();
			fos = new FileOutputStream(file2);
			fos.write(filebytes);
			System.out.println("下载完毕！");
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} 
		finally {
			
			try {
				if(is!=null)
				{
					is.close();
				}
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			
			try {
				if(os!=null)
				{
					os.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}
		
	}
     
}
