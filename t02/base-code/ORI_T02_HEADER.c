/* ==========================================================================
 * Universidade Federal de São Carlos - Campus Sorocaba
 * Disciplina: Organização de Recuperação da Informação
 * Prof. Tiago A. Almeida
 *
 * Trabalho 02 - Árvore-B
 *
 * ========================================================================== *
 *   <<< IMPLEMENTE AQUI!!! COPIE E COLE O CONTEÚDO DESTE ARQUIVO NO AVA >>>
 * ========================================================================== */

/* Bibliotecas */
#include "ORI_T02_HEADER.h"

/* ===========================================================================
 * ================================= FUNÇÕES ================================= */


/* <<< COLOQUE AQUI OS DEMAIS PROTÓTIPOS DE FUNÇÕES, SE NECESSÁRIO >>> */

/**
 * Função interna para desalocar o espaço necessário dos campos chaves (vetor de strings) e filhos (vetor de inteiros) da struct btree_node.<br />
 *
 * @param t Nó da arvore
 */
void btree_node_free(btree_node no) {
	for (int i = 0; i < btree_order - 1; ++i) {
		free(no.chaves[i]);
	}

  free(no.chaves);
  free(no.filhos);
}

/* Compara a chave (key) com cada elemento do índice (elem).
 * Funções auxiliares para o buscar e inserir chaves em Árvores-B.
 * Note que, desta vez, as funções comparam chaves no formato string, e não struct.
 * "key" é a chave do tipo string que está sendo buscada ou inserida. 
 * "elem" é uma chave do tipo string da struct btree_node.
 *
 * Dica: consulte sobre as funções strncmp() e strnlen(). Muito provavelmente, você vai querer utilizá-las no código.
 * */

/* Função de comparação entre chaves do índice corredores_idx */
int order_corredores_idx(const void *key, const void *elem) {
    return strncmp(key, elem, TAM_ID_CORREDOR-1);
}

/* Função de comparação entre chaves do índice veiculos_idx */
int order_veiculos_idx(const void *key, const void *elem) {
	// IMPLEMENTADA
	return strncmp(key, elem, TAM_ID_VEICULO - 1);
}

/* Função de comparação entre chaves do índice pistas_idx */
int order_pistas_idx(const void *key, const void *elem) {
  // IMPLEMENTADA
	return strncmp(key, elem, TAM_ID_PISTA - 1);
}

/* Função de comparação entre chaves do índice corridas_idx */
int order_corridas_idx(const void *key, const void *elem) {
	// IMPLEMENTADA
	return strncmp(key, elem, TAM_ID_PISTA + TAM_DATETIME - 2);
}

/* Função de comparação entre chaves do índice nome_pista_idx */
int order_nome_pista_idx(const void *key, const void *elem) {
  // IMPLEMENTADA
	return strncmp(key, elem, TAM_MAX_NOME_PISTA - 1);
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int order_preco_veiculo_idx(const void *key, const void *elem) {
	// IMPLEMENTADA
	// #TODO verificar se está certo
	return strncmp(key, elem, TAM_FLOAT_NUMBER + TAM_ID_VEICULO - 2);
}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int order_corredor_veiculo_idx(const void *key, const void *elem) {
	// IMPLEMENTADA
	// #TODO verificar se está certo
	return strncmp(key, elem, TAM_MAX_MODELO - 1);
}

/* Cria o índice respectivo */
void criar_corredores_idx() {
    char corredor_str[TAM_CHAVE_CORREDORES_IDX + 1];
    for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
			Corredor c = recuperar_registro_corredor(i);

			sprintf(corredor_str, "%s%04d", c.id_corredor, i);
			btree_insert(corredor_str, &corredores_idx);
    }
    printf(INDICE_CRIADO, "corredores_idx");
}

void criar_veiculos_idx() {
	// IMPLEMENTADA
	char veiculo_str[TAM_CHAVE_VEICULOS_IDX + 1];
	for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		Veiculo v = recuperar_registro_veiculo(i);

		sprintf(veiculo_str, "%s%04d", v.id_veiculo, i);
		btree_insert(veiculo_str, &veiculos_idx);
	}

	printf(INDICE_CRIADO, "veiculos_idx");
}

void criar_pistas_idx() {
	// IMPLEMENTADA
	char pista_str[TAM_CHAVE_PISTAS_IDX + 1];
	for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Pista p = recuperar_registro_pista(i);

		sprintf(pista_str, "%s%04d", p.id_pista, i);
		btree_insert(pista_str, &veiculos_idx);
	}

	printf(INDICE_CRIADO, "pistas_idx");
}

void criar_corridas_idx() {
	// IMPLEMENTADA
	char corrida_str[TAM_CHAVE_CORRIDAS_IDX + 1];
	for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Corrida c = recuperar_registro_corrida(i);

		sprintf(corrida_str, "%s%s%04d", c.ocorrencia, c.id_pista, i);
		btree_insert(corrida_str, &corridas_idx);
	}

	printf(INDICE_CRIADO, "corridas_idx");
}

void criar_nome_pista_idx() {
	// IMPLEMENTADA
	// #TODO veriricar se irá precisar deixar em upper case o nome da pista
	char nome_pista_str[TAM_CHAVE_NOME_PISTA_IDX + 1];
	for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
		Pista p = recuperar_registro_pista(i);

		for(unsigned j = 0; p.nome[j]; j++) {
			p.nome[j] = toupper(p.nome[j]);
		}

		sprintf(nome_pista_str, "%s%s", p.nome, p.id_pista);
		btree_insert(nome_pista_str, &nome_pista_idx);
	}

	printf(INDICE_CRIADO, "nome_pista_idx");
}

