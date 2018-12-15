//#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "proc.h"
#include "memory.h"

class Gzip {
public:
    void compress()
    {
        namespace bio = boost::iostreams;


        std::stringstream ss;
        ss<<sysconf(_SC_NPROCESSORS_ONLN)<<"/"<<get_cpu()<<"/"<<
          *(process_mem_usage())<<"/"<<*(process_mem_usage()+1)<<"/"<<
          *(physical_mem_usage())<<"/"<<*(physical_mem_usage()+1);

        std::stringstream compressed;
        //std::stringstream origin(data);


        bio::filtering_streambuf<bio::input> out;
        out.push(bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));
        out.push(ss);
        bio::copy(out, compressed);

        char telemetry[sizeof(ss)/8];
        ss>>telemetry;
        std::cout<<telemetry<<std::endl;

    //    return compressed.str();
    }

    static std::string decompress(const std::string& data)
    {
        namespace bio = boost::iostreams;

        std::stringstream compressed(data);
        std::stringstream decompressed;

        bio::filtering_streambuf<bio::input> out;
        out.push(bio::gzip_decompressor());
        out.push(compressed);
        bio::copy(out, decompressed);

        return decompressed.str();
    }
};

void zip(){
   Gzip zip;
   zip.compress();


    /*
    std::stringstream ss;
    ss<<sysconf(_SC_NPROCESSORS_ONLN)<<"/"<<get_cpu()<<"/"<<
    *(process_mem_usage())<<"/"<<*(process_mem_usage()+1)<<"/"<<
    *(physical_mem_usage())<<"/"<<*(physical_mem_usage()+1);
    char telemetry[sizeof(ss)/8];
    ss>>telemetry;
    std::cout<<telemetry<<std::endl;*/
}