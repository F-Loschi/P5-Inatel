import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Conta C = new Conta(13500,6000);
        HashSet<Cliente> clientes = new HashSet<>();
        Cliente C1 = new Cliente("Gepeto",123);
        clientes.add(C1);
        Cliente C2 = new Cliente("Tazz",456);
        clientes.add(C2);
        Cliente C3 = new Cliente("Gepeto",123);
        C3 = null;
        clientes.add(C3);
        C.setClientes(clientes);

        try {
            C.sacar(14000);
        }
        catch (SaldoInsuficienteException e) {
            System.out.println(e.getMessage());
        }
        C.mostraInfo();
    }
}