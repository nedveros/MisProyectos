#ifndef EQUIPO_H
#define EQUIPO_H


class Equipo{
    private:
        int numEquipo;
        int efectivos;
    public:

        Equipo(int num=0){
            efectivos = (rand()%100)+1;
            numEquipo = num;

        };

        virtual ~Equipo(){};

        Equipo(const Equipo& other){
            this->efectivos =other.efectivos;
            this->numEquipo =other.numEquipo;
        };

        bool operator<(const Equipo &c) {
            if (this->efectivos < c.efectivos)
                return true;
            return false;
        }

        int getEfectivos() {
            return efectivos;
        }

        int getNumEquipo() {
            return numEquipo;
        }

        int getNumCiudad() {
            return numEquipo;
        }

};



#endif // EQUIPO_H
