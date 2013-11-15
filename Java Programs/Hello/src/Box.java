
public class Box {
	private double length, width, height;
	
	//Constructors
	public Box(double l, double w, double h){
		length = l;
		width = w;
		height = h;
	}
	public Box(){
	}
	
	//Accessors
	public double getLength(){
		return length;
	}
	public double getWidth(){
		return width;
	}
	public double getHeight(){
		return height;
	}
	
	//Mutators
	public void setLength(double l){
		length = l;
	}
	public void setWidth(double w){
		width = w;
	}
	public void setHeight(double h){
		height = h;
	}
	
	public double volumeOfBox(){
		return (length * width * height);
	}
	
	public static void boxClient(){
		Box b = new Box();
		System.out.println("Length = " + b.getLength());
		System.out.println("Width = " + b.getWidth());
		System.out.println("Height = " + b.getHeight());
		System.out.println("Volume = " + b.volumeOfBox());
		b.setLength(5);
		b.setWidth(5);
		b.setHeight(5);
		System.out.println("Length = " + b.getLength());
		System.out.println("Width = " + b.getWidth());
		System.out.println("Height = " + b.getHeight());
		System.out.println("Volume = " + b.volumeOfBox());
		
		Box b2 = new Box(6, 7, 8);
		System.out.println("Length = " + b2.getLength());
		System.out.println("Width = " + b2.getWidth());
		System.out.println("Height = " + b2.getHeight());
		System.out.println("Volume = " + b2.volumeOfBox());
	}
}
