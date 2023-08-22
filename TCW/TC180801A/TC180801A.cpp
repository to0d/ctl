#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <vector>
#include <memory>
#include <fstream>

/***********************************************************/
// Copy from `gdb-code\elfcpp\elfcpp.h`
/***********************************************************/

// Offsets within the Ehdr e_ident field.
const int EI_MAG0       = 0;
const int EI_MAG1       = 1;
const int EI_MAG2       = 2;
const int EI_MAG3       = 3;
const int EI_CLASS      = 4;
const int EI_DATA       = 5;
const int EI_VERSION    = 6;
const int EI_OSABI      = 7;
const int EI_ABIVERSION = 8;
const int EI_PAD        = 9;
const int EI_NIDENT     = 16;

// The valid values found in Ehdr e_ident[EI_CLASS].
enum {
    ELFCLASSNONE = 0,
    ELFCLASS32 = 1,
    ELFCLASS64 = 2
};

// ByteOrder
enum {
    ELFDATANONE = 0,
    ELFDATA2LSB = 1,
    ELFDATA2MSB = 2
};

// The valid values found in the Phdr p_type field.
enum PT
{
    PT_NULL     = 0,
    PT_LOAD     = 1,
    PT_DYNAMIC  = 2,
    PT_INTERP   = 3,
    PT_NOTE     = 4,
    PT_SHLIB    = 5,
    PT_PHDR     = 6,
    PT_TLS      = 7,
    PT_LOOS     = 0x60000000,
    PT_HIOS     = 0x6fffffff,
    PT_LOPROC   = 0x70000000,
    PT_HIPROC   = 0x7fffffff,
    // The remaining values are not in the standard.
    // Frame unwind information.
    PT_GNU_EH_FRAME     = 0x6474e550,
    PT_SUNW_EH_FRAME    = 0x6474e550,
    // Stack flags.
    PT_GNU_STACK        = 0x6474e551,
    // Read only after relocation.
    PT_GNU_RELRO        = 0x6474e552,
    // Platform architecture compatibility information
    PT_ARM_ARCHEXT      = 0x70000000,
    // Exception unwind tables
    PT_ARM_EXIDX        = 0x70000001
};

// Dynamic tags found in the PT_DYNAMIC segment.
enum DT
{
    DT_NULL = 0,
    DT_NEEDED = 1,
    DT_PLTRELSZ = 2,
    DT_PLTGOT = 3,
    DT_HASH = 4,
    DT_STRTAB = 5,
    DT_SYMTAB = 6,
    DT_RELA = 7,
    DT_RELASZ = 8,
    DT_RELAENT = 9,
    DT_STRSZ = 10,
    DT_SYMENT = 11,
    DT_INIT = 12,
    DT_FINI = 13,
    DT_SONAME = 14,
    DT_RPATH = 15,
    DT_SYMBOLIC = 16,
    DT_REL = 17,
    DT_RELSZ = 18,
    DT_RELENT = 19,
    DT_PLTREL = 20,
    DT_DEBUG = 21,
    DT_TEXTREL = 22,
    DT_JMPREL = 23,
    DT_BIND_NOW = 24,
    DT_INIT_ARRAY = 25,
    DT_FINI_ARRAY = 26,
    DT_INIT_ARRAYSZ = 27,
    DT_FINI_ARRAYSZ = 28,
    DT_RUNPATH = 29,
    DT_FLAGS = 30,

    // This is used to mark a range of dynamic tags.  It is not really
    // a tag value.
    DT_ENCODING = 32,

    DT_PREINIT_ARRAY = 32,
    DT_PREINIT_ARRAYSZ = 33,
    DT_LOOS = 0x6000000d,
    DT_HIOS = 0x6ffff000,
    DT_LOPROC = 0x70000000,
    DT_HIPROC = 0x7fffffff,

