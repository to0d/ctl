package test;

import java.io.IOException;
import java.io.InputStream;

import org.apache.commons.net.telnet.TelnetClient;

public class Test_apache_commons_net_TelnetClient {

	public static void main(String[] args) {

		try {

			TelnetClient telnetClient = new TelnetClient();
			telnetClient.setDefaultTimeout(5000);
			telnetClient.connect("9.123.96.191", 23); // Port 23
			InputStream inputStream = telnetClient.getInputStream();

			readUntil(inputStream, 3000);
			
			telnetClient.disconnect();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static int readUntil(InputStream inputStream, long timeout) throws IOException {

		TimeoutChecker checker = new TimeoutChecker(timeout);

		int totalRead = 0;
		int bufLen = 0;

		while (!checker.timeIsUpNow()) {

			while ((bufLen = inputStream.available()) != 0) {

				byte b = (byte) inputStream.read();

				for (int i = 0; i < bufLen; ++i) {
					System.out.print(String.format("%02X", b) + ";");
				}

				totalRead += bufLen;
			}

			if (!checker.timeIsUpNow()) {

				try {
					Thread.sleep(50);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}

		return totalRead;

	}
}