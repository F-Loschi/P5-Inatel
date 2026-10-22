public class BrownieNutella extends Brownie{

    public BrownieNutella(String nome, double preco, String sabor) {
        super(nome, preco, sabor);
    }

    public void adicionaNutella(){
        System.out.println(this.nome + " está adicionando Nutella");
    }

    @Override
    public void addCarrinhoDeCompras(){
        System.out.println("Brownin de nutellinha foi adicionado no carrinho de compras");
    }
}