    // The remaining values are extensions used by GNU or Solaris.
    DT_VALRNGLO = 0x6ffffd00,
    DT_GNU_PRELINKED = 0x6ffffdf5,
    DT_GNU_CONFLICTSZ = 0x6ffffdf6,
    DT_GNU_LIBLISTSZ = 0x6ffffdf7,
    DT_CHECKSUM = 0x6ffffdf8,
    DT_PLTPADSZ = 0x6ffffdf9,
    DT_MOVEENT = 0x6ffffdfa,
    DT_MOVESZ = 0x6ffffdfb,
    DT_FEATURE = 0x6ffffdfc,
    DT_POSFLAG_1 = 0x6ffffdfd,
    DT_SYMINSZ = 0x6ffffdfe,
    DT_SYMINENT = 0x6ffffdff,
    DT_VALRNGHI = 0x6ffffdff,

    DT_ADDRRNGLO = 0x6ffffe00,
    DT_GNU_HASH = 0x6ffffef5,
    DT_TLSDESC_PLT = 0x6ffffef6,
    DT_TLSDESC_GOT = 0x6ffffef7,
    DT_GNU_CONFLICT = 0x6ffffef8,
    DT_GNU_LIBLIST = 0x6ffffef9,
    DT_CONFIG = 0x6ffffefa,
    DT_DEPAUDIT = 0x6ffffefb,
    DT_AUDIT = 0x6ffffefc,
    DT_PLTPAD = 0x6ffffefd,
    DT_MOVETAB = 0x6ffffefe,
    DT_SYMINFO = 0x6ffffeff,
    DT_ADDRRNGHI = 0x6ffffeff,

    DT_RELACOUNT = 0x6ffffff9,
    DT_RELCOUNT = 0x6ffffffa,
    DT_FLAGS_1 = 0x6ffffffb,
    DT_VERDEF = 0x6ffffffc,
    DT_VERDEFNUM = 0x6ffffffd,
    DT_VERNEED = 0x6ffffffe,
    DT_VERNEEDNUM = 0x6fffffff,

    DT_VERSYM = 0x6ffffff0,

    // Specify the value of _GLOBAL_OFFSET_TABLE_.
    DT_PPC_GOT = 0x70000000,

    // Specify the start of the .glink section.
    DT_PPC64_GLINK = 0x70000000,

    // Specify the start and size of the .opd section.
    DT_PPC64_OPD = 0x70000001,
    DT_PPC64_OPDSZ = 0x70000002,

    // The index of an STT_SPARC_REGISTER symbol within the DT_SYMTAB
    // symbol table.  One dynamic entry exists for every STT_SPARC_REGISTER
    // symbol in the symbol table.
    DT_SPARC_REGISTER = 0x70000001,

    DT_AUXILIARY = 0x7ffffffd,
    DT_USED = 0x7ffffffe,
    DT_FILTER = 0x7fffffff
};;

/***********************************************************/
// Copy from `gdb-code\include\elf\external.h`
/***********************************************************/

/* ELF Header (32-bit implementations) */
typedef struct {
    unsigned char    e_ident[16];       /* ELF "magic number"               */
    unsigned char    e_type[2];         /* Identifies object file type      */
    unsigned char    e_machine[2];      /* Specifies required architecture  */
    unsigned char    e_version[4];      /* Identifies object file version   */
    unsigned char    e_entry[8];        /* Entry point virtual address      */
    unsigned char    e_phoff[8];        /* Program header table file offset */
    unsigned char    e_shoff[8];        /* Section header table file offset */
    unsigned char    e_flags[4];        /* Processor-specific flags         */
    unsigned char    e_ehsize[2];       /* ELF header size in bytes         */
    unsigned char    e_phentsize[2];    /* Program header table entry size  */
    unsigned char    e_phnum[2];        /* Program header table entry count */
    unsigned char    e_shentsize[2];    /* Section header table entry size  */
    unsigned char    e_shnum[2];        /* Section header table entry count */
    unsigned char    e_shstrndx[2];     /* Section header string table index*/
} Elf64_External_Ehdr;

