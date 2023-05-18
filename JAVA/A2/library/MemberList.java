public class MemberList {

    private ArrayList<Member> members;

    public MemberList() {
        members = new ArrayList<>();
    }

    public void addMember(String memberId, String name, String dateOfBirth) {
        if (isMemberIdUnique(memberId)) {
            members.add(new Member(memberId, name, dateOfBirth));
        } else {
            System.out.println("Member ID already exists.");
        }
    }

    public void showAllMembers() {
        for (Member member : members) {
            System.out.println(member);
        }
    }

    public void showMemberDetails(String memberId) {
        for (Member member : members) {
            if (member.getMemberId().equals(memberId)) {
                System.out.println(member);
                return;
            }
        }
        System.out.println("Member ID does not exist.");
    }

    public boolean isMemberIdUnique(String memberId) {
        for (Member member : members) {
            if (member.getMemberId().equals(memberId)) {
                return false;
            }
        }
        return true;
    }

    public int getNoOfMembers() {
        return members.size();
    }

    public int getNoOfBooksIssued(String memberId) {
        int count = 0;
        for (Member member : members) {
            if (member.getMemberId().equals(memberId)) {
                count = member.getNoOfBooksIssued();
                break;
            }
        }
        return count;
    }

    public void increaseNoOfBooksIssued(String memberId) {
        for (Member member : members) {
            if (member.getMemberId().equals(memberId)) {
                member.increaseNoOfBooksIssued();
                break;
            }
        }
    }

    public void decreaseNoOfBooksIssued(String memberId) {
        for (Member member : members) {
            if (member.getMemberId().equals(memberId)) {
                member.decreaseNoOfBooksIssued();
                break;
            }
        }
    }

}

