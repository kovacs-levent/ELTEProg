#include <iostream>
#include "fileSystem.h"
#include "File.h"
#include "Directory.h"

using namespace std;

int main()
{
    FileSystem myFile;
    Directory* dir = new Directory;
    File* p = new File("file1", "some important data");
    File* p2= new File("file2",  "an actual cat picture");
    File* p3 = new File("file3", "");
    File* p4 = new File("file4", "sorozatreszek tanulas helyett");
    dir->addEntry(p);
    dir->addEntry(p2);
    dir->addEntry(p3);
    dir->addEntry(p4);
    myFile.addEntry(dir);
    File* p5 = new File("file5", "random file with random system data that nobody understands");
    myFile.addEntry(p5);
    std::cout << myFile.getSize();
    return 0;
}
