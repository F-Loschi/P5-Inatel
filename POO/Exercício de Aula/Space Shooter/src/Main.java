import br.inatel.cdg.inimigo.Asteroide;
import br.inatel.cdg.jogador.Nave;

public class Main {
    public static void main(String[] args) {
        Asteroide ast1 = new Asteroide("Abrasado", "Grande");
        Asteroide ast2 = new Asteroide("Grandão", "Pequeno");
        Nave nave1 = new Nave("Gargantua", 310, "Normal");
        Nave nave2 = new Nave("ChicoGimenes", 310, "Explosivo");
        System.out.println(nave1.getNome());
        System.out.println(nave2.getNome());
        System.out.println(ast1.getNome());
        System.out.println(ast2.getNome());
        nave1.atirar(ast1);
        nave1.atirar(ast2);
        nave2.atirar(ast1);
        nave2.atirar(ast2);
    }
}