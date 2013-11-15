
import java.util.*;

public class Chapter5Question {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		threeHeads();
	}
	
	public static void threeHeads() {
		
		Random r = new Random();
		int coin = r.nextInt(2);
		int numHeads = 0;
		
		while(numHeads != 3){
			if(coin == 0){
				System.out.print("H ");
				numHeads++ ;
			}
			else {
				System.out.print("T ");
				numHeads = 0;
			}
			coin = r.nextInt(2);
		}
		
		System.out.println("\nThree heads in a row!");
	}

}
