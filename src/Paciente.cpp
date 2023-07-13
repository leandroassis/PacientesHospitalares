#include "Paciente.h"

// funções de Paciente
Paciente::Paciente(const std::string& nome) : nome(nome) {}

Paciente::~Paciente() {}

std::string Paciente::getNome() const {
    return nome;
}

void Paciente::imprime(std::ostream& os) const {
    os << "Nome: " << nome;
}
// fim das funções de Paciente

// funções de PacientePediatrico
PacientePediatrico::PacientePediatrico(const std::string& nome, int idade) : Paciente(nome), idade(idade) {}

void PacientePediatrico::imprime(std::ostream& os) const {
    os << "Nome: " << nome << ", Idade: " << idade << " anos";
}

// funções de PacienteGeriatrico
PacienteGeriatrico::PacienteGeriatrico(const std::string& nome, int idade) : Paciente(nome), idade(idade) {}

void PacienteGeriatrico::imprime(std::ostream& os) const {
    os << "Nome: " << nome << ", Idade: " << idade << " anos";
}

// funções de PacienteClinico
PacienteClinico::PacienteClinico(const std::string& nome, int idade) : Paciente(nome), idade(idade) {}

void PacienteClinico::imprime(std::ostream& os) const {
    os << "Nome: " << nome << ", Idade: " << idade << " anos";
}

// operadores sobrecarregados
std::ostream& operator<<(std::ostream& os, const Paciente& paciente) {
    paciente.imprime(os);
    return os;
}
