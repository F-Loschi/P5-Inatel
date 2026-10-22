## Comando `CREATE`

```sql
CREATE TABLE IF NOT EXISTS empresa (
    matricula INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45),
    cpf VARCHAR(45),
    cargo VARCHAR(45),
    nProjetos INT
);
```

### Explicação dos comandos:  
- `INT`: Define o tipo do campo como inteiro.  
- `NOT NULL`: Indica que o campo não pode ter valores nulos (o padrão permite valores nulos, caso essa restrição não seja especificada).  
- `AUTO_INCREMENT`: Faz com que o valor do campo seja incrementado automaticamente a cada nova inserção.  
- `PRIMARY KEY`: Define a chave primária da tabela, garantindo que os valores sejam únicos e identificadores da linha.  
- `CREATE TABLE IF NOT EXISTS`: Cria a tabela apenas se ela ainda não existir, evitando erros causados por tentativas de criar tabelas duplicadas.
## Modelos:
* Opções da coluna:
	* PK: Chave primária
	* NN: Não nulo
	* UQ: Valor único
	* B: booleano
	* UN: sem parte negativa
	* ZF: Preencher com zero
	* AI: Auto incremento
	* G: gerado(não entrada)
* Relacionamentos:
	* 1:1 -> Cada Jedi só pode possuir um sabre de luz e cada sabre de luz só pode ser possuído por apenas um Jedi
	* 1:N -> Um treinador pode possuir N pokémons, mas cada pokémon só pode pertencer a um único treinador
	* N:M -> Uma pessoa pode usar várias redes sociais e uma rede social pode ser usada por várias pessoas