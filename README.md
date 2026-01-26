# algoritmos em C

Algoritmos básicos implementados em **C**, com foco em clareza, eficiência e boas práticas.

---

## Algoritmo 1 — Prefix Sum

O **Prefix Sum** é um algoritmo utilizado para pré-processar um vetor numérico de forma que seja possível calcular rapidamente a soma de qualquer intervalo contínuo (*range sum query*).

A ideia central do algoritmo é construir um vetor auxiliar onde cada posição armazena a soma de todos os elementos anteriores (incluindo o atual).

---

### ⏱️ Complexidade

- **Tempo:** `O(n)` — o vetor é percorrido uma única vez
- **Espaço:** `O(n)` — é necessário um vetor auxiliar para armazenar as somas prefixadas

Após o pré-processamento, a soma dos elementos no intervalo `[l, r]` pode ser obtida em tempo **`O(1)`**.
---

## Algoritmo 2 — Prefix Sum 2D

O **Prefix Sum 2D** é uma extensão do algoritmo de **Prefix Sum** para matrizes bidimensionais.
Ele permite calcular, de forma eficiente, a soma dos elementos de qualquer submatriz retangular em tempo constante após um pré-processamento.

---

### ⏱️ Complexidade

- **Tempo:** `O(n * m)` 
- **Espaço:** `O(n * m)` 

Após o pré-processamento, qualquer consulta de soma em uma submatriz é feita em **O(1)**.

---

### 💻 Implementação

A implementação neste repositório foi escrita em **C**, priorizando:

- Passagem de parâmetros por referência para evitar cópias desnecessárias
- Código simples e legível
- Boa separação de responsabilidades entre funções

---

### 📌 Observação

O início deste repositório é uma forma de manter constância nos estudos e registrar a resolução dos problemas propostos pelo canal **Web Fusion with Bharadwaj**, que apresenta uma série de 150 problemas resolvidos em Java.  
Aqui, os algoritmos são reimplementados em **C**, com foco didático e conceitual.

