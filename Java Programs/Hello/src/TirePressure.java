import java.util.*;
public class TirePressure {

	
	public static void main(String[] args) {
		double lFront, rFront, lBack, rBack;
		Scanner console = new Scanner(System.in);
		
		lFront = getPressure(console, "front", "left");
		rFront = getPressure(console, "front", "right");
		lBack = getPressure(console, "back", "left");
		rBack = getPressure(console, "back", "right");
		evaluatePressure(lFront, rFront, lBack, rBack);

	}
	public static double getPressure(Scanner console, String tireDir, String tireSide){
		double pressure;
		System.out.print("Enter the pressure for the " 
		    + tireDir + " " + tireSide + " tire: ");
		pressure = console.nextDouble();
		while (pressure < 30 || pressure > 40){
			System.out.println("Pressure entered is not valid.");
			System.out.print("Enter a pressure between 30 and 40: ");
			pressure = console.nextDouble();
		}
		return pressure;
	}
	public static void evaluatePressure(double lf, double rf, double lb, double rb){
		if (lf == rf && lb == rb){
			System.out.println("Tire pressures are good.");
		}
		else {
			if (lf != rf){
				System.out.println("Front tires do not have the same pressure.");
			}
			if (lb != rb){
				System.out.println("Back tires do not have the same pressure.");
			}
		}
	}

}
