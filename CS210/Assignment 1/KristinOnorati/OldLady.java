//Kristin Onorati
//Assignment 1 - Chapter 1 - Programming Question 3
//CS 210 - Gandham

/* This program outputs the lyrics to the song "There was an old lady"
 * using static methods to reduce redundancy 
 */
public class OldLady {

	//Creates lines 2-3 of the first verse
	public static void flyChorus() {
		System.out.println("I don't know why she swallowed that fly,");
		System.out.println("Perhaps she'll die.");
		System.out.println();
	}
	//Creates lines 3-5 of the second verse
	public static void spiderChorus() {
		System.out.println("She swallowed the spider to catch the fly,");
		flyChorus();
	}
	//Creates lines 3-6 of the third verse
	public static void birdChorus() {
		System.out.println("She swallowed the bird to catch the spider,");
		spiderChorus();
	}
	//Creates lines 3-7 of the fourth verse
	public static void catChorus() {
		System.out.println("She swallowed the cat to catch the bird,");
		birdChorus();
	}
	//Creates lines 3-8 of the fifth verse
	public static void dogChorus() {
		System.out.println("She swallowed the dog to catch the cat,");
		catChorus();
	}
	//Creates Verse 1 
	public static void flyVerse() {
		System.out.println("There was an old lady who swallowed a fly,");
		flyChorus();
	}
	//Creates verse 2
	public static void spiderVerse() {
		System.out.println("There was an old lady who swallowed a spider,");
		System.out.println("That wriggled and iggled and jiggled inside her.");
		spiderChorus();
	}
	//Creates verse 3
	public static void birdVerse() {
		System.out.println("There was an old lady who swallowed a bird,");
		System.out.println("How absurd to swallow a bird.");
		birdChorus();
	}
	//Creates verse 4
	public static void catVerse() {
		System.out.println("There was an old lady who swallowed a cat,");
		System.out.println("Imagine that to swallow a cat.");
		catChorus();
	}
	//Creates verse 5
	public static void dogVerse() {
		System.out.println("There was an old lady who swallowed a dog,");
		System.out.println("What a hog to swallow a dog.");
		dogChorus();
	}
	//Creates verse 6
	public static void horseVerse() {
		System.out.println("There was an old lady who swallowed a horse,");
		System.out.println("She died of course.");
	}
	/* This method executes the program by using static methods to
	 * create the 6 verses of the song 
	 */
	public static void main(String[] args) {
		flyVerse();
		spiderVerse();
		birdVerse();
		catVerse();
		dogVerse();
		horseVerse();
	}

}
