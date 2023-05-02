public class Metric {
    public static double kilometerToMile(double kilometer) {
        return kilometer / 1.5;
    }

    public static double mileToKilometer(double mile) {
        return mile * 1.5;
    }

    public static void main(String[] args) {
        double km = 10;
        double mi = Metric.kilometerToMile(km);
        System.out.println(km + " kilometers is equal to " + mi + " miles.");

        mi = 5;
        km = Metric.mileToKilometer(mi);
        System.out.println(mi + " miles is equal to " + km + " kilometers.");
    }
}