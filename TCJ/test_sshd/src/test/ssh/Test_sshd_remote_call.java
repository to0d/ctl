package test.ssh;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.EnumSet;
import java.util.concurrent.TimeUnit;

import org.apache.sshd.client.SshClient;
import org.apache.sshd.client.channel.ClientChannel;
import org.apache.sshd.client.channel.ClientChannelEvent;
import org.apache.sshd.client.session.ClientSession;
import org.apache.sshd.common.channel.Channel;

public class Test_sshd_remote_call {

	static SshClient client;

	static ClientSession session;

	static int timeout = 10 * 1000;

	static ClientChannel channel;

	static OutputStream pipedIn;

	static InputStream pipeOut;

	static String serverAddr = "192.168.3.20";

	static int serverPort = 22;

	static String userName = "todd";

	static String password = "password";

	public static void main(String[] args) throws IOException {

		/*********************************************/
		// Start connection
		/*********************************************/
		client = SshClient.setUpDefaultClient();
		client.start();

		session = client.connect(userName, serverAddr, serverPort).verify(timeout).getSession();
		session.addPasswordIdentity(password);

		if (!session.auth().verify(timeout).isSuccess()) {
			throw new IOException("auth faild");
		}

		channel = session.createChannel(Channel.CHANNEL_SHELL);
		if (!channel.open().verify(timeout).isOpened()) {
			throw new IOException("open faild");
		}

		pipedIn = channel.getInvertedIn();
		pipeOut = channel.getInvertedOut();

		/*********************************************/
		// Wait welcome info
		/*********************************************/
		readOutput(10);

		/*********************************************/
		// Execute remote command
		/*********************************************/
		execute("cd ~");
		execute("ls");

		/*********************************************/
		// Close connection
		/*********************************************/
		pipeOut.close();
		channel.waitFor(EnumSet.of(ClientChannelEvent.CLOSED), TimeUnit.SECONDS.toMillis(timeout));
		channel.close();

		if (client != null) {
			client.stop();
			client.close();
		}
	}

	static void readOutput(int maxTry) throws IOException {

		StringBuffer sb = new StringBuffer();
		int len = 0;
		int tryNum = 0;

		while (tryNum < 3) {

			if ((len = pipeOut.available()) == 0) {
				tryNum++;
				try {
					Thread.sleep(50);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				continue;
			}

			tryNum = maxTry;

			for (int i = 0; i < len; ++i) {
				sb.append((char) pipeOut.read());
			}
		}

		System.out.println(sb.toString());
	}

	static void execute(String command) throws IOException {

		pipedIn.write((command + "\n").getBytes());
		pipedIn.flush();
		readOutput(3);
	}

}
