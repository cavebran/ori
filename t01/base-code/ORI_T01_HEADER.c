/* ==========================================================================
 * Universidade Federal de São Carlos - Campus Sorocaba
 * Disciplina: Organização de Recuperação da Informação
 * Prof. Tiago A. Almeida
 *
 * Trabalho 01 - Indexação
 *
 * ========================================================================== *
 *   <<< IMPLEMENTE AQUI!!! COPIE E COLE O CONTEÚDO DESTE ARQUIVO NO AVA >>>
 * ========================================================================== */

/* Bibliotecas */
#include "ORI_T01_HEADER.h"

/* ===========================================================================
 * ================================= FUNÇÕES ================================= */


/* <<< COLOQUE AQUI OS DEMAIS PROTÓTIPOS DE FUNÇÕES, SE NECESSÁRIO >>> */


/* Funções auxiliares para o qsort.
 * Com uma pequena alteração, é possível utilizá-las no bsearch, assim, evitando código duplicado.
 * */

/* Função de comparação entre chaves do índice corredores_idx */
int qsort_corredores_idx(const void *a, const void *b) {
	return strcmp( ( (corredores_index *)a )->id_corredor, ( (corredores_index *)b )->id_corredor);
}

/* Função de comparação entre chaves do índice veiculos_idx */
int qsort_veiculos_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	return strcmp( ( (veiculos_index *)a )->id_veiculo, ( (veiculos_index *)b )->id_veiculo);
}

/* Função de comparação entre chaves do índice pistas_idx */
int qsort_pistas_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	return strcmp( ( (pistas_index *)a )->id_pista, ( (pistas_index *)b )->id_pista);
}

/* Função de comparação entre chaves do índice corridas_idx */
int qsort_corridas_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	int o = strcmp( ( (corridas_index *)a )->ocorrencia, ( (corridas_index *)b )->ocorrencia);
	if(o != 0) {
		return o;
	}

	return strcmp( ( (corridas_index *)a )->id_pista, ( (corridas_index *)b )->id_pista);
}

/* Funções de comparação apenas entre data de ocorrencia do índice corridas_idx */
int qsort_data_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	return strcmp( ( (corridas_index *)a )->ocorrencia, ( (corridas_index *)b )->ocorrencia);
}

/* Função de comparação entre chaves do índice nome_pista_idx */
int qsort_nome_pista_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	return strcmp( ( (nome_pista_index *)a )->nome, ( (nome_pista_index *)b )->nome);
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int qsort_preco_veiculo_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	return  ( (preco_veiculo_index *)a )->preco - ( (preco_veiculo_index *)b )->preco;
}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int qsort_corredor_veiculos_secundario_idx(const void *a, const void *b) {
	// IMPLEMENTADA
	return strcmp( ( (corredor_veiculos_secundario_index *)a )->chave_secundaria, ( (corredor_veiculos_secundario_index *)b )->chave_secundaria);
}

/* Cria o índice respectivo */
void criar_corredores_idx() {
	if (!corredores_idx) {
		corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
	}

	if (!corredores_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
		Corredor c = recuperar_registro_corredor(i);

		if (strncmp(c.id_corredor, "*|", 2) == 0) {
			corredores_idx[i].rrn = -1; // registro excluído
		} else {
			corredores_idx[i].rrn = i;
		}

		strcpy(corredores_idx[i].id_corredor, c.id_corredor);
	}

	qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	printf(INDICE_CRIADO, "corredores_idx");
}

void criar_veiculos_idx() {
	// IMPLEMENTADA
	if(!veiculos_idx) {
		veiculos_idx = malloc(MAX_REGISTROS * sizeof(veiculos_index));
	}

	if(!veiculos_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		Veiculo v = recuperar_registro_veiculo(i);

		if(strncmp(v.id_veiculo, "*|", 2) == 0) {
			veiculos_idx[i].rrn = -1; // registro excluído
		} else {
			veiculos_idx[i].rrn = i;
		}

		strcpy(veiculos_idx[i].id_veiculo, v.id_veiculo);
	}

	qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
	printf(INDICE_CRIADO, "veiculos_idx");
}

void criar_pistas_idx() {
	// IMPLEMENTADA
	if(!pistas_idx) {
		pistas_idx = malloc(MAX_REGISTROS * sizeof(pistas_index));
	}

	if(!pistas_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Pista p = recuperar_registro_pista(i);

		if(strncmp(p.id_pista, "*|", 2) == 0) {
			pistas_idx[i].rrn = -1; // registro excluído
		} else
			pistas_idx[i].rrn = i;

		strcpy(pistas_idx[i].id_pista, p.id_pista);
	}

	qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
	printf(INDICE_CRIADO, "pistas_idx");
}

void criar_corridas_idx() {
	// IMPLEMENTADA
	if(!corridas_idx)
		corridas_idx = malloc(MAX_REGISTROS * sizeof(corridas_index));

	if(!corridas_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_corridas; ++i) {
		Corrida c = recuperar_registro_corrida(i);

		corridas_idx[i].rrn = i;
		strcpy(corridas_idx[i].id_pista, c.id_pista);
		strcpy(corridas_idx[i].ocorrencia, c.ocorrencia);
	}

	qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);
	printf(INDICE_CRIADO, "corridas_idx");
}

