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
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "order_veiculos_idx");
}

/* Função de comparação entre chaves do índice pistas_idx */
int order_pistas_idx(const void *key, const void *elem) {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "order_pistas_idx");
}

/* Função de comparação entre chaves do índice corridas_idx */
int order_corridas_idx(const void *key, const void *elem) {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "order_corridas_idx");
}

/* Função de comparação entre chaves do índice nome_pista_idx */
int order_nome_pista_idx(const void *key, const void *elem) {
	/* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "order_nome_pista_idx");
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int order_preco_veiculo_idx(const void *key, const void *elem) {
	/* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "order_preco_veiculo_idx");
}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int order_corredor_veiculo_idx(const void *key, const void *elem) {
	/* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "order_corredor_veiculo_idx");
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
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "criar_veiculos_idx");
}

void criar_pistas_idx() {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "criar_pistas_idx");
}

void criar_corridas_idx() {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "criar_corridas_idx");
}

void criar_nome_pista_idx() {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "criar_nome_pista_idx");
}

void criar_preco_veiculo_idx() {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "criar_preco_veiculo_idx");
}

void criar_corredor_veiculos_idx() {
    /* IMPLEMENTAR A FUNÇÃO AQUI */
    printf(ERRO_NAO_IMPLEMENTADO, "criar_corredor_veiculos_idx");
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
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_veiculo");
	
	return false;
}

bool exibir_pista(int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_pista");
	
	return false;
}

bool exibir_corrida(int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_corrida");
	
	return false;
}

/* Exibe um registro com base na chave de um btree_node */
bool exibir_btree_corredores(char *chave) {
	int rrn = atoi(chave + TAM_ID_CORREDOR - 1);
    return exibir_corredor(rrn);
}

bool exibir_btree_veiculos(char *chave) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_btree_veiculos");
	
	return false;
}

bool exibir_btree_pistas(char *chave) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_btree_pistas");
	
	return false;
}

bool exibir_btree_corridas(char *chave) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_btree_corridas");
	
	return false;
}

bool exibir_btree_nome_pista(char *chave) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "exibir_btree_nome_pista");
	
	return false;
}

bool exibir_btree_preco_veiculo(char *chave) {
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
	Veiculo v;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "recuperar_registro_veiculo");
	
	return v;
}

Pista recuperar_registro_pista(int rrn) {
	Pista p;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "recuperar_registro_pista");

	return p;
}

Corrida recuperar_registro_corrida(int rrn) {
    Corrida c;

	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "recuperar_registro_corrida");

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
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "escrever_registro_veiculo");
}

void escrever_registro_pista(Pista p, int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "escrever_registro_pista");
}

void escrever_registro_corrida(Corrida i, int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "escrever_registro_corrida");
}

/* Funções principais */
void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_corredor_menu");
}

void remover_corredor_menu(char *id_corredor) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "remover_corredor_menu");
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, true);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "adicionar_saldo");
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "comprar_veiculo_menu");
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_veiculo_menu");
}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "cadastrar_pista_menu");
}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
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
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "buscar_pista_id_menu");
}

void buscar_pista_nome_menu(char *nome_pista) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "buscar_pista_nome_menu");
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else
		btree_print_in_order(NULL, NULL, exibir_btree_corredores, corredores_idx.rrn_raiz, &corredores_idx);
}

void listar_corredores_modelo_menu(char *modelo) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corredores_modelo_menu");
}

void listar_veiculos_compra_menu(char *id_corredor) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_veiculos_compra_menu");
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "listar_corridas_periodo_menu");
}

/* Liberar espaço */
void liberar_espaco_menu() {
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
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_veiculos_idx_menu");
}

void imprimir_pistas_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_pistas_idx_menu");
}

void imprimir_corridas_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corridas_idx_menu");
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_nome_pista_idx_menu");
}

void imprimir_preco_veiculo_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_preco_veiculo_idx_menu");
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corredor_veiculos_secundario_idx_menu");
}

void imprimir_corredor_veiculos_primario_idx_menu(){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corredor_veiculos_primario_idx_menu");
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
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_insert");
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
    promovido_aux p;

	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_insert_aux");

    return p;
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
    promovido_aux p;

	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_divide");

    return p;
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
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_search");
	return false;
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
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_print_in_order");
	return false;
}

/**
 * Função interna para ler um nó em uma Árvore-B (T).<br />
 *
 * @param no No a ser lido da Árvore-B.
 * @param t Árvore-B na qual será feita a leitura do nó.
 */
btree_node btree_read(int rrn, btree *t) {
    btree_node te;
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_read");
	return te;
}

/**
 * Função interna para escrever um nó em uma Árvore-B (T).<br />
 *
 * @param no No a ser escrito na Árvore-B.
 * @param t Árvore-B na qual será feita a escrita do nó.
 */
void btree_write(btree_node no, btree *t) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_write");
	return false;
}

/**
 * Função interna para alocar o espaço necessário dos campos chaves (vetor de strings) e filhos (vetor de inteiros) da struct btree_node.<br />
 *
 * @param t Árvore-B base para o qual será alocado um struct btree_node.
 */
btree_node btree_node_malloc(btree *t) {
    btree_node no;
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "btree_node_malloc");
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
    int ret=-1;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	printf(ERRO_NAO_IMPLEMENTADO, "busca_binaria_com_reps");
	return ret;
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