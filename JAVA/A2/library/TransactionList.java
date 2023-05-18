class TransactionList {

    private ArrayList<Transaction> transactions;

    public TransactionList() {
        transactions = new ArrayList<>();
    }

    public void addTransaction(String bookId, String memberId) {
        Transaction transaction = new Transaction(bookId, memberId);
        transactions.add(transaction);
    }

    public void markTransactionAsReturned(String bookId, String memberId) {
        for (Transaction transaction : transactions) {
            if (transaction.getBookId().equals(bookId) && transaction.getMemberId().equals(memberId)) {
                transaction.setReturned(true);
                break;
            }
        }
    }

    public boolean isTransactionValid(String bookId, String memberId) {
        for (Transaction transaction : transactions) {
            if (transaction.getBookId().equals(bookId) && transaction.getMemberId().equals(memberId) && !transaction.isReturned()) {
                return true;
            }
        }

        return false;
    }

    public void showAllTransactions() {
        for (Transaction transaction : transactions) {
            System.out.println(transaction);
        }
    }

}

