 class Instructor {
    private String name;
    private String phoneNumber;

    public Instructor(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public void viewInformation() {
        System.out.println("Name: " + name);
        System.out.println("Phone Number: " + phoneNumber);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
}

 class Textbook {
    private String title;
    private String authorName;
    private String publisher;

    public Textbook(String title, String authorName, String publisher) {
        this.title = title;
        this.authorName = authorName;
        this.publisher = publisher;
    }

    public void setData(String title, String authorName, String publisher) {
        this.title = title;
        this.authorName = authorName;
        this.publisher = publisher;
    }

    public void viewData() {
        System.out.println("Title: " + title);
        System.out.println("Author Name: " + authorName);
        System.out.println("Publisher: " + publisher);
    }
}

 class Course {
    private String courseName;
    private Instructor instructor;
    private Textbook textbook;

    public Course(String courseName, Instructor instructor, Textbook textbook) {
        this.courseName = courseName;
        this.instructor = instructor;
        this.textbook = textbook;
    }

    public void setCourseData(String courseName, Instructor instructor, Textbook textbook) {
        this.courseName = courseName;
        this.instructor = instructor;
        this.textbook = textbook;
    }

    public void viewCourseData() {
        System.out.println("Course Name: " + courseName);
        System.out.print("Instructor: ");
        instructor.viewInformation();
        System.out.print("Textbook: ");
        textbook.viewData();
    }
}

class q11 {
    public static void main(String[] args) {
  Instructor instructor1 = new Instructor("John Doe", "123-456-7890");
  Textbook textbook1 = new Textbook("Introduction to Java", "Jane Doe", "Pearson");
  Course course1 = new Course("CS101", instructor1, textbook1);

  course1.viewCourseData();
}
}