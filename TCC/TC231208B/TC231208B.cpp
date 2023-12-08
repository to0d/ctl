#include <iostream>
#include <cxxabi.h>
#include <cstdlib>
#include <cstring>

std::string demangle(const std::string& mangled_name) {
    int status;
    const char* str = mangled_name.c_str();
    char* demangled_name = abi::__cxa_demangle(str, nullptr, nullptr, &status);
    std::string result;
    if (status == 0) {
        result = mangled_name;
    }
    std::free(demangled_name);
    return result;
}

std::string demangle_func_name(const std::string& mangled_name) {
    int status;
    const char* str = mangled_name.c_str();
    char* demangled_name = abi::__cxa_demangle(str, nullptr, nullptr, &status);
    std::string result;
    if (status == 0) {
        const char* pos = strchr(demangled_name, '(');
        if( pos != NULL )
            result = std::string(demangled_name, 0, pos - demangled_name);
        else
            result = demangled_name;
    }
    std::free(demangled_name);
    return result;
}

int main() {
    std::string mangled_name = "_Z12SIMDLOOP_TAGi";
    std::string original_name = demangle(mangled_name);
    std::string func_name = demangle_func_name(mangled_name);
    std::cout << "Mangled  Name: " << mangled_name << std::endl;
    std::cout << "Original Name: " << original_name << std::endl;
    std::cout << "Function Name: " << func_name << std::endl;
    return 0;
}