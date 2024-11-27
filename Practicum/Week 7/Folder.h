#include "AbstractFile.h"
#include "Node.hpp"

class Folder : public AbstractFile {
public:
    void add(AbstractFile* newFile);
    void remove(const std::string& name);
    std::string getName();
    AbstractFile* getContent();
private:
    Node<AbstractFile*> content;
};