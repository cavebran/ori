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
	if(o != 0)
			return o;
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
	return strcmp( ( (nome_pista_index *)a )->id_pista, ( (nome_pista_index *)b )->id_pista);
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int qsort_preco_veiculo_idx(const void *a, const void *b){
	// IMPLEMENTADA
	return strcmp( ( (preco_veiculo_index *)a )->id_veiculo, ( (preco_veiculo_index *)b )->id_veiculo);
}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int qsort_corredor_veiculos_secundario_idx(const void *a, const void *b){
	// IMPLEMENTADA
	return strcmp( ( (corredor_veiculos_secundario_index *)a )->chave_secundaria, ( (corredor_veiculos_secundario_index *)b )->chave_secundaria);
}

/* Cria o índice respectivo */
void criar_corredores_idx() {
	if (!corredores_idx)
		corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));

	if (!corredores_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
		Corredor c = recuperar_registro_corredor(i);

		if (strncmp(c.id_corredor, "*|", 2) == 0)
			corredores_idx[i].rrn = -1; // registro excluído
		else
			corredores_idx[i].rrn = i;

		strcpy(corredores_idx[i].id_corredor, c.id_corredor);
	}

	qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	printf(INDICE_CRIADO, "corredores_idx");
}

void criar_veiculos_idx() {
	// IMPLEMENTADA
	if (!veiculos_idx)
		veiculos_idx = malloc(MAX_REGISTROS * sizeof(veiculos_index));

	if (!veiculos_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		Veiculo v = recuperar_registro_veiculo(i);

		if (strncmp(v.id_veiculo, "*|", 2) == 0)
			veiculos_idx[i].rrn = -1; // registro excluído
		else
			veiculos_idx[i].rrn = i;

		strcpy(veiculos_idx[i].id_veiculo, v.id_veiculo);
	}

	qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
	printf(INDICE_CRIADO, "veiculos_idx");
}

void criar_pistas_idx() {
	// IMPLEMENTADA
	if (!pistas_idx)
		pistas_idx = malloc(MAX_REGISTROS * sizeof(pistas_index));

	if (!pistas_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Pista p = recuperar_registro_pista(i);

		if (strncmp(p.id_pista, "*|", 2) == 0)
			pistas_idx[i].rrn = -1; // registro excluído
		else
			pistas_idx[i].rrn = i;

		strcpy(pistas_idx[i].id_pista, p.id_pista);
	}

	qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
	printf(INDICE_CRIADO, "pistas_idx");
}

void criar_corridas_idx() {
	// IMPLEMENTADA
	if (!corridas_idx)
		corridas_idx = malloc(MAX_REGISTROS * sizeof(corridas_index));

	if (!corridas_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_corridas; ++i) {
		Corrida c = recuperar_registro_corrida(i);

		if (strncmp(c.id_pista, "*|", 2) == 0)
			corridas_idx[i].rrn = -1; // registro excluído
		else
			corridas_idx[i].rrn = i;

		strcpy(corridas_idx[i].id_pista, c.id_pista);
		strcpy(corridas_idx[i].ocorrencia, c.ocorrencia);
	}

	qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);
	printf(INDICE_CRIADO, "corridas_idx");
}

void criar_nome_pista_idx() {
	// IMPLEMENTADA
	if (!nome_pista_idx)
		nome_pista_idx = malloc(MAX_REGISTROS * sizeof(nome_pista_index));

	if (!nome_pista_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Pista p = recuperar_registro_pista(i);

		strcpy(nome_pista_idx[i].id_pista, p.id_pista);
		strcpy(nome_pista_idx[i].nome, strupr(p.nome));
	}

	qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
	printf(INDICE_CRIADO, "nome_pista_idx");
}

void criar_preco_veiculo_idx() {
	// IMPLEMENTADA
	if (!preco_veiculo_idx)
		preco_veiculo_idx = malloc(MAX_REGISTROS * sizeof(preco_veiculo_index));

	if (!preco_veiculo_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		Veiculo v = recuperar_registro_veiculo(i);

		strcpy(preco_veiculo_idx[i].id_veiculo, v.id_veiculo);
		v.preco = preco_veiculo_idx[i].preco;
	}

	qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
	printf(INDICE_CRIADO, "preco_veiculo_idx");
}

