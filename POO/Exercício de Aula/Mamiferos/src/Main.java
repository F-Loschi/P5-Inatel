public class Main {
    public static void main(String[] args) {
        Cachorro C1 = new Cachorro("Cleber", 600);
        Lontra L1 = new Lontra("Robertinha", 8000);
        Boi B1 = new Boi("Creison", 500);

        B1.emitirSom();
        B1.mostraInfo();

        C1.emitirSom();
        C1.mostraInfo();

        L1.emitirSom();
        L1.mostraInfo();
        L1.nadar();
    }
}