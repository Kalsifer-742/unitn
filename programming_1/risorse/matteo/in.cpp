#include <iostream>
#include <limits>

void recover_stream_after_error (std::istream& input_stream) {
    input_stream.clear();
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool just_return_true() { return true; }


   
float prompt_for_float(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong) { 
   float value; 
   bool value_is_set = false; 
   while (!value_is_set) { 
      std::cout << prompt << std::flush; 
      input_stream >> value; 

      if(!input_stream) { 
         std::cout << suggest_if_wrong << std::endl; 
         recover_stream_after_error(input_stream); 
      } 
      else 
         value_is_set = true; 
   } 

   return value; 
} 
float prompt_for_float(const char* prompt, const char* suggest_if_wrong) { 
   return prompt_for_float(std::cin, prompt, suggest_if_wrong); 
} 
   
float prompt_for_float_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, float min, float max) { 
   float value; 
   bool value_is_valid = false; 
   while(!value_is_valid) { 
      value = prompt_for_float(input_stream, prompt, suggest_if_wrong); 
      value_is_valid = value >= min && value < max; 
      if(!value_is_valid) 
         std::cout << suggest_if_wrong << std::endl; 
   } 
   return value; 
} 
float prompt_for_float_within_range(const char* prompt, const char* suggest_if_wrong, float min, float max) { 
   return prompt_for_float_within_range(std::cin, prompt, suggest_if_wrong, min, max); 
}

   
double prompt_for_double(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong) { 
   double value; 
   bool value_is_set = false; 
   while (!value_is_set) { 
      std::cout << prompt << std::flush; 
      input_stream >> value; 

      if(!input_stream) { 
         std::cout << suggest_if_wrong << std::endl; 
         recover_stream_after_error(input_stream); 
      } 
      else 
         value_is_set = true; 
   } 

   return value; 
} 
double prompt_for_double(const char* prompt, const char* suggest_if_wrong) { 
   return prompt_for_double(std::cin, prompt, suggest_if_wrong); 
} 
   
double prompt_for_double_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, double min, double max) { 
   double value; 
   bool value_is_valid = false; 
   while(!value_is_valid) { 
      value = prompt_for_double(input_stream, prompt, suggest_if_wrong); 
      value_is_valid = value >= min && value < max; 
      if(!value_is_valid) 
         std::cout << suggest_if_wrong << std::endl; 
   } 
   return value; 
} 
double prompt_for_double_within_range(const char* prompt, const char* suggest_if_wrong, double min, double max) { 
   return prompt_for_double_within_range(std::cin, prompt, suggest_if_wrong, min, max); 
}

   
long prompt_for_long(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong) { 
   long value; 
   bool value_is_set = false; 
   while (!value_is_set) { 
      std::cout << prompt << std::flush; 
      input_stream >> value; 

      if(!input_stream) { 
         std::cout << suggest_if_wrong << std::endl; 
         recover_stream_after_error(input_stream); 
      } 
      else 
         value_is_set = true; 
   } 

   return value; 
} 
long prompt_for_long(const char* prompt, const char* suggest_if_wrong) { 
   return prompt_for_long(std::cin, prompt, suggest_if_wrong); 
} 
   
long prompt_for_long_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, long min, long max) { 
   long value; 
   bool value_is_valid = false; 
   while(!value_is_valid) { 
      value = prompt_for_long(input_stream, prompt, suggest_if_wrong); 
      value_is_valid = value >= min && value < max; 
      if(!value_is_valid) 
         std::cout << suggest_if_wrong << std::endl; 
   } 
   return value; 
} 
long prompt_for_long_within_range(const char* prompt, const char* suggest_if_wrong, long min, long max) { 
   return prompt_for_long_within_range(std::cin, prompt, suggest_if_wrong, min, max); 
}

   
int prompt_for_int(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong) { 
   int value; 
   bool value_is_set = false; 
   while (!value_is_set) { 
      std::cout << prompt << std::flush; 
      input_stream >> value; 

      if(!input_stream) { 
         std::cout << suggest_if_wrong << std::endl; 
         recover_stream_after_error(input_stream); 
      } 
      else 
         value_is_set = true; 
   } 

   return value; 
} 
int prompt_for_int(const char* prompt, const char* suggest_if_wrong) { 
   return prompt_for_int(std::cin, prompt, suggest_if_wrong); 
} 
   
int prompt_for_int_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, int min, int max) { 
   int value; 
   bool value_is_valid = false; 
   while(!value_is_valid) { 
      value = prompt_for_int(input_stream, prompt, suggest_if_wrong); 
      value_is_valid = value >= min && value < max; 
      if(!value_is_valid) 
         std::cout << suggest_if_wrong << std::endl; 
   } 
   return value; 
} 
int prompt_for_int_within_range(const char* prompt, const char* suggest_if_wrong, int min, int max) { 
   return prompt_for_int_within_range(std::cin, prompt, suggest_if_wrong, min, max); 
}

   
unsigned prompt_for_uint(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong) { 
   unsigned value; 
   bool value_is_set = false; 
   while (!value_is_set) { 
      std::cout << prompt << std::flush; 
      input_stream >> value; 

      if(!input_stream) { 
         std::cout << suggest_if_wrong << std::endl; 
         recover_stream_after_error(input_stream); 
      } 
      else 
         value_is_set = true; 
   } 

   return value; 
} 
unsigned prompt_for_uint(const char* prompt, const char* suggest_if_wrong) { 
   return prompt_for_uint(std::cin, prompt, suggest_if_wrong); 
} 
   
unsigned prompt_for_uint_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, unsigned min, unsigned max) { 
   unsigned value; 
   bool value_is_valid = false; 
   while(!value_is_valid) { 
      value = prompt_for_uint(input_stream, prompt, suggest_if_wrong); 
      value_is_valid = value >= min && value < max; 
      if(!value_is_valid) 
         std::cout << suggest_if_wrong << std::endl; 
   } 
   return value; 
} 
unsigned prompt_for_uint_within_range(const char* prompt, const char* suggest_if_wrong, unsigned min, unsigned max) { 
   return prompt_for_uint_within_range(std::cin, prompt, suggest_if_wrong, min, max); 
}

   
unsigned long prompt_for_ulong(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong) { 
   unsigned long value; 
   bool value_is_set = false; 
   while (!value_is_set) { 
      std::cout << prompt << std::flush; 
      input_stream >> value; 

      if(!input_stream) { 
         std::cout << suggest_if_wrong << std::endl; 
         recover_stream_after_error(input_stream); 
      } 
      else 
         value_is_set = true; 
   } 

   return value; 
} 
unsigned long prompt_for_ulong(const char* prompt, const char* suggest_if_wrong) { 
   return prompt_for_ulong(std::cin, prompt, suggest_if_wrong); 
} 
   
unsigned long prompt_for_ulong_within_range(std::istream& input_stream, const char* prompt, const char* suggest_if_wrong, unsigned long min, unsigned long max) { 
   unsigned long value; 
   bool value_is_valid = false; 
   while(!value_is_valid) { 
      value = prompt_for_ulong(input_stream, prompt, suggest_if_wrong); 
      value_is_valid = value >= min && value < max; 
      if(!value_is_valid) 
         std::cout << suggest_if_wrong << std::endl; 
   } 
   return value; 
} 
unsigned long prompt_for_ulong_within_range(const char* prompt, const char* suggest_if_wrong, unsigned long min, unsigned long max) { 
   return prompt_for_ulong_within_range(std::cin, prompt, suggest_if_wrong, min, max); 
}
