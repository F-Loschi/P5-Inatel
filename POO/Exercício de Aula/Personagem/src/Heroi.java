public class Heroi extends Personagem implements Combater{

    public Heroi(String nome, int vida) {
        super(nome, vida);
    }

    @Override
    public void usarEspecial(Personagem personagem) {
        for (int i=0; i<2;i++) {
            personagem.arma[i] = null;
        }

    }
}
