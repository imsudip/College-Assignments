package Transaction;

public class TransactionEntry {
    private String memberId;
    private String bookId;

    // Constructor
    public TransactionEntry(String memberId, String bookId) {
        this.memberId = memberId;
        this.bookId = bookId;
    }

    // Getters and Setters
    public String getMemberId() {
        return memberId;
    }

    public String getBookId() {
        return bookId;
    }

    public void setMemberId(String memberId) {
        this.memberId = memberId;
    }

    // Method to mark the transaction as returned
    public void markReturned() {
        memberId = "xxxx";
    }
}