void criar_corredor_veiculos_idx() {
	// IMPLEMENTADA
	if (!corredor_veiculos_idx.corredor_veiculos_primario_idx)
		corredor_veiculos_idx.corredor_veiculos_primario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_primario_index));

	if(!corredor_veiculos_idx.corredor_veiculos_secundario_idx)
		corredor_veiculos_idx.corredor_veiculos_secundario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_secundario_index));

	if (!corredor_veiculos_idx.corredor_veiculos_primario_idx || !corredor_veiculos_idx.corredor_veiculos_secundario_idx) {
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}

	for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
		Corredor c = recuperar_registro_corredor(i);

		strcpy(corredor_veiculos_idx.corredor_veiculos_primario_idx->chave_primaria, c.id_corredor);

		if(!corredor_veiculos_idx.corredor_veiculos_primario_idx->proximo_indice)
			corredor_veiculos_idx.corredor_veiculos_primario_idx->proximo_indice = -1;

		// #TODO: implementar a lógica do índice secundário
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
	if (rrn < 0)
			return false;

	Veiculo v = recuperar_registro_veiculo(rrn);

	printf("%s, %s, %s, %s, %i, %i, %i, %.2lf\n", v.id_veiculo, v.marca, v.modelo, v.poder, v.velocidade, v.aceleracao, v.peso, v.preco);
	return true;
}

bool exibir_pista(int rrn) {
	// IMPLEMENTADA
	if (rrn < 0)
			return false;

	Pista p = recuperar_registro_pista(rrn);

	printf("%s, %s, %i, %i, %i\n", p.id_pista, p.nome, p.dificuldade, p.distancia, p.recorde);
	return true;
}

bool exibir_corrida(int rrn) {
	// IMPLEMENTADA
	if (rrn < 0)
			return false;

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
	char temp[TAM_REGISTRO_CORRIDA + 1], *p;
	strncpy(temp, ARQUIVO_CORRIDAS + (rrn * TAM_REGISTRO_CORRIDA), TAM_REGISTRO_CORRIDA);
	temp[TAM_REGISTRO_CORRIDA] = '\0';

	p = strtok(temp, ";");
	strcpy(c.id_pista, p);
	p = strtok(NULL, ";");
	strcpy(c.ocorrencia, p);
	p = strtok(NULL, ";");
	strcpy(c.id_corredores, p);
	p = strtok(NULL, ";");
	strcpy(c.id_veiculos, p);

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
	sprintf(p, "%d", v.velocidade);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%d", v.aceleracao);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%d", v.peso);
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
	sprintf(pp, "%d", p.dificuldade);
	strcat(temp, pp);
	strcat(temp, ";");
	sprintf(pp, "%d", p.distancia);
	strcat(temp, pp);
	strcat(temp, ";");
	sprintf(pp, "%d", p.recorde);
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
	strcat(temp, ";");
	strcat(temp, i.ocorrencia);
	strcat(temp, ";");
	strcat(temp, i.id_corredores);
	strcat(temp, ";");
	strcat(temp, i.id_veiculos);
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_CORRIDA);

	strncpy(ARQUIVO_CORRIDAS + rrn*TAM_REGISTRO_CORRIDA, temp, TAM_REGISTRO_CORRIDA);
}

/* Funções principais */
void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido) {
	// IMPLEMENTADA
	corredores_index corredor_indice;
	Corredor corredor_registro;
	strcpy(corredor_indice.id_corredor, id_corredor);

	if(busca_binaria(&corredor_indice, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, false, 0)){
		printf(ERRO_PK_REPETIDA, id_corredor);
		return;
	}

	strcpy(corredor_registro.id_corredor, id_corredor);
	strcpy(corredor_registro.nome, nome);
	strcpy(corredor_registro.apelido, apelido);

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
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "remover_corredor_menu()");
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, true);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag) {
	// IMPLEMENTADA
	if(valor <= 0) {
		printf(ERRO_VALOR_INVALIDO);
		return;
	}

	corredores_index index;
	strcpy(index.id_corredor, id_corredor);
	corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);

	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else {
		Corredor c = recuperar_registro_corredor(found->rrn);
		c.saldo += valor;
		printf(SUCESSO);
	}
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "comprar_veiculo_menu()");
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_veiculo_menu()");
}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_pista_menu()");
}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "executar_corrida_menu()");
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
	pistas_index index;
	strcpy(index.id_pista, id_pista);
    pistas_index *found = busca_binaria((void*)&index, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);
	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else
		exibir_pista(found->rrn);
}