void criar_preco_veiculo_idx() {
	// IMPLEMENTADA
	char preco_veiculo_str[TAM_CHAVE_PRECO_VEICULO_IDX + 1];
	for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
		Veiculo v = recuperar_registro_veiculo(i);

		sprintf(preco_veiculo_str, "%013f%s", v.preco, v.id_veiculo);
		btree_insert(preco_veiculo_str, &preco_veiculo_idx);
	}

	printf(INDICE_CRIADO, "preco_veiculo_idx");
}

void criar_corredor_veiculos_idx() {
	// IMPLEMENTADA
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

/* Exibe um registro com base na chave de um btree_node */
bool exibir_btree_corredores(char *chave) {
	int rrn = atoi(chave + TAM_ID_CORREDOR - 1);
    return exibir_corredor(rrn);
}

bool exibir_btree_veiculos(char *chave) {
	// IMPLEMENTADA
	int rrn = atoi(chave + TAM_ID_VEICULO - 1);

	return exibir_corredor(rrn);
}

bool exibir_btree_pistas(char *chave) {
	// IMPLEMENTADA
	int rrn = atoi(chave + TAM_ID_PISTA - 1);

	return exibir_corredor(rrn);
}

bool exibir_btree_corridas(char *chave) {
	// IMPLEMENTADA
	int rrn = atoi(chave + TAM_ID_PISTA + TAM_DATETIME - 2);

	return exibir_corredor(rrn);
}

bool exibir_btree_nome_pista(char *chave) {
	// IMPLEMENTADA
	int rrn = atoi(chave + TAM_MAX_NOME_PISTA - 1);

	return exibir_corredor(rrn);
}

bool exibir_btree_preco_veiculo(char *chave) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_btree_preco_veiculo");
	
	return false;
}

/* Recupera do arquivo o registro com o RRN informado
 * e retorna os dados nas structs */
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
	char temp[TAM_REGISTRO_CORREDOR + 1], p[TAM_FLOAT_NUMBER];
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
	char temp[TAM_REGISTRO_VEICULO + 1], p[TAM_FLOAT_NUMBER];
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
	char temp[TAM_REGISTRO_PISTA + 1], pp[TAM_FLOAT_NUMBER];
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
	// #TODO mudar pq o codigo n eh meu

	if(btree_search(NULL, false, id_corredor, corredores_idx.rrn_raiz, &corredores_idx)){
		printf(ERRO_PK_REPETIDA, id_corredor);
		return;
	}

	Corredor c;

	strcpy(c.id_corredor, id_corredor);
	strcpy(c.nome, nome);
	strcpy(c.apelido, apelido);

	for(int i = 0; i < QTD_MAX_VEICULO; i++){
		c.veiculos[i][0] = '\0';
	}

	c.saldo = 0;
	current_datetime(c.cadastro);

	char corredor_str[TAM_CHAVE_CORREDORES_IDX + 1];
	escrever_registro_corredor(c, qtd_registros_corredores++);
	sprintf(corredor_str, "%s%04d", id_corredor, qtd_registros_corredores - 1);
	corredor_str[TAM_CHAVE_CORREDORES_IDX] = '\0';
	btree_insert(corredor_str, &corredores_idx);
	printf(SUCESSO);

}

void remover_corredor_menu(char *id_corredor) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "remover_corredor_menu");
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, true);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag) {
	// IMPLEMENTADA
	// #TODO mudar pq o codigo n eh meu

	char chave[TAM_CHAVE_CORREDORES_IDX + 1], p[5];
	Corredor corredor_registro;

	if(!btree_search(chave, false, id_corredor, corredores_idx.rrn_raiz, &corredores_idx)){
			printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			return;
	}

	if(valor <= 0){
			printf(ERRO_VALOR_INVALIDO);
			return;
	}

	strncpy(p, &chave[TAM_ID_CORREDOR - 1], TAM_RRN_REGISTRO);//rrn
	p[4] = '\0';
	int rrn = atoi(p);
	corredor_registro = recuperar_registro_corredor(rrn);
	corredor_registro.saldo += valor;
	escrever_registro_corredor(corredor_registro, rrn);
	printf(SUCESSO);
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "comprar_veiculo_menu");
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	// IMPLEMENTADA

	Veiculo veiculo_registro;
	char id_aux[TAM_CHAVE_VEICULOS_IDX];
	id_aux[0] = '\0';

	sprintf(veiculo_registro.id_veiculo, "%07d", qtd_registros_veiculos);
	sprintf(id_aux, "%07d", atoi(veiculo_registro.id_veiculo));

	if(btree_search(NULL, false, id_aux, veiculos_idx.rrn_raiz, &veiculos_idx)){
		printf(ERRO_PK_REPETIDA, id_aux);
		return;
	}

	//Cadastrar infos do veiculo
	strcpy(veiculo_registro.marca, marca);
	strcpy(veiculo_registro.modelo, modelo);
	strcpy(veiculo_registro.poder, poder);

	veiculo_registro.velocidade = velocidade;
	veiculo_registro.aceleracao = aceleracao;
	veiculo_registro.peso = peso;
	veiculo_registro.preco = preco;

	char veiculo_str[TAM_CHAVE_VEICULOS_IDX + 1];
	sprintf(veiculo_str, "%s%04d", veiculo_registro.id_veiculo, qtd_registros_veiculos + 1);
	btree_insert(veiculo_str, &veiculos_idx);

	escrever_registro_veiculo(veiculo_registro, qtd_registros_veiculos++);

	char preco_str[TAM_CHAVE_PRECO_VEICULO_IDX + 1];
	sprintf(preco_str, "%013.2f%s", veiculo_registro.preco, veiculo_registro.id_veiculo);
	btree_insert(preco_str, &preco_veiculo_idx);

	printf(SUCESSO);
}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_pista_menu");
}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "executar_corrida_menu");
}

