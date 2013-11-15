
public class DrawBox {
	public static void drawBox(){
		System.out.println("+--------+");
		System.out.println("|        |");
		System.out.println("|        |");
		System.out.println("+--------+");
		
	}
	
	public static void drawCone(){
		System.out.println("    /\\   ");
		System.out.println("   /  \\  ");
		System.out.println("  /    \\ ");
		System.out.println(" /      \\");
	}
	public static void main(String[] args){
		drawBox();
		System.out.println();
		drawCone();
		drawBox();
	}

}