void buscar_pista_nome_menu(char *nome_pista) {
	// IMPLEMENTADA
	nome_pista_index index;
	strcpy(index.nome, nome_pista);
	pistas_index *found = busca_binaria((void*)&index, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, true, 0);
	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else
		exibir_pista(found->rrn);
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else
		for (unsigned int i = 0; i < qtd_registros_corredores; i++)
			exibir_corredor(corredores_idx[i].rrn);
}

void listar_corredores_modelo_menu(char *modelo){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corredores_modelo_menu()");
}

void listar_veiculos_compra_menu(char *id_corredor) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_veiculos_compra_menu()");
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corridas_periodo_menu()");
}

/* Liberar espaço */
void liberar_espaco_menu() {
    int pos_valido = 0;

    for (int i = 0; i < qtd_registros_corredores; ++i) {
			if (ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * i] == '*') {
				continue;
			} else if (i != pos_valido) {
				strncpy(&ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * pos_valido], &ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * i], TAM_REGISTRO_CORREDOR);
			}

			pos_valido++;
    }

    ARQUIVO_CORREDORES[TAM_REGISTRO_CORREDOR * pos_valido] = '\0';
    qtd_registros_corredores = pos_valido;

    //criar indice usuario de novo
    if (!corredores_idx) {
			corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
		}
 
    if (!corredores_idx) {
			printf(ERRO_MEMORIA_INSUFICIENTE);
			exit(1);
    }
 
    for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
			Corredor u = recuperar_registro_corredor(i);

			if (strncmp(u.id_corredor, "*|", 2) == 0) {
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
	if (qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_VEICULOS);
}

void imprimir_arquivo_pistas_menu() {
	// IMPLEMENTADA
	if (qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_PISTAS);
}

void imprimir_arquivo_corridas_menu() {
	// IMPLEMENTADA
	if (qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORRIDAS);
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
	if (veiculos_idx == NULL || qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_veiculos; ++i)
			printf("%s, %d\n", veiculos_idx[i].id_veiculo, veiculos_idx[i].rrn);
}

void imprimir_pistas_idx_menu() {
	// IMPLEMENTADA
	if (pistas_idx == NULL || qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_pistas; ++i)
			printf("%s, %d\n", pistas_idx[i].id_pista, pistas_idx[i].rrn);
}

void imprimir_corridas_idx_menu() {
	// IMPLEMENTADA
	if (corridas_idx == NULL || qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corridas; ++i)
			printf("%s, %s, %d\n", corridas_idx[i].ocorrencia, corridas_idx[i].id_pista, corridas_idx[i].rrn);
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	// IMPLEMENTADA
	if (nome_pista_idx == NULL || qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corridas; ++i)
			printf("%s, %s\n", nome_pista_idx[i].nome, nome_pista_idx[i].id_pista);
}

void imprimir_preco_veiculo_idx_menu() {
	// IMPLEMENTADA
	if (preco_veiculo_idx == NULL || qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_veiculos; ++i)
			printf("%lf, %s\n", preco_veiculo_idx[i].preco, preco_veiculo_idx[i].id_veiculo);
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	// IMPLEMENTADA
	if (corredor_veiculos_idx.corredor_veiculos_secundario_idx == NULL || corredor_veiculos_idx.qtd_registros_secundario == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < corredor_veiculos_idx.qtd_registros_secundario; ++i)
			printf("%s, %d\n", corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].chave_secundaria, corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].primeiro_indice);
}

void imprimir_corredor_veiculos_primario_idx_menu(){
	// IMPLEMENTADA
	if (corredor_veiculos_idx.corredor_veiculos_primario_idx == NULL || corredor_veiculos_idx.qtd_registros_primario == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < corredor_veiculos_idx.qtd_registros_primario; ++i)
			printf("%s, %d\n", corredor_veiculos_idx.corredor_veiculos_primario_idx[i].chave_primaria, corredor_veiculos_idx.corredor_veiculos_primario_idx[i].proximo_indice);
}