/* Busca */
void buscar_corredor_id_menu(char *id_corredor) {
	char result[TAM_CHAVE_CORREDORES_IDX + 1];
    printf(RRN_NOS);
    bool found = btree_search(result, true, id_corredor, corredores_idx.rrn_raiz, &corredores_idx);
    printf("\n");
    if (!found)
        printf(ERRO_REGISTRO_NAO_ENCONTRADO);
    else
        exibir_corredor(atoi(result+TAM_ID_CORREDOR-1));
}

void buscar_pista_id_menu(char *id_pista) {
	// IMPLEMENTADA
	char result[TAM_CHAVE_PISTAS_IDX + 1];
	printf(RRN_NOS);
	bool found = btree_search(result, true, id_pista, pistas_idx.rrn_raiz, &pistas_idx);
	printf("\n");

	if (!found) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	} else {
		exibir_pista(atoi(result+TAM_ID_PISTA-1));
	}
}

void buscar_pista_nome_menu(char *nome_pista) {
	// IMPLEMENTADA
	char result[TAM_NOME_PISTA_IDX + 1];
	printf(RRN_NOS);
	bool found = btree_search(result, true, nome_pista, nome_pista_idx.rrn_raiz, &nome_pista_idx);
	printf("\n");

	if (!found) {
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	} else {
		exibir_pista(atoi(result+TAM_NOME_PISTA_IDX-1));
	}
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else
		btree_print_in_order(NULL, NULL, exibir_btree_corredores, corredores_idx.rrn_raiz, &corredores_idx);
}

void listar_corredores_modelo_menu(char *modelo) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corredores_modelo_menu");
}

void listar_veiculos_compra_menu(char *id_corredor) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_veiculos_compra_menu");
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corridas_periodo_menu");
}

/* Liberar espaço */
void liberar_espaco_menu() {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "liberar_espaco_menu");
}

/* Imprimir arquivos de dados */
void imprimir_arquivo_corredores_menu() {
	if (qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORREDORES);
}

void imprimir_arquivo_veiculos_menu() {
	if (qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_VEICULOS);
}

void imprimir_arquivo_pistas_menu() {
	if (qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_PISTAS);
}

void imprimir_arquivo_corridas_menu() {
	if (qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORRIDAS);
}

/* Imprimir índices primários */
void imprimir_corredores_idx_menu() {
	if (corredores_idx.qtd_nos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORREDORES_IDX);
}

void imprimir_veiculos_idx_menu() {
	// IMPLEMENTADA
	if (veiculos_idx.qtd_nos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_VEICULOS_IDX);
	}
}

void imprimir_pistas_idx_menu() {
	// IMPLEMENTADA
	if (pistas_idx.qtd_nos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_PISTAS_IDX);
	}
}

void imprimir_corridas_idx_menu() {
	// IMPLEMENTADA
	if (corridas_idx.qtd_nos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_CORRIDAS_IDX);
	}
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	// IMPLEMENTADA
	if (nome_pista_idx.qtd_nos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_NOME_PISTA_IDX);
	}
}

void imprimir_preco_veiculo_idx_menu() {
	// IMPLEMENTADA
	if (preco_veiculo_idx.qtd_nos == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_PRECO_VEICULO_IDX);
	}
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	// IMPLEMENTADA
	if (corredor_veiculos_idx.qtd_registros_secundario == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_CORREDOR_VEICULO_SECUNDARIO_IDX);
	}
}

void imprimir_corredor_veiculos_primario_idx_menu(){
	// IMPLEMENTADA
	if (corredor_veiculos_idx.qtd_registros_primario == 0) {
		printf(ERRO_ARQUIVO_VAZIO);
	}
	else {
		printf("%s\n", ARQUIVO_CORREDOR_VEICULO_PRIMARIO_IDX);
	}
}

/* Funções de manipulação de Lista Invertida */
/**
 * Responsável por inserir duas chaves (chave_secundaria e chave_primaria) em uma Lista Invertida (t).<br />
 * Atualiza os parâmetros dos índices primário e secundário conforme necessário.<br />
 * As chaves a serem inseridas devem estar no formato correto e com tamanho t->tam_chave_primario e t->tam_chave_secundario.<br />
 * O funcionamento deve ser genérico para qualquer Lista Invertida, adaptando-se para os diferentes parâmetros presentes em seus structs.<br />
 *
 * @param chave_secundaria Chave a ser buscada (caso exista) ou inserida (caso não exista) no registro secundário da Lista Invertida.
 * @param chave_primaria Chave a ser inserida no registro primário da Lista Invertida.
 * @param t Ponteiro para a Lista Invertida na qual serão inseridas as chaves.
 */
void inverted_list_insert(char *chave_secundaria, char *chave_primaria, inverted_list *t) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_insert");
}

/**
 * Responsável por buscar uma chave no índice secundário de uma Lista invertida (T). O valor de retorno indica se a chave foi encontrada ou não.
 * O ponteiro para o int result pode ser fornecido opcionalmente, e conterá o índice inicial das chaves no registro primário.<br />
 * <br />
 * Exemplos de uso:<br />
 * <code>
 * // Exemplo 1. A chave encontrada deverá ser retornada e o caminho não deve ser informado.<br />
 * ...<br />
 * int result;<br />
 * bool found = inverted_list_secondary_search(&result, false, modelo, &corredor_veiculos_idx);<br />
 * ...<br />
 * <br />
 * // Exemplo 2. Não há interesse na chave encontrada, apenas se ela existe, e o caminho não deve ser informado.<br />
 * ...<br />
 * bool found = inverted_list_secondary_search(NULL, false, modelo, &corredor_veiculos_idx);<br />
 * ...<br />
 * <br />
 * // Exemplo 3. Há interesse no caminho feito para encontrar a chave.<br />
 * ...<br />
 * int result;<br />
 * bool found = inverted_list_secondary_search(&result, true, modelo, &corredor_veiculos_idx);<br />
 * </code>
 *
 * @param result Ponteiro para ser escrito o índice inicial (primeira ocorrência) das chaves do registro primário. É ignorado caso NULL.
 * @param exibir_caminho Indica se o caminho percorrido deve ser impresso.
 * @param chave_secundaria Chave a ser buscada.
 * @param t Ponteiro para o índice do tipo Lista invertida no qual será buscada a chave.
 * @return Indica se a chave foi encontrada.
 */
bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
  // #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_secondary_search");
	return false;}

/**
 * Responsável por percorrer o índice primário de uma Lista invertida (T). O valor de retorno indica a quantidade de chaves encontradas.
 * O ponteiro para o vetor de strings result pode ser fornecido opcionalmente, e será populado com a lista de todas as chaves encontradas.
 * O ponteiro para o inteiro indice_final também pode ser fornecido opcionalmente, e deve conter o índice do último campo da lista encadeada
 * da chave primaria fornecida (isso é útil na inserção de um novo registro).<br />
 * <br />
 * Exemplos de uso:<br />
 * <code>
 * // Exemplo 1. As chaves encontradas deverão ser retornadas e tanto o caminho quanto o indice_final não devem ser informados.<br />
 * ...<br />
 * char chaves[TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX][MAX_REGISTROS];<br />
 * int qtd = inverted_list_primary_search(chaves, false, indice, NULL, &corredor_veiculos_idx);<br />
 * ...<br />
 * <br />
 * // Exemplo 2. Não há interesse nas chaves encontradas, apenas no indice_final, e o caminho não deve ser informado.<br />
 * ...<br />
 * int indice_final;
 * int qtd = inverted_list_primary_search(NULL, false, indice, &indice_final, &ccorredor_veiculos_idx);<br />
 * ...<br />
 * <br />
 * // Exemplo 3. Há interesse nas chaves encontradas e no caminho feito.<br />
 * ...<br />
 * char chaves[TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX][MAX_REGISTROS];<br />
 * int qtd = inverted_list_primary_search(chaves, true, indice, NULL, &corredor_veiculos_idx);<br />
 * ...<br />
 * <br />
 * </code>
 *
 * @param result Ponteiro para serem escritas as chaves encontradas. É ignorado caso NULL.
 * @param exibir_caminho Indica se o caminho percorrido deve ser impresso.
 * @param indice Índice do primeiro registro da lista encadeada a ser procurado.
 * @param indice_final Ponteiro para ser escrito o índice do último registro encontrado (cujo campo indice é -1). É ignorado caso NULL.
 * @param t Ponteiro para o índice do tipo Lista invertida no qual será buscada a chave.
 * @return Indica a quantidade de chaves encontradas.
 */
