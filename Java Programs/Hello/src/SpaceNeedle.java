
//Kristin Onorati
//Assignment 2 
//CS 210 - Gandham

public class SpaceNeedle {

	/** This class creates a figure depicting the space needle
	 * which can be changed to any size => 2
	 */
	//Creates a class constant for the size of the figure
	public static final int SIZE = 4;
	
	//Creates the needle of figure
	public static void needle() { 
		for (int line = 1; line <= SIZE; line++){
			for (int i = 1; i <= SIZE * 3; i++) {
				System.out.print(" ");
			}
			System.out.println("||");
		}
	}
	//Creates the top part of the ball of the space needle and the base
	public static void topBottom() { 
		for (int line = 1; line <= SIZE; line++) {
			for (int i = 1; i <= (SIZE-line) * 3; i++) {
			 	 System.out.print(" ");
			}
			System.out.print("__/");
			for (int i = 1; i <= (line * 3) - 3; i++) {
				System.out.print(":");
			}
			System.out.print("||");
			for (int i = 1; i <= (line * 3) - 3; i++) {
				System.out.print(":");
			}
			System.out.println("\\__");
			
		}
		System.out.print("|");
		for (int i = 1; i <= SIZE * 6; i++) {
			System.out.print("\"");
		}
		System.out.println("|");
	}
	//Creates the main part of the tower of the figure
	public static void tower() { 
		for (int k = 1; k <= SIZE; k++) {
			for (int line = 1; line <= SIZE; line++) {
				for (int i = 1; i <= (SIZE * 3) - 3; i++) {
					System.out.print(" ");
				}
				for (int i = 1; i <= 2; i++) {
					System.out.print("|%%|");
				}
				System.out.println();
			}
		}
	}
	//Creates the bottom part of the ball of the space needle
	public static void topBase() { 
		for (int line = 1; line <= SIZE; line++) {
			for (int i = 1; i <= (line * 2) - 2; i++) {
				System.out.print(" ");
			}
			System.out.print("\\_");
			for (int i = 1; i <= (SIZE - line) * 2 + (SIZE+ 1) ; i++) {
				System.out.print("/\\");
			}
			System.out.println("_/");
		}
		
	}
	//main method calls the static methods to draw the figure
	public static void main(String[] args) { 
		
		needle();
		topBottom();
		topBase();
		needle();
		tower();
		topBottom();

	}

}
