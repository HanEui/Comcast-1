#include <string>
class nade{
    public:
        nade(std::string id){
            myID = id;
        }

        std::string getID() const{
            return myID;
        }
    private:
        std::string myID;

};
