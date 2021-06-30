package lesson10;

import java.io.File;
import java.util.Arrays;

public class FileTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("./");
		
		System.err.println("We are at "+f.getAbsolutePath());
		System.err.println("Exisits: "+ f.exists());
		System.err.println("Is dirictory: "+f.isDirectory());
		System.err.println("Content: "+Arrays.toString(f.list()));
		
		File src = new File (f, "src");
		//File src = new File (f, "../");
		System.err.println("Src are at "+src.getAbsolutePath());
		System.err.println("Exisits: "+ src.exists());
		System.err.println("Is dirictory: "+src.isDirectory());
		System.err.println("Content: "+Arrays.toString(src.list()));
		System.err.println("Content: "+Arrays.toString(src.listFiles()));
		
		
		File newSubdir = new File(src,"newdir");
		File newDir = new File (newSubdir, "neateddir");
		newDir.mkdirs();
		System.err.println("Content[2]: "+Arrays.toString(src.listFiles()));
		newDir.delete();
		System.err.println("Content[3]: "+Arrays.toString(src.listFiles()));
		new File(newSubdir, "newdir/neateddir").delete();
		new File(newSubdir, "newdir").delete();
		System.err.println("Content[3]: "+Arrays.toString(src.listFiles()));
		
		newDir.mkdirs();
		File newName = new File(newSubdir, "newnameddir");
		newDir.renameTo(newName); //bvz yt bpvtybkjcm!!!
		System.err.println("C: "+Arrays.toString(new File(src, "newdir").list()));
		System.err.println("Newdir: "+newDir.exists());
		System.err.println("Newdir[2]: "+new File(src, "newdir/neateddir").exists());
		System.err.println("Newname: "+newName.exists());
		
	}

}
