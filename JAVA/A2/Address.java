public class Address {
    private String premisesNumber;
    private String street;
    private String city;
    private String pin;
    private String state;

    public Address(String premisesNumber, String street, String city, String pin, String state) {
        this.premisesNumber = premisesNumber;
        this.street = street;
        this.city = city;
        this.pin = pin;
        this.state = state;
    }

    @Override
    public String toString() {
        return premisesNumber + ", " + street + ", " + city + ", " + pin + ", " + state;
    }

    public void setPremisesNumber(String premisesNumber) {
        this.premisesNumber = premisesNumber;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setPin(String pin) {
        this.pin = pin;
    }

    public void setState(String state) {
        this.state = state;
    }
}