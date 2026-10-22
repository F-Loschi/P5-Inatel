# 5° Período

Repositório com os materiais do 5° período da graduação: anotações de aula, exercícios, relatórios de laboratório e projetos de cada disciplina.

## Estrutura

### [`BD/`](BD) — Banco de Dados
- **`Aula/`** — scripts SQL das aulas (queries, functions, procedures, views, triggers), listas de exercícios, material da AV2/P2 e um glossário de SQL em PDF.
- **`Lab/`** — listas de exercícios do laboratório, provas antigas e modelos do MySQL Workbench (`.mwb`), incluindo o projeto SHOP-E.
  - **`Banco de Dados/`** — vault do Obsidian com resumos teóricos por capítulo e anotações do laboratório (comandos básicos, criação de tabelas e modelos).
- `Exercicio Sala Empresa.sql` — exercício feito em sala.

### [`F04/`](F04) — Física (Relatividade e Física Moderna)
Vault do Obsidian com as anotações das aulas, organizadas por módulo e capítulo (relatividade restrita, radiação térmica/corpo negro etc.), com desenhos feitos no Excalidraw.

### [`Micro/`](Micro) — Microcontroladores (E09)
- **`Aula/`** — exercícios de cada aula (Arduino/AVR em C), com os circuitos do SimulIDE (`.sim1`) e os `.hex` compilados. Temas: lógica, interrupções (PCINT, CTC), temporizadores e PWM.
- **`Lab/`** — relatórios de laboratório 1 a 11 e a reposição, com código, diagramas de máquina de estados e fotos/simulações dos circuitos.
- **`Projeto/`** — projeto final da disciplina (`Projeto.ino`, com UART e interrupções).
- Notas do Obsidian sobre interrupção, temporizador, PWM e resumos para prova.

### [`POO/`](POO) — Programação Orientada a Objetos (Java)
- **`Exercício de Aula/`** — projetos IntelliJ feitos em aula: herança e polimorfismo (Brownie, Mamíferos, Personagem), encapsulamento/pacotes (Conta, Arkanoid, Space Shooter), exceções (try-catch), coleções, arquivos com NIO, threads e medição de desempenho.
- **`PCMania/`** — projeto avaliativo de montagem/venda de computadores.
- **`testandoIntegracao/`** — projeto Maven de integração Java + banco de dados com JDBC (padrão DAO).
- **`POO/`** — vault do Obsidian com anotações teóricas (arrays, coleções, construtores e `static`, herança, exceções, revisão para a prova 1).

### Outros arquivos
- `Wireframe app_250319_191918.pdf` — wireframe de um aplicativo.

## Ferramentas usadas
- **Obsidian** (com plugin Excalidraw) para as anotações em `.md`
- **MySQL / MySQL Workbench** para BD
- **Arduino IDE** e **SimulIDE** para Microcontroladores
- **IntelliJ IDEA** e **Maven** para POO
