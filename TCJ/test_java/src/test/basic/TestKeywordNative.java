package test.basic;

public class TestKeywordNative {

	// ������뽫һ��������Ϊһ�����ط����Ļ���
	// ��ô��ͱ��������ķ���Ϊnative�ģ����Ҳ���ʵ��
	public native void displayHelloWorld();

	static {
		System.loadLibrary("hello");
	}

	public static void main(String[] args) {
		new TestKeywordNative().displayHelloWorld();
	}

}
