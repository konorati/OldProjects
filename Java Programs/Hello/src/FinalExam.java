import java.io.*;
import java.util.*;
public class FinalExam {

	public static void main(String[] args) throws FileNotFoundException {
		
		
		Scanner input = new Scanner(new File("C:/Users/Kristin/workspace/Hello/finalexam.txt"));
		while (input.hasNext()){
			System.out.print(input.nextInt() + " ");
		}
	}

	public static void readFile(String file) 
			throws FileNotFoundException{
		Scanner input = new Scanner(new File(file));
		while (input.hasNextInt()){
			int next = input.nextInt();
			System.out.print(next + " ");
		}
	}
	public static void textCount(Scanner s){
		String longestText = "";
		int totalLines = 0;
		
		while (s.hasNextLine()){
			totalLines++;
			String line = s.nextLine();
			if (line.length() > longestText.length()){
				longestText = line;
			}
		}
		System.out.println("Total lines = " + totalLines);
		System.out.println("Length of longest line = " + longestText.length());
		System.out.println(longestText);
	}
	public static boolean isAllEven(int[] nums){
		boolean even = true;
		for (int i = 0; i < nums.length; i++){
			if (nums[i] % 2 != 0){
				even = false;
			}
		}
		return even;
	}
	public static boolean isUnique(int[] list){
		boolean unique = true;
		for (int i = 0; i < (list.length - 1); i++){
			for (int j = i + 1; j < list.length; j++){
				if (list[i] == list[j]){
					unique = false;
				}
			}
		}
		return unique;
	}
}