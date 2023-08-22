package test.nio;

import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.CharacterCodingException;
import java.nio.charset.Charset;
import java.nio.charset.CharsetEncoder;

public class TestNIOCharset {

	public static void main(String[] args) throws CharacterCodingException {

		String some_string = "This is a string that Java natively stores as Unicode.";
		Charset latin1_charset = Charset.forName("ISO-8859-1");
		CharsetEncoder latin1_encoder = latin1_charset.newEncoder();
		ByteBuffer latin1_bbuf = latin1_encoder.encode(CharBuffer.wrap(some_string));

		int i = 0;
		for (byte b : latin1_bbuf.array()) {
			System.out.print(String.format("%02X", b));
			if (++i % 20 == 0) {
				System.out.println();
			}
		}

	}

}
