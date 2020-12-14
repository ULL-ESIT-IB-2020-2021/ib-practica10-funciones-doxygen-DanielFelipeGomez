/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file criptografia_final.cc
  * @author Daniel Felipe Gómez alu0101438139@ull.edu.es
  * @date 13 Diciembre 2020
  * @brief El programa recibe un fichero de texto y lo encripta en Cesar o Xor
  *        según elija el usuario
  * @bug Existe incompatibilidad en el Xor, ya que se programo en windows por problemas con 
  *      conexión a la máquina remota. Sin embargo el programa realmente funciona.
  * @see 
  */
#include <iostream>
#include <fstream>
#include <string>

///Función para verificar que el usuario introduce correctamente los datos
void Ejecucion(int argc, char *argv[]){
    
    std::string parametro{argv[1]};
    if (parametro == "--help"){
        std::cout<< "\n./cripto -- Cifrado de ficheros \nModo de uso: ./cripto fichero_entrada fichero_salida método password operación\n \nfichero_entrada: Fichero a codificar\nfichero_salida:  Fichero codificado\nmétodo:          Indica el método de encriptado                   \n1: Cifrado xor                    \n2: Cifrado de César\npassword:        Palabra secreta en el caso de método 1, Valor de K en el método 2\noperación:       Operación a realizar en el fichero                   \n+: encriptar el fichero                   \n-: desencriptar el fichero\n"<< std::endl;
        exit(EXIT_SUCCESS);
    }if (argc != 6){
        std::cout<< argv[0] << ": Falta un número como parámetro." << std::endl;
        std::cout<< "Pruebe "<< argv[0] <<" --help para más información." << std::endl;
        exit(EXIT_SUCCESS);
    }
}
///Declaración de variables generales
std::string criptado,clave, frase, resultado;
int numero_criptado[19];
int numero_clave[19];
int numero_palabra[19];
/** Función para encriptar a partir de una varibale de tipo string que almacena la 
*  información del fichero introducido*/
std::string EncriptarCesar(std::string frase, int longitud, std::string numero){
  const size_t knumero = stoi(numero);
  std::string encriptado;
  for (int i=0; i<=longitud; i++){
    int aux = frase[i];
    char letra(aux+knumero);
    encriptado += letra;
  }
  return encriptado;
}
/** Función para desencriptar a partir de una varibale de tipo string que almacena la 
*  información del fichero introducido*/
std::string DesencriptarCesar(std::string frase, int longitud, std::string numero){
  const size_t knumero = stoi(numero);
  std::string encriptado;
  for (int i=0; i<=longitud; i++){
    int aux = frase[i];
    char letra(aux-knumero);
    encriptado += letra;
  }
  return encriptado;
}
/** Función para encriptar a partir de una varibale de tipo string que almacena la 
*  información del fichero introducido*/
std::string EncriptarXor(std::string frase,int longitud, std::string clave){

	for(int i=0; i<=longitud+1;i++){
	  numero_clave[i]= int(clave[i]);
	  numero_palabra[i]= int(frase[i]);
	  numero_criptado[i]= (numero_palabra[i]^numero_clave[i]);
	  criptado[i]=(char(numero_criptado[i]));
	  resultado+= criptado[i];
	}

	return resultado;

}
/** Función para encriptar a partir de una varibale de tipo string que almacena la 
*  información del fichero introducido*/
std::string DesencriptarXor(std::string frase,int longitud, std::string clave){
	for(int i=0; i<=longitud+1;i++){
	  numero_clave[i]= int(clave[i]);
	  numero_palabra[i]= int(frase[i]);
	  numero_criptado[i]= (numero_palabra[i]^numero_clave[i]);
	  criptado[i]=(char(numero_criptado[i]));
	  resultado+= criptado[i];
	}

	return resultado;

}


int main(int argc, char* argv[]){
  ///Llamado a función para la verificación de datos, previo a la ejecución
    Ejecucion(argc, argv);
  ///Almacenamiento de datos a partir de parámetros introducidos por línea de comandos
    std::ifstream ficheroEntrada{argv[1]};
    std::ofstream ficheroSalida{argv[2]};
    std::string metodo = {argv[3]};
    std::string numero ={argv[4]};
    std::string operacion = {argv[5]};
    int longitud;

  ficheroEntrada.open("fichero_entrada.txt");
  getline(ficheroEntrada, frase);
  ficheroEntrada.close();
  longitud=frase.length();
  ///Ejecución en caso de encriptar con Xor
  if(metodo == "xor"){
    
    if (operacion=="+"){
      ficheroSalida << EncriptarXor(frase,longitud,numero) << std::endl;
    }if(operacion=="-"){
      ficheroSalida << DesencriptarXor(frase,longitud,numero) << std::endl;
    }
  }
  //////Ejecución en caso de encriptar con Cesar
  if(metodo=="cesar"){
    if (operacion=="+"){
      ficheroSalida <<EncriptarCesar(frase, longitud,numero) << std::endl;
    }if(operacion=="-"){
      ficheroSalida << DesencriptarCesar(frase, longitud, numero) << std::endl;
    }
  }
}
