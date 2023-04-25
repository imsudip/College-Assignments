import java.util.Scanner;

public class q5 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("Enter a String: ");
    String str1 = input.nextLine();
    System.out.print("Enter a String: ");
    String str2 = input.nextLine();

    System.out.println("Using == operator:");
    System.out.println("str1 == str2: " + (str1 == str2));

    System.out.println("Using equals() method:");
    System.out.println("str1.equals(str2): " + str1.equals(str2));

    System.out.print("Enter another String: ");
    String str3 = input.nextLine();
    String str4 = str3;

    System.out.println("Using == operator:");
    System.out.println("str3 == str4: " + (str3 == str4));

    System.out.println("Using equals() method:");
    System.out.println("str3.equals(str4): " + str3.equals(str4));
  }
}
