# Atividades de BCC402 - Algoritmos e programação avançada

Os arquivos e pastas deste repositório fazem todos menção aos exercícios propostos para realização durante o semestre da disciplina BCC402. Todos eles se encontram divididos por semana, de modo que esteja bem organizado para apresentação e visualização dos exercícios.

## Modo de execução

Para executar e verificar que tudo esta funcionando corretamente, foi realizado a configuração em cada uma das pastas de uma arquivo make, que realiza tanto a compilação, execução e teste de cada um dos programas

## Comandos disponíveis

Cada arquivo make possui 4 comandos disponíveis: make run, make test, make clean e make all.

### Make run

O make run é o responsável pela compilação, execução do programa e a geração do arquivo de output que será utilizado para teste.

### Make test

O make test realiza o teste do arquivo de output gerado, a partir de um arquivo já configurado para verificar se existem divergências entre eles ou não.

### Make clean

O make clean realiza a limpeza de arquivos que não são importantes e de arquivos gerados nas etapas anteriores.

### Make all

O make all simplesmente realiza todas essas ações na ordem de make run, make test e make clean.