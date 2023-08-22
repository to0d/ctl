package test.socket;

import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;

public class TestListMultiSocket {

	public static void main(String[] args) throws SocketException {

		Enumeration<NetworkInterface> nics = NetworkInterface.getNetworkInterfaces();
		while (nics.hasMoreElements()) {

			NetworkInterface inc = nics.nextElement();
			if (!inc.isUp()) {
				continue;
			}

			Enumeration<InetAddress> addresses = inc.getInetAddresses();
			while (addresses.hasMoreElements()) {

				InetAddress add = addresses.nextElement();
				if (add.isLoopbackAddress()) {
					continue;
				}

				if (!(add instanceof Inet4Address)) {
					continue;
				}

				System.out.println(add.getHostAddress());
			}
		}

	}

}
