package test.string;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TestJavaRegex {

	public static void main(String[] args) {

		String str = "_type : FQDN , _oid : 51a867e4773da1128b1422ad";

		String reg = "[0-9A-Za-z]{24,}"; // appear at least 24 times

		// ^[0-9A-Za-z]{24,}
		Pattern pattern = Pattern.compile(reg);
		Matcher matcher = pattern.matcher(str);

		if (matcher.find()) {
			System.out.println("Match: " + matcher.group());
		} else {
			System.err.println("Not match!");
		}
	}

}
