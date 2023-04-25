import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("Yo, gimme the first short integer: ");
    short num1 = input.nextShort();

    System.out.print("And now the second one: ");
    short num2 = input.nextShort();

    short sum = (short) (num1 + num2);

    System.out.println("The sum of " + num1 + " and " + num2 + " is " + sum + "! Pretty simple, huh?");
  }
}