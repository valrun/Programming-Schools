package lesson9;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.Writer;

public class IOTest {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		try (ByteArrayOutputStream baos = new ByteArrayOutputStream();
			Writer 		   		   wr = new OutputStreamWriter(baos)){	
   
			wr.write("тестовая строка");
			//System.err.println("Len = "+baos.size());
			wr.flush();
			
			byte[] date = new byte[100];
			char[] charDate = new char[100];
			int len;
			try(ByteArrayInputStream is = new ByteArrayInputStream(baos.toByteArray());
				Reader 	rdr = new InputStreamReader(is)) {
				//System.err.println("Read1: "+ (len = is.read(date))); //read with read
				//System.err.println("Read2: "+ is.read(date));
				//System.err.println("read: "+ new String(date, 0, len));
				
				System.err.println("read: "+(len = rdr.read(charDate)));
				System.err.println("read: "+ new String(charDate, 0, len));
			}
			
		} // baos.close();
		
		
		try (FileOutputStream baos = new FileOutputStream("./x.txt");
			Writer wr = new OutputStreamWriter(baos)){	
				wr.write("тестовая строка");
				wr.flush();
				
				char[] charDate = new char[100];
				int len;
				try(FileInputStream is = new FileInputStream("./x.txt");
					Reader rdr = new InputStreamReader(is);
					BufferedReader brbr = new BufferedReader(rdr)) {
			//		System.err.println("read: "+(len = rdr.read(charDate)));
			//		System.err.println("read: "+ new String(charDate, 0, len));
					
					//System.err.println("Line: " brbr.readLine());
				}
				
			} // baos.close();			
	}

}
