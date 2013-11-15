import java.util.*;


public class Quiz3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner console = new Scanner(System.in);
		System.out.print(longestWord("oh hello, how are you"));
	}
	public static double sumTo(int n){
		double sum = 0.0;
		for(int i = 1; i <= n; i++){
			sum += (1.0/i);
		}
		return sum;
	}
	public static boolean isVowel(Scanner console){
		System.out.print("Enter a character: ");
		char ch = console.next().toLowerCase().charAt(0);
		boolean vowel = false;
		if (ch == 'a' || ch == 'e' || ch == 'i' 
				|| ch == 'o' || ch == 'u'){
			vowel = true;
		}
		return vowel;
	}
	public static int longestWord(String s){
		int longWord = 0;
		int wordEnd = 0;
		int wordLength = 0;
		for (int i = 0; i <= s.length(); i += (wordEnd + 1)){
			if (s.indexOf(" ", i) == -1)
				wordEnd = s.length() - 1;
			else {
				wordEnd = s.indexOf(" ", i);
			}
			wordLength = s.substring(i, wordEnd).length();
			if (wordLength > longWord){
				longWord = wordLength;
			}
		}
		return longWord;
	}
	public static int digitSum(int num){
		int sum = 0;
		while (num != 0){
			int remainder =  num % 10;
			sum += remainder;
			num -= remainder;
			num /= 10;
		}
		return sum;			
	}
}
