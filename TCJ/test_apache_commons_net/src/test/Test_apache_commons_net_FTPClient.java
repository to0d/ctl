package test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collection;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;

public class Test_apache_commons_net_FTPClient {

	static final int FTP_RC_CODE_OK = 250;

	static final String password = "password";

	static final String serverAddr = "192.168.3.20";

	static final int serverPort = 21;

	static final String userName = "todd";

	public static void cd(FTPClient client, String dir) throws IOException {

		System.out.println("cd " + dir);
		int rc = client.cwd(dir);

		if (FTP_RC_CODE_OK != rc) {
			throw new IOException("fail to cd \"" + dir + "\", rc=" + rc);
		}
	}

	static String getChildDirPath(String path, String name) {
		return remoteTailSeperator(path) + "/" + remoteHeadSeperator(name);
	}

	static FTPClient getFTPClient(String ftpHost, String ftpUserName, String ftpPassword, int ftpPort) {

		FTPClient ftpClient = null;
		try {

			ftpClient = new FTPClient();

			ftpClient.connect(ftpHost, ftpPort);

			ftpClient.login(ftpUserName, ftpPassword);

			if (!FTPReply.isPositiveCompletion(ftpClient.getReplyCode())) {
				System.out.println("Fail to connection ftp server, replycode: " + ftpClient.getReplyCode());
				ftpClient.disconnect();

			} else {
				System.out.println("Connection sucessfully.");
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

		return ftpClient;
	}

	public static void main(String[] args) throws IOException {

		/**********************************/
		// Connection to ftp server
		/**********************************/
		FTPClient client = getFTPClient(serverAddr, userName, password, serverPort);

		client.enterLocalPassiveMode(); // set PassiveMode
		// client.setFileType(FTPClient.BINARY_FILE_TYPE); // bin

		/**********************************/
		// Prepare tmp file
		/**********************************/
		String test_path = "/tmp/test_ftp1/";
		String test_file = "tmp1.txt";

		ArrayList<String> lines = new ArrayList<>();
		lines.add("abc");
		lines.add("abc");

		saveTxtFile(test_file, lines);

		/**********************************/
		// Create remote target folder
		/**********************************/
		mkdir(client, test_path);
		cd(client, test_path);

		/**********************************/
		// Upload local file
		/**********************************/
		upload(client, test_file, test_file);

		/**********************************/
		// Read remote file
		/**********************************/
		read(client, test_file);

		/**********************************/
		// Clean
		/**********************************/
		new File(test_file).delete();
		client.disconnect();
	}

	static void mkdir(FTPClient client, String directory) throws IOException {

		ArrayList<String> paths = new ArrayList<>();
		String rootPath = ".";

		if (directory.startsWith("/")) {
			rootPath = "/";
			directory = directory.substring(1);
		} else if (directory.startsWith("./")) {
			rootPath = ".";
			directory = directory.substring(2);
		}

		for (String sub : directory.split("/")) {
			if (sub != null && !sub.trim().isEmpty()) {
				paths.add(sub);
			}
		}

		if (!rootPath.equals(".")) {
			cd(client, rootPath);
		}

		String curPath = rootPath;
		ArrayList<String> newPaths = null;

		SUB: for (String sub : paths) {

			if (newPaths == null) {

				for (FTPFile ff : client.listFiles()) {

					if (ff.getName().equals(sub)) {

						if (ff.isDirectory()) {

							cd(client, sub);
							curPath = getChildDirPath(curPath, sub);
							System.out.println("succ, cur path:" + curPath);
							continue SUB;
						} else {
							System.err.println(String.format("%s is not a path", curPath));
							return;
						}
					}
				}

				// not directory found
				newPaths = new ArrayList<>();
				newPaths.add(sub);
				continue;
			}
			newPaths.add(sub);
		}

		if (newPaths != null) {

			for (String sub : newPaths) {

				System.out.println(String.format("mkdir %s", sub));
				if (!client.makeDirectory(sub)) {
					System.err.println("fail to mkdir: " + sub);
					return;
				}

				cd(client, sub);
				curPath = getChildDirPath(curPath, sub);
				System.out.println("succ, cur path:" + curPath);
			}
		}

	}

	static void read(FTPClient ftpClient, String fileName) throws IOException {

		System.out.println("ftp: read" + fileName + " file");

		try (InputStream in = ftpClient.retrieveFileStream(fileName)) {

			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String data = null;

			while ((data = br.readLine()) != null) {
				System.out.println(data);
			}
		}

	}

	static String remoteHeadSeperator(String path) {

		if (path.startsWith("/") || path.startsWith("\\")) {
			path = path.substring(1);
		}

		return path;
	}

	static String remoteTailSeperator(String path) {

		if (path.endsWith("/") || path.endsWith("\\")) {
			path = path.substring(0, path.length() - 1);
		}

		return path;
	}

	static void saveTxtFile(String outPath, Collection<String> content) throws IOException {

		try (PrintStream out = new PrintStream(outPath)) {
			for (String line : content) {
				if (line != null) {
					out.println(line);
				}
			}
		}
	}

	static void upload(FTPClient client, String remoteFileName, String uploadFilePath) throws IOException {

		File f = new File(uploadFilePath);
		InputStream in = new FileInputStream(f);
		client.storeFile(remoteFileName, in);
		in.close();

		System.out.println("ftp: upload " + remoteFileName + " succ!");
	}
}
