import java.util.Scanner;

class Student {
    private int roll;
    private String name;
    private int score;

    public Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
    }

    public int getRoll() {
        return roll;
    }

    public String getName() {
        return name;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) throws IllegalArgumentException {
        if (score < 0 || score > 100) {
            throw new IllegalArgumentException("Invalid score. Score must be between 0 and 100.");
        }
        this.score = score;
    }
}

public class q5 {
    public static void main(String[] args) {
        Student student = new Student(1, "John Doe");
        System.out.println("Roll: " + student.getRoll());
        System.out.println("Name: " + student.getName());
        System.out.println("Score: " + student.getScore());
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Enter score: ");
            int score = scanner.nextInt();
            try {
                student.setScore(score);
                break;
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
        scanner.close();

    }
}
