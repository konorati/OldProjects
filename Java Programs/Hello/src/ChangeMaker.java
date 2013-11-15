
//Kristin Onorati
//Week#2 Problem
//CS 210 - Gandham

/* Takes an amount of money (in cents) and outputs 
 * the best way to make the change in US currency
 */
public class ChangeMaker {

	public static void main(String[] args) {
		// Declare variables
		int money, Q, D, N, P, X, Y, Z;
		
		//Input amount of money
		money = 67;
		
		//Calculate number of quarters
		Q = (money/25);
		
		//Calculate number of dimes
		X = (money%25);
		D = (X/10);
		
		//Calculate number of nickels
		Y = (X%10);
		N = (Y/5);
		
		//Calculate number of pennies
		P = (Y%5);
		
		//Output the number of quarters, dimes, nickels, and pennies
		System.out.println(Q + " Quarters, " + D + " Dimes, " + N + " Nickels, " + P + " Pennies");
		
	}

}