void criar_nome_pista_idx() {
	// IMPLEMENTADA
	if(!nome_pista_idx) {
		nome_pista_idx = malloc(MAX_REGISTROS * sizeof(nome_pista_index));
	}

	if(!nome_pista_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Pista p = recuperar_registro_pista(i);

		int j;
		for(j = 0; p.nome[j]; j++) {
			p.nome[j] = toupper(p.nome[j]);
		}

		strcpy(nome_pista_idx[i].id_pista, p.id_pista);
		strcpy(nome_pista_idx[i].nome, strupr(p.nome));
	}

	qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
	printf(INDICE_CRIADO, "nome_pista_idx");
}

void criar_preco_veiculo_idx() {
	// IMPLEMENTADA
	if(!preco_veiculo_idx) {
		preco_veiculo_idx = malloc(MAX_REGISTROS * sizeof(preco_veiculo_index));
	}

	if(!preco_veiculo_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		Veiculo v = recuperar_registro_veiculo(i);

		strcpy(preco_veiculo_idx[i].id_veiculo, v.id_veiculo);
		preco_veiculo_idx[i].preco = v.preco;
	}

	qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
	printf(INDICE_CRIADO, "preco_veiculo_idx");
}

void criar_corredor_veiculos_idx() {
	// IMPLEMENTADA
	if(!corredor_veiculos_idx.corredor_veiculos_primario_idx) {
		corredor_veiculos_idx.corredor_veiculos_primario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_primario_index));
	}

	if(!corredor_veiculos_idx.corredor_veiculos_secundario_idx) {
		corredor_veiculos_idx.corredor_veiculos_secundario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_secundario_index));
	}

	if(!corredor_veiculos_idx.corredor_veiculos_primario_idx || !corredor_veiculos_idx.corredor_veiculos_secundario_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_corredores; ++i) {
		Corredor c = recuperar_registro_corredor(i);

		for(unsigned j = 0; j < QTD_MAX_VEICULO; ++j) {
			if(c.veiculos[j][0]) {
				inverted_list_insert(strupr(c.veiculos[j]), c.id_corredor, &corredor_veiculos_idx);
			}
		}
	}

	printf(INDICE_CRIADO, "corredor_veiculos_idx");
}

/* Exibe um registro com base no RRN */
bool exibir_corredor(int rrn) {
	if (rrn < 0)
		return false;

	Corredor c = recuperar_registro_corredor(rrn);

	printf("%s, %s, %s, %s, %.2lf\n", c.id_corredor, c.nome, c.apelido, c.cadastro, c.saldo);
	return true;
}

bool exibir_veiculo(int rrn) {
	// IMPLEMENTADA
	if(rrn < 0) {
		return false;
	}

	Veiculo v = recuperar_registro_veiculo(rrn);

	printf("%s, %s, %s, %s, %i, %i, %i, %.2lf\n", v.id_veiculo, v.marca, v.modelo, v.poder, v.velocidade, v.aceleracao, v.peso, v.preco);
	return true;
}

bool exibir_pista(int rrn) {
	// IMPLEMENTADA
	if(rrn < 0) {
		return false;
	}

	Pista p = recuperar_registro_pista(rrn);

	printf("%s, %s, %i, %i, %i\n", p.id_pista, p.nome, p.dificuldade, p.distancia, p.recorde);
	return true;
}

bool exibir_corrida(int rrn) {
	// IMPLEMENTADA
	if(rrn < 0) {
		return false;
	}

	Corrida c = recuperar_registro_corrida(rrn);

	printf("%s, %s, %s, %s\n", c.id_pista, c.ocorrencia, c.id_corredores, c.id_veiculos);
	return true;
}

/* Recupera do arquivo o registro com o RRN informado
 * e retorna os dados nas structs corredor, Curso e Inscricao */
Corredor recuperar_registro_corredor(int rrn) {
	Corredor c;
	char temp[TAM_REGISTRO_CORREDOR + 1], *p;
	strncpy(temp, ARQUIVO_CORREDORES + (rrn * TAM_REGISTRO_CORREDOR), TAM_REGISTRO_CORREDOR);
	temp[TAM_REGISTRO_CORREDOR] = '\0';

	p = strtok(temp, ";");
	strcpy(c.id_corredor, p);
	p = strtok(NULL, ";");
	strcpy(c.nome, p);
	p = strtok(NULL, ";");
	strcpy(c.apelido, p);
	p = strtok(NULL, ";");
	strcpy(c.cadastro, p);
	p = strtok(NULL, ";");
	c.saldo = atof(p);
	p = strtok(NULL, ";");

	for(int i = 0; i < QTD_MAX_VEICULO; ++i)
		c.veiculos[i][0] = '\0';

	if(p[0] != '#') {
		p = strtok(p, "|");

		for(int pos = 0; p; p = strtok(NULL, "|"), ++pos)
			strcpy(c.veiculos[pos], p);
	}

	return c;
}

