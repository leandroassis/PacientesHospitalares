#include <iostream>
#include <string>
#include <exception>
#include "Sistema.h"
#include "Paciente.h"

int main() {
    Sistema sistema;

    try {
        sistema.insere(PacientePediatrico("João", 5));
        sistema.insere(PacienteGeriatrico("Maria", 70));
        sistema.insere(PacientePediatrico("Pedro", 8));

        const Paciente* paciente = sistema.busca("Maria");
        if (paciente != nullptr) {
            std::cout << "Paciente encontrado: " << *paciente << std::endl;
        } else {
            std::cout << "Paciente não encontrado" << std::endl;
        }

        paciente = sistema.busca("Ana");
        if (paciente != nullptr) {
            std::cout << "Paciente encontrado: " << *paciente << std::endl;
        } else {
            std::cout << "Paciente não encontrado" << std::endl;
        }

        std::cout << "Lista de pacientes:" << std::endl;
        sistema.imprime(std::cout);
    } catch (const std::exception& ex) {
        std::cout << "Erro: " << ex.what() << std::endl;
    }

    return 0;
}
