package lesson10;

import java.io.File;

public class ListDir {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("./");
		rec(f, 0);
	}
	
	public static void rec(File f, int level) {
		for (int i = 0; i < level; i++) {
			System.err.print("    ");
		}
		
		if (f.isDirectory()) {
			System.err.println('/'+f.getName());
			File arr[] = f.listFiles();
			//System.err.println(arr.length);
			
			for (int i = 0; i < arr.length; i++) {
				rec(arr[i],  + 1);
			}
		}
		else {
			System.err.println(f.getName());
		}
			
	}
}
