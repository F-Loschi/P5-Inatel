public class Main {
    public static void main(String[] args) {
        Heroi batman = new Heroi("Batman", 980);
        batman.arma = new Arma[2];
        Vilao curinga = new Vilao("Coringa", 750);
        curinga.arma = new Arma[2];

        Arma armaH0 = new Arma("Comedora", 210, 450);
        Arma armaH1 = new Arma("Habuko", 155, 650);


        Arma armaV0 = new Arma("Picadora", 180, 410);
        Arma armaV1 = new Arma("Batedora", 210, 390);

        batman.addArma(armaH0);
        batman.addArma(armaH1);

        curinga.addArma(armaV0);
        curinga.addArma(armaV1);

        batman.mostrarArmas();
        batman.atacar(0, curinga);
        batman.atacar(1, curinga);

        curinga.mostrarArmas();
        curinga.atacar(0, batman);
        curinga.atacar(1, batman);

        batman.usarEspecial(curinga);
        curinga.usarEspecial(batman);

        System.out.println(batman.vida);
        System.out.println(curinga.vida);
    }
}