package test.log4j;

import org.apache.logging.log4j.Level;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class TestLog4j1 {

	static Logger logger = LogManager.getLogger("TEST");

	public static void main(String[] args) {

		logger.entry();

		logger.error("error: aaaa");
		logger.info("info: bbbb");
		logger.debug("debug: cccc");
		logger.warn("warn: dddd");
		logger.fatal("fatal: eeeee");
		logger.log(Level.DEBUG, "log: debug: ffff");

		logger.exit();
	}

}
