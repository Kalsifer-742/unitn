





#include <iostream>
#include <limits>

void recover_stream_after_error (std::istream& input_stream);


   
float prompt_for_float(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong); 
float prompt_for_float(const char* prompt, const char* suggest_if_wrong); 
   
float prompt_for_float_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, float min, float max = std::numeric_limits<float>::max()); 
float prompt_for_float_within_range(const char* prompt, const char* suggest_if_wrong, float min, float max = std::numeric_limits<float>::max());

   
double prompt_for_double(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong); 
double prompt_for_double(const char* prompt, const char* suggest_if_wrong); 
   
double prompt_for_double_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, double min, double max = std::numeric_limits<double>::max()); 
double prompt_for_double_within_range(const char* prompt, const char* suggest_if_wrong, double min, double max = std::numeric_limits<double>::max());

   
long prompt_for_long(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong); 
long prompt_for_long(const char* prompt, const char* suggest_if_wrong); 
   
long prompt_for_long_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, long min, long max = std::numeric_limits<long>::max()); 
long prompt_for_long_within_range(const char* prompt, const char* suggest_if_wrong, long min, long max = std::numeric_limits<long>::max());

   
int prompt_for_int(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong); 
int prompt_for_int(const char* prompt, const char* suggest_if_wrong); 
   
int prompt_for_int_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, int min, int max = std::numeric_limits<int>::max()); 
int prompt_for_int_within_range(const char* prompt, const char* suggest_if_wrong, int min, int max = std::numeric_limits<int>::max());

   
unsigned prompt_for_uint(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong); 
unsigned prompt_for_uint(const char* prompt, const char* suggest_if_wrong); 
   
unsigned prompt_for_uint_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, unsigned min, unsigned max = std::numeric_limits<unsigned>::max()); 
unsigned prompt_for_uint_within_range(const char* prompt, const char* suggest_if_wrong, unsigned min, unsigned max = std::numeric_limits<unsigned>::max());

   
unsigned long prompt_for_ulong(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong); 
unsigned long prompt_for_ulong(const char* prompt, const char* suggest_if_wrong); 
   
unsigned long prompt_for_ulong_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, unsigned long min, unsigned long max = std::numeric_limits<unsigned long>::max()); 
unsigned long prompt_for_ulong_within_range(const char* prompt, const char* suggest_if_wrong, unsigned long min, unsigned long max = std::numeric_limits<unsigned long>::max());
