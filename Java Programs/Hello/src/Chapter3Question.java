
import java.util.*; //For scanner

public class Chapter3Question {

	/**
	 * @param args
	 */
	

	public static void printPalindrome(Scanner console) {
		
		String s;
		boolean palindrome = true;
		int length;
	
		System.out.print("Enter word(s): ");
		s = console.nextLine();
		
		length = s.length(); //finds the length of the string
		s = s.toLowerCase(); //Changes s to all lower case so case doesn't matter
		
		//Compares the first and last letters, moving inward, to determine if they are equal
		for (int x = 0, y = length - 1; x < length/2; x++, y-- ) {
			//If the letters are not equal change palindrome to false
			if (s.charAt(x) != s.charAt(y)) {
				palindrome = false;
			}
		}
		
		if (palindrome){
			System.out.println(s + " is a palindrome!");
		}
		
		else {
			System.out.println(s + " is not a palindrome.");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner console = new Scanner(System.in);
		
		printPalindrome(console);
	

	}

}
