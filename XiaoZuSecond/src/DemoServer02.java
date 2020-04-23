import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;



public class DemoServer02 implements Runnable{
ServerSocket server = null;
	

	public static void main(String[] args) {
		Thread demo = new Thread(new DemoServer02());
		demo.start();

	}

	@Override
	public void run() {
		Socket socket = null;
		try {
			server = new ServerSocket(8888);
			System.out.println("服务端已开启，等待连接......");
			int count=0;
			InputStream is =null;
			OutputStream os = null;
			String path =null;
			File file2 = null;
			while(true) {
				count++;
				socket = server.accept();
				System.out.println("客户端"+count+"已连接");
				is = socket.getInputStream();
				byte[] in = new byte[1024];
				int len = 0;
				while((len=is.read(in))!=-1)
				{
					path = new String(in,0,len,"UTF-8");
				}
				file2 = new File(path);
					
				socket.close();
				socket = server.accept();
				os = socket.getOutputStream();
					
				if(file2.exists()==false)
					{
						String unfind = "服务端没有该文件!";
						System.out.println(unfind);
						os.write(unfind.getBytes());
					}
					else {
						String find = "服务端中找到文件!";
						System.out.println(find);
						os.write(find.getBytes());
						}
				
				long filesize = file2.length();
				System.out.println("文件大小为："+filesize);
				ServerSend singlesend = new ServerSend(server,socket,path,filesize);
				singlesend.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	    class ServerSend extends Thread{
		Socket socket =null;
		ServerSocket server=null;
		String path = null;
		FileInputStream fis = null;
		OutputStream os = null;
		long filesize;
		public ServerSend(ServerSocket server,Socket socket,String path,long fielsize)
		{
			this.server=server;
			this.socket=socket;
			this.path=path;
			this.filesize=filesize;
		}
		
		public void run() {
			File file1 = new File(path);
			try {
				os = socket.getOutputStream();
				fis = new FileInputStream(file1);
				byte[] buffer = new byte[1024*128];
				os.write((int)filesize);
				int n;
				while((n=fis.read(buffer))!=-1)
				{
					os.write(buffer,0,n);
				}
				os.close();
			} catch (IOException e) {
				
				e.printStackTrace();
			} finally {
				
				try {
					if(os!=null)
					{
						os.close();
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
				
				try {
					if(fis!=null)
					{
						fis.close();
					}
				} catch (IOException e1) {
					e1.printStackTrace();
				}
				
			}
		}
		
	}
}
