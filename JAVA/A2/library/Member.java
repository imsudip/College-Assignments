package library;

public class Member {

    private String memberId;
    private String name;
    private String dateOfBirth;
    private int noOfBooksIssued;

    public Member(String memberId, String name, String dateOfBirth) {
        this.memberId = memberId;
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.noOfBooksIssued = 0;
    }

    public String getMemberId() {
        return memberId;
    }

    public String getName() {
        return name;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public int getNoOfBooksIssued() {
        return noOfBooksIssued;
    }

    public void setNoOfBooksIssued(int noOfBooksIssued) {
        this.noOfBooksIssued = noOfBooksIssued;
    }

    @Override
    public String toString() {
        return "Member{" +
                "memberId='" + memberId + '\'' +
                ", name='" + name + '\'' +
                ", dateOfBirth='" + dateOfBirth + '\'' +
                ", noOfBooksIssued=" + noOfBooksIssued +
                '}';
    }
}