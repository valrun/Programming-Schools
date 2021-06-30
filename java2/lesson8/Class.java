package lesson8;

public class Class implements MyExtendentInterface, MyNewInterface{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyInterface in = new Class();
		MyNewInterface in2 = (MyNewInterface) in;
		
		in.myMethod1();
		in2.myMethod1();
		
		System.err.println(in.add(1, 2));
		((MyExtendentInterface)in).myMethod2();
		
		call(new Class());
		
		call(new MyInterface() {

			@Override
			public void myMethod1() {
				// TODO Auto-generated method stub
				System.err.println("My INNER");
			}

			@Override
			public int add(int x1, int x2) {
				// TODO Auto-generated method stub
				return 0;
			}
			
		});
		
		call (new Class().new InnerClass());
		
	}
	
	public static void call(MyInterface interf) {
		interf.myMethod1();
	}
	

	@Override
	public void myMethod1() {
		// TODO Auto-generated method stub
		System.err.println("My method");
	}

	@Override
	public int add(final int x1, final int x2) {
		// TODO Auto-generated method stub
		new MyInterface() {

			@Override
			public void myMethod1() {
				// TODO Auto-generated method stub
				System.err.println("Parameters: "+x1+" and "+x2);
			}

			@Override
			public int add(int x1, int x2) {
				// TODO Auto-generated method stub
				return 0;
			}
			
		}.myMethod1();
		
		return x2 + x1;
	}

	@Override
	public void myMethod2() {
		// TODO Auto-generated method stub
		System.err.println("My metho2");
	}

	private class InnerClass implements MyInterface{

		@Override
		public void myMethod1() {
			// TODO Auto-generated method stub
			System.err.println("Nested class");
			Class.this.add(2, 3);
		}

		@Override
		public int add(int x1, int x2) {
			// TODO Auto-generated method stub
			return x1 * x2;
		}
		
	}

	@Override
	public int sub(int x1, int x2) {
		// TODO Auto-generated method stub
		return 0;
	}

}