int inverted_list_primary_search(char result[][TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_primary_search");
	return -1;
}

/**
 * Responsável por buscar uma chave (k) dentre os registros secundários de uma Lista Invertida de forma eficiente.<br />
 * O valor de retorno deve indicar se a chave foi encontrada ou não.
 * O ponteiro para o int result pode ser fornecido opcionalmente, e conterá o índice no registro secundário da chave encontrada.<br />
 *
 * @param result Ponteiro para ser escrito o índice nos registros secundários da chave encontrada. É ignorado caso NULL.
 * @param exibir_caminho Indica se o caminho percorrido deve ser impresso.
 * @param chave Chave a ser buscada na Lista Invertida.
 * @param t Ponteiro para o índice da Lista Invertida no qual será buscada a chave.
 * @return Indica se a chave foi encontrada.
 */
bool inverted_list_binary_search(int* result, bool exibir_caminho, char *chave, inverted_list *t) {
	// #TODO
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_binary_search");
	return false;

}

/* Funções de manipulação de Árvores-B */
/**
 * Responsável por inserir uma chave (k) em uma Árvore-B (T). Atualiza os parâmetros da Árvore-B conforme necessário.<br />
 * A chave a ser inserida deve estar no formato correto e com tamanho t->tam_chave.<br />
 * O funcionamento deve ser genérico para qualquer Árvore-B, considerando que os únicos parâmetros que se alteram entre
 * as árvores é o t->tam_chave.<br />
 * <br />
 * Exemplo de uso:<br />
 * <code>
 * ...<br />
 * char corredor_str[TAM_CHAVE_CORREDORES_IDX + 1];<br />
 * sprintf(corredor_str, "%s%04d", id_corredor, rrn_corredor);<br />
 * btree_insert(corredor_str, &corredores_idx);<br />
 * ...<br />
 * </code>
 *
 * @param chave Chave a ser inserida na Árvore-B.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual será inserida a chave.
 */
void btree_insert(char *chave, btree *t) {
	// #TODO refatorar
	// IMPLEMENTADA
	
  if (t->qtd_nos == 0) {
    t->rrn_raiz = 0;
    t->qtd_nos = 1;

    btree_node no = btree_node_malloc(t);
    no.this_rrn = 0;
    no.folha = true;
    no.qtd_chaves = 1;

    strcpy(no.chaves[0], chave);

    btree_write(no, t);
    btree_node_free(no);
    return;
  }

  promovido_aux promovido_auxiliar = btree_insert_aux(chave, t->rrn_raiz, t);

  if (strlen(promovido_auxiliar.chave_promovida) != 0) {
    t->qtd_nos++;
    btree_node no2 = btree_node_malloc(t);
    no2.folha = false;
    no2.this_rrn = t->qtd_nos - 1;
    no2.qtd_chaves = 1;
    strcpy(no2.chaves[0], promovido_auxiliar.chave_promovida);
    no2.filhos[0] = t->rrn_raiz;
    no2.filhos[1] = promovido_auxiliar.filho_direito;
    t->rrn_raiz = no2.this_rrn;

    if (no2.qtd_chaves == btree_order) {
      promovido_aux promo;
      promo.chave_promovida[0] = '\0';
      promo.filho_direito = -1;
      memcpy(promo.chave_promovida, no2.chaves[(btree_order - 1) / 2], sizeof(char) * t->tam_chave);
      promo.filho_direito = t->qtd_nos;

      btree_divide(promo, &no2, no2.this_rrn, t);
    }

    btree_write(no2, t);
    btree_node_free(no2);
  }
}

/**
 * Função auxiliar de inserção de uma chave (k) em uma Árvore-B (T). Atualiza os parâmetros da Árvore-B conforme necessário.<br />
 * Esta é uma função recursiva. Ela recebe o RRN do nó a ser trabalhado sobre.<br />
 *
 * @param chave Chave a ser inserida na Árvore-B.
 * @param rrn RRN do nó no qual deverá ser processado.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual será inserida a chave.
 * @return Retorna uma struct do tipo promovido_aux que contém a chave promovida e o RRN do filho direito.
 */
promovido_aux btree_insert_aux(char *chave, int rrn, btree *t) {
	// #TODO refatorar
	// IMPLEMENTADA

	btree_node no = btree_read(rrn, t);

  if (no.folha) {
    if (no.qtd_chaves < btree_order - 1) {
      int i;
      for (i = no.qtd_chaves - 1; i >= 0 && t->compar(chave, no.chaves[i]) < 0; i--) {
        strcpy(no.chaves[i + 1], no.chaves[i]);
      }

      strcpy(no.chaves[i + 1], chave);
      no.qtd_chaves++;

      btree_write(no, t);
      btree_node_free(no);

      promovido_aux promovido_auxiliar;
      promovido_auxiliar.chave_promovida[0] = '\0';
      promovido_auxiliar.filho_direito = -1;

      return promovido_auxiliar;
    } else { 
      promovido_aux promo;
      memcpy(promo.chave_promovida, chave, sizeof(char) * t->tam_chave);

      return btree_divide(promo, &no, -1, t);
    }
  } else {
    int i;
    for (i = no.qtd_chaves - 1; i >= 0 && t->compar(chave, no.chaves[i]) < 0;i--) {
      i++;
		}

    promovido_aux promovido_auxiliar = btree_insert_aux(chave, no.filhos[i], t);

    if (strlen(promovido_auxiliar.chave_promovida) != 0) {
      chave = promovido_auxiliar.chave_promovida;

      if (no.qtd_chaves < btree_order - 1) { 
        int j;

        for (j = no.qtd_chaves - 1; j >= i; j--) {
          strcpy(no.chaves[j + 1], no.chaves[j]);
          no.filhos[j + 2] = no.filhos[j + 1];
        }

        strcpy(no.chaves[i], chave);
        no.filhos[i + 1] = promovido_auxiliar.filho_direito;
        no.qtd_chaves++;

        promovido_auxiliar.chave_promovida[0] = '\0';
        promovido_auxiliar.filho_direito = -1;
        btree_write(no, t);
        btree_node_free(no);

        return promovido_auxiliar;
      } else { 
        promovido_aux promo;
        memcpy(promo.chave_promovida, chave, sizeof(char) * t->tam_chave);
        promo.filho_direito = promovido_auxiliar.filho_direito;

        return btree_divide(promo, &no, no.this_rrn, t);
      }
    } else { 
      btree_node_free(no);
      promovido_auxiliar.chave_promovida[0] = '\0';
      promovido_auxiliar.filho_direito = -1;

      return promovido_auxiliar;
    }
  }
}

/**
 * Função auxiliar para dividir um nó de uma Árvore-B (T). Atualiza os parâmetros conforme necessário.<br />
 *
 * @param promo Uma struct do tipo promovido_aux que contém a chave a ser inserida e o RRN do seu filho direito.
 * @param node Ponteiro para nó que deve ser dividido. 
 * @param i O índice da posição onde a chave a ser inserida deve estar.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual será inserida a chave.
 * @return Retorna uma struct do tipo promovido_aux que contém a chave promovida e o RRN do filho direito.
 */
promovido_aux btree_divide(promovido_aux promo, btree_node *node, int i, btree *t) {
	// #TODO arrumar o codigo dps, n é meu
	// IMPLEMENTADA

  btree_node no = btree_read(node->this_rrn, t);
	btree_node novo = btree_node_malloc(t);
	t->qtd_nos++;
	novo.this_rrn = t->qtd_nos - 1;
	novo.qtd_chaves = (btree_order - 1) / 2;

	i = no.qtd_chaves - 1;
	bool chave_alocada = false;

	for (int k = novo.qtd_chaves - 1; k >= 0; --k) {
		if (!chave_alocada && t->compar(promo.chave_promovida, no.chaves[i]) > 0) {
			memcpy(novo.chaves[k], promo.chave_promovida, t->tam_chave);
			novo.filhos[k + 1] = promo.filho_direito;
			chave_alocada = 1;
		} else {
			memcpy(novo.chaves[k], no.chaves[i], t->tam_chave);
			memset(no.chaves[i], 0, t->tam_chave);
			novo.filhos[k + 1] = no.filhos[i + 1];
			i--;
		}
	}

	if (!chave_alocada) {
		while (i >= 0 && t->compar(promo.chave_promovida, no.chaves[i]) < 0) {
			strncpy(no.chaves[i + 1], no.chaves[i], t->tam_chave);
			no.filhos[i + 2] = no.filhos[i + 1];
			i--;
		}

		strncpy(no.chaves[i + 1], promo.chave_promovida, t->tam_chave);
		no.filhos[i + 2] = promo.filho_direito;
	}

	promovido_aux chave_promovida;
	strncpy(chave_promovida.chave_promovida, no.chaves[(btree_order - 1) / 2], t->tam_chave);
	novo.filhos[0] = no.filhos[(btree_order - 1) / 2 + 1];
	no.qtd_chaves = btree_order / 2;
	chave_promovida.filho_direito = novo.this_rrn;

	btree_write(no, t);
	btree_write(novo, t);

	btree_node_free(novo);
	btree_node_free(no);

	return chave_promovida;
}

/**
 * Responsável por remover uma chave (k) de uma Árvore-B (T). Atualiza os parâmetros da Árvore-B conforme necessário.<br />
 * A chave a ser removida deve estar no formato correto e com tamanho t->tam_chave.<br />
 * O funcionamento deve ser genérico para qualquer Árvore-B, considerando que os únicos parâmetros que se alteram entre
 * as árvores é o t->tam_chave.<br />
 * <br />
 * Exemplo de uso:<br />
 * <code>
 * ...<br />
 * char corredor_str[TAM_CHAVE_USUARIOS_IDX + 1];<br />
 * sprintf(corredor_str, "%s%04d", id_corredor, rrn_corredor);<br />
 * btree_delete(corredor_str, &corredores_idx);<br />
 * ...<br />
 * </code>
 *
 * @param chave Chave a ser removida da Árvore-B.
 * @param t Ponteiro para o índice do tipo Árvore-B do qual será removida a chave.
 */
void btree_delete(char *chave, btree *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// #TODO
	printf(ERRO_NAO_IMPLEMENTADO, "btree_delete");
}

/**
 * Função auxiliar de remoção de uma chave (k) de uma Árvore-B (T). Atualiza os parâmetros da Árvore-B conforme necessário.<br />
 * Esta é uma função recursiva. Ela recebe o RRN do nó a ser trabalhado sobre.<br />
 *
 * @param chave Chave a ser removida da Árvore-B.
 * @param rrn RRN do nó no qual deverá ser processado.
 * @param t Ponteiro para o índice do tipo Árvore-B do qual será removida a chave.
 * @return Indica se a remoção deixou o nó que foi processado com menos chaves que o mínimo necessário.
 */
bool btree_delete_aux(char *chave, int rrn, btree *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// #TODO
	printf(ERRO_NAO_IMPLEMENTADO, "btree_delete_aux");

	return false;
}

/**
 * Função auxiliar para redistribuir ou concatenar nós irmãos adjacentes à esquerda e à direita de um nó pai em uma Árvore-B (T). 
 * Atualiza os parâmetros conforme necessário.<br />
 *
 * @param node Ponteiro para nó pai dos nós irmãos adjacentes que deve ser redistribuidos ou concatenados. 
 * @param i O índice da posição no nó pai onde se encontra a chave separadora dos nós irmãos adjacentes.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual serão redistribuídos ou concatenados os nós irmãos adjacentes.
 * @return Indica se a redistribuição ou concatenação deixou o nó pai com menos chaves que o mínimo necessário.
 */
bool btree_borrow_or_merge(btree_node *node, int i, btree *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	// #TODO
	printf(ERRO_NAO_IMPLEMENTADO, "btree_borrow_or_merge");

	return false;
}

/**
 * Responsável por buscar uma chave (k) em uma Árvore-B (T). O valor de retorno indica se a chave foi encontrada ou não.
 * O ponteiro para a string result pode ser fornecido opcionalmente, e conterá o resultado encontrado.<br />
 * Esta é uma função recursiva. O parâmetro rrn recebe a raíz da Árvore-B na primeira chamada, e nas chamadas
 * subsequentes é o RRN do filho de acordo com o algoritmo fornecido.<br />
 * Comportamento de acordo com as especificações do PDF sobre Árvores-B e suas operações.<br />
 * <br />
 * Exemplos de uso:<br />
 * <code>
 * // Exemplo 1. A chave encontrada deverá ser retornada e o caminho não deve ser informado.<br />
 * ...<br />
 * char result[TAM_CHAVE_CORREDORES_IDX + 1];<br />
 * bool found = btree_search(result, false, id_corredor, corredores_idx.rrn_raiz, &corredores_idx);<br />
 * ...<br />
 * <br />
 * // Exemplo 2. Não há interesse na chave encontrada, apenas se ela existe, e o caminho não deve ser informado.<br />
 * ...<br />
 * bool found = btree_search(NULL, false, id_corredor, corredores_idx.rrn_raiz, &corredores_idx);<br />
 * ...<br />
 * <br />
 * // Exemplo 3. Busca por uma chave de tamanho variável (específico para o caso de buscas por chaves PIX).<br />
 * ...<br />
 * char modelo_str[TAM_MAX_MODELO];<br />
 * strcpy(nome_pista_str, nome_pista);<br />
 * strpadright(nome_pista_str, '#', TAM_MAX_NOME_PISTA - 1);<br />
 * bool found = btree_search(NULL, false, nome_pista_str, nome_pista_idx.rrn_raiz, &nome_pista_idx);<br />
 * ...<br />
 * <br />
* // Exemplo 4. Há interesse no caminho feito para encontrar a chave.<br />
  * ...<br />
 * char result[TAM_CHAVE_CORREDORES_IDX + 1];<br />
 * printf(RRN_NOS);<br />
 * bool found = btree_search(result, true, id_corredor, corredores_idx.rrn_raiz, &corredores_idx);<br />
 * printf("\n");<br />
 * </code>
 *
 * @param result Ponteiro para ser escrita a chave encontrada. É ignorado caso NULL.
 * @param exibir_caminho Indica se o caminho percorrido deve ser impresso.
 * @param chave Chave a ser buscada na Árvore-B.
 * @param rrn RRN do nó no qual deverá ser processado. É o RRN da raíz da Árvore-B caso seja a primeira chamada.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual será buscada a chave.
 * @return Indica se a chave foi encontrada.
 */
bool btree_search(char *result, bool exibir_caminho, char *chave, int rrn, btree *t) {
	// #TODO refator	ar
	//IMPLEMENTADA

  if (t->rrn_raiz == -1) {
    return false;
  }

  if (exibir_caminho) {
    if (rrn == t->rrn_raiz) {
      printf(RRN_NOS);
    }
    printf(" %d ( ", rrn);
  }

  if (t->qtd_nos == 0) {
    return false;
  }

  btree_node node = btree_read(rrn, t);
  int resultado;

  bool chave_encontrada = btree_binary_search(&resultado, exibir_caminho, chave, &node, t);

  if (chave_encontrada) {
    if (result) {
      strcpy(result, node.chaves[resultado]);
    }

    btree_node_free(node);

    if (exibir_caminho) {
      printf("\n");
    }

    return true;
  } else {
    int rrn_novo = node.filhos[resultado];
    bool folha = node.folha;
    btree_node_free(node);

    if (folha) {
      if (exibir_caminho) {
        printf("\n");
      }

      return false;
    }

    bool retorno = btree_search(result, exibir_caminho, chave, rrn_novo, t);

    if (exibir_caminho) {
      if (rrn_novo == t->rrn_raiz) {
        printf("\n");
      }
    }

    return retorno;
  }
}

/**
 * Responsável por buscar uma chave (k) dentro do nó de uma Árvore-B (T) de forma eficiente. O valor de retorno indica se a chave foi encontrada ou não.
 * O ponteiro para o int result pode ser fornecido opcionalmente, e indica o índice da chave encontrada (caso tenha sido encontrada) 
 * ou o índice do filho onde esta chave deve estar (caso não tenha sido encontrada).<br />
 *
 * @param result Ponteiro para ser escrito o índice da chave encontrada ou do filho onde ela deve estar. É ignorado caso NULL.
 * @param exibir_caminho Indica se o caminho percorrido deve ser impresso.
 * @param chave Chave a ser buscada na Árvore-B.
 * @param node Ponteiro para o nó onde a busca deve ser feita.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual será buscada a chave.
 * @return Indica se a chave foi encontrada.
 */
bool btree_binary_search(int *result, bool exibir_caminho, char* chave, btree_node* node, btree* t) {
	int i = busca_binaria(chave, node->chaves[0], node->qtd_chaves, t->tam_chave+1, t->compar, exibir_caminho, +1);
    if (result != NULL) 
        *result = i;
    return i >= 0 && i < node->qtd_chaves && !t->compar(chave, node->chaves[i]);
}

/**
 * Função para percorrer uma Árvore-B (T) em ordem.<br />
 * Os parâmetros chave_inicio e chave_fim podem ser fornecidos opcionalmente, e contém o intervalo do percurso.
 * Caso chave_inicio e chave_fim sejam NULL, o índice inteiro é percorrido.
 * Esta é uma função recursiva. O parâmetro rrn recebe a raíz da Árvore-B na primeira chamada, e nas chamadas
 * subsequentes é o RRN do filho de acordo com o algoritmo de percursão em ordem.<br />
 * <br />
 * Exemplo de uso:<br />
 * <code>
 * // Exemplo 1. Intervalo não especificado.
 * ...<br />
 * bool imprimiu = btree_print_in_order(NULL, NULL, exibir_btree_corredor, corredores_idx.rrn_raiz, &corredores_idx);
 * ...<br />
 * <br />
 * // Exemplo 2. Imprime as transações contidas no intervalo especificado.
 * ...<br />
 * bool imprimiu = btree_print_in_order(data_inicio, data_fim, exibir_btree_pista, pistas_idx.rrn_raiz, &pistas_idx);
 * ...<br />
 * </code>
 *
 * @param chave_inicio Começo do intervalo. É ignorado caso NULL.
 * @param chave_fim Fim do intervalo. É ignorado caso NULL.
 * @param exibir Função utilizada para imprimir uma chave no índice. É informada a chave para a função.
 * @param rrn RRN do nó no qual deverá ser processado.
 * @param t Ponteiro para o índice do tipo Árvore-B no qual será inserida a chave.
 * @return Indica se alguma chave foi impressa.
 */
bool btree_print_in_order(char *chave_inicio, char *chave_fim, bool (*exibir)(char *chave), int rrn, btree *t) {
	// #TODO refatorar
	//IMPLEMENTADA

  btree_node no = btree_read(rrn, t);
  int num_impressoes = 0, i = 0;

  while (i <= no.qtd_chaves - 1) {
    if (no.filhos[i] != -1) {
      bool houve_impressao = btree_print_in_order(chave_inicio, chave_fim, exibir, no.filhos[i], t);

      if (houve_impressao) {
        num_impressoes++;
      }
    }

    if ((chave_inicio == NULL || t->compar(chave_inicio, no.chaves[i]) <= 0) &&
        (chave_fim == NULL || t->compar(chave_fim, no.chaves[i]) >= 0)) {
      exibir(no.chaves[i]);
      num_impressoes++;
    }

    i++;
  }

  if (no.filhos[i] != -1) {
    if (btree_print_in_order(chave_inicio, chave_fim, exibir, no.filhos[i], t)) {
      num_impressoes++;
    }
  }

  btree_node_free(no);

  if (num_impressoes == 0) {
    return false;
  }

  return true;
}

/**
 * Função interna para ler um nó em uma Árvore-B (T).<br />
 *
 * @param no No a ser lido da Árvore-B.
 * @param t Árvore-B na qual será feita a leitura do nó.
 */
btree_node btree_read(int rrn, btree *t) {
	// #TODO arrumar o codigo dps, n é meu
	//IMPLEMENTADA

  btree_node no = btree_node_malloc(t);
  char temp[btree_register_size(t) + 1];
  char *p = temp;
  char aux[4];

  memcpy(temp, t->arquivo + (rrn * btree_register_size(t)), btree_register_size(t));
  temp[btree_register_size(t)] = '\0';

  memcpy(aux, p, 3);
  aux[3] = '\0';
  no.qtd_chaves = atoi(aux);
  p += 3;

  for (int i = 0; i < btree_order - 1; ++i) {
    if (p[0] != '#') {
      memcpy(no.chaves[i], p, t->tam_chave);
      no.chaves[i][t->tam_chave] = '\0';
    }

    p += t->tam_chave;
  }

  no.folha = (p[0] == 'T');
  p += 1;

  for (int i = 0; i < btree_order; ++i) {
    if (p[0] != '*') {
      memcpy(aux, p, 3);
      aux[3] = '\0';
      no.filhos[i] = atoi(aux);
    }

    p += 3;
  }

  no.this_rrn = rrn;
  return no;
}

/**
 * Função interna para escrever um nó em uma Árvore-B (T).<br />
 *
 * @param no No a ser escrito na Árvore-B.
 * @param t Árvore-B na qual será feita a escrita do nó.
 */
void btree_write(btree_node no, btree *t) {
	// #TODO refatorar
	// IMPLEMENTADA
	
	char temp[btree_register_size(t) + 1], p[10];
	temp[0] = '\0'; 
	p[0] = '\0';

	sprintf(p, "%03d", no.qtd_chaves);
	strcpy(temp, p);

	for (int i = 0; i < btree_order - 1; ++i) {
		if(strlen(no.chaves[i]) == 0) {
			char vazio[t->tam_chave + 1];
			vazio[0] = '\0';
			strpadright(vazio, '#', t->tam_chave);
			strcat(temp, vazio);
		} else {
			strcat(temp, no.chaves[i]);
		}
	}

	if(no.folha) {
		strcat(temp, "T");

		for (int i = 0; i < btree_order; ++i) {
			strcat(temp, "***");
		}
	} else {
		strcat(temp, "F");

		for (int i = 0; i < btree_order; ++i) {
			if(no.filhos[i] == -1) {
				strcat(temp, "***");
			} else {
				p[0] = '\0';
				sprintf(p, "%03d", no.filhos[i]);
				strcat(temp, p);
			}
		}
	}

	strncpy(t->arquivo + (no.this_rrn * btree_register_size(t)), temp, btree_register_size(t));
	t->arquivo[t->qtd_nos * btree_register_size(t)] = '\0';
}

/**
 * Função interna para alocar o espaço necessário dos campos chaves (vetor de strings) e filhos (vetor de inteiros) da struct btree_node.<br />
 *
 * @param t Árvore-B base para o qual será alocado um struct btree_node.
 */
btree_node btree_node_malloc(btree *t) {
	// #TODO verificar com a doc pra confirmar se é isso msm
	// IMPLEMENTADA

	btree_node no;
	no.chaves = malloc((btree_order - 1) * sizeof(char*));

	for (unsigned i = 0; i < btree_order - 1; ++i) {
		no.chaves[i] = malloc(t->tam_chave + 1);
		no.chaves[i][0] = '\0';
	}

	no.filhos = malloc(btree_order * sizeof(int));

	for (int i = 0; i < btree_order; ++i) {
		no.filhos[i] = -1;
	}

	return no;
}

/**
 * Função interna para calcular o tamanho em bytes de uma Árvore-B.<br />
 *
 * @param t Árvore-B base para o qual será calculado o tamanho.
 */
int btree_register_size(btree *t) {
    int chaves_ordenadas = (btree_order-1)*t->tam_chave;
    return 3 + chaves_ordenadas + 1 + (btree_order*3);
}

/* Funções de busca binária */
/**
 * Função Genérica de busca binária, que aceita parâmetros genéricos (assinatura baseada na função bsearch da biblioteca C).
 *
 * @param key Chave de busca genérica.
 * @param base0 Base onde ocorrerá a busca, por exemplo, um ponteiro para um vetor.
 * @param nmemb Número de elementos na base.
 * @param size Tamanho do tipo do elemento na base, dica: utilize a função sizeof().
 * @param compar Ponteiro para a função que será utilizada nas comparações.
 * @param exibir_caminho Indica se o caminho percorrido deve ser impresso. Se true, imprime as posições avaliadas durante a busca, até que todas sejam visitadas ou o elemento seja encontrado (pela 1a vez).
 *                       Caso o número de elementos seja par (p.ex, 10 elementos), então há 2 (duas) possibilidades para a posição da mediana dos elementos (p.ex., 5a ou 6a posição se o total fosse 10).
 *                       Neste caso, SEMPRE escolha a posição mais à direita (p.ex., a posição 6 caso o total for 10).
 * @param posicao_caso_repetido Caso o elemento seja encontrado, se houver mais do que 1 ocorrência, indica qual deve ser retornada. As opções são:
 *                     -1 = primeira : retorna a PRIMEIRA ocorrência (posição mais à esquerda).
 *                      0 = meio : retorna a ocorrência do MEIO (posição central). [modo padrão]
 *                     +1 = ultima : retorna a ÚLTIMA ocorrência (posição mais à direita).
 * @param retorno_se_nao_encontrado Caso o elemento NÃO seja encontrado, indica qual valor deve ser retornado. As opções são:
 *                     -1 = predecessor : retorna o elemento PREDECESSOR (o que apareceria imediatamente antes do elemento procurado, caso fosse encontrado).
 *                      0 = nulo : retorna NULL. [modo padrão]
 *                     +1 = sucessor : retorna o elemento SUCESSOR (o que apareceria imediatamente depois do elemento procurado, caso fosse encontrado).
 * @return Retorna o elemento encontrado ou NULL se não encontrou.
 * @return Retorna o indice do elemento encontrado ou -1 se não encontrou. 
 */
int busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
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

			if (posicao_caso_repetido == 0) {
				return mid; 
			} else {
				return posicao_caso_repetido;
			}
		}
	}

	if(retorno_se_nao_encontrado == 1) {
		if(limit < nmemb) {
			if(exibir_caminho) {
				printf("\n");
			}
		}

		return mid;
	} else if(retorno_se_nao_encontrado == -1) {
		if(limit > 0) {
			if(exibir_caminho) {
				printf("\n");
			}
		}
		
		return mid - 1;
	}

	if(exibir_caminho) {
		printf("\n");
	}

	return -1;
}

int busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
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