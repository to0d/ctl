package test.system;

public class TestJVMSystemEnvVar {

	public static void main(String[] args) {

		System.out.println("�û�����Ŀ¼=" + System.getProperty("user.home"));
		System.out.println("�û����˻�����=" + System.getProperty("user.name"));
		System.out.println("�û��ĵ�ǰ����Ŀ¼=" + System.getProperty("user.dir"));
		System.out.println("һ��������չĿ¼��·��=" + System.getProperty("java.ext.dirs"));
		System.out.println("Ҫʹ�õ�JIT������������=" + System.getProperty("java.compiler"));
		System.out.println("�ļ��ָ���=" + System.getProperty("file.separator"));
		System.out.println("Ĭ�ϵ���ʱ�ļ�·��=" + System.getProperty("java.io.tmpdir"));
		System.out.println("·���ָ���=" + System.getProperty("path.separator"));
		System.out.println("���ؿ�ʱ������·���б�=" + System.getProperty("java.library.path"));
		System.out.println("�зָ���=" + System.getProperty("line.separator"));
		System.out.println("����ϵͳ������=" + System.getProperty("os.name"));
		System.out.println("����ϵͳ�ļܹ�=" + System.getProperty("os.arch"));
		System.out.println("����ϵͳ�İ汾=" + System.getProperty("os.version"));
		System.out.println("Java����ʱ�����淶����=" + System.getProperty("java.specification.name"));
		System.out.println("Java����ʱ�����淶��Ӧ��=" + System.getProperty("java.specification.vendor"));
		System.out.println("Java����ʱ�����淶�汾=" + System.getProperty("java.specification.version"));
		System.out.println("Java����ʱ������Ӧ��=" + System.getProperty("java.vendor"));
		System.out.println("Java����ʱ�����汾=" + System.getProperty("java.version"));
		System.out.println("Java�����ʵ������=" + System.getProperty("java.vm.name"));
		System.out.println("Java�����ʵ�ֹ�Ӧ��=" + System.getProperty("java.vm.vendor"));
		System.out.println("Java�����ʵ�ְ汾=" + System.getProperty("java.vm.version"));
		System.out.println("Java������淶����=" + System.getProperty("java.vm.specification.name"));
		System.out.println("Java������淶��Ӧ��=" + System.getProperty("java.vm.specification.vendor"));
		System.out.println("Java������淶�汾=" + System.getProperty("java.vm.specification.version"));
		System.out.println("Java��·��=" + System.getProperty("java.class.path"));
		System.out.println("Java���ʽ�汾��=" + System.getProperty("java.class.version"));
		System.out.println("Java��Ӧ�̵�URL=" + System.getProperty("java.vendor.url"));
		System.out.println("Java��װĿ¼=" + System.getProperty("java.home"));

	}
}