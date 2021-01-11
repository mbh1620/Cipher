#include <iostream>

//The Rotor class is used to change a letter from one to another depending on the configuration on the construction of the rotor.

//Encyrption is order turning to chaos. 
//To Decrypt you need the same order starting configuration and then look to see if the chaos which is produced is the same as the original.


class Rotor {

    private:

        std::unordered_map<char, int> rotor_mappings;
        std::deque<char> rotor_list;
        std::vector<char> original;
        Rotor *next_rotor;
        //We need a rotor heirachy so that we know where to pass the letters too
        //We could do this using pointers 


    public:

        Rotor(std::vector<char> letters){
            //When creating a rotor we need to map letters with each other. This can be done by passing a char array to the construstor.
            rotor_list.clear();
            for(int i = 0; i < letters.size(); i++){
                //Index 0 corresponds to a etc...
                // rotor_mappings.insert({letters[i],i});
                original.push_back(letters[i]);
                rotor_list.push_back(letters[i]);
            }
            reset_map();
        }

        void reset_map(){
            rotor_mappings.clear();
            for(int i = 0; i < rotor_list.size(); i++){
                //Index 0 corresponds to a etc...
                rotor_mappings.insert({rotor_list[i],i});
            }
        }

        void itr_rotor(){

            char temp = rotor_list[0];
            this->rotor_list.pop_front();
            this->rotor_list.push_back(temp);

        }

        void set_next(Rotor *rotor_next){
            this->next_rotor = rotor_next;
        }

        char convert(int num){

            char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

            return alphabet[num];
        }

        char cipher(char letter){
            std::unordered_map<char, int>::iterator itr = rotor_mappings.find(letter);
            char val;
            if(itr != rotor_mappings.end()){
                val = this->convert(itr->second);
            }
            itr_rotor();
            reset_map();
            return val;
        }

        void reset_rotor(){
            rotor_list.clear();
            for(int i = 0; i < this->original.size(); i++){
                //Index 0 corresponds to a etc...
                // rotor_mappings.insert({letters[i],i});
                rotor_list.push_back(original[i]);
            }
        }

};