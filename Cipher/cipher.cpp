#include <iostream>
#include <Vector>
#include <Deque>
#include <unordered_map>
#include "Rotor.cpp"
#include "decoder.cpp"


int main()
{   

    std::vector<char> list1 = {'u','w','c','f','i','h','j','s','q','b','k','v','e','z','n','r','o','y','t','l','m','x','d','a','g','p'};
    std::vector<char> list2 = {'u','x','p','f','i','h','s','m','j','b','k','v','e','z','n','r','o','y','t','l','q','w','d','a','g','c'};
    std::vector<char> list3 = {'g','a','c','f','i','r','j','s','q','b','k','v','e','h','n','t','o','y','z','l','m','x','d','w','u','p'};
    Rotor rotor1(list1);
    Rotor rotor2(list2);
    Rotor rotor3(list3);

    std::string ciphered = "";
    std::string text = "";    
    char mode = 'c';

    while(true){
        std::cout << "Which mode would you like to use? cipher or decipher? c/d";
        std::cin >> mode;
    if(mode == 'c'){
        std::cout << "please input message: \n";
        std::cin >> text; 
        ciphered = "";
        for(int i = 0; i < text.size(); i++){
        ciphered.push_back(rotor3.cipher(rotor2.cipher(rotor1.cipher(text[i]))));
        }
        std::cout << ciphered << "\n";
    } else if( mode == 'd'){
        decoder(rotor1, rotor2, rotor3, ciphered);
    }
}
}