/* Program header */
typedef struct {
    unsigned char    p_type[4];         /* Identifies program segment type  */
    unsigned char    p_flags[4];        /* Segment flags                    */
    unsigned char    p_offset[8];       /* Segment file offset              */
    unsigned char    p_vaddr[8];        /* Segment virtual address          */
    unsigned char    p_paddr[8];        /* Segment physical address         */
    unsigned char    p_filesz[8];       /* Segment size in file             */
    unsigned char    p_memsz[8];        /* Segment size in memory           */
    unsigned char    p_align[8];        /* Segment alignment, file & memory */
} Elf64_External_Phdr;

/* dynamic section structure */
typedef struct {
    unsigned char    d_tag[8];          /* entry tag value */
    union {
        unsigned char    d_val[8];
        unsigned char    d_ptr[8];
    } d_un;
} Elf64_External_Dyn;

/* Relocation Entries */
typedef struct {
    unsigned char r_offset[8];          /* Location at which to apply the action */
    unsigned char    r_info[8];         /* index and type of relocation          */
    unsigned char    r_addend[8];       /* Constant addend used to compute value */
} Elf64_External_Rela;

/* Symbol table entry */
typedef struct {
    unsigned char    st_name[4];        /* Symbol name, index in string tbl */
    unsigned char    st_info[1];        /* Type and binding attributes      */
    unsigned char    st_other[1];       /* No defined meaning, 0            */
    unsigned char    st_shndx[2];       /* Associated section index         */
    unsigned char    st_value[8];       /* Value of the symbol              */
    unsigned char    st_size[8];        /* Associated symbol size           */
} Elf64_External_Sym;


std::shared_ptr<void> resolveLibraryFunc(const std::string& name);


class Loader {
    std::ifstream fileStream_;

public:
    Loader(const std::string& path);
    Loader(std::ifstream&& fileStream);
    void execute();
};


Loader::Loader(const std::string& path) : Loader(std::ifstream(path, std::ios::in | std::ios::binary))
{}

Loader::Loader(std::ifstream&& fileStream) : fileStream_(std::move(fileStream)) {
    if (!fileStream_) {
        throw std::runtime_error("open file failed");
    }
}