Veiculo recuperar_registro_veiculo(int rrn) {
	// IMPLEMENTADA
	Veiculo v;
	char temp[TAM_REGISTRO_VEICULO + 1], *p;
	strncpy(temp, ARQUIVO_VEICULOS + (rrn * TAM_REGISTRO_VEICULO), TAM_REGISTRO_VEICULO);
	temp[TAM_REGISTRO_VEICULO] = '\0';

	p = strtok(temp, ";");
	strcpy(v.id_veiculo, p);
	p = strtok(NULL, ";");
	strcpy(v.marca, p);
	p = strtok(NULL, ";");
	strcpy(v.modelo, p);
	p = strtok(NULL, ";");
	strcpy(v.poder, p);
	p = strtok(NULL, ";");
	v.velocidade = atoi(p);
	p = strtok(NULL, ";");
	v.aceleracao = atoi(p);
	p = strtok(NULL, ";");
	v.peso = atoi(p);
	p = strtok(NULL, ";");
	v.preco = atof(p);
	p = strtok(NULL, ";");

	return v;
}

Pista recuperar_registro_pista(int rrn) {
	// IMPLEMENTADA
	Pista pista;
	char temp[TAM_REGISTRO_PISTA + 1], *p;
	strncpy(temp, ARQUIVO_PISTAS + (rrn * TAM_REGISTRO_PISTA), TAM_REGISTRO_PISTA);
	temp[TAM_REGISTRO_PISTA] = '\0';

	p = strtok(temp, ";");
	strcpy(pista.id_pista, p);
	p = strtok(NULL, ";");
	strcpy(pista.nome, p);
	p = strtok(NULL, ";");
	pista.dificuldade = atoi(p);
	p = strtok(NULL, ";");
	pista.distancia = atoi(p);
	p = strtok(NULL, ";");
	pista.recorde = atoi(p);
	p = strtok(NULL, ";");

	return pista;
}

Corrida recuperar_registro_corrida(int rrn) {
	// IMPLEMENTADA
	Corrida c;
	char temp[TAM_REGISTRO_CORRIDA + 1];
	strncpy(temp, ARQUIVO_CORRIDAS + (rrn * TAM_REGISTRO_CORRIDA), TAM_REGISTRO_CORRIDA);
	temp[TAM_REGISTRO_CORRIDA] = '\0';

	strncpy(c.id_pista, temp, TAM_ID_PISTA);
	c.id_pista[TAM_ID_PISTA - 1] = '\0';

	strncpy(c.ocorrencia, temp + TAM_ID_PISTA - 1, TAM_DATETIME);
	c.ocorrencia[TAM_DATETIME - 1] = '\0';

	strncpy(c.id_corredores, temp + TAM_ID_PISTA + TAM_DATETIME - 2, TAM_ID_CORREDORES);
	c.id_corredores[TAM_ID_CORREDORES - 1] = '\0';

	strncpy(c.id_veiculos, temp + TAM_ID_PISTA + TAM_DATETIME + TAM_ID_CORREDORES - 3, TAM_ID_VEICULOS);
	c.id_veiculos[TAM_ID_VEICULOS - 1] = '\0';

	return c;
}

/* Escreve em seu respectivo arquivo na posição informada (RRN) */
void escrever_registro_corredor(Corredor c, int rrn) {
	char temp[TAM_REGISTRO_CORREDOR + 1], p[100];
	temp[0] = '\0'; p[0] = '\0';

	strcpy(temp, c.id_corredor);
	strcat(temp, ";");
	strcat(temp, c.nome);
	strcat(temp, ";");
	strcat(temp, c.apelido);
	strcat(temp, ";");
	strcat(temp, c.cadastro);
	strcat(temp, ";");
	sprintf(p, "%013.2lf", c.saldo);
	strcat(temp, p);
	strcat(temp, ";");

	for(int i = 0, k = 0; i < QTD_MAX_VEICULO; ++i) {
		if(strlen(c.veiculos[i]) > 0) {
			if (k == 0)
				k = 1;
			else
				strcat(temp, "|");
			strcat(temp, c.veiculos[i]);
		}
	}
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_CORREDOR);

	strncpy(ARQUIVO_CORREDORES + rrn*TAM_REGISTRO_CORREDOR, temp, TAM_REGISTRO_CORREDOR);
}

void escrever_registro_veiculo(Veiculo v, int rrn) {
	// IMPLEMENTADA
	char temp[TAM_REGISTRO_VEICULO + 1], p[100];
	temp[0] = '\0'; p[0] = '\0';

	strcpy(temp, v.id_veiculo);
	strcat(temp, ";");
	strcat(temp, v.marca);
	strcat(temp, ";");
	strcat(temp, v.modelo);
	strcat(temp, ";");
	strcat(temp, v.poder);
	strcat(temp, ";");
	sprintf(p, "%04d", v.velocidade);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%04d", v.aceleracao);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%04d", v.peso);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%013.2lf", v.preco);
	strcat(temp, p);
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_VEICULO);
	strncpy(ARQUIVO_VEICULOS + rrn*TAM_REGISTRO_VEICULO, temp, TAM_REGISTRO_VEICULO);
}

