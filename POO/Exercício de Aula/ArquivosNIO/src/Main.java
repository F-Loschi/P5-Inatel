import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Path arquivo = Paths.get("src\\professores_disciplina.txt");
        try{
            List<String> conteudo = Files.readAllLines(arquivo);
            HashMap<String,String> professores = new HashMap<>();
            conteudo.forEach((linha)->{
                String[] split = linha.split("=");
                professores.put(split[0],split[1]);
        });
            professores.forEach((key, value)->{
                System.out.println("Professor: " + key);
                System.out.println("Matéria: " + value);
            });
        }
        catch(Exception e){
            System.out.println(e);
        }

    }
}