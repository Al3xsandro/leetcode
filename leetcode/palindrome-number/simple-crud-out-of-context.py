# simple crud in python for practicing

data = []

while True:
    operation = input('Digite [i, r, u, d, q]: ').lower()

    if operation == 'q':
        print('Saindo...')
        break

    elif operation == 'i':
        id = input('Digite um id para inserir: ')
        if id in data:
            print('Id já existe')
        else:
            data.append(id)
            print(f'Adicionado: {id}')

    elif operation == 'r':
        id = input('Digite o id para encontrar: ')
        if id in data:
            print(f'Id encontrado: {id}')
        else:
            print('Id não encontrado')

    elif operation == 'u':
        id = input('Digite o id para atualizar: ')
        if id in data:
            new_id = input('Digite o novo id: ')
            index = data.index(id)
            data[index] = new_id
            print(f'Id atualizado para: {new_id}')
        else:
            print('Id não encontrado')

    elif operation == 'd':
        id = input('Digite o id para deletar: ')
        if id in data:
            data.remove(id)
            print(f'Id removido: {id}')
        else:
            print('Id não encontrado')

    else:
        print('Operação inválida')
