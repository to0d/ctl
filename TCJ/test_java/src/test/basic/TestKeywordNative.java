package test.basic;

public class TestKeywordNative {

	// 如果你想将一个方法做为一个本地方法的话，
	// 那么你就必须声明改方法为native的，并且不能实现
	public native void displayHelloWorld();

	static {
		System.loadLibrary("hello");
	}

	public static void main(String[] args) {
		new TestKeywordNative().displayHelloWorld();
	}

}
