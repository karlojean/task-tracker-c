# Task Tracker CLI

**Task Tracker** é um projeto simples de linha de comando (CLI) para gerenciamentos de tarefas, desenvolvido em **C**. 

*Este é o meu **primeiro projeto em C**, criado com o objetivo de estudar e praticar conceitos fundamentais da linguagem, como:*

---

## Objetivo

O objetivo deste projeto foi:
1. **Praticar a linguagem C**: Implementando funcionalidades úceis em um programa CLI.
2. **Aprender boas práticas**: Estruturando o código de forma modular.
3. **Estudar bibliotecas externas**: Usando o cJSON para manipular dados em formato JSON.
4. **Familiarizar-se com Makefiles**: Automatizando o processo de build e limpeza.

---

## Requisitos

- **Compilador GCC**: Para compilar o projeto.
- **Biblioteca cJSON**: Para trabalhar com JSON. Instale no Linux com:
  ```bash
  sudo apt-get install libcjson-dev
  ```
  Ou no macOS com Homebrew:
  ```bash
  brew install cjson
  ```

---

## Configuração e Compilação

1. Clone o repositório:
   ```bash
   git clone https://github.com/karlojean/task-tracker-c
   cd task-tracker
   ```

2. Compile o projeto com o `Makefile`:
   ```bash
   make
   ```

3. Limpe os arquivos gerados:
   ```bash
   make clean
   ```

O binário gerado será chamado `task_list`.

---

## Comandos da CLI

Abaixo estão os comandos disponíveis para gerenciar tarefas no **Task Tracker**:

### Adicionar Tarefa

Adiciona uma nova tarefa com uma descrição fornecida.  
**Uso**:
```bash
./task_list add "Descrição da tarefa"
```
**Exemplo**:
```bash
./task_list add "Estudar linguagem C"
```

---

### Atualizar Tarefa

Atualiza a descrição de uma tarefa existente.  
**Uso**:
```bash
./task_list update <id_da_tarefa> "Nova descrição"
```
**Exemplo**:
```bash
./task_list update 1 "Estudar linguagem C e praticar"
```

---

### Excluir Tarefa

Remove uma tarefa pelo seu ID.  
**Uso**:
```bash
./task_list delete <id_da_tarefa>
```
**Exemplo**:
```bash
./task_list delete 1
```

---

### Alterar Status de uma Tarefa

#### Marcar como "Em Progresso"
**Uso**:
```bash
./task_list mark-in-progress <id_da_tarefa>
```
**Exemplo**:
```bash
./task_list mark-in-progress 1
```

#### Marcar como "Concluído"
**Uso**:
```bash
./task_list mark-done <id_da_tarefa>
```
**Exemplo**:
```bash
./task_list mark-done 1
```

---

### Listar Tarefas

#### Listar Todas as Tarefas
Exibe todas as tarefas cadastradas.  
**Uso**:
```bash
./task_list list
```
**Exemplo**:
```bash
./task_list list
# Saída:
# ID: 1 | Descrição: Estudar linguagem C | Status: To Do
# ID: 2 | Descrição: Fazer compras         | Status: Done
```

#### Listar Tarefas por Status
Filtra as tarefas pelo status: `todo`, `in-progress` ou `done`.  
**Uso**:
```bash
./task_list list <status>
```
**Exemplo**:
```bash
./task_list list todo
# Saída:
# ID: 1 | Descrição: Estudar linguagem C | Status: To Do
```

---

## Desafios Enfrentados

Como este foi o meu primeiro projeto em C, enfrentei vários desafios, incluindo:
- Aprender a organizar código em múltiplos arquivos `.c` e `.h`.
- Gerenciar memória manualmente para evitar vazamentos.
- Entender como usar bibliotecas externas (como o cJSON).
- Estruturar um Makefile funcional para compilar o projeto.

---

## Inspiração

Exemplo de solução para o desafio do [Task Tracker CLI](https://roadmap.sh/projects/task-tracker) do roadmap.sh.