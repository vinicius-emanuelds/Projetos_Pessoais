import textwrap

def saque(*, saldo, valor, extrato, limite, numero_saques, limite_saques):
    excedeu_saldo = valor > saldo
    excedeu_saques = numero_saques >= limite_saques
    excedeu_limite = valor > limite
    
    if excedeu_saldo:
        print("\nTransação não autorizada! Saldo insuficiente!")

    elif excedeu_saques:
        print("\nTransação não autorizada! Limite de saques diários atingido!")

    elif excedeu_limite:
        print("\nTransação não autorizada! Limite diário atingido")

    elif valor > 0:
        saldo -= valor
        numero_saques += 1
        extrato += f"Saque:\t\tR$: {valor:.2f}\n"
        msg = " Saque realizado com sucesso! "
        print(msg.center(50, "-"))
    
    else:
        print("A operação falhou! Digite um valor válido")

    return saldo, extrato, numero_saques

def deposito(saldo, valor, extrato, /):
    if valor > 0:
        saldo += valor
        extrato += f"Depósito:\t\tR$: {valor:.2f}\n"
        msg = " Depósito realizado com sucesso! "
        print(msg.center(50, "-"))
    else:
        print("A operação falhou! Digite um valor válido")

    return saldo, extrato

def exibir_extrato(saldo, /, *, extrato):
    titulo = " EXTRATO "
    separador = "-"

    print(titulo.center(50, "-"))

    if extrato:
        print(extrato)
        print(f"\nSaldo:\t\tR$ {saldo:.2f}")
    else:
        print("Não foram realizadas movimentações.")
    
    print(separador.center(50, "-"))

def filtrar_cliente(cpf, clientes):
    for usuario in clientes:
        if usuario["cpf"] == cpf:
            return usuario
    return None

def criar_cliente(clientes):
    cpf = input("Informe o CPF (somente números): ")
    cliente = filtrar_cliente(cpf, clientes)

    if cliente:
        print("\nJá existe cliente com esse CPF!")
        return

    nome = input("Informe o nome completo: ")
    data_nascimento = input("Informe a data de nascimento (dd-mm-aaaa): ")
    endereco = input("Informe o endereço (logradouro, nº - bairro - cidade/sigla do estado): ")

    clientes.append({"nome": nome, "data_nascimento": data_nascimento, "cpf": cpf, "endereco": endereco})

    msg = " Cliente criado com sucesso! "
    print(msg.center(50, "-"))

def criar_conta(agencia, nro_conta, clientes):
    cpf = input("Informe o CPF do cliente: ")
    cliente = filtrar_cliente(cpf, clientes)

    if cliente:
        msg = " Conta criada com sucesso! "
        print(msg.center(50, "-"))
        return {"agencia": agencia, "nro_conta": nro_conta, "cliente": cliente}

    print("\nUsuário não encontrado! Fluxo de criação de conta encerrado!")

def menu():
    menu = """\n
        Bem vindo ao DIO BANK!

        Digite a opção desejada:
        1 - Depósito
        2 - Saque
        3 - Extrato
        4 - Novo cliente
        5 - Nova conta
        6 - Listar contas
        0 - Sair
        >>> """
    
    return input(textwrap.dedent(menu))

def listar_contas(contas):
    for conta in contas:
        linha = f"""\
            Agência:\t{conta['agencia']}
            C/C:\t\t{conta['nro_conta']}
            Titular:\t{conta['cliente']['nome']}
        """
        separador = "-"
        print(separador.center(50, "-"))
        print(textwrap.dedent(linha))

def main():
    LIMITE_SAQUES = 3
    AGENCIA = "0001"

    saldo = 0
    limite = 500
    extrato = ""
    numero_saques = 0
    clientes = []
    contas = []

    while True:
        opcao = menu()

        if opcao == '1':
            valor = float(input("Informe o valor do depósito: "))
            saldo, extrato = deposito(saldo, valor, extrato)

        elif opcao == '2':
            valor = float(input("Informe o valor do saque: "))
            saldo, extrato, numero_saques = saque(
                saldo=saldo,
                valor=valor,
                extrato=extrato,
                limite=limite,
                numero_saques=numero_saques,
                limite_saques=LIMITE_SAQUES,
            )

        elif opcao == '3':
            exibir_extrato(saldo, extrato=extrato)

        elif opcao == '4':
            criar_cliente(clientes)

        elif opcao == '5':
            nro_conta = len(contas) + 1
            conta = criar_conta(AGENCIA, nro_conta, clientes)

            if conta:
                contas.append(conta)

        elif opcao == '6':
            listar_contas(contas)

        elif opcao == '0':
            break

        else:
            print("Operação inválida, por favor selecione novamente a operação desejada.")

main()
