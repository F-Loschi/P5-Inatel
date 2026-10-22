import br.inatel.cdg.Cliente;
import br.inatel.cdg.Conta;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Conta conta = new Conta();
        conta.setNumero(0);


        Cliente cliente1 = new Cliente();
        Cliente cliente2 = new Cliente();
        Cliente cliente3 = new Cliente();

        System.out.println("Digite o nome do primeiro cliente:");
        String nome1 = sc.nextLine();
        System.out.println("Digite o CPF do primeiro cliente:");
        long numero1 = Long.parseLong(sc.nextLine());

        System.out.println("Digite o nome do segundo cliente:");
        String nome2 = sc.nextLine();
        System.out.println("Digite o CPF do segundo cliente:");
        long numero2 = Long.parseLong(sc.nextLine());

        System.out.println("Digite o nome do terceiro cliente:");
        String nome3 = sc.nextLine();
        System.out.println("Digite o CPF do terceiro cliente:");
        long numero3 = Long.parseLong(sc.nextLine());

        // Atribuindo valores aos clientes
        cliente1.setNome(nome1);
        cliente1.setCpf(numero1);
        cliente2.setNome(nome2);
        cliente2.setCpf(numero2);
        cliente3.setNome(nome3);
        cliente3.setCpf(numero3);

        conta.setClientes(cliente1, cliente2, cliente3);
        conta.getClientes();

        System.out.println("Coloque seu saldo: ");
        float x = sc.nextFloat();
        conta.setSaldo(x);

        System.out.println("Quanto deseja depositar: ");
        float y = sc.nextFloat();
        conta.depositar(y);

        System.out.println("Quanto deseja sacar: ");
        float z = sc.nextFloat();
        conta.sacar(z);
    }
}