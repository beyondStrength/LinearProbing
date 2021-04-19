#include <iostream>
#include <cstdlib>
#include <time.h>

class HashNode  {
public:
    int key;
    char data;

    HashNode(int key, char data){
        this->key = key;
        this->data = data;
    }
};

class HashTable {
public:
    HashNode **array;
    int maxSize;
    int size;
     

    HashTable(int max) {
        maxSize = max;
        size = 0;
        array = new HashNode*[maxSize];

        for (int i = 0; i < maxSize; i++)   {
            array[i] = 0;
        }
    }

    int hashKey(int key)   {
        return key % maxSize;
    }

    void insertNode(int key, char data)   {
        
        HashNode *newNode = new HashNode(key,data);
        int hashI = hashKey(key);

        if (size < maxSize) {
            while(array[hashI] != 0 && array[hashI]->key != key )    {
                hashI++;
                hashI = hashKey(hashI);
            }
            if(array[hashI] == 0)
                size++;
            array[hashI] = newNode;

        }else   {
            HashTable *newHashTable = new HashTable(maxSize*2);
            for (int i = 0 ; i < maxSize ; i++)  {
                if (array[i] != 0){
                    newHashTable->insertNode(array[i]->key,array[i]->data);        
                }
            }
            newHashTable->insertNode(newNode->key,newNode->data);
            *this = *newHashTable;

        }
    }

    char deleteNode(int key)    {
        int hashI = hashKey(key);

        while (array[hashI] != 0)   {
            if(array[hashI]->key == key)    {
                HashNode *aux =  array[hashI];
                size--;
                array[hashI] = 0;
                return aux->data;
            }
            hashI++;
            hashI = hashKey(hashI);   
        }
        return 0;
    }

    void printHashTable()   {
        std::cout << "\n  .:HashTable:.\n";
        for (int i = 0 ; i < maxSize ; i++)  {
            if (array[i] != 0){
                std::cout << "key: "<< array[i]->key <<" data: "<< array[i]->data<<std::endl;
            }
        }
        std::cout << std::endl;
    }

};

int main(int argc, char const *argv[])   {

    
    
    HashTable *hashTable = new HashTable(9);
    std::cout << "insere A com a chave 1" << std::endl;
    hashTable->insertNode(1,'A');
    //hashTable->printHashTable();
    
    std::cout << "insere B com a chave 9" << std::endl;
    hashTable->insertNode(9,'B');
    //hashTable->printHashTable();
    
    std::cout << "insere C com a chave 27" << std::endl;
    hashTable->insertNode(27,'C');
    hashTable->printHashTable();
    
    std::cout << "insere D com a chave 27" << std::endl;
    hashTable->insertNode(27,'D');
    hashTable->printHashTable();
    
    std::cout << "deleta da chave 9 o valor " << hashTable->deleteNode(9) << std::endl;
    hashTable->printHashTable();

    std::cout << "tamanho final: " << hashTable->size << std::endl;

    return 0;} //*/
    /*
    
    clock_t t;
    double deltaTime;
    char alfabeto[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int key = 0;

    //Sem Colisao
    HashTable *semColisao = new HashTable(26);
    t = clock();
    for (int i = 0; i < 36; i++){
        key = i;
        semColisao->insertNode(key, alfabeto[i%26]);
    }
    deltaTime = double(clock() - t)/1000;

    std::cout << "HashTable sem colisao" << std::endl;
    semColisao->printHashTable();
    std::cout << "o tempo que levou: " << deltaTime << std::endl;


    //Muita Colisao
    HashTable *muitaColisao = new HashTable(26);
    t = clock();
    for (int i = 0; i < 26*26; i+=26){
        key = i;
        muitaColisao->insertNode(key, alfabeto[i/26]);
    }
    deltaTime = double(clock() - t)/1000;

    std::cout << "\nHashTable muita colisao" << std::endl;
    muitaColisao->printHashTable();
    std::cout << "o tempo que levou: " << deltaTime << std::endl;


    //Aleatorio

    HashTable *aleatorioColisao = new HashTable(26);
    t = clock();
    for (int i = 0; i < 260; i++){
        key = rand() % 26;
        aleatorioColisao->insertNode(key, alfabeto[i%26]);
    }
    deltaTime = double(clock() - t)/1000;

    std::cout << "\nHashTable aleatorio colisao" << std::endl;
    aleatorioColisao->printHashTable();
    std::cout << "o tempo que levou: " << deltaTime << std::endl;

    return 0;
}//*/
