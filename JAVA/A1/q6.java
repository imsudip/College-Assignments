public class q6 {
    void show(int num) {
        System.out.println("show(int): " + num);
    }
    
    void show(double num) {
        System.out.println("show(double): " + num);
    }
    
    public static void main(String[] args) {
        q6 obj = new q6();
        
        short s = 10;
        double d = 3.14;
        
        // call show(int) with short parameter
        obj.show(s);
        
        // call show(double) with double parameter
        obj.show(d);
        
        // call show(int) with double parameter
        obj.show((int) d);
    }
}