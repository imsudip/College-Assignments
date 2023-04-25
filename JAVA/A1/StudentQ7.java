public class StudentQ7 {
    private int roll;
    private String name;
    private int score;

    public StudentQ7(int roll, String name, int score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
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

    public void display() {
        System.out.println("Roll: " + roll);
        System.out.println("Name: " + name);
        System.out.println("Score: " + score);
    }

    public void copy(StudentQ7 other) {
        other.setRoll(this.roll);
        other.setName(this.name);
        other.setScore(this.score);
    }
    public static void main(String[] args) {
    StudentQ7 student1 = new StudentQ7(1, "John", 85);
    StudentQ7 student2 = new StudentQ7(2, "Mary", 92);

    student1.display();
    student2.display();

    // Modify attributes of studentQ71
    student1.setRoll(3);
    student1.setName("Bob");
    student1.setScore(78);

    // Copy studentQ71 to studentQ72
    student1.copy(student2);

    student1.display();
    student2.display();
}

}
