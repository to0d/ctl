package test.basic;

public strictfp class TestKeywordStrictfp {

	static strictfp class StrictfpClass {

		public static void action() {

			System.out.println("\nStrictfp Class output: ");

			float aFloat = 0.6710339f;
			double aDouble = 0.04150553411984792d;
			double sum = aFloat + aDouble;
			float quotient = (float) (aFloat / aDouble);
			System.out.println("float: " + aFloat);
			System.out.println("double: " + aDouble);
			System.out.println("sum: " + sum);
			System.out.println("quotient: " + quotient);
		}
	}

	static class NonStrictfpClass {

		public static void action() {

			System.out.println("NonStrictfp Class output: ");

			float aFloat = 0.6710339f;
			double aDouble = 0.04150553411984792d;
			double sum = aFloat + aDouble;
			float quotient = (float) (aFloat / aDouble);
			System.out.println("float: " + aFloat);
			System.out.println("double: " + aDouble);
			System.out.println("sum: " + sum);
			System.out.println("quotient: " + quotient);
		}
	}

	public static void main(String[] args) {

		NonStrictfpClass.action();
		StrictfpClass.action();
	}

}
