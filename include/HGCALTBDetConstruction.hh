//**************************************************
// \file HGCALTBDetConstruction.hh
// \brief: definition of HGCALTBDetConstruction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 10 January 2024
//**************************************************

#ifndef HGCALTBDetConstruction_h
#  define HGCALTBDetConstruction_h 1

// Includers from Geant4
//
#  include "G4VUserDetectorConstruction.hh"
#  include "G4Version.hh"

class HGCALTBDetConstruction : public G4VUserDetectorConstruction
{
  public:
    HGCALTBDetConstruction(G4String gdml_input_file);
    ~HGCALTBDetConstruction();
    // virtual methods from base class
    //
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

  private:
    G4String _gdml_input_file = {""};
    void DefineVisAttributes();
#  if G4VERSION_NUMBER > 1100
    void CheckOverlaps(G4VPhysicalVolume* PhysVol);
#  endif
};

#endif  // HGCALTBDetConstruction_h

//**************************************************