/* Liberar memória e encerrar programa */
void liberar_memoria_menu() {
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
	int primeira_pos_primario = 0;
	int ultima_pos_primario;
	int encontrou;

	if ((encontrou = inverted_list_secondary_search(&primeira_pos_primario, false, chave_secundaria, t))) {
			inverted_list_primary_search(NULL, false, primeira_pos_primario, &ultima_pos_primario, t);
			t->corredor_veiculos_primario_idx[ultima_pos_primario].proximo_indice = t->qtd_registros_primario;
	} else {
			corredor_veiculos_secundario_index  corre_veic_sec_indice;
			strcpy(corre_veic_sec_indice.chave_secundaria, strupr(chave_secundaria));
			corre_veic_sec_indice.primeiro_indice = t->qtd_registros_primario;

			t->corredor_veiculos_secundario_idx[t->qtd_registros_secundario++] = corre_veic_sec_indice;
			qsort(t->corredor_veiculos_secundario_idx, t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx);
	}

	corredor_veiculos_primario_index corre_veic_pri_indice;
	strcpy(corre_veic_pri_indice.chave_primaria, chave_primaria);
	corre_veic_pri_indice.proximo_indice = -1;

	t->corredor_veiculos_primario_idx[t->qtd_registros_primario++] = corre_veic_pri_indice;
}

bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
	// IMPLEMENTADA
	corredor_veiculos_secundario_index corre_veic_indice, *encontrado;
	strcpy(corre_veic_indice.chave_secundaria, chave_secundaria);

	encontrado = busca_binaria(&corre_veic_indice, t->corredor_veiculos_secundario_idx, t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx, exibir_caminho, 0);

	if (!encontrado) {
		return false;
	}

	if (result) {
		*result = encontrado->primeiro_indice;
	}

	return true;
}

int inverted_list_primary_search(char result[][TAM_ID_CORREDOR], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
	// IMPLEMENTADA
	if (exibir_caminho) {
		printf(REGS_PERCORRIDOS);
	}

	int pos = 0;
	while (indice != -1){
		if (exibir_caminho) {
			printf(" %d", indice);
		}
		if (indice_final) {
			*indice_final = indice; 
		}
		if (result) {
			strcpy(result[pos], t->corredor_veiculos_primario_idx[indice].chave_primaria);
		}

		++pos;
		indice = t->corredor_veiculos_primario_idx[indice].proximo_indice;
	}

	if (exibir_caminho) {
		printf("\n");
	}

	return pos;
}

void* busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
	// IMPLEMENTADA
	if (exibir_caminho) {
		printf(REGS_PERCORRIDOS);
	}

  const char *base = (const char *) base0;
	const void *p;
	int lim = 0, cmp;
  int meio = 0;

	for (lim = nmemb; lim != 0; lim >>= 1) {
		p = base + (lim >> 1) * size;
		meio += nmemb / 2;

		if (exibir_caminho) {
			printf(" %d", meio);
		}

		cmp = (*compar)(key, p);

		if (cmp > 0) {	
			base = (const char *)p + size;
			lim--;
			++meio;
			nmemb = (nmemb - 1) / 2;
		} else if(cmp < 0){
				nmemb /= 2;
				meio -= nmemb;
		}
		else if (cmp == 0){
			if (exibir_caminho) {
					printf("\n");
			}

			return (void *)p;
		}
	}

	if (retorno_se_nao_encontrado == 1){
		if(lim < nmemb) {
			if (exibir_caminho) {
				printf("\n");
			}
		}

		return (void *)(base + lim * size);
	} else if(retorno_se_nao_encontrado == -1) {
		if(lim > 0) {
			if (exibir_caminho) {
				printf("\n");
			}
		}
		
		return (void *)(base + (lim - 1) * size);
	}

	if (exibir_caminho) {
		printf("\n");
	}

	return NULL;
}

void* busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
	return busca_binaria_com_reps(key, base0, nmemb, size, compar, exibir_caminho, 0, retorno_se_nao_encontrado);
}

char *strpadright(char *str, char pad, unsigned size){
	for (unsigned i = strlen(str); i < size; ++i)
		str[i] = pad;
	str[size] = '\0';
	return str;
}
char *strupr(char *str){
	for (char *p = str; *p; ++p)
		*p = toupper(*p);
	return str;
}
char *strlower(char *str){
	for (char *p = str; *p; ++p)
		*p = tolower(*p);
	return str;
}