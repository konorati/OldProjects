
public class Christmas {

	/**
	 * @param args
	 */
	
	public static void day1(){
		System.out.println("a partidge in a pear tree");
	}
	
	public static void day2(){
		System.out.println("two turtle doves, and");
	}
	
	public static void day3(){
		System.out.println("three french hens");
	}
	
	public static void love(){
		System.out.println("my true love gave to me");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String christmas = new String("on the first day of Christmas");
		System.out.println(christmas);
		love();
		day1();
		System.out.println();
		christmas = christmas.replace("first", "second");
		System.out.println(christmas);
		love();
		day2();
		day1();
		System.out.println();
		System.out.println("on the third day of Christmas");
		love();
		day3();
		day2();
		day1();

	}

}
