
public class BodyMassIndex {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//declare variables
		double height;
		double weight;
		double bmi;
		
		//compute bmi
		height = 63;
		weight = 118;
		bmi = weight / (height * height) * 703;
				
		//print results
		System.out.println("Current BMI:");
		System.out.println(bmi);

	}

}