void escrever_registro_pista(Pista p, int rrn) {
	// IMPLEMENTADA
	char temp[TAM_REGISTRO_PISTA + 1], pp[100];
	temp[0] = '\0'; pp[0] = '\0';

	strcpy(temp, p.id_pista);
	strcat(temp, ";");
	strcat(temp, p.nome);
	strcat(temp, ";");
	sprintf(pp, "%04d", p.dificuldade);
	strcat(temp, pp);
	strcat(temp, ";");
	sprintf(pp, "%04d", p.distancia);
	strcat(temp, pp);
	strcat(temp, ";");
	sprintf(pp, "%04d", p.recorde);
	strcat(temp, pp);
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_PISTA);
	strncpy(ARQUIVO_PISTAS + rrn*TAM_REGISTRO_PISTA, temp, TAM_REGISTRO_PISTA);
}

void escrever_registro_corrida(Corrida i, int rrn) {
	// IMPLEMENTADA
	char temp[TAM_REGISTRO_CORRIDA + 1];
	temp[0] = '\0';

	strcpy(temp, i.id_pista);
	strcat(temp, i.ocorrencia);
	strcat(temp, i.id_corredores);
	strcat(temp, i.id_veiculos);

	strpadright(temp, '#', TAM_REGISTRO_CORRIDA);
	strncpy(ARQUIVO_CORRIDAS + rrn*TAM_REGISTRO_CORRIDA, temp, TAM_REGISTRO_CORRIDA);
}

/* Funções principais */
void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido) {
	// IMPLEMENTADA
	corredores_index corredor_indice;
	Corredor corredor_registro;
	strcpy(corredor_indice.id_corredor, id_corredor);

	if(busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0)) {
		printf(ERRO_PK_REPETIDA, id_corredor);
		return;
	}

	strcpy(corredor_registro.id_corredor, id_corredor);
	strcpy(corredor_registro.nome, nome);
	strcpy(corredor_registro.apelido, apelido);

	for(int i = 0; i < QTD_MAX_VEICULO; ++i) {
		corredor_registro.veiculos[i][0] = '\0';
	}

	char data_atual[TAM_DATETIME];
	current_datetime(data_atual);
	strcpy(corredor_registro.cadastro, data_atual);

	corredor_registro.saldo = 0;

	corredor_indice.rrn = qtd_registros_corredores;
	corredores_idx[qtd_registros_corredores] = corredor_indice;

	escrever_registro_corredor(corredor_registro, qtd_registros_corredores++);
	qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	printf(SUCESSO);
}

