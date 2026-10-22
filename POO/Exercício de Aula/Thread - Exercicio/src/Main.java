public class Main {
    public static void main(String[] args) {
        Numero n1 = new Numero();
        Numero n2 = new Numero();
        Numero n3 = new Numero();

        Thread t1 = new Thread(n1);
        Thread t2 = new Thread(n2);
        Thread t3 = new Thread(n3);
        t1.start();
        t2.start();
        t3.start();
    }
}