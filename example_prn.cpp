#include <vector>
#include <map>
#include <iostream>

// Producing reproducible random sequences for an exact cross-check
// We define one sequence for each test case, and select between them
// using the 'seed' as an identifier.
// This lets us test with more than one sequence
static inline std::map<uint64_t, std::vector<double> > sequences;
static inline std::map<uint64_t, size_t> sequence_index;

inline void register_sequence(uint64_t seed, std::vector<double> & seq){
  if(sequences.count(seed) == 0){
    //register
    sequences[seed] = seq;
    sequence_index[seed] = 0;
  }else{
    throw std::runtime_error("Sequence already registered for seed");
  }
}

inline double prn(uint64_t * seed){
  if(sequences.count(*seed)){
    // Starting the yield
    size_t ind = sequence_index[*seed];
    if(ind < sequences[*seed].size()){
      return sequences[*seed][sequence_index[*seed] ++];
    }else{
      throw std::runtime_error("Random sequence exhausted");
    }
  }else{
    throw std::runtime_error("Random sequence for seed not found");
  }
}

int main(){
  std::uint64_t seed = 1234;
  std::vector<double> random_seq{0.1, 0.1, 0.5, 0.0, 1.0, 0.0, 1.0, 0.1, 0.67};
  register_sequence(seed, random_seq);
  for(size_t i = 0; i < random_seq.size(); i++) std::cout<<prn(&seed)<<std::endl;

}
