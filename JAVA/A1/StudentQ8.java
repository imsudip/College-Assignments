public class StudentQ8 {
    private int roll;
    private String name;
    private int score;

    // Constructor with roll only
    public StudentQ8(int roll) {
        this.roll = roll;
    }

    // Constructor with roll and name only
    public StudentQ8(int roll, String name) {
        this.roll = roll;
        this.name = name;
    }

    // Constructor with roll, name, and score
    public StudentQ8(int roll, String name, int score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }

    // Default constructor with no values
    public StudentQ8() {
    }

    // Copy constructor
    public StudentQ8(StudentQ8 other) {
        this.roll = other.roll;
        this.name = other.name;
        this.score = other.score;
    }

    // Setter methods
    public void setRoll(int roll) {
        this.roll = roll;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setScore(int score) {
        this.score = score;
    }

    // Display method
    public void display() {
        System.out.println("Roll: " + roll);
        System.out.println("Name: " + name);
        System.out.println("Score: " + score);
    }

    // Copy method
    public void copy(StudentQ8 other) {
        other.setRoll(this.roll);
        other.setName(this.name);
        other.setScore(this.score);
    }

    // main
    public static void main(String[] args) {
        StudentQ8 student1 = new StudentQ8(1, "John", 85);
        StudentQ8 student2 = new StudentQ8(2, "Mary", 92);

        student1.display();
        student2.display();

        // Modify attributes of studentQ81
        student1.setRoll(3);
        student1.setName("Bob");
        student1.setScore(78);

        // Copy studentQ81 to studentQ82
        student1.copy(student2);

        student1.display();
        student2.display();
    }
}
