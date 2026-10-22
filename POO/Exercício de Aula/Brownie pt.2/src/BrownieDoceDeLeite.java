public class BrownieDoceDeLeite extends Brownie{

    public BrownieDoceDeLeite(String nome, double preco, String sabor) {
        super(nome, preco, sabor);
    }

    public void adicionaDoceDeLeite(){
        System.out.println(this.nome + " está adicionando doce de leite");
    }

    @Override
    public void addCarrinhoDeCompras(){
        System.out.println("Brownin di do di lei foi adicionado no carrinho de compras");
    }
}
