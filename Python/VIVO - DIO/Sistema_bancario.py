LIMITE_SAQUES = 3
limite = 500
extrato = ""
numero_saques = 0
saldo = 0

while True:
    opcao = int(input(
        """
        Bem vindo ao DIO BANK!

        Digite a opção desejada:
        1 - Depósito
        2 - Saque
        3 - Extrato
        0 - Sair
        
        >>> """
    ))

    if opcao == 1:
        valor = float(input("Informe o valor a ser depositado: "))

        if valor > 0:
            saldo += valor
            extrato += f"Depósito: R$ {valor:.2f}\n"
        else:
            print("Operação falhou! O valor informado é inválido.")

    elif opcao == 2:
        saque = float(input("Informe o valor a ser sacado:"))

        if numero_saques < LIMITE_SAQUES:
            if saque <= limite and saque > 0:
                if saque <= saldo:
                    saldo -= saque
                    extrato += f"Saque: R$ {saque:.2f}\n"
                    numero_saques += 1
                    limite -= saque
                else:
                    print("Operação falhou! Saldo insuficiente!")
            else:
                print("Operação falhou! Limite de saque excedido ou valor inválido!")
        else:
            print("Operação falhou! Limite diário de saques excedido!")

    elif opcao == 3:
        print("\n-------- EXTRATO --------")
        if extrato:
            print(extrato)
        else:
            print("Não foram realizadas movimentações.")
        print(f"\nSaldo: R$ {saldo:.2f}")
        print("--------------------------")

    elif opcao == 0:
        print("Obrigado por utilizar o DIO BANK!")
        break

    else:
        print("Opção inválida!")
