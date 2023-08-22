package test.pdf;

import java.io.IOException;

import org.apache.pdfbox.io.RandomAccessBufferedFileInputStream;
import org.apache.pdfbox.io.RandomAccessRead;
import org.apache.pdfbox.pdfparser.PDFParser;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.text.PDFTextStripper;

public class TestPdfbox {

	public static void main(String[] args) throws IOException {
		System.out.println(TestPdfbox.readPdfText("C:\\data\\doc\\doc_public\\GCC\\An Introduction to GCC.pdf"));
	}

	static String readPdfText(String path) throws IOException {

		RandomAccessRead randomAccessRead = new RandomAccessBufferedFileInputStream(path);

		PDFParser parser = new PDFParser(randomAccessRead);
		parser.parse();

		try (PDDocument document = parser.getPDDocument()) {
			PDFTextStripper stripper = new PDFTextStripper();
			return stripper.getText(document);
		}
	}
}