void remover_corredor_menu(char *id_corredor) {
	// IMPLEMENTADA
	corredores_index corredor_indice, *found_corredor;
	Corredor corredor_registro;
	strcpy(corredor_indice.id_corredor, id_corredor);
	found_corredor = busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);

	if(!found_corredor) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		return;
	}
	
	corredor_registro = recuperar_registro_corredor(found_corredor->rrn);
	corredor_registro.id_corredor[0] = '*';
	corredor_registro.id_corredor[1] = '|';

	escrever_registro_corredor(corredor_registro, found_corredor->rrn);
	found_corredor->rrn = -1;
	
	printf(SUCESSO);
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, false);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag) {
	// IMPLEMENTADA
	if(valor <= 0) {
		printf(ERRO_VALOR_INVALIDO);
		return;
	}

	corredores_index corredor_indice, *found_corredor;
	strcpy(corredor_indice.id_corredor, id_corredor);
	Corredor corredor_registro;
	found_corredor = busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, flag, 0);

	if(!found_corredor || found_corredor->rrn < 0) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	} else {
		corredor_registro = recuperar_registro_corredor(found_corredor->rrn);
		corredor_registro.saldo += valor;
		escrever_registro_corredor(corredor_registro, found_corredor->rrn);
		printf(SUCESSO);
	}
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	// IMPLEMENTADA
	corredores_index corredor_indice, *found_corredor;
	strcpy(corredor_indice.id_corredor, id_corredor);
	Corredor corredor_registro;
	found_corredor = busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);

	if(!found_corredor) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		return;
	}

	veiculos_index veiculo_indice, *found_veiculo;
	strcpy(veiculo_indice.id_veiculo, id_veiculo);
	Veiculo veiculo_registro;
	found_veiculo = busca_binaria(&veiculo_indice, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0);

	if(!found_veiculo) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		return;
	}

	corredor_registro = recuperar_registro_corredor(found_corredor->rrn);
	veiculo_registro = recuperar_registro_veiculo(found_veiculo->rrn);

	if(corredor_registro.saldo < veiculo_registro.preco) {
		printf(ERRO_SALDO_NAO_SUFICIENTE);
		return;
	}

	for(unsigned i = 0; i < QTD_MAX_VEICULO; ++i) {
		if(strcmp(veiculo_registro.modelo, corredor_registro.veiculos[i]) == 0) {
			printf(ERRO_VEICULO_REPETIDO, corredor_registro.id_corredor, veiculo_registro.id_veiculo);
			return;
		} else if(corredor_registro.veiculos[i][0] == '\0') {
			strcpy(corredor_registro.veiculos[i], veiculo_registro.modelo);
			break;
		}
	}

	corredor_registro.saldo -= veiculo_registro.preco;
	escrever_registro_corredor(corredor_registro, found_corredor->rrn);
	inverted_list_insert(veiculo_registro.modelo, corredor_registro.id_corredor, &corredor_veiculos_idx);
	
	printf(SUCESSO);
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	// IMPLEMENTADA
	veiculos_index veiculo_indice;
	preco_veiculo_index preco_veiculo_indice;

	Veiculo veiculo_registro;
	char id_veiculo[TAM_ID_VEICULO];
	sprintf(id_veiculo, "%07d", qtd_registros_veiculos);
	strcpy(veiculo_indice.id_veiculo, id_veiculo);

	strcpy(preco_veiculo_indice.id_veiculo, id_veiculo);
	preco_veiculo_indice.preco = preco;

	if(busca_binaria(&veiculo_indice, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0)) {
		printf(ERRO_PK_REPETIDA, id_veiculo);
		return;
	}

	strcpy(veiculo_registro.id_veiculo, id_veiculo);
	strcpy(veiculo_registro.marca, marca);
	strcpy(veiculo_registro.modelo, modelo);
	strcpy(veiculo_registro.poder, poder);
	veiculo_registro.velocidade = velocidade;
	veiculo_registro.aceleracao = aceleracao;
	veiculo_registro.peso = peso;
	veiculo_registro.preco = preco;

	veiculo_indice.rrn = qtd_registros_veiculos;
	veiculos_idx[qtd_registros_veiculos] = veiculo_indice;
	preco_veiculo_idx[qtd_registros_veiculos] = preco_veiculo_indice;

	escrever_registro_veiculo(veiculo_registro, qtd_registros_veiculos++);
	qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
	qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
	printf(SUCESSO);
}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde) {
	// IMPLEMENTADA
	pistas_index pista_indice;
	nome_pista_index nome_pista_indice;
	Pista pista_registro;
	char id_pista[TAM_ID_PISTA], nome_upper[TAM_MAX_NOME_PISTA];
	unsigned i;

	sprintf(id_pista, "%08d", qtd_registros_pistas);
	strcpy(pista_indice.id_pista, id_pista);
	strcpy(nome_pista_indice.id_pista, id_pista);

	for(i = 0; i < strlen(nome); ++i){
		nome_upper[i] = toupper(nome[i]);
	} nome_upper[i] = '\0';

	strcpy(nome_pista_indice.nome, nome_upper);

	if(busca_binaria(&nome_pista_indice, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, false, 0)) {
		printf(ERRO_PK_REPETIDA, nome);
		return;
	}

	strcpy(pista_registro.id_pista, id_pista);
	strcpy(pista_registro.nome, nome);
	pista_registro.dificuldade = dificuldade ? dificuldade: 1;
	pista_registro.distancia = distancia;
	pista_registro.recorde = recorde;

	pista_indice.rrn = qtd_registros_pistas;
	pistas_idx[qtd_registros_pistas] = pista_indice;
	nome_pista_idx[qtd_registros_pistas] = nome_pista_indice;

	escrever_registro_pista(pista_registro, qtd_registros_pistas++);
	qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
	qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
	printf(SUCESSO);
}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
	// IMPLEMENTADA
	corridas_index corrida_indice;
	Corrida corrida_registro;
	strcpy(corrida_indice.id_pista, id_pista);
	strcpy(corrida_indice.ocorrencia, ocorrencia);

	if(busca_binaria(&corrida_indice, corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx, false, 0)) {
		printf(ERRO_PK_REPETIDA, strcat(ocorrencia, id_pista));
		return;
	}

	pistas_index pista_indice, *found_pista;
	Pista pista_registro;
	strcpy(pista_indice.id_pista, id_pista);
	found_pista = busca_binaria(&pista_indice, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, false, 0);

	if(!found_pista) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		return;
	}
	
	pista_registro = recuperar_registro_pista(found_pista->rrn);

	double total_value = 6 * (TX_FIXA * pista_registro.dificuldade);
	double first_prize = 0.4 * total_value;
	double second_prize = 0.3 * total_value;
	double third_prize = 0.2 * total_value;
	bool is_to_return = false;

	for(unsigned i = 0; i < 6; ++i) {
		corredores_index corredor_indice, *found_corredor;
		Corredor corredor_registro;

		char id_corredor_corrida[TAM_ID_CORREDOR];
		strncpy(id_corredor_corrida, &id_corredores[(TAM_ID_CORREDOR - 1) * i], TAM_ID_CORREDOR - 1);
		id_corredor_corrida[TAM_ID_CORREDOR - 1] = '\0';
		strcpy(corredor_indice.id_corredor, id_corredor_corrida);

		if((found_corredor = busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0)) == NULL || found_corredor->rrn == -1) {
			printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			return;
		}

		veiculos_index veiculo_indice, *found_veiculo;
		Veiculo veiculo_registro;

		char id_veiculo_corrida[TAM_ID_VEICULO];
		strncpy(id_veiculo_corrida, &id_veiculos[(TAM_ID_VEICULO - 1) * i], TAM_ID_VEICULO - 1);
		id_veiculo_corrida[TAM_ID_VEICULO - 1] = '\0';
		strcpy(veiculo_indice.id_veiculo, id_veiculo_corrida);
		found_veiculo = busca_binaria(&veiculo_indice, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0);

		if(!found_veiculo || found_veiculo->rrn == -1) { 
			printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		}

		corredor_registro = recuperar_registro_corredor(found_corredor->rrn);
		veiculo_registro = recuperar_registro_veiculo(found_veiculo->rrn);

		bool found_flag = false;
		for(int j = 0; j < QTD_MAX_VEICULO; ++j) {
			if(strcmp(corredor_registro.veiculos[j], veiculo_registro.modelo) == 0) {
				found_flag = true;
				break;
			}
		}

		if(!found_flag) {
			printf(ERRO_CORREDOR_VEICULO, corredor_registro.id_corredor, veiculo_registro.id_veiculo);
			is_to_return = true;
		}		

		if(!is_to_return) {
			switch(i) {
				case 0:
					corredor_registro.saldo += first_prize;
					break;
				case 1:
					corredor_registro.saldo += second_prize;
					break;;
				case 2:
					corredor_registro.saldo += third_prize;
					break;
				default:
					break;
			}
		
			escrever_registro_corredor(corredor_registro, found_corredor->rrn);
		}
	}
	
	if(is_to_return) {
		return;
	}

	strcpy(corrida_registro.id_pista, id_pista);
	strcpy(corrida_registro.ocorrencia, ocorrencia);
	strcpy(corrida_registro.id_corredores, id_corredores);
	strcpy(corrida_registro.id_veiculos, id_veiculos);

	corrida_indice.rrn = qtd_registros_corridas;
	corridas_idx[qtd_registros_corridas] = corrida_indice;

	escrever_registro_corrida(corrida_registro, qtd_registros_corridas++);
	qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);

  printf(SUCESSO);
}

