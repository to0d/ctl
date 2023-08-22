package test_jnr;

import jnr.posix.POSIXFactory;

public class Test_jnr_posix_chdir {

	public static void main(String[] args) {

		System.out.println("current dir: " + System.getProperty("user.dir"));
		POSIXFactory.getPOSIX().chdir("C:\\tmp");
		System.out.println("current dir: " + System.getProperty("user.dir"));
	}

}
