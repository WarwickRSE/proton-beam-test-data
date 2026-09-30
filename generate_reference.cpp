
#include "material.h"
#include "cross_sections.h"

//Update to path to folder equiv to 'Splines'
const std::string ref_data_path = "/media/raid/MathRadData/protons/";

int main(int argc, char ** argv){

  // Energies to verify
  std::vector<double> energies{200, 150, 100, 75, 40};
 
  // Creating some atoms
  std::vector<Atom> atoms;
  
  {
    double a = 1.008;
    int z = 1;
    std::string name = "hydrogen";
    Atom myAtom(a, z, ref_data_path + name + "_el_ruth_cross_sec.txt",
               0.04);
    atoms.push_back(myAtom);
  }
  {
    double a = 15.999;
    int z = 8;
    std::string name = "oxygen";
    Atom myAtom(a, z, ref_data_path + name + "_ne_rate.txt",
               ref_data_path + name + "_el_ruth_cross_sec.txt",
               ref_data_path + name + "_ne_energyangle_cdf.txt",
               0.04);
    atoms.push_back(myAtom);
  }
  {
    double a = 12.011;
    int z = 6;
    std::string name = "carbon";
    Atom myAtom(a, z, ref_data_path + name + "_ne_rate.txt",
               ref_data_path + name + "_el_ruth_cross_sec.txt",
               ref_data_path + name + "_ne_energyangle_cdf.txt",
               0.04);
    atoms.push_back(myAtom);
  }

  // Creating material of SINGLE atoms
  double I_water = 75.0;
  //Hydrogen only, I for water
 //Material(std::vector<Atom> &atoms, const std::vector<int> &id,
    //       const std::vector<double> &x0, const double d0, const double I0)
    //  : density(d0), I(I0 / 1e6), x(x0), at()

  std::cout<<"Energies ";
  for(int i=0; i<5; i++) std::cout<<energies[i]<<", ";
  std::cout<<std::endl;
  std::cout<<"----------------------------"<<std::endl;
 
  {
    std::cout<<"Bethe-Bloch for Hydrogen only (I for water)"<<std::endl;
    std::cout<<"std::vector<double> ref_loss{";

    Material myMat(atoms, {0}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.bethe_bloch(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }
  {
    std::cout<<"Bethe-Bloch for Oxygen only (I for water)"<<std::endl;
    std::cout<<"std::vector<double> ref_loss{";
    
    Material myMat(atoms, {1}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.bethe_bloch(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  {
    std::cout<<"Bethe-Bloch for Carbon only (I 85)"<<std::endl;
    std::cout<<"std::vector<double> ref_loss{";
    
    Material myMat(atoms, {2}, {1.0}, 1.0, 85.0, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.bethe_bloch(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  std::cout<<"----------------------------"<<std::endl;
 
  {
    std::cout<<"Energy Straggling for Hydrogen only"<<std::endl;
    std::cout<<"std::vector<double> ref_strag{";

    Material myMat(atoms, {0}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.energy_straggling_sd(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }
 
  {
    std::cout<<"Energy Straggling for Oxygen only"<<std::endl;
    std::cout<<"std::vector<double> ref_strag{";

    Material myMat(atoms, {1}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.energy_straggling_sd(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  {
    std::cout<<"Energy Straggling for Carbon only"<<std::endl;
    std::cout<<"std::vector<double> ref_strag{";

    Material myMat(atoms, {2}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.energy_straggling_sd(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  std::cout<<"----------------------------"<<std::endl;
 
  {
    std::cout<<"Elastic Loss for Hydrogen only"<<std::endl;
    std::cout<<"std::vector<double> ref_el{";

    Material myMat(atoms, {0}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.rutherford_and_elastic_rate(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }
 
  {
    std::cout<<"Elastic Loss for Oxygen only"<<std::endl;
    std::cout<<"std::vector<double> ref_el{";

    Material myMat(atoms, {1}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.rutherford_and_elastic_rate(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  {
    std::cout<<"Elastic Loss for Carbon only"<<std::endl;
    std::cout<<"std::vector<double> ref_el{";

    Material myMat(atoms, {2}, {1.0}, 2.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.rutherford_and_elastic_rate(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  std::cout<<"----------------------------"<<std::endl;
 
  {
    std::cout<<"NonElastic Loss for Hydrogen only"<<std::endl;
    std::cout<<"std::vector<double> ref_ne{";

    Material myMat(atoms, {0}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.nonelastic_rate(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }
 
  {
    std::cout<<"NonElastic Loss for Oxygen only"<<std::endl;
    std::cout<<"std::vector<double> ref_ne{";

    Material myMat(atoms, {1}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.nonelastic_rate(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  {
    std::cout<<"NonElastic Loss for Carbon only"<<std::endl;
    std::cout<<"std::vector<double> ref_ne{";

    Material myMat(atoms, {2}, {1.0}, 2.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.nonelastic_rate(energies[i]);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  std::cout<<"----------------------------"<<std::endl;
 
  {
    std::cout<<"Small Angle SD for Hydrogen only"<<std::endl;
    std::cout<<"std::vector<double> ref_sa{";

    Material myMat(atoms, {0}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.multiple_scattering_sd(energies[i], 1);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }
 
  {
    std::cout<<"Small Angle SD for Oxygen only"<<std::endl;
    std::cout<<"std::vector<double> ref_sa{";

    Material myMat(atoms, {1}, {1.0}, 1.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.multiple_scattering_sd(energies[i], 1);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }

  {
    std::cout<<"Small Angle SD for Carbon only"<<std::endl;
    std::cout<<"std::vector<double> ref_sa{";

    Material myMat(atoms, {2}, {1.0}, 2.0, I_water, 0.05);

    for(int i=0; i < 5; i++){
      std::cout<<myMat.multiple_scattering_sd(energies[i], 1);
      if(i<4) std::cout<<", ";
    }
    std::cout<<"};"<<std::endl;
  }
  
  std::cout<<"----------------------------"<<std::endl;

  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.5, 0.0, 1.0, 0.0, 1.0, 0.1, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Elastic Scattering Sampled Angle for Hydrogen"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<double> ref_el_ang{";
    for(size_t i=0; i < energies.size(); i++){
      std::cout<<atoms[0].el_ruth_angle_cdf.sample(energies[i], &myGen);
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.5, 0.0, 1.0, 0.0, 1.0, 0.1, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Elastic Scattering Sampled Angle for Oxygen"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<double> ref_el_ang{";
    for(size_t i=0; i < energies.size(); i++){
      std::cout<<atoms[1].el_ruth_angle_cdf.sample(energies[i], &myGen);
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.5, 0.0, 1.0, 0.0, 1.0, 0.1, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Elastic Scattering Sampled Angle for Carbon"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<double> ref_el_ang{";
    for(size_t i=0; i < energies.size(); i++){
      std::cout<<atoms[2].el_ruth_angle_cdf.sample(energies[i], &myGen);
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }

 
  std::cout<<"----------------------------"<<std::endl;

  {
    gsl_rng myGen;
    std::vector<double> random_seq{0., 0.1, 0.1, 0., 0.1, 0.1, 0., 0.5, 0.5, 0., 0.0, 0.0, 0, 1.0, 1.0, 0, 0.0, 0.0, 0, 1.0, 1.0, 0, 0.1, 0.1, 0, 0.67, 0.67};   
    myGen.prime(random_seq);

    //$$$$$$$$$$ IMPORTANT $$$$$$$$
    // Test code includes one random sample to draw for phi
    // IF matched implementation does not draw for phi in this call-chain, MUST modify the
    // random sequence to match the expected draws
    // CURRENTLY this is the very first draw so we set all 0s above

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};
    
    Material myMat(atoms, {0}, {1.0}, 1.0, I_water, 0.05);

    std::cout<<"Elastic Scattering Complete Angle for Hydrogen"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_el_ang{";
    for(size_t i=0; i < energies.size(); i++){
      std::vector<double> ang{0.0, 0.0};
      double out_e = energies[i], s=0; // s appears to be tracking dE ? It is not _used_ upstream, only set
      myMat.rutherford_elastic_scatter(ang, out_e, s, &myGen);
      std::cout<<"{"<<ang[0]<<", "<<out_e<<"}"; // Ignore ang[1] which is a random phi draw;
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
  {
    gsl_rng myGen;
    std::vector<double> random_seq{0., 0.1, 0.1, 0., 0.1, 0.1, 0., 0.5, 0.5, 0., 0.0, 0.0, 0, 1.0, 1.0, 0, 0.0, 0.0, 0, 1.0, 1.0, 0, 0.1, 0.1, 0, 0.67, 0.67};   
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    Material myMat(atoms, {1}, {1.0}, 1.0, I_water, 0.05);

    std::cout<<"Elastic Scattering Complete Angle for Oxygen"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_el_ang{";
    for(size_t i=0; i < energies.size(); i++){
      std::vector<double> ang{0.0, 0.0};
      double out_e = energies[i], s=0; // s appears to be tracking dE ? It is not _used_ upstream, only set
      myMat.rutherford_elastic_scatter(ang, out_e, s, &myGen);
      std::cout<<"{"<<ang[0]<<", "<<out_e<<"}"; // Ignore ang[1] which is a random phi draw;
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
  {
    gsl_rng myGen;
    std::vector<double> random_seq{0., 0.1, 0.1, 0., 0.1, 0.1, 0., 0.5, 0.5, 0., 0.0, 0.0, 0, 1.0, 1.0, 0, 0.0, 0.0, 0, 1.0, 1.0, 0, 0.1, 0.1, 0, 0.67, 0.67};   
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    Material myMat(atoms, {2}, {1.0}, 1.0, I_water, 0.05);

    std::cout<<"Elastic Scattering Complete Angle for Carbon"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_el_ang{";
    for(size_t i=0; i < energies.size(); i++){
      std::vector<double> ang{0.0, 0.0};
      double out_e = energies[i], s=0; // s appears to be tracking dE ? It is not _used_ upstream, only set
      myMat.rutherford_elastic_scatter(ang, out_e, s, &myGen);
      std::cout<<"{"<<ang[0]<<", "<<out_e<<"}"; // Ignore ang[1] which is a random phi draw;
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }

  std::cout<<"----------------------------"<<std::endl;

  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.5, 0.0, 1.0, 0.0, 1.0, 0.1, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Non Elastic Scattering Sampled Rates for Oxygen"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_ne_ang{";
    for(size_t i=0; i < energies.size(); i++){
      double out_r=0, out_e;
      atoms[1].ne_energy_angle.sample(energies[i], out_r, out_e, &myGen);
      std::cout<<"{"<<out_r<<", "<<out_e<<"}";
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.5, 0.0, 1.0, 0.0, 1.0, 0.1, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Non Elastic Scattering Sampled Rates for Carbon"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_ne_ang{";
    for(size_t i=0; i < energies.size(); i++){
      double out_r=0, out_e;
      atoms[2].ne_energy_angle.sample(energies[i], out_r, out_e, &myGen);
      std::cout<<"{"<<out_r<<", "<<out_e<<"}";
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }

  std::cout<<"----------------------------"<<std::endl;

  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.1, 0.1, 0.5, 0.5, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.1, 0.1, 0.67, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Non Elastic Scattering Full Rates for Oxygen"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_ne_ang_entire{";
    for(size_t i=0; i < energies.size(); i++){
      //In-place update
      double out_e = energies[i], out_r = 0;
      atoms[1].sample_nonelastic_collision(out_e, out_r, &myGen);
      std::cout<<"{"<<out_r<<", "<<out_e<<"}";
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
  {
    gsl_rng myGen;
    std::vector<double> random_seq{0.1, 0.1, 0.1, 0.1, 0.5, 0.5, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.1, 0.1, 0.67, 0.67};
    myGen.prime(random_seq);

    std::vector<double> energies{100.0, 73.0, 5.3, 1.0, 1.0, 160.0, 160.0, 150.0, 150.0};

    std::cout<<"Non Elastic Scattering Full Rates for Carbon"<<std::endl;
    std::cout<<"Energies: ";
    for(size_t i=0; i < energies.size(); i++) std::cout<<energies[i]<<", ";
    std::cout<<"\nRandom Draws: ";
    for(size_t i=0; i < random_seq.size(); i++) std::cout<<random_seq[i]<<", ";
    std::cout<<std::endl<<"std::vector<std::vector<double>> ref_ne_ang_entire{";
    for(size_t i=0; i < energies.size(); i++){
      //In-place update
      double out_e = energies[i], out_r = 0;
      atoms[2].sample_nonelastic_collision(out_e, out_r, &myGen);
      std::cout<<"{"<<out_r<<", "<<out_e<<"}";
      if(i != energies.size() -1)  std::cout<<", ";
    } 
    std::cout<<"};"<<std::endl;
  }
 
}
