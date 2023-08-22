package test.basic;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class TestKeywordTransient {

	static class LoggingInfo implements Serializable {

		private static final long serialVersionUID = 5257852905186365471L;

		private String uid;

		private transient String pwd;

		LoggingInfo(String user, String password) {
			uid = user;
			pwd = password;
		}

		public String toString() {
			return String.format("logon : user=%s, pass=%s ", uid, pwd);
		}

	}

	public static void main(String[] args) throws IOException, ClassNotFoundException {

		String outputFile = "logInfo.out";

		{

			LoggingInfo logInfo = new LoggingInfo("User1", "abc123");
			System.out.println(logInfo.toString());

			// write object
			try (ObjectOutputStream o = new ObjectOutputStream(new FileOutputStream(outputFile))) {
				o.writeObject(logInfo);
				o.close();
			}
		}

		{
			// read object back
			try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(outputFile))) {
				LoggingInfo logInfo = (LoggingInfo) in.readObject();
				System.out.println(logInfo.toString());
			}
		}

		new File(outputFile).delete();
	}
}