/* Busca */
void buscar_corredor_id_menu(char *id_corredor) {
	corredores_index index;
	strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else
		exibir_corredor(found->rrn);
}

void buscar_pista_id_menu(char *id_pista) {
	// IMPLEMENTADA
	pistas_index pista_indice, *found_pista;
	strcpy(pista_indice.id_pista, id_pista);
	found_pista = busca_binaria((void*)&pista_indice, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);

	if(!found_pista || found_pista->rrn < 0) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	} else {
		exibir_pista(found_pista->rrn);
	}
}

void buscar_pista_nome_menu(char *nome_pista) {
	// IMPLEMENTADA
	nome_pista_index nome_pista_indice, *found_nome_pista;
	strcpy(nome_pista_indice.nome, strupr(nome_pista));
	found_nome_pista  = busca_binaria(&nome_pista_indice, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, true, 0);

	if(!found_nome_pista) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	} else {
		buscar_pista_id_menu(found_nome_pista->id_pista);
	}
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else
		for(unsigned int i = 0; i < qtd_registros_corredores; i++)
			exibir_corredor(corredores_idx[i].rrn);
}

void listar_corredores_modelo_menu(char *modelo) {
	// IMPLEMENTADA
	int first_index;

	if(!inverted_list_secondary_search(&first_index, false, strupr(modelo), &corredor_veiculos_idx)) {
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
		return;
	}

	char list_found_corredores[qtd_registros_corredores][TAM_ID_CORREDOR];
	int qty_found_corredores = inverted_list_primary_search(list_found_corredores, true, first_index, NULL, &corredor_veiculos_idx);

	if(qty_found_corredores < 1) {
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
		return;
	}

	qsort(list_found_corredores, qty_found_corredores, TAM_ID_CORREDOR, qsort_corredor_veiculos_secundario_idx);

	for(unsigned i = 0; i < qty_found_corredores; ++i) {
		char list_found_corredores_temp[TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX + 1];
		strncpy(list_found_corredores_temp, list_found_corredores[i], TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX);
		list_found_corredores_temp[TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX] = '\0';
		
		corredores_index *search_result = busca_binaria(list_found_corredores_temp, corredores_idx, qtd_registros_corredores, sizeof(corredores_index),qsort_corredores_idx, false, 0);
		exibir_corredor(search_result->rrn);
	}
}

void listar_veiculos_compra_menu(char *id_corredor) {
	// IMPLEMENTADA	
	corredores_index corredor_indice, *found_corredor;
	strcpy(corredor_indice.id_corredor, id_corredor);
	found_corredor = busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0);

	if(!found_corredor || found_corredor->rrn == -1) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		return;
	}
		
	Corredor corredor_registro = recuperar_registro_corredor(found_corredor->rrn);
	Veiculo veiculo_registro;

	preco_veiculo_index *veiculos_preco_indice = (preco_veiculo_index *)malloc(sizeof(preco_veiculo_index) * qtd_registros_veiculos);
	unsigned qtd_veiculos_p_compra = 0;

	for(unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		veiculo_registro = recuperar_registro_veiculo(veiculos_idx[i].rrn);

		if(corredor_registro.saldo >= veiculo_registro.preco) {
			strcpy(veiculos_preco_indice[qtd_veiculos_p_compra].id_veiculo, veiculos_idx[i].id_veiculo);
			veiculos_preco_indice[qtd_veiculos_p_compra].preco = veiculo_registro.preco;
			qtd_veiculos_p_compra++;
		}
	}

	qsort(veiculos_preco_indice, qtd_veiculos_p_compra, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);

	for(unsigned i = 0; i < qtd_veiculos_p_compra; ++i) {
		veiculos_index veiculo_indice;
		strcpy(veiculo_indice.id_veiculo, veiculos_preco_indice[i].id_veiculo);

		veiculos_index *found_veiculo = busca_binaria(&veiculo_indice, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx, false, 0);
		exibir_veiculo(found_veiculo->rrn);
	}
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	// IMPLEMENTADA
  if (!qtd_registros_corridas) {
    printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
    return;
  }
	
  corridas_index *start_date = busca_binaria(data_inicio, corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_data_idx, true, 1);
	printf("\n");
  corridas_index *end_date = busca_binaria(data_fim, corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_data_idx, false, -1);

  if (!start_date || !end_date) {
    printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
    return;
  }

  unsigned i = 0;
  while (i < qtd_registros_corridas) {
    if (strcmp(corridas_idx[i].ocorrencia, data_inicio) >= 0 && strcmp(corridas_idx[i].ocorrencia, data_fim) <= 0) {
      exibir_corrida(corridas_idx[i].rrn);
    }

    i++;
  }
}

