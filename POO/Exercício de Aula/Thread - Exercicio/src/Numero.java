public class Numero implements Runnable{
    public int numero;

    @Override
    public void run() {
        for(int i=0;i<1000;i++){
            System.out.println(Thread.currentThread().getName()+" "+i);
        }
    }
}
