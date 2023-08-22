package test.jsse;

import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.KeyStore;

import javax.net.ssl.KeyManagerFactory;
import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLServerSocket;
import javax.net.ssl.SSLServerSocketFactory;
import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;
import javax.net.ssl.TrustManagerFactory;

public class Test_JSSE_Example1 {

	static void run_server() throws Exception {

		KeyStore serverKeyStore = KeyStore.getInstance("JKS");
		serverKeyStore.load(new FileInputStream("test\\test.jks"), "123456".toCharArray());

		KeyManagerFactory kmf = KeyManagerFactory.getInstance("SunX509");
		kmf.init(serverKeyStore, "123456".toCharArray());

		KeyStore clientKeyStore = KeyStore.getInstance("JKS");
		clientKeyStore.load(new FileInputStream("test\\test.jks"), "123456".toCharArray());

		TrustManagerFactory tmf = TrustManagerFactory.getInstance("SunX509");
		tmf.init(clientKeyStore);

		SSLContext sslContext = SSLContext.getInstance("SSL");
		sslContext.init(kmf.getKeyManagers(), tmf.getTrustManagers(), null);

		// SSLServerSocket
		SSLServerSocketFactory serverFactory = sslContext.getServerSocketFactory();
		SSLServerSocket svrSocket = (SSLServerSocket) serverFactory.createServerSocket(34567);
		// svrSocket.setNeedClientAuth(true);

		String[] supported = svrSocket.getEnabledCipherSuites();
		svrSocket.setEnabledCipherSuites(supported);

		System.out.println("server: socket open");

		SSLSocket cntSocket = (SSLSocket) svrSocket.accept();
		InputStream in = cntSocket.getInputStream();

		byte buf[] = new byte[102];
		int bytes = in.read(buf);

		System.out.println("server: receive:" + bytes + " bytes");

	}

	static void run_client() throws Exception {

		KeyStore clientKeyStore = KeyStore.getInstance("JKS");
		clientKeyStore.load(new FileInputStream("test\\test.jks"), "123456".toCharArray());

		KeyManagerFactory kmf = KeyManagerFactory.getInstance("SunX509");
		kmf.init(clientKeyStore, "123456".toCharArray());

		KeyStore serverKeyStore = KeyStore.getInstance("JKS");
		serverKeyStore.load(new FileInputStream("test\\test.jks"), "123456".toCharArray());

		TrustManagerFactory tmf = TrustManagerFactory.getInstance("SunX509");
		tmf.init(serverKeyStore);

		SSLContext sslContext = SSLContext.getInstance("SSL");
		sslContext.init(kmf.getKeyManagers(), tmf.getTrustManagers(), null);

		SSLSocketFactory sslcntFactory = (SSLSocketFactory) sslContext.getSocketFactory();
		SSLSocket sslSocket = (SSLSocket) sslcntFactory.createSocket("127.0.0.1", 34567);

		String[] supported = sslSocket.getSupportedCipherSuites();
		sslSocket.setEnabledCipherSuites(supported);

		OutputStream out = sslSocket.getOutputStream();
		out.write("hello".getBytes());
	}

	public static void main(String[] args) throws Exception {

		new Thread(() -> {
			try {
				run_server();
			} catch (Exception e) {
				e.printStackTrace();
			}

		}).start();

		new Thread(() -> {
			try {
				Thread.sleep(1000);
				run_client();
			} catch (Exception e) {
				e.printStackTrace();
			}

		}).start();

	}
}
