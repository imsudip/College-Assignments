import java.util.Scanner;

public class q3 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("Yo, give me your height in cm: ");
    int heightInCm = input.nextInt();

    double heightInInches = heightInCm / 2.54;
    int feet = (int) (heightInInches / 12);
    double remainingInches = heightInInches % 12;

    System.out.println("So you're " + feet + " feet and " + remainingInches + " inches tall? That's cool, I guess. But I prefer metric units, personally.");
  }
}
