public class Address {
    private String street;
    private String pin;
    public Address( String street,String pin,) {
       
        this.street = street;
        this.pin = pin;
    }
    @Override
    public String toString() {
        return  street + ", " + pin ;
    }
    public void setStreet(String street) {
        this.street = street;
    }
}