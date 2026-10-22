import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> listaArray = new ArrayList<>();
        Set<Integer> listaSet = new HashSet<>();
        Map<Integer, Integer> mapArray = new HashMap<>();

        long t1 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            listaArray.add(i);
        }
        long t2 = System.currentTimeMillis();
        long tt1 = t2 - t1;
        System.out.println("Tempo total para a criação de uma ArrayList de 100.000 de casas: "+tt1+" milisegundos");

        long t3 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            listaSet.add(i);
        }
        long t4 = System.currentTimeMillis();
        long tt2 = t4 - t3;
        System.out.println("Tempo total para a criação de uma HashSet de 100.000 de casas: "+tt2+" milisegundos");

        long t5 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            mapArray.put(i, i);
        }
        long t6 = System.currentTimeMillis();
        long tt3 = t6 - t5;
        System.out.println("Tempo total para a criação de uma HashMap de 100.000 de casas: "+tt3+" milisegundos");

        long t7 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            listaArray.contains(i);
        }
        long t8 = System.currentTimeMillis();
        long tt4 = t8 - t7;
        System.out.println("Procurar por todas as casas demora "+tt4+" milisegundos para ArrayList de 100.000 de casas");

        long t9 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            listaSet.contains(i);
        }
        long t10 = System.currentTimeMillis();
        long tt5 = t10 - t9;
        System.out.println("Procurar por todas as casas demora "+tt5+" milisegundos para HashSet de 100.000 de casas");

        long t11 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            mapArray.containsKey(i);
        }
        long t12 = System.currentTimeMillis();
        long tt6 = t12 - t11;
        System.out.println("Procurar por todas as chaves demora "+tt6+" milisegundos para HashMap de 100.000 de casas");
        
    }
}