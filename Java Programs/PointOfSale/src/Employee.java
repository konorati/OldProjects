
public class Employee {
	private String firstName;
	private String lastName;
	private char midInitial;
	private String streetAddress;
	private String city;
	private String state;
	private int zipCode;
	private SocSecNum socSecNum;
	private double payRate;
	
	
//Constructors
	public Employee(){
		firstName = null;
		lastName = null;
		midInitial = '\0';
		streetAddress = null;
		city = null;
		state = null;
		zipCode = 00000;
		socSecNum = new SocSecNum();
		payRate = 0.00;
		
	}
	
	public Employee(String first, String last, char mid, String street, 
			String tmpCity, String tmpState, int zip, int soc, double pay){
		firstName = first;
		lastName = last;
		midInitial = mid;
		streetAddress = street;
		city = tmpCity;
		state = tmpState;
		zipCode = zip;
		socSecNum.setSocSecNum(soc);
		payRate = pay;
	}
	
//Accessors
	public String getFirstName(){
		return firstName;
	}
	
	public String getLastName(){
		return lastName;
	}
	
	public char getMidInitial(){
		return midInitial;
	}
	
	public String getStreetAddress(){
		return streetAddress;
	}
	
	public String getCity(){
		return city;
	}
	
	public String getState(){
		return state;
	}
	
	public int getZipCode(){
		return zipCode;
	}
	
	public int getSocSecNum(){
		return socSecNum;
	}
	
	public double getPayRate(){
		return payRate;
	}
	
//Mutators
	public void setFirstName(String name){
		firstName = name;
	}
	
	public void setLastName(String name){
		lastName = name;
	}
	
	public void setMidInitial(char mid){
		midInitial = mid;
	}
	
	public void setStreetAddress(String address){
		streetAddress = address;
	}
	
	public void setCity(String tmpCity){
		city = tmpCity;
	}
	
	public void setState(String tmpState){
		state = tmpState;
	}
	
	public void setZipCode(int zip){
		zipCode = zip;
	}
	
	public void setSocSecNum(int soc){
		socSecNum = soc;
	}
	
	public void setPayRate(double rate){
		payRate = rate;
	}
}
