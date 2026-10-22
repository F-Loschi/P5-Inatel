import computador.Computador;

public class Cliente {
    public String nome;
    public long cpf;
    public Computador[]computador = new Computador[100];


    public float calculaTotalCompra(){
        int i=0;
        float soma=0;
        while(computador[i]!=null){
            soma+=computador[i].preco;
            i++;
        }
        return soma;
    }
}