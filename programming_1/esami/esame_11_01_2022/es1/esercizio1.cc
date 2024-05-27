#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

static bool is_base17_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'G');
}

static bool is_separator(char c) {
    return c == '\n' || c == ' ';
}

static bool is_operator(char c) {
    return c == '+' || c == '*' || c == '^';
}

static long parse_base17_digit(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'G')
        return c - 'A' + 10;

    cerr << "errore interno: il valore '" << c << "' (ascii " << 
        (int)c << "passato a parse_base17_digit è invalido" << endl;
}

static void extract_separators(std::istream& i) {
    while(is_separator(i.peek()))
        i.get();
}

static long parse_base17_num(std::istream& in_stream) {
    long ret = 0;

    while(is_base17_digit(in_stream.peek())) {
        char c = in_stream.get();

        long digit_val = parse_base17_digit(c);
        ret *= 17;
        ret += digit_val;
    }

    extract_separators(in_stream);

    return ret;
}

struct operation {
    long a, b;
    char op;
};


static operation parse_operation(std::istream& in_stream) {
    operation ret;
    
    ret.a = parse_base17_num(in_stream);

    in_stream >> ret.op;
    if(!is_operator(ret.op))
        cerr << "errore interno: '" << ret.op << "' (ascii "<< (int)ret.op <<
            ") passato a parse_operation non e' un operatore valido" << endl;

    extract_separators(in_stream);

    ret.b = parse_base17_num(in_stream);
    
    extract_separators(in_stream);
    
    return ret;
}

static long get_result(operation o) {
    switch(o.op) {
        case '+':
            return o.a + o.b;
        case '*':
            return o.a * o.b;
        case '^':
            return pow(o.a, o.b);
        default:
            cerr << "errore interno: '" << o.op << "' passato a get_result non e' un operatore valido" << endl;
    }
}

struct io_fstreams {
    ifstream i;
    ofstream o;
    bool is_valid;
};

static io_fstreams get_files(int argc, char** argv) {
    io_fstreams ret;

    if(argc < 3) {
        cerr << "l'argomento del programma devono essere il file di input e quello di output" << endl;
        ret.is_valid = false;
        return ret;
    }

    ret.i.open(argv[1]);

    if(ret.i.fail()) {
        cerr << "Il file di input non esiste" << endl;
        ret.is_valid = false;
        return ret;
    }

    ret.o.open(argv[2]);

    return ret;
}



int main(int argc, char** argv) {
    io_fstreams files = get_files(argc, argv);
    if(files.is_valid) {
        while(files.i)
            files.o << get_result(parse_operation(files.i)) << endl;
    }
}
