
public class ConeFlame {
	//draws the cone/flame of a rocket
	 
	public static final int SIZE = 5;
	
	public static void coneFlame(){ //creates the cone/flame of ship
		for(int line = 1; line <= SIZE * 2 - 1; line++){
			for(int i = 1; i <= SIZE * 2 - line; i++){
				System.out.print(" ");
			}
			for (int i = 1; i <= line; i++){
				System.out.print("/");
			}
			System.out.print("**");
			for (int i = 1; i <= line; i++){
				System.out.print("\\");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		// executes the program by calling the coneFlame static method
		coneFlame();
	}
}