/* Liberar espaço */
void liberar_espaco_menu() {
	// IMPLEMENTADA
	int valid_position = 0;

	for(int i = 0; i < qtd_registros_corredores; ++i) {
		if(ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * i] == '*') {
			continue;
		} else if(i != valid_position) {
			strncpy(&ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * valid_position], &ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * i], TAM_REGISTRO_CORREDOR);
		}

		valid_position++;
	}

	ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * valid_position] = '\0';
	qtd_registros_corredores = valid_position;

	if(!corredores_idx) {
		corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
	}

	if(!corredores_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for(unsigned i = 0; i < qtd_registros_corredores; ++i) {
		Corredor u = recuperar_registro_corredor(i);

		if(strncmp(u.id_corredor, "*|", 2) == 0) {
			corredores_idx[i].rrn = -1;
		} else {
			corredores_idx[i].rrn = i;
		}

		strcpy(corredores_idx[i].id_corredor, u.id_corredor);
	}

	qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	printf(SUCESSO);
}

/* Imprimir arquivos de dados */
void imprimir_arquivo_corredores_menu() {
	if (qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORREDORES);
}

void imprimir_arquivo_veiculos_menu() {
	// IMPLEMENTADA
	if(qtd_registros_veiculos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		printf("%s\n", ARQUIVO_VEICULOS);
	}
}

void imprimir_arquivo_pistas_menu() {
	// IMPLEMENTADA
	if(qtd_registros_pistas == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		printf("%s\n", ARQUIVO_PISTAS);
	}
}

void imprimir_arquivo_corridas_menu() {
	// IMPLEMENTADA
	if(qtd_registros_corridas == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		printf("%s\n", ARQUIVO_CORRIDAS);
	}
}

/* Imprimir índices primários */
void imprimir_corredores_idx_menu() {
	if (corredores_idx == NULL || qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corredores; ++i)
			printf("%s, %d\n", corredores_idx[i].id_corredor, corredores_idx[i].rrn);
}

void imprimir_veiculos_idx_menu() {
	// IMPLEMENTADA
	if(!veiculos_idx || qtd_registros_veiculos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		for(unsigned i = 0; i < qtd_registros_veiculos; ++i) {
			printf("%s, %d\n", veiculos_idx[i].id_veiculo, veiculos_idx[i].rrn);
		}
	}
}

void imprimir_pistas_idx_menu() {
	// IMPLEMENTADA
	if(!pistas_idx || qtd_registros_pistas == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		for(unsigned i = 0; i < qtd_registros_pistas; ++i) {
			printf("%s, %d\n", pistas_idx[i].id_pista, pistas_idx[i].rrn);
		}
	}
}

void imprimir_corridas_idx_menu() {
	// IMPLEMENTADA
	if(!corridas_idx || qtd_registros_corridas == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}	else {
		for(unsigned i = 0; i < qtd_registros_corridas; ++i) {
			printf("%s, %s, %d\n", corridas_idx[i].ocorrencia, corridas_idx[i].id_pista, corridas_idx[i].rrn); 
		}
	}
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	// IMPLEMENTADA
	if(!nome_pista_idx || qtd_registros_pistas == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		for(unsigned i = 0; i < qtd_registros_pistas; ++i) {
			printf("%s, %s\n", nome_pista_idx[i].nome, nome_pista_idx[i].id_pista); 
		}
	}
}

void imprimir_preco_veiculo_idx_menu() {
	// IMPLEMENTADA
	if(!preco_veiculo_idx || qtd_registros_veiculos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		for(unsigned i = 0; i < qtd_registros_veiculos; ++i) {
			printf("%.2lf, %s\n", preco_veiculo_idx[i].preco, preco_veiculo_idx[i].id_veiculo);
		}
	}
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	// IMPLEMENTADA
	if(!corredor_veiculos_idx.corredor_veiculos_secundario_idx || corredor_veiculos_idx.qtd_registros_secundario == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		for(unsigned i = 0; i < corredor_veiculos_idx.qtd_registros_secundario; ++i) {
			printf("%s, %d\n", corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].chave_secundaria, corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].primeiro_indice);
		}
	}
}

void imprimir_corredor_veiculos_primario_idx_menu() {
	// IMPLEMENTADA
	if(!corredor_veiculos_idx.corredor_veiculos_primario_idx || corredor_veiculos_idx.qtd_registros_primario == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	} else {
		for(unsigned i = 0; i < corredor_veiculos_idx.qtd_registros_primario; ++i) {
			printf("%s, %d\n", corredor_veiculos_idx.corredor_veiculos_primario_idx[i].chave_primaria, corredor_veiculos_idx.corredor_veiculos_primario_idx[i].proximo_indice);
		}
	}
}

