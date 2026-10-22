import java.util.HashSet;

public class Conta {

    private double saldo;
    private double limite;
    private HashSet<Cliente> clientes;

    public Conta(double saldo, double limite) {
        this.saldo = saldo;
        this.limite = limite;
        this.clientes = new HashSet<>();
    }

    public void mostraInfo(){
        for (Cliente cliente : clientes){
            try {
                System.out.println("Saldo: " + cliente.getNome());
                System.out.println("Limite: " + cliente.getCpf());
            }
            catch(NullPointerException e){
                System.out.println("Erro: "+e.getMessage());
            }
        }

    }

    public void sacar(double quantia) {
        if(quantia <= this.limite) {
            this.saldo -= quantia;
        }
        else {
            throw new SaldoInsuficienteException();
        }
    }

    public void setClientes(HashSet<Cliente> clientes) {
        this.clientes = clientes;
    }
}