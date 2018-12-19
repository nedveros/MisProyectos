#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


class Cliente{
    private:
        int numCliente;
        int minutosTrabajo;
        int espera;
    public:

        Cliente(int num=0){
            minutosTrabajo = (rand()%300)+1;
            numCliente = num;
            espera=0;
        };

        virtual ~Cliente(){};

        Cliente(const Cliente& other){
            this->minutosTrabajo =other.minutosTrabajo;
            this->numCliente =other.numCliente;
            this->espera =other.espera;
        };

        Cliente& operator=(const Cliente& other){
            if (this!=&other){
                this->minutosTrabajo =other.minutosTrabajo;
                this->numCliente =other.numCliente;
                this->espera =other.espera;
            }
            return *this;
        };

        bool operator<(const Cliente &c) {
            if (this->minutosTrabajo < c.minutosTrabajo)
                return true;
            return false;
        }

        int getNumCliente() {
            return numCliente;
        }

        int getMinutosTrabajo() {
            return minutosTrabajo;
        }

        int getEspera() {
            return espera;
        }

        void setEspera(int n){
            espera=n;
        }
};



#endif // CLIENTE_H_INCLUDED
