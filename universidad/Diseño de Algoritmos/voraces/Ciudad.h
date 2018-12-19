#ifndef CIUDAD_H
#define CIUDAD_H


class Ciudad{
    private:
        int numCiudad;
        int efectivos;
    public:

        Ciudad(int num=0){
            efectivos = (rand()%100)+1;
            numCiudad = num;

        };

        virtual ~Ciudad(){};

        Ciudad(const Ciudad& other){
            this->efectivos =other.efectivos;
            this->numCiudad =other.numCiudad;
        };

    //para sort
        bool operator<(const Ciudad &c) {
            if (this->efectivos < c.efectivos)
                return true;
            return false;
        }

        int getEfectivos() const{
            return efectivos;
        }

        int getNumCiudad() {
            return numCiudad;
        }

};

#endif // CIUDAD_H
