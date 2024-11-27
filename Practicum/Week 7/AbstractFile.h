#include<cstddef>
#include<string>

class AbstractFile {
public:
    virtual void func() = 0;
    
    void setName(std::string value) {
        this->name = value;
    }

    std::string getName() const {
        return this->name;
    }

    size_t getSize() const {
        return this->size;
    }
private:
    std::string name;
    size_t size;
};