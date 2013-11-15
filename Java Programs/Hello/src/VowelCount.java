import java.util.*;
public class VowelCount {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		dReverse("hello", 0);
		/*String s = "hi how are you";
		int[] vowels = vowelCount(s);
		System.out.println(Arrays.toString(vowels));
		int[] numVowels = vowelCount1(s);
		System.out.println(Arrays.toString(numVowels));*/
	}
	public static int[] vowelCount(String s){
		int[] vowels = new int[5];
		for (int i = 0; i < s.length(); i++){
			if (s.charAt(i) == 'a'){
				vowels[0]++;
			}
			else if (s.charAt(i) == 'e'){
				vowels[1]++;
			}
			else if (s.charAt(i) == 'i'){
				vowels[2]++;
			}
			else if (s.charAt(i) == 'o'){
				vowels[3]++;
			}
			else if (s.charAt(i) == 'u'){
				vowels[4]++;
			}
		}
		return vowels;
	}
	public static int[] vowelCount1(String s){
		int[] numVowels = new int[5];
		char[] vowels = {'a', 'e', 'i', 'o', 'u'};
		for (int i = 0; i < s.length(); i++){
			for (int j = 0; j < vowels.length; j++){
				if (s.charAt(i) == vowels[j]){
					numVowels[j]++;
				}
			}
		}
		return numVowels;
	}
	
	public static void dReverse(String s, int i){
		if(i != s.length()){
			dReverse(s, i+1);
			System.out.print(s.charAt(i));
			System.out.print(s.charAt(i));
		}
	}
	
	public static void starString(int i){
		if(i == 0){
			System.out.print("*");
		}
		else{
			starString(i-1);
			System.out.print("**");
		}
		
	}

}
