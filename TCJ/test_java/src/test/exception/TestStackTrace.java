package test.exception;

public class TestStackTrace {

	public static void main(String[] args) {
		test();
	}

	public static void test() {
		System.out.println(whereAmI());
	}

	public static String whereAmI() {

		StackTraceElement traceElement = ((new Exception()).getStackTrace())[1];
		String loc = String.format("[%s|%d|%s]", traceElement.getFileName(), traceElement.getLineNumber(),
				traceElement.getMethodName());

		return loc;
	}

}
