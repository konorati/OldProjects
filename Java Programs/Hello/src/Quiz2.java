import java.util.*;
public class Quiz2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
		printNumbers();

	}
	
	public static double averageOf3(int num1, int num2, int num3){
		double average;
		
		average = (num1 + num2 + num3) / 3;
		
		return average;
	}
	public static void hurricane(){
		Scanner console = new Scanner(System.in);
		int hurricaneClass;
		System.out.print("What is the wind speed? ");
		int windSpeed = console.nextInt();
		
		if (windSpeed < 74){
			System.out.println("This does not qualify as a hurricane");
		}
		else {
			if (windSpeed > 155)
				hurricaneClass = 5;
			else if (windSpeed > 130)
				hurricaneClass = 4;
			else if (windSpeed > 110)
				hurricaneClass = 3;
			else if (windSpeed > 95)
				hurricaneClass = 2;
			else
				hurricaneClass = 1;
			System.out.println("This is a class " + hurricaneClass + " hurricane.");
		}
	}
	
	public static void printMultiples(int num, int multiples){
		System.out.print("The first " + multiples + " multiples of " + num + " are " + num);
		for (int i = 2; i <= multiples; i++){
			System.out.print(", " + num*i);
		}
	}
	
	public static void printNumbers(){
		for (int i = 100; i <=200; i++){
			if (!(i%5 == 0 && i%6 == 0)){
				if(i%5 == 0 || i%6 ==0){
					System.out.println(i);
				}
			}
		}
	}
	
}
