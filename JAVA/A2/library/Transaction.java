package library;

public class Transaction {

    private String bookId;
    private String memberId;
    private String issueDate;
    private String dueDate;
    private String returnDate;

    public Transaction(String bookId, String memberId, String issueDate, String dueDate, String returnDate) {
        this.bookId = bookId;
        this.memberId = memberId;
        this.issueDate = issueDate;
        this.dueDate = dueDate;
        this.returnDate = returnDate;
    }

    public String getBookId() {
        return bookId;
    }

    public String getMemberId() {
        return memberId;
    }

    public String getIssueDate() {
        return issueDate;
    }

    public String getDueDate() {
        return dueDate;
    }

    public String getReturnDate() {
        return returnDate;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "bookId='" + bookId + '\'' +
                ", memberId='" + memberId + '\'' +
                ", issueDate='" + issueDate + '\'' +
                ", dueDate='" + dueDate + '\'' +
                ", returnDate='" + returnDate + '\'' +
                '}';
    }
}