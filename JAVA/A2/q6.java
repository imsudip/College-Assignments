import java.util.Scanner;

class NumericWrapper<T extends Number> {
    private T value;

    public NumericWrapper(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public Object toObject() {
        return value;
    }

    public static <T extends Number> NumericWrapper<T> fromObject(Object obj) {
        if (obj instanceof Number) {
            return new NumericWrapper<>((T) obj);
        } else {
            throw new IllegalArgumentException("Invalid type. Expected a numeric object.");
        }
    }

    public String toString() {
        return String.valueOf(value);
    }

    public static <T extends Number> NumericWrapper<T> fromString(String str) {
        try {
            // You can modify this to support other numeric types like Double, Float, etc.
            return new NumericWrapper<>((T) Integer.valueOf(str));
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Invalid string format. Expected a numeric value.");
        }
    }
}

public class q6 {
    public static void main(String[] args) {
        // Conversion from basic to object
        NumericWrapper<Integer> wrapper1 = new NumericWrapper<>(10);
        Object obj = wrapper1.toObject();

        // Conversion from object to basic
        NumericWrapper<Integer> wrapper2 = NumericWrapper.fromObject(obj);
        int value = wrapper2.getValue();

        // Conversion from basic to string
        NumericWrapper<Integer> wrapper3 = new NumericWrapper<>(42);
        String str = wrapper3.toString();

        // Conversion from string (holding numeric data) to numeric object
        NumericWrapper<Integer> wrapper4 = NumericWrapper.fromString("100");
        int numericValue = wrapper4.getValue();

        // Conversion from object to string
        NumericWrapper<Double> wrapper5 = new NumericWrapper<>(3.14);
        String stringValue = wrapper5.toString();

        System.out.println(value);
        System.out.println(str);
        System.out.println(numericValue);
        System.out.println(stringValue);
    }
}
