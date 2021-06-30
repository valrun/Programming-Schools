import java.lang.reflect.Array;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Arrays;


public class ReflectionTest {
    public static int x = 10;
    
    public static void main(String[] args) throws NoSuchFieldException, IllegalArgumentException, IllegalAccessException, NoSuchMethodException, InvocationTargetException, InstantiationException {
        Class<?>    cl = Test.class;
        
        System.err.println("Name="+cl.getName());
        System.err.println("Modifier:"+cl.getModifiers());
        System.err.println("Is abstract ? "+Modifier.isAbstract(cl.getModifiers()));
        System.err.println("INherit: "+cl.getSuperclass());
        System.err.println("Fields:"+Arrays.toString(cl.getFields()));
        Field   f = cl.getDeclaredField("x");
        
        System.err.println("Field name="+f.getName());
        System.err.println("Field type="+f.getType());
        f.setAccessible(true);
        System.err.println("Field value="+f.getInt(null));
        f.setInt(null,20);
        
        Method  m = cl.getDeclaredMethod("print");
        m.setAccessible(true);
        m.invoke(null);
        
        Constructor c = cl.getDeclaredConstructor();
        Test    t = (Test)c.newInstance();
        
        System.err.println("Created class: "+t.getClass());
        System.err.println("Y="+t.y);
        
        Field   fY = t.getClass().getField("y");
        
        fY.setInt(t,123);
        System.err.println("New Y="+t.y);
        
        Test[]  tt = (Test[]) Array.newInstance(t.getClass(),2);
        tt[0] = (Test) c.newInstance();
        tt[1] = (Test) c.newInstance();
        System.err.println("Array content: "+Arrays.toString(tt));
 //       System.err.println("X="+Test.x);
    
        Class   clInner = Inner.class;
    
        System.err.println("COnstructors: "+Arrays.toString(clInner.getConstructors()));
        
        ReflectionTest  owner = new ReflectionTest();
        Constructor     innerC = clInner.getConstructor(ReflectionTest.class);
        
        Inner   inst = (Inner) innerC.newInstance(owner);
        
        System.err.println("Inner: "+inst);
    }
    
    public class Inner {
        public Inner(){}
    }
}

class Test {
    private static int x = 30;
    public int y = 100;

    private static void print(){System.err.println("URA!!!");};
    
    @Override
    public String toString(){return "Test: x=" + x + ", y=" + y;}
}