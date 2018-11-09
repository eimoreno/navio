// Construção baseada nas definições de https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

  if(argc<2){
    cout << "Deve-se informar o arquivo executavel que deseja investigar" << endl;
    return 1;
  }
  string filename=argv[1];

  cout << "O arquivo " << filename << " será aberto" << endl;

  ifstream executable(filename.c_str(), ios::in | ios::binary);

  if(!executable.is_open()){
    cout << "Erro de abertura do arquivo " << endl;
    return 1;
  }

  char magic[8];
  executable.read(magic,4);

  cout << std::hex<< (short)magic[0] << magic [1] << magic[2] << magic[3];
  if((magic[0]=0x7f) &&
     (magic[1]='E')&&
     (magic[1]='L')&&
     (magic[1]='F')
    )
    cout << " - File header indicates a lnx file";

  cout << endl;

  executable.read(magic,1);
  cout << std::hex<< (short)magic[0];
  cout << " - this is a " << std::dec << ((magic[0]=0x1)?32:64) << " bit format file" << endl;

  executable.read(magic,1);
  cout << std::hex<< (short)magic[0];
  cout << " - this is a " << std::dec << ((magic[0]=0x1)?"little":"big") << " endianness format file (this affects interpretation of multi-byte fields starting with offset 0x10)" << endl;

  executable.read(magic,1);
  cout << std::hex<< (short)magic[0];

  executable.read(magic,1);
  cout << std::hex<< (short)magic[0];
  cout << " - this is a ";
  switch(magic[0]){
    case 0x00: cout << "System V"; break;
    case 0x01: cout << "HP-UX"; break;
    case 0x02: cout << "NetBSD"; break;
    case 0x03: cout << "Linux"; break;
    case 0x04: cout << "GNU Hurd"; break;
    case 0x06: cout << "Solaris"; break;
    case 0x07: cout << "AIX"; break;
    case 0x08: cout << "IRIX"; break;
    case 0x09: cout << "FreeBSD"; break;
    case 0x0A: cout << "Tru64"; break;
    case 0x0B: cout << "Novell Modesto"; break;
    case 0x0C: cout << "OpenBSD"; break;
    case 0x0D: cout << "OpenVMS"; break;
    case 0x0E: cout << "NonStop Kernel"; break;
    case 0x0F: cout << "AROS"; break;
    case 0x10: cout << "Fenix OS"; break;
    case 0x11: cout << "Cloud ABI"; break;
    case 0x53: cout << "Sortix"; break;
    default: cout << "Unknown"; break;
  }
  cout << endl;

  executable.read(magic,1);
  cout << std::hex<< (short)magic[0];
  cout << " - ABI version" << endl;

  executable.read(magic,7);
  cout << std::hex<< (short)magic[0];
  cout << " - currently unused info" << endl;

  executable.read(magic,2);
  cout << std::hex<< (short)magic[0] << " " << (short) magic[1];
  cout << " - the object is ";
  switch(magic[0]){
    case 0x1: cout << "relocatable "; break;
    case 0x2: cout << "executable "; break;
    case 0x3: cout << "shared"; break;
    case 0x4: cout << "core"; break;
  }
  cout << endl;

  executable.read(magic,2);
  cout << std::hex<< (short)magic[0] << " " << (short) magic[1];
  cout << " - the instruction set is ";
  switch((unsigned int) magic[0]){
    case 0x00: cout << "No specific instruction set"; break;
    case 0x02: cout << "SPARC"; break;
    case 0x03: cout << "x86"; break;
    case 0x08: cout << "MIPS"; break;
    case 0x14: cout << "PowerPC"; break;
    case 0x16: cout << "S390"; break;
    case 0x28: cout << "ARM"; break;
    case 0x2A: cout << "SuperH"; break;
    case 0x32: cout << "IA-64"; break;
    case 0x3E: cout << "x86-64"; break;
    case 0xB7: cout << "AArch64"; break;
    case 0xF3: cout << "RISC-V"; break;
    default: cout << "Unkown"; break;
  }
  cout << endl;

  executable.close();


  return 0;
}


