#include <iostream>
#include <string>
#include <exception>
#include "Sistema.h"
#include "Paciente.h"

int main(int argc, const char* const argv[]){
    Sistema sistema;
    string nome;
    int idade, opcao;
    const Paciente* paciente;

    while(true){
        std::cout << "Insira a opção desejada. ";
        std::cout << "Opções disponíveis:" << std::endl;
        std::cout << "1 - Inserir paciente" << std::endl;
        std::cout << "2 - Buscar paciente" << std::endl;
        std::cout << "3 - Imprimir pacientes" << std::endl;
        std::cout << "Outros - Sair" << std::endl;
        std::cin >> opcao;
        std::cin.ignore();

        switch(opcao){
            case 1:
                system("clear");
                std::cout << "Insira o nome do paciente: " << std::endl;
                getline(std::cin, nome);
                std::cout << "Insira a idade do paciente: " << std::endl;
                std::cin >> idade;
                std::cin.ignore();

                try{
                    if(idade < 15) sistema.insere(PacientePediatrico(nome, idade));
                    else if(idade > 60) sistema.insere(PacienteGeriatrico(nome, idade));
                    else sistema.insere(PacienteClinico(nome, idade));
                } catch (const std::exception& ex){
                    std::cout << "Erro: " << ex.what() << std::endl;
                    std::cout << "O paciente não foi inserido" << std::endl;
                    break;
                }

                std::cout << "Paciente inserido com sucesso" << std::endl;
                break;
                
            case 2:
                system("clear");

                std::cout << "Insira o nome do paciente: " << std::endl;
                getline(std::cin, nome);

                try{
                    paciente = sistema.busca(nome);
                } catch (const std::exception& ex){
                    std::cout << "Erro: " << ex.what() << std::endl;
                    std::cout << "O paciente não foi encontrado" << std::endl;
                    break;
                }

                std::cout << "Paciente encontrado: " << *paciente << std::endl;
                break;

            case 3:
                system("clear");
                
                std::cout << "Lista de pacientes:" << std::endl;
                sistema.imprime(std::cout);
                break;

            default:
                std::cout << "Opção inválida" << std::endl;
                return 1;
                break;
        }
    }

    return 0;
}
