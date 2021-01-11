

void decoder(Rotor rotor1, Rotor rotor2, Rotor rotor3 , std::string ciphered){


//Reset the rotors and use brute force to find what the letter is that makes the 
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string decoded = "";
    std::cout << ciphered.size() << "\n";
    for(int t = 0; t < ciphered.size(); t++){
        for(int z = 0; z<26; z++){
            rotor1.reset_rotor();
            rotor2.reset_rotor();
            rotor3.reset_rotor();

            // std::cout << alphabet[z] << " " << rotor3.cipher(rotor2.cipher(rotor1.cipher(alphabet[z]))) << "\n";
            
            for(int y = 0; y < decoded.size(); y++){
                rotor3.cipher(rotor2.cipher(rotor1.cipher(ciphered[y])));
            }
            

            char temp = rotor3.cipher(rotor2.cipher(rotor1.cipher(alphabet[z])));
            std::cout << temp << " " << ciphered[t] << " \n";
            if( temp == ciphered[t]){
                decoded.push_back(alphabet[z]);
                std::cout << "pushed " << alphabet[z] << " to decoded \n";
                break;
            }
            //std::cout << decoded << "\n";
        }
        
    }
    std::cout << "\n" << decoded << "\n";
    





}


