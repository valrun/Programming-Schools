package lesson9;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class ReadFile {

	public static void main(String[] args) throws IOException {
		// TODO read file 
		int a = 0;
		try(FileOutputStream baos = new FileOutputStream("t:/java/test.txt")){
			try(FileInputStream is = new FileInputStream("t:/java/test.txt")) {
				//while (baos.read() != -1) {
				//a += (int)baos;
				//}
			}
		}
	}

}
