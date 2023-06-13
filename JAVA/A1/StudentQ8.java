public class StudentQ8 {
    private int roll;
    private String name;
    private int score;

    public StudentQ8(int roll) {
        this.roll = roll;
    }

    public StudentQ8(int roll, String name) {
        this.roll = roll;
        this.name = name;
    }

    public StudentQ8(int roll, String name, int score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }

    public StudentQ8() {
    }

    public StudentQ8(StudentQ8 other) {
        this.roll = other.roll;
        this.name = other.name;
        this.score = other.score;
    }

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
        // Add constructors in the Student class of earlier problems so
        // that objects can be created with i) roll only, ii) roll and name only, iii)
        // roll,
        // name, and score, iv) no value. Also include a copy constructor. Check
        // whether constructors are working or not. Verify, copy constructors result in
        // deep copy or not.

        // roll only
        StudentQ8 student1 = new StudentQ8(1);
        // roll and name only
        StudentQ8 student2 = new StudentQ8(2, "Mary");
        // roll, name, and score
        StudentQ8 student3 = new StudentQ8(3, "John", 85);
        // no value
        StudentQ8 student4 = new StudentQ8();
        // copy constructor
        StudentQ8 student5 = new StudentQ8(student3);

        student1.display();
        student2.display();
        student3.display();
        student4.display();
        student5.display();

        // deep copy check
        student3.setRoll(4);
        student3.setName("Bob");
        student3.setScore(78);

        student3.display();
        student5.display();

        System.out.println("Deep copy verified");

    }
}
