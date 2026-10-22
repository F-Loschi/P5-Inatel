public class BrownieCafe extends Brownie{

    public BrownieCafe(String nome, double preco, String sabor) {
        super(nome, preco, sabor);
    }

    public void adicionaCafe(){
        System.out.println(this.nome + " está adicionando café");
    }

    @Override
    public void addCarrinhoDeCompras(){
        System.out.println("Brownin de coffee foi adicionado no carrinho de compras");
    }
}
