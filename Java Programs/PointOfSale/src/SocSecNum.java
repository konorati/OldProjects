
public class SocSecNum {
	private int first;
	private int second;
	private int third;
	
	public SocSecNum(){
		first = 000;
		second = 00;
		third = 0000;
	}
	
	public SocSecNum(int frst, int scnd, int thrd){
		first = frst;
		second = scnd;
		third = thrd;
	}
	
	public int getLastFour(){
		return third;
	}
	
	public String getSocSecNum(){
		StringBuilder sb = new StringBuilder();
		sb.append(first);
		sb.append('-');
		sb.append(second);
		sb.append('-');
		sb.append(third);
		return (sb.toString());
	}
	
	public void setSocSecNum(int socTotal){
		third = socTotal % 10000;
		socTotal = (socTotal - third)/10000;
		second = socTotal % 100;
		third = (socTotal - second)/100;
	}
}
