package test.ssh;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import ch.ethz.ssh2.Connection;
import ch.ethz.ssh2.Session;
import ch.ethz.ssh2.StreamGobbler;

public class Test_ganymed_ssh_remote_cmd {

	public static void main(String[] args) {

		String hostname = "192.168.3.20"; // ssh server address
		String username = "todd";
		String password = "password";

		try {

			Connection conn = new Connection(hostname);
			conn.connect();

			boolean isAuthenticated = conn.authenticateWithPassword(username, password);

			if (isAuthenticated == false)
				throw new IOException("Authentication failed.");

			Session sess = conn.openSession();

			System.out.println("Remote:");

			sess.execCommand("pwd"); // Execute command in remote server

			InputStream stdout = new StreamGobbler(sess.getStdout());

			BufferedReader br = new BufferedReader(new InputStreamReader(stdout));

			while (true) {
				String line = br.readLine();
				if (line == null)
					break;
				System.out.println("> " + line);
			}

			System.out.println("ExitCode: " + sess.getExitStatus());

			sess.close();
			conn.close();

		} catch (IOException e) {
			e.printStackTrace();
			System.exit(2);
		}
	}
}