import java.util.Scanner;

public class q4 {
    public static void main(String[] args) {
        final double PI = 3.14; // Declare constant pi

        // Prompt the user for the radius of the circle
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        double radius = scanner.nextDouble();

        // Calculate the area of the circle
        double area = PI * radius * radius;

        // Display the area of the circle
        System.out.println("The area of the circle is: " + area);
    }
}
