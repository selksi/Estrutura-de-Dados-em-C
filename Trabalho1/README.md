# 🏢 Sistema Gerenciador de Listas Multi-Setoriais (Trabalho 1)

Este projeto consiste em um sistema em linguagem C desenvolvido para a disciplina de Estruturas de Dados 1 na Universidade de Brasília (UnB). O programa simula o processamento e a unificação de bancos de dados de empresas de três setores distintos: Indústria, Comércio e Serviços.

## 📐 Estruturas de Dados Utilizadas

Para atender às especificidades de cada setor, foram implementadas três arquiteturas diferentes de listas encadeadas do zero:

1. **Setor de Indústrias:** Lista Linear Simplesmente Encadeada.
2. **Setor de Comércios:** Lista Duplamente Encadeada Circular.
3. **Setor de Serviços:** Lista Duplamente Encadeada com Nó Descritor.
4. **Lista Unificada:** Lista Duplamente Encadeada com Nó Descritor (responsável por centralizar os dados dos três setores e identificar a origem de cada empresa).

---

## 🛠️ Funcionalidades do Menu

O programa conta com um menu interativo no terminal contendo as seguintes opções:

* **1. Carregar Dados de Entrada:** Realiza a leitura dos arquivos textuais (`Industria.txt`, `Comercio.txt` e `Servico.txt`), aloca a memória dinamicamente e monta as três listas base.
* **2. Gerar Lista Unificada:** Percorre as três listas estruturadas e mescla todos os cadastros em uma quarta lista (Unificada), injetando a flag do tipo de empresa (`I`, `C` ou `S`).
* **3 a 9. Relatórios de Percurso:** Exibição dos dados formatados na tela. Permite a leitura convencional (ida) e a leitura reversa (volta/invertida) para as estruturas que possuem ponteiros para o nó anterior (`->Ant`).
* **10. Apagar Listas:** Rotina rigorosa de desalocação de memória. Libera individualmente a carga de dados (`struct Cadastro`) e o nó de cada vagão (`free()`), limpando os ponteiros e prevenindo *Memory Leaks*.

---

## 📋 Formato dos Arquivos de Entrada (.txt)

Os arquivos de dados devem ser armazenados na mesma pasta do executável e seguir rigidamente o padrão de 4 linhas por registro, sem linhas em branco adicionais:

```text
[CNPJ da Empresa]
[Razão Social / Nome]
[Cidade]
[Telefone]
