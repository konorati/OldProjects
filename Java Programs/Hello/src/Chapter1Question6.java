//Kristin Onorati
//Assignment 1 - Chapter 1 - Question 6
//CS 210 - Gandham

/* This program creates two lines of code followed by an empty line
  followed by the same two lines of code*/
public class Chapter1Question6 {

	//This method prints out two Strings on two separate lines
	public static void oneThing() {
		
		System.out.println("There's one thing every coder must understand:");
		System.out.println("The System.out.println command.");
	}
	
	//This method prints out the 5 lines of code
	public static void main(String[] args) {
		
		oneThing();
		System.out.println();
		oneThing();

	}

}