void Loader::execute() {

    std::cout << "====== start loading elf ======" << std::endl;

    // 检查当前运行程序是否64位
    if (sizeof(intptr_t) != sizeof(std::int64_t)) {
        throw std::runtime_error("please use x64 compile and run this program");
    }

    // 读取ELF头
    Elf64_External_Ehdr elfHeader = {};
    fileStream_.seekg(0);
    fileStream_.read(reinterpret_cast<char*>(&elfHeader), sizeof(elfHeader));

    // 检查ELF头，只支持64位且byte order是little endian的程序
    if (std::string(reinterpret_cast<char*>(elfHeader.e_ident), 4) != "\x7f\x45\x4c\x46") {
        throw std::runtime_error("magic not match");
    }
    else if (elfHeader.e_ident[EI_CLASS] != ELFCLASS64) {
        throw std::runtime_error("only support ELF64");
    }
    else if (elfHeader.e_ident[EI_DATA] != ELFDATA2LSB) {
        throw std::runtime_error("only support little endian");
    }

    // 获取program table的信息
    std::uint32_t programTableOffset = *reinterpret_cast<std::uint32_t*>(elfHeader.e_phoff);
    std::uint16_t programTableEntrySize = *reinterpret_cast<std::uint16_t*>(elfHeader.e_phentsize);
    std::uint16_t programTableEntryNum = *reinterpret_cast<std::uint16_t*>(elfHeader.e_phnum);
    std::cout << "program table at: " << programTableOffset << ", "
              << programTableEntryNum << " x " << programTableEntrySize << std::endl;

    // 获取section table的信息
    // section table只给linker用，loader中其实不需要访问section table
    std::uint32_t sectionTableOffset = *reinterpret_cast<std::uint32_t*>(elfHeader.e_shoff);
    std::uint16_t sectionTableEntrySize = *reinterpret_cast<std::uint16_t*>(elfHeader.e_shentsize);
    std::uint16_t sectionTableEntryNum = *reinterpret_cast<std::uint16_t*>(elfHeader.e_shentsize);
    std::cout << "section table at: " << sectionTableOffset << ", "
              << sectionTableEntryNum << " x " << sectionTableEntrySize << std::endl;

    // 准备动态链接的信息
    std::uint64_t jmpRelAddr = 0; // 重定位记录的开始地址
    std::uint64_t pltRelType = 0; // 重定位记录的类型 RELA或REL
    std::uint64_t pltRelSize = 0; // 重定位记录的总大小
    std::uint64_t symTabAddr = 0; // 动态符号表的开始地址
    std::uint64_t strTabAddr = 0; // 动态符号名称表的开始地址
    std::uint64_t strTabSize = 0; // 动态符号名称表的总大小

    // 遍历program hedaer
    std::vector<Elf64_External_Phdr> programHeaders;
    programHeaders.resize(programTableEntryNum);
    fileStream_.read(reinterpret_cast<char*>(programHeaders.data()), programTableEntryNum * programTableEntrySize);
    std::vector<std::shared_ptr<void>> loadedSegments;
    
    for (const auto& programHeader : programHeaders) {
        std::uint32_t type = *reinterpret_cast<const std::uint32_t*>(programHeader.p_type);
        if (type == PT_LOAD) {
            // 把文件内容(包含程序代码和数据)加载到虚拟内存，这个示例不考虑地址冲突
            std::uint64_t fileOffset = *reinterpret_cast<const std::uint64_t*>(programHeader.p_offset);
            std::uint64_t fileSize = *reinterpret_cast<const std::uint64_t*>(programHeader.p_filesz);
            std::uint64_t virtAddr = *reinterpret_cast<const std::uint64_t*>(programHeader.p_vaddr);
            std::uint64_t memSize = *reinterpret_cast<const std::uint64_t*>(programHeader.p_memsz);
            if (memSize < fileSize) {
                throw std::runtime_error("invalid memsz in program header, it shouldn't less than filesz");
            }
            // 在指定的虚拟地址分配内存
            std::cout << std::hex << "allocate address at: 0x" << virtAddr <<
                " size: 0x" << memSize << std::dec << std::endl;
            void* addr = ::VirtualAlloc((void*)virtAddr, memSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
            if (addr == nullptr) {
                throw std::runtime_error("allocate memory at specific address failed");
            }
            loadedSegments.emplace_back(addr, [](void* ptr) { ::VirtualFree(ptr, 0, MEM_RELEASE); });
            // 复制文件内容到虚拟内存
            fileStream_.seekg(fileOffset);
            if (!fileStream_.read(reinterpret_cast<char*>(addr), fileSize)) {
                throw std::runtime_error("read contents into memory from LOAD program header failed");
            }
        }
        else if (type == PT_DYNAMIC) {
            // 遍历动态节
            std::uint64_t fileOffset = *reinterpret_cast<const std::uint64_t*>(programHeader.p_offset);
            fileStream_.seekg(fileOffset);
            Elf64_External_Dyn dynSection = {};
            std::uint64_t dynSectionTag = 0;
            std::uint64_t dynSectionVal = 0;
            do {
                if (!fileStream_.read(reinterpret_cast<char*>(&dynSection), sizeof(dynSection))) {
                    throw std::runtime_error("read dynamic section failed");
                }
                dynSectionTag = *reinterpret_cast<const std::uint64_t*>(dynSection.d_tag);
                dynSectionVal = *reinterpret_cast<const std::uint64_t*>(dynSection.d_un.d_val);
                if (dynSectionTag == DT_JMPREL) {
                    jmpRelAddr = dynSectionVal;
                }
                else if (dynSectionTag == DT_PLTREL) {
                    pltRelType = dynSectionVal;
                }
                else if (dynSectionTag == DT_PLTRELSZ) {
                    pltRelSize = dynSectionVal;
                }
                else if (dynSectionTag == DT_SYMTAB) {
                    symTabAddr = dynSectionVal;
                }
                else if (dynSectionTag == DT_STRTAB) {
                    strTabAddr = dynSectionVal;
                }
                else if (dynSectionTag == DT_STRSZ) {
                    strTabSize = dynSectionVal;
                }
            } while (dynSectionTag != 0);
        }
    }

    // 读取动态链接符号表
    std::string dynamicSymbolNames(reinterpret_cast<char*>(strTabAddr), strTabSize);
    Elf64_External_Sym* dynamicSymbols = reinterpret_cast<Elf64_External_Sym*>(symTabAddr);

    // 设置动态链接的函数地址
    std::cout << std::hex << "read dynamic entires at: 0x" << jmpRelAddr <<
        " size: 0x" << pltRelSize << std::dec << std::endl;
    if (jmpRelAddr == 0 || pltRelType != DT_RELA || pltRelSize % sizeof(Elf64_External_Rela) != 0) {
        throw std::runtime_error("invalid dynamic entry info, rel type should be rela");
    }
    std::vector<std::shared_ptr<void>> libraryFuncs;
    for (std::uint64_t offset = 0; offset < pltRelSize; offset += sizeof(Elf64_External_Rela)) {
        Elf64_External_Rela* rela = (Elf64_External_Rela*)(jmpRelAddr + offset);
        std::uint64_t relaOffset = *reinterpret_cast<const std::uint64_t*>(rela->r_offset);
        std::uint64_t relaInfo = *reinterpret_cast<const std::uint64_t*>(rela->r_info);
        std::uint64_t relaSym = relaInfo >> 32; // ELF64_R_SYM
        std::uint64_t relaType = relaInfo & 0xffffffff; // ELF64_R_TYPE
        // 获取符号
        Elf64_External_Sym* symbol = dynamicSymbols + relaSym;
        std::uint32_t symbolNameOffset = *reinterpret_cast<std::uint32_t*>(symbol->st_name);
        std::string symbolName(dynamicSymbolNames.data() + symbolNameOffset);
        std::cout << "relocate symbol: " << symbolName << std::endl;
        // 替换函数地址
        // 原本应该延迟解决，这里图简单就直接覆盖了
        void** relaPtr = reinterpret_cast<void**>(relaOffset);
        std::shared_ptr<void> func = resolveLibraryFunc(symbolName);
        if (func == nullptr) {
            throw std::runtime_error("unsupport symbol name");
        }
        libraryFuncs.emplace_back(func);
        *relaPtr = func.get();
    }

    // 获取入口点
    std::uint64_t entryPointAddress = *reinterpret_cast<const std::uint64_t*>(elfHeader.e_entry);
    void(*entryPointFunc)() = reinterpret_cast<void(*)()>(entryPointAddress);
    std::cout << "entry point: " << entryPointFunc << std::endl;
    std::cout << "====== finish loading elf ======" << std::endl;

    // 执行主程序
    // 会先调用__libc_start_main, 然后再调用main
    // 调用__libc_start_main后的指令是hlt，所以必须在__libc_start_main中退出执行
    entryPointFunc();
}

 
// 原始的返回地址
thread_local void* originalReturnAddress = nullptr;

void* getOriginalReturnAddress() {
    return originalReturnAddress;
}

void setOriginalReturnAddress(void* address) {
    originalReturnAddress = address;
}

// 模拟libc调用main的函数，目前不支持传入argc和argv
void __libc_start_main(int(*main)()) {
    std::cout << "call main: " << main << std::endl;
    int ret = main();
    std::cout << "result: " << ret << std::endl;
    std::exit(0);
}

// 模拟printf函数
int __printf(const char* fmt, ...) {
    int ret;
    va_list myargs;
    va_start(myargs, fmt);
    ret = ::vprintf(fmt, myargs);
    va_end(myargs);
    return ret;
}

// 把System V AMD64 ABI转换为Microsoft x64 calling convention
// 因为vc++不支持inline asm，只能直接写hex
// 这个函数支持任意长度的参数，但是性能会有损耗，如果参数数量已知可以编写更快的loader代码    
const unsigned char generic_func_loader[]{
    // 让参数连续排列在栈上
    // [第一个参数] [第二个参数] [第三个参数] ...
    0x58, // pop %rax 暂存原返回地址
    0x41, 0x51, // push %r9 入栈第六个参数，之后的参数都在后续的栈上
    0x41, 0x50, // push %r8 入栈第五个参数
    0x51, // push %rcx 入栈第四个参数
    0x52, // push %rdx 入栈第三个参数
    0x56, // push %rsi 入栈第二个参数
    0x57, // push %rdi 入栈第一个参数

    // 调用setOriginalReturnAddress保存原返回地址
    0x48, 0x89, 0xc1, // mov %rax, %rcx 第一个参数是原返回地址
    0x48, 0x83, 0xec, 0x20, // sub $0x20, %rsp 预留32位的影子空间
    0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // movabs $0, %rax
    0xff, 0xd0, // callq *%rax 调用setOriginalReturnAddress
    0x48, 0x83, 0xc4, 0x20, // add %0x20, %rsp 释放影子空间

    // 转换到Microsoft x64 calling convention
    0x59, // pop %rcx 出栈第一个参数
    0x5a, // pop %rdx 出栈第二个参数
    0x41, 0x58, // pop %r8 // 出栈第三个参数
    0x41, 0x59, // pop %r9 // 出栈第四个参数

    // 调用目标函数
    0x48, 0x83, 0xec, 0x20, // sub $0x20, %esp 预留32位的影子空间
    0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // movabs 0, %rax
    0xff, 0xd0, // callq *%rax 调用模拟的函数
    0x48, 0x83, 0xc4, 0x30, // add $0x30, %rsp 释放影子空间和参数(影子空间32 + 参数8*2)
    0x50, // push %rax 保存返回值

    // 调用getOriginalReturnAddress获取原返回地址
    0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // movabs $0, %rax
    0xff, 0xd0, // callq *%rax 调用getOriginalReturnAddress
    0x48, 0x89, 0xc1, // mov %rax, %rcx 原返回地址存到rcx
    0x58, // 恢复返回值
    0x51, // 原返回地址入栈顶
    0xc3 // 返回
};

const int generic_func_loader_set_addr_offset = 18;
const int generic_func_loader_target_offset   = 44;
const int generic_func_loader_get_addr_offset = 61;


// 获取动态链接函数的调用地址
std::shared_ptr<void> resolveLibraryFunc(const std::string& name) {
    void* funcPtr = nullptr;
    if (name == "__libc_start_main") {
        funcPtr = (void*) __libc_start_main;
    }
    else if (name == "printf") {
        funcPtr = (void*) __printf;
    }
    else {
        return nullptr;
    }
    void* addr = ::VirtualAlloc(nullptr,
        sizeof(generic_func_loader), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (addr == nullptr) {
        throw std::runtime_error("allocate memory for _libc_start_main_loader failed");
    }
    std::shared_ptr<void> result(addr, [](void* ptr) { ::VirtualFree(ptr, 0, MEM_RELEASE); });
    std::memcpy(addr, generic_func_loader, sizeof(generic_func_loader));
    char* addr_c = reinterpret_cast<char*>(addr);
    *reinterpret_cast<void**>(addr_c + generic_func_loader_set_addr_offset) = (void*)setOriginalReturnAddress;
    *reinterpret_cast<void**>(addr_c + generic_func_loader_target_offset)   = (void*)funcPtr;
    *reinterpret_cast<void**>(addr_c + generic_func_loader_get_addr_offset) = (void*)getOriginalReturnAddress;
    return result;
}
    
int main() {
    
    try {
        Loader loader("hello.a");
        loader.execute();
    }
    catch (const std::exception& ex) {
        std::cout << "error: " << ex.what() << std::endl;
    }
    return 0;
}
    