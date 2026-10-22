import java.util.*;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        ArrayList<Double> listaDeDoubles = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            listaDeDoubles.add(rand.nextDouble()*100);
        }
        Collections.sort(listaDeDoubles, Collections.reverseOrder());
        for (Double d : listaDeDoubles) {
            System.out.println(d);
        }
    }
}