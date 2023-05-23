package MemberList;

public class Member {
    private String memberId;
    private String name;
    private String dateOfBirth;
    private int booksIssued;

    // Constructor
    public Member(String memberId, String name, String dateOfBirth) {
        this.memberId = memberId;
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.booksIssued = 0;
    }

    // Getters and Setters
    public String getMemberId() {
        return memberId;
    }

    public String getName() {
        return name;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public int getBooksIssued() {
        return booksIssued;
    }

    public void setBooksIssued(int booksIssued) {
        this.booksIssued = booksIssued;
    }

    // Method to increment the number of books issued
    public void incrementBooksIssued() {
        booksIssued++;
    }

    // Method to decrement the number of books issued
    public void decrementBooksIssued() {
        booksIssued--;
    }
}
