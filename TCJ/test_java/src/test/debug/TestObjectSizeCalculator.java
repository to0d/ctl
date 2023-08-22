package test.debug;

import jdk.nashorn.internal.ir.debug.ObjectSizeCalculator;

public class TestObjectSizeCalculator {

	static class Test1 {
		String a = "abc";
	}

	static class Test2 {
		Test1 t1 = new Test1();
		String a = "abc";
	}

	public static void main(String[] args) {

		Test2 t2 = new Test2();
		System.out.println("Byte: " + ObjectSizeCalculator.getObjectSize(t2));
	}

}
