import java.util.Scanner;

public class q3 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("give me your height in cm: ");
    int heightInCm = input.nextInt();

    double heightInInches = heightInCm / 2.54;
    int feet = (int) (heightInInches / 12);
    double remainingInches = heightInInches % 12;
    String formattedInches = String.format("%.2f", remainingInches);

    System.out.println("So you're " + feet + " feet and " + formattedInches
        + " inches tall.");
    input.close();
  }
}
