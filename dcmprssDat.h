#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "proc.h"
#include "memory.h"

using namespace std;
class Gzip {
public:
    std::stringstream ss;
    ~Gzip()=default;

    Gzip(){
       this->ss << "0";
    };

    unsigned short data_amount(){
            ss << sysconf(_SC_NPROCESSORS_ONLN) << "/" << get_cpu() << "/" <<
               *(process_mem_usage()) << "/" << *(process_mem_usage() + 1) << "/" <<
               *(physical_mem_usage()) << "/" << *(physical_mem_usage() + 1);
            return sizeof(ss);
    }

    string compress() {
        namespace bio = boost::iostreams;

        bio::filtering_streambuf<bio::input> out;
        out.push(bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));
        out.push(ss);
        bio::copy(out, ss);

        std::cout << ss.str() << std::endl;
        return ss.str();
    }
};