/* Liberar memória e encerrar programa */
void liberar_memoria_menu() {
	// IMPLEMENTADA
	free(corredores_idx);
	free(veiculos_idx);
	free(pistas_idx);
	free(corridas_idx);
	free(nome_pista_idx);
	free(preco_veiculo_idx);
	free(corredor_veiculos_idx.corredor_veiculos_primario_idx);
	free(corredor_veiculos_idx.corredor_veiculos_secundario_idx);
}

void inverted_list_insert(char *chave_secundaria, char *chave_primaria, inverted_list *t) {
	// IMPLEMENTADA
	int primario_first_position = 0, primario_last_position, found = inverted_list_secondary_search(&primario_first_position, false, chave_secundaria, t);

	if((found)) {
		inverted_list_primary_search(NULL, false, primario_first_position, &primario_last_position, t);
		t->corredor_veiculos_primario_idx[primario_last_position].proximo_indice = t->qtd_registros_primario;
	} else {
		corredor_veiculos_secundario_index  corredor_veiculos_secundario_indice;
		strcpy(corredor_veiculos_secundario_indice.chave_secundaria, strupr(chave_secundaria));
		corredor_veiculos_secundario_indice.primeiro_indice = t->qtd_registros_primario;

		t->corredor_veiculos_secundario_idx[t->qtd_registros_secundario++] = corredor_veiculos_secundario_indice;
		qsort(t->corredor_veiculos_secundario_idx, t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx);
	}

	corredor_veiculos_primario_index corredor_veiculos_primario_indice;
	strcpy(corredor_veiculos_primario_indice.chave_primaria, chave_primaria);
	corredor_veiculos_primario_indice.proximo_indice = -1;

	t->corredor_veiculos_primario_idx[t->qtd_registros_primario++] = corredor_veiculos_primario_indice;
}

bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
	// IMPLEMENTADA
	corredor_veiculos_secundario_index corredor_veiculo_secundario_indice, *found_corredor_veiculo;
	strcpy(corredor_veiculo_secundario_indice.chave_secundaria, chave_secundaria);
	found_corredor_veiculo = busca_binaria(strupr(corredor_veiculo_secundario_indice.chave_secundaria), t->corredor_veiculos_secundario_idx, t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx, exibir_caminho, 0);

	if(!found_corredor_veiculo || !result) {
		return false; 
	}

	*result = found_corredor_veiculo->primeiro_indice;
	return true;
}

int inverted_list_primary_search(char result[][TAM_ID_CORREDOR], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
	// IMPLEMENTADA
	if(exibir_caminho) {
		printf(REGS_PERCORRIDOS);
	}

	int position = 0;

	while (indice != -1) {
		if(exibir_caminho) {
			printf(" %d", indice);
		}
		if(indice_final) {
			*indice_final = indice; 
		}
		if(result) {
			strcpy(result[position], t->corredor_veiculos_primario_idx[indice].chave_primaria);
		}

		++position;
		indice = t->corredor_veiculos_primario_idx[indice].proximo_indice;
	}

	if(exibir_caminho) {
		printf("\n");
	}

	return position;
}

void* busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
	// IMPLEMENTADA
	if(exibir_caminho) {
		printf(REGS_PERCORRIDOS);
	}

  const char *base = (const char *) base0;
	const void *p;
	int limit = 0, mid = 0, cmp;

	for(limit = nmemb; limit != 0; limit >>= 1) {
		p = base + (limit >> 1) * size;
		mid += nmemb / 2;

		if(exibir_caminho) {
			printf(" %d", mid);
		}

		cmp = (*compar)(key, p);

		if(cmp > 0) {	
			base = (const char *)p + size;
			limit--;
			++mid;
			nmemb = (nmemb - 1) / 2;
		} else if(cmp < 0) {
			nmemb /= 2;
			mid -= nmemb;
		} else if(cmp == 0) {
			if(exibir_caminho) {
				printf("\n");
			}

			return (void *)p;
		}
	}

	if(retorno_se_nao_encontrado == 1) {
		if(limit < nmemb) {
			if(exibir_caminho) {
				printf("\n");
			}
		}

		return (void *)(base + limit * size);
	} else if(retorno_se_nao_encontrado == -1) {
		if(limit > 0) {
			if(exibir_caminho) {
				printf("\n");
			}
		}
		
		return (void *)(base + (limit - 1) * size);
	}

	if(exibir_caminho) {
		printf("\n");
	}

	return NULL;
}

void* busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
	return busca_binaria_com_reps(key, base0, nmemb, size, compar, exibir_caminho, 0, retorno_se_nao_encontrado);
}

char *strpadright(char *str, char pad, unsigned size) {
	for (unsigned i = strlen(str); i < size; ++i)
		str[i] = pad;
	str[size] = '\0';
	return str;
}
char *strupr(char *str) {
	for (char *p = str; *p; ++p)
		*p = toupper(*p);
	return str;
}
char *strlower(char *str) {
	for (char *p = str; *p; ++p)
		*p = tolower(*p);
	return str;
}