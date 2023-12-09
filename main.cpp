#include "puzzle.hpp"
#include <experimental/random>

int main(int argc, char **argv){
  std::srand(std::time(nullptr));

  std::vector<int> nums;

  // geramos os números
  while( nums.size() < 16 ){
    int x;
    x = std::experimental::randint(1,16);
    if(std::find(nums.begin(),nums.end(),x) != nums.end()){
      continue;
    }else{
      nums.push_back(x);
    }    
  }
  // exibimos os números
 // for( auto &y : nums ){
 //   std::cout << y << ' ';
 // }
//  std::cout.put('\n');

  auto p = std::make_unique<Puzzle>(nums);
  p->run();

  return 0;
}
