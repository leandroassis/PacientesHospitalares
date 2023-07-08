#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Paciente {
    protected:
        std::string nome;

    public:
        Paciente(const std::string&);

        virtual ~Paciente();

        std::string getNome() const;

        virtual void imprime(std::ostream&) const;
};

class PacientePediatrico : public Paciente {
    private:
        int idade;

    public:
        PacientePediatrico(const std::string&, int);

        void imprime(std::ostream&) const override;
};

class PacienteGeriatrico : public Paciente {
    private:
        int idade;

    public:
        PacienteGeriatrico(const std::string&, int);

        void imprime(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const Paciente&);

#endif
