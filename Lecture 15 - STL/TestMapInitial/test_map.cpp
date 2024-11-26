#include <map>

class wrapper
{
   public:
      const unsigned int content;

      wrapper(unsigned int _content):
         content(_content)
      {}

};

int main()
{
   std::map<unsigned int, wrapper>  my_map;
   wrapper my_wrapper(1);

   my_map[1] = my_wrapper;
   return 0;
}
