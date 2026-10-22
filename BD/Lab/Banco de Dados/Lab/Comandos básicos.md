## Chave Primária  
Identificador exclusivo de cada registro em uma tabela.  

## Comando de Inserção em Tabelas  
```sql
INSERT INTO tabela VALUES (valores);
```

## Comando de Atualização de Dados  
```sql
UPDATE tabela SET coluna = novo_valor WHERE condição;
```

## Comando de Exclusão de Dados  
```sql
DELETE FROM tabela WHERE condição;
```

## Busca de Dados  
```sql
SELECT colunas FROM tabela WHERE condição;
```
- O uso de `*` seleciona todas as colunas da tabela.  
```sql
SELECT * FROM Cliente;
```
- O operador lógico `AND NOT` retorna os registros que **não** atendem a determinada condição.  
```sql
SELECT nome, cidade, totalCompra FROM Cliente WHERE totalCompra>=100 AND NOT cidade='Itajubá';
```
- A função `MAX(coluna)` retorna o maior valor de uma coluna numérica. 
```sql
SELECT max(totalCompra), nome FROM Cliente;
```
- O operador `LIKE` permite buscas por padrões em valores de texto:  
  - `LIKE 'alguma_coisa%'` → retorna tudo que começa com `"alguma_coisa"`, podendo ter mais caracteres depois.  
  - `LIKE '%usto'` → encontra registros que terminam com `"usto"`.  
  - `LIKE 'João % Garcia'` → busca registros que começam com `"João"` e terminam com `"Garcia"`.  
  - `LIKE 'João%'` → encontra registros que começam com `"João"`.  
- O comando `LIMIT` restringe a quantidade de registros retornados.  
```sql
SELECT nome, telefone FROM Cliente limit 3;
```
- `SELECT DISTINCT` retorna apenas valores únicos, removendo repetições. 
```sql
SELECT DISTINCT cidade FROM Cliente;
```
- `COUNT(*)` retorna o número total de registros que atendem a uma condição.

```sql
SELECT COUNT(*) FROM Ninja WHERE dinheiro <= 1000;